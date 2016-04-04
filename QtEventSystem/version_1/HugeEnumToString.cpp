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
	// _strEnum 一般都很大， 为避免 out of stack, 将_strEnum内容复制
	std::shared_ptr<QString> pEnumContents( new QString );
	*pEnumContents = _strEnum;

	//QStringList strEnumList = pEnumContents->split( "\n" );


	// 去除注释
	// 去除单行注释
	QRegExp regex_slcoments("//.*\\n");
	regex_slcoments.setMinimal( true );
	pEnumContents->remove( regex_slcoments );

	// 去除多行注释
	QRegExp regex_mlcoments( "/\\*.*\\*/" );
	regex_mlcoments.setMinimal( true );
	pEnumContents->remove( regex_mlcoments );



	// 去除预处理指令

	QRegExp regex_def( "#.*\\n" );
	pEnumContents->remove( regex_def );

	// enum定义
	
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
		
		// 如果有等号， 等号右边 要么是数字， 要么是该enum中前面定义好的成员， 要么是全局常量表达式
		if( pos != -1 )
		{
			strLeftEqual = strNew.left( pos ).trimmed();
			
			strRightEqual = strNew.mid( ++pos ).trimmed();			
			QRegExp regex_num( "\\b^[0-9]+\\b"  );  // "\\^[0-9]+\\$" 匹配不了

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
			// 无等号情况
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
