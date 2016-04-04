#include "Testor.h"
#include "MainWnd.h"
#include <QtGui/QIcon>
#include <QtCore/QDebug>
#include <QtCore/QVariant>
#include <QtCore/QMetaType>


CMainWnd		*g_pWnd = nullptr;

CTestor::CTestor()
{
	Init();
}
void CTestor::Init()
{
	g_pWnd = new CMainWnd;
	g_pWnd->setWindowIcon( QIcon( ":/window/images/window.ico" ) );
	g_pWnd->show();
}

namespace test_QVariant
{
	namespace base_using_of_QVariant
	{
		class CBook
		{
		public:
			CBook() = default;
			//CBook( const CBook& _other ) = delete;  
			CBook( const QString & _strName )
			{
				m_strName = _strName;
			}
			QString BookName() const
			{
				return m_strName;
			}
		private:
			QString		m_strName;
		};

		void test()
		{
			QVariant v;

			// ��/ȡ ����
			v.setValue<int>( 20 );
			int value = v.value<int>();


			double dvalue = v.toDouble();
			QString strValue = v.toString();

			CBook shuxue = qvariant_cast<QString>( v );



			// ת���������� ,convert(): If the cast cannot be done, the variant is cleared
			if( v.canConvert<QString>() && v.convert( QVariant::Type::String ) )
			{
				g_pWnd->Log( v.value<QString>() );
				g_pWnd->Log( "shuxue: " );
				g_pWnd->Log( shuxue.BookName() );
			}


		}
	}

	namespace user_defined_data_with_QVariant
	{
		class CBook
		{
		public:
			CBook() = default;
			//CBook( const CBook& _other ) = delete;  
			CBook( const QString & _strName )
			{
				m_strName = _strName;
			}
			QString BookName() const
			{
				return m_strName;
			}
		private:
			QString		m_strName;
		};

		void test()
		{			

			QVariant v;
			v.setValue<CBook>( CBook( QObject::tr("yuwen") ) );
						
			/*
				ֱ�Ӹ�ֵ��

				The inverse conversion (e.g., from QColor to QVariant) 
				is automatic for all data types supported by QVariant, 
				including GUI-related types:
			*/
			QVariant v2 = v; 

			CBook yuwen = v2.value<CBook>();
			
			g_pWnd->Log( yuwen.BookName() );

			
			//static_assert( false, "xfs::static_assert function message" );
		}
	}
}


/*
	QMetaType:	
		register type to meta-type system, 
		type must include defualt construct, copy construct, destruct
	
	1:
	Q_DECLARE_METATYPE: for QVariant / template function

	2:
	qRegisterMetaType(): for non-template function

*/
Q_DECLARE_METATYPE( test_QVariant::user_defined_data_with_QVariant::CBook );


void CTestor::Test()
{
	g_pWnd->Log( QString() );


	qDebug() << "hello \n";


	{
		using namespace test_QVariant;
		base_using_of_QVariant::test();

		user_defined_data_with_QVariant::test();
	}
}


