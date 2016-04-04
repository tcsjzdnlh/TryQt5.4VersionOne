#include "HugeEnumToString.h"
#include <memory>
#include <QtCore/QStringList>
#include <QtWidgets/QFileDialog>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtWidgets/QMessageBox>
#include <regex>
#include <QtCore/QRegExp>
#include <QtCore/QRegularExpression>
#include "MainWnd.h"

extern CMainWnd	*g_pWnd;


CHugeEnumToString::CHugeEnumToString( const QString &_strEnum, bool _bIsFn )
{
	
	QString strEnumContents;
		
	if( _bIsFn )
	{
		QFile file( _strEnum );
		if( !file.open( QIODevice::ReadOnly ) )
		{
			QMessageBox::warning( nullptr, QObject::tr( "title" ),
									QObject::tr( "open file %1 failed" ).arg( _strEnum ),
									QMessageBox::Ok );


			return;
		}


		QTextStream in( &file );
		strEnumContents =  in.readAll();		
	}


	
	Parse( strEnumContents );

}

CHugeEnumToString::EnumString CHugeEnumToString::GetEnumString() const
{
	return m_EnumString;
}

CHugeEnumToString::EnumString CHugeEnumToString::GetEnumString( const QString &_strEnum, bool _bIsFn /*= true */ )
{

	QString strEnumContents;

	if( _bIsFn )
	{
		QFile file( _strEnum );
		if( !file.open( QIODevice::ReadOnly ) )
		{
			QMessageBox::warning( nullptr, QObject::tr( "title" ),
				QObject::tr( "open file %1 failed" ).arg( _strEnum ),
				QMessageBox::Ok );


			return EnumString();
		}


		QTextStream in( &file );
		strEnumContents = in.readAll();
	}



	Parse( strEnumContents );
	
	
	return m_EnumString;
}

void CHugeEnumToString::Parse( const QString &_strEnum )
{
	// _strEnum һ�㶼�ܴ� Ϊ���� out of stack, ��_strEnum���ݸ���
	std::shared_ptr<QString> pEnumContents( new QString );
	*pEnumContents = _strEnum;

	//QStringList strEnumList = pEnumContents->split( "\n" );


	// ȥ��ע��
	// ȥ������ע��
	QRegExp regex_slcoments("//.*\\n");
	regex_slcoments.setMinimal( true );
	pEnumContents->remove( regex_slcoments );

	// ȥ������ע��
	QRegExp regex_mlcoments( "/\\*.*\\*/" );
	regex_mlcoments.setMinimal( true );
	pEnumContents->remove( regex_mlcoments );



	// ȥ��Ԥ����ָ��

	QRegExp regex_def( "#.*\\n" );
	pEnumContents->remove( regex_def );

	// enum����
	
	pEnumContents->remove( QRegExp( "enum.*\\{" ) );
	pEnumContents->remove( QRegExp( "\\} *;" ) );


	int iKey = 0;
	QString strLeftEqual;
	QString strRightEqual;
	

	QString strNew;
	int		iPreValue;

	*pEnumContents = pEnumContents->simplified();
	QStringList pairs = pEnumContents->split( "," );

	QStringList::iterator ibegin = pairs.begin();
	QStringList::iterator iFlag = ibegin;
	QStringList::iterator iend = pairs.end();

	
	while( ibegin != iend )
	{		
		strNew = *ibegin++;
				
		int pos = QRegExp( "=" ).indexIn( strNew );
		
		// ����еȺţ� �Ⱥ��ұ� Ҫô�����֣� Ҫô�Ǹ�enum��ǰ�涨��õĳ�Ա�� Ҫô��ȫ�ֳ������ʽ
		if( pos != -1 )
		{
			strLeftEqual = strNew.left( pos ).trimmed();
			
			strRightEqual = strNew.mid( ++pos ).trimmed();			
			QRegExp regex_num( "\\b^[0-9]+\\b"  );  // "\\^[0-9]+\\$" ƥ�䲻��

			if( -1 != regex_num.indexIn( strRightEqual ) )
			{
				//g_pWnd->Log( strValue )->Log( strKey );
				iKey = strRightEqual.toInt();
			}
			else
			{
				iKey = m_EnumString.key( strRightEqual );
			}
									
		}
		else
		{
			// �޵Ⱥ����
			strNew.trimmed();

			if( ibegin == iFlag )
			{				
				iKey = 0;
			}

			iKey = iPreValue;
			++iKey;
			
		}
					
		m_EnumString.insertMulti( iKey, strLeftEqual );
		iPreValue = iKey;
		iKey = 0;		
	}
	

	
}
