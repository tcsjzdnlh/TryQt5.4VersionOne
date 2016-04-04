#include "Testor.h"
#include "MainWnd.h"
#include <QtWidgets/QWidget>
#include <QtCore/QEvent>
#include <QtCore/QVariant>
#include <QtCore/QRegExp>
//#include "HugeEnumToString.h"
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QRect>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>
#include <QtCore/QMetaEnum>

#include "Book.h"
#include "EnumParam.h"
#include "MacFlags.h"


CMainWnd		*g_pWnd = nullptr;


CTestor::CTestor()
{
	Init();
}
void CTestor::Init()
{	
	g_pWnd = new CMainWnd;	
	
	//g_pWnd->SetEventsMap( CHugeEnumToString().GetEnumString( "events_file.cpp" ) );
	
	int width =  qApp->desktop()->width() / 2;
	int height = 9 * qApp->desktop()->height() / 10;

	g_pWnd->setGeometry( QRect( 10, 30, width, height ) );
	g_pWnd->show();
}


// -------------------------------------------------------------------
// -------------------------------------------------------------------

namespace test_qt_assistance_system
{
	namespace mac_Q_ENUMS
	{
		//class CBook : public QObject
		//{
		//	//Q_GADGET
		//	Q_OBJECT
		//	Q_ENUMS( eWeek )
		//	
		//public:
		//	enum eWeek{ e_monday, e_tuesday, e_wednesday, e_friday, e_saturday, e_sunday };
		//};
				
		void test()
		{			
			CBook *pYuwen = new CBook;
			
			const QMetaObject *pMeta = pYuwen->metaObject();
			
			int index = pMeta->indexOfEnumerator( "eWeek" );
			QMetaEnum me = pMeta->enumerator( index );
			g_pWnd->Log( me.name() );
			g_pWnd->Log( me.scope() );
			g_pWnd->Log( me.key( int( CBook::EWeek::e_monday ) ) );

			//for( int i = 0; i < pMeta->enumeratorCount(); ++i )
			//{
			//	QMetaEnum me = pMeta->enumerator( i );
			//	g_pWnd->Log( me.name() );

			//	for( int j = 0; j < me.keyCount(); ++j )
			//	{
			//		g_pWnd->Log( me.key( j ) );
			//	}

			//}			
		}
	}

	namespace enum_param
	{
		void test()
		{
			CEnumParam ep;
			ep.Days( Axis_X | Axis_Y );
		}
	}

	namespace mac_flags
	{
		void test()
		{
			CMacFlags *pMF = new CMacFlags;
			const QMetaObject *pMeta = pMF->metaObject();
			
			for( int i = 0; i < pMeta->enumeratorCount(); ++i )
			{
				QMetaEnum me = pMeta->enumerator( i );
				g_pWnd->Log( me.name() );

				for( int j = 0; j < me.keyCount(); ++j )
				{
					g_pWnd->Log( me.key( j ) );
				}
			}
		}
	}
}

// -------------------------------------------------------------------
// -------------------------------------------------------------------
void CTestor::Test()
{
	{
		using namespace test_qt_assistance_system;
		//mac_Q_ENUMS::test();
		//enum_param::test();
		mac_flags::test();
	}
}