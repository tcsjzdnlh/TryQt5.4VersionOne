#include "Testor.h"
#include "MainWnd.h"
#include <QtWidgets/QWidget>
#include <QtCore/QEvent>
#include <QtCore/QVariant>
#include <QtCore/QRegExp>
#include "HugeEnumToString.h"
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QRect>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>
#include "BindEventWithQShortcutQAction.h"
#include "TimerTicker.h"
#include "EventReceiver.h"
#include "DragFile.h"
#include "DragItemDialog.h"


CMainWnd		*g_pWnd = nullptr;
void *g_pEventTarget = nullptr;

CTestor::CTestor()
{
	Init();
}
void CTestor::Init()
{	
	g_pWnd = new CMainWnd;	
	
	g_pWnd->SetEventsMap( CHugeEnumToString().GetEnumString( "events_file.cpp" ) );
	
	int width = qApp->desktop()->width() / 2;
	int height = 9 * qApp->desktop()->height() / 10;

	g_pWnd->setGeometry( QRect( 10, 30, width, height ) );
	g_pWnd->show();
}


// -------------------------------------------------------------------
// -------------------------------------------------------------------

namespace test_event
{
	namespace event_flow
	{
		// 等编译QT源码的时候在查看
	}
	namespace qt_event_handler
	{
		class CWidget : public QWidget
		{
		public:
			CWidget( QWidget *_pParent = nullptr )
				:QWidget( _pParent )
			{
			}

		public:
			bool event( QEvent *_pEvent )
			{
				g_pWnd->Log( ( QString( "event is spontaneous : %1  " ).arg( _pEvent->spontaneous() )
					+ g_pWnd->CurrentEvent( _pEvent->type() ) ) );

				if( _pEvent->type() == QEvent::Close )
				{
					g_pWnd->LogLeft( QString( "close event happend !" ) );
					return true; //返回 true 表明已经处理，返回false，则qt event 系统将事件传递给 parent 窗口处理
				}

				return QWidget::event( _pEvent );
			}
			void keyPressEvent( QKeyEvent *_pEvent )
			{
				switch( _pEvent->key() )
				{
				case Qt::Key::Key_0:
				{
					g_pWnd->LogLeft( QString( "Key_0 pressed ..." ) );
					break;
				}
				case Qt::Key::Key_2:
				{
					if( _pEvent->modifiers() & Qt::ControlModifier )
					{
						g_pWnd->LogLeft( QString( "key_2 pressed with contrl" ) );
					}
					break;
				}
				default:
					QWidget::keyPressEvent( _pEvent );
				}
			}
		};

		void test()
		{
			CWidget *pTargetWnd = new CWidget;

			int width = QApplication::desktop()->width() / 5;
			int height = qApp->desktop()->height() / 10;

			pTargetWnd->setGeometry( QRect( 4 * width, 0, width, 9 * height ) );


			pTargetWnd->show();
		}
	}
	namespace bind_event_with_QShortcut_QAction
	{
		void test()
		{
			CWidget *pWnd = new CWidget;
			pWnd->show();
		}
	}
	namespace timer_event
	{
		void test()
		{
			CTimerTicker *pWnd = new CTimerTicker;
			pWnd->SetText( "i'm coming at you with my crazy foot ! hello world !" );

			pWnd->show();
		}
	}


	namespace event_filter
	{


		void test()
		{
			CEventReceiver *pEventReceiver = new CEventReceiver;
			g_pEventTarget = pEventReceiver;

			pEventReceiver->show();

			// 下面的 event filter 副作用极大
			//qApp->installEventFilter( pEventReceiver );


		}
	}

	namespace drag_event
	{
		namespace drag_file_out_of_app
		{
			void test()
			{
				CDragWnd *pWnd = new CDragWnd;
				pWnd->show();
			}
		}

		namespace drag_item
		{
			void test()
			{
				CDragItemDialog *pDlg = new CDragItemDialog;
				pDlg->show();
			}
		}
	}
}

namespace test_QRegExp
{
	
	//  In other regexp documentation, sets of characters are often called "character classes".
	
	/*
	\b: word boundary
	(?!__): The regexp can then be written as &(?!amp;),
	i.e. Match an ampersand that is not followed by amp;

	(?:__)
	If we want to use parentheses purely for grouping and not for capturing
	we can use the non-capturing syntax, e.g. (?:green|blue)
	In this example we match either 'green' or 'blue'
	but we do not capture the match
	so we only know whether or not we matched
	but not which color we actually found.

	*/

	namespace test_word_boundary
	{
		// \b

		void test()
		{
			QString strTarget( "a Dog !" );
			
			QRegExp regex_1( "a\\bD" );
			QRegExp regex_2( "a \\bD" );
			QRegExp regex_3( "a\\b D" );

			int pos = 100;
			int iTrueRslt = 0;

			if( ( pos = regex_1.indexIn( strTarget ) ) != -1 )
			{
				g_pWnd->Log( QString( "\\b is space and pos is : %1" ).arg( pos ) );
				
				++iTrueRslt;

			}			
			if( ( pos = regex_2.indexIn( strTarget ) ) != -1 )
			{
				g_pWnd->Log( QString( "\\b is start letter of word and pos is : %1" ).arg( pos ) );

				++iTrueRslt;
			}
			if( ( pos = regex_3.indexIn( strTarget ) ) != -1 )
			{
				g_pWnd->Log( QString( "a\\b D   -->matched, "
										"means \\b is word of vocabulary, pos is: %1 " ).arg( pos ) );

				++iTrueRslt;
			}
			
			if( iTrueRslt == 0 )
			{
				g_pWnd->Log( "all match failed ...!" );
			}
			


			//if( regex_1 == regex_2 )
			//{
			//	g_pWnd->Log( "regex_1 is equal to regex_2" );
			//}
			//else
			//{
			//	g_pWnd->Log( "regex_1 and regex_2 are not equal " );
			//}

		}

	}

	namespace test_non_word_boundary
	{
		void test()
		{
			g_pWnd->Log( "\n\n\ntest_non_word_boundary started ... --->" );
			
			
			QString strTarget( "hello world !" );

			QRegExp regex_1( "\\Bh" );
			int pos_1 = 0;
			pos_1 = regex_1.indexIn( strTarget );


			if( -1 != pos_1 )
			{
				g_pWnd->Log( QString( "regex_1 matched, pos is: %1" ).arg( pos_1 ) );
			}
			else
			{
				g_pWnd->Log( QString( "regex_1 failed ... !" ) );
			}


			QRegExp regex_2( "\\Bd" );
			int pos_2 = regex_2.indexIn( strTarget );
			if( -1 != pos_2 )
			{
				g_pWnd->Log( QString( "regex_2 matched, the pos is: %1" ).arg( pos_2 ) );
			}
			else
			{
				g_pWnd->Log( QString( "regex_2 failed ...!" ) );
			}

		}
	}

	namespace test_no_behind
	{
		// _(?!__)
		void test()
		{
			g_pWnd->Log( "\n\n\ntest  is started ... --->" );
			
			QString strTarget( "okone oktwo okthree" );
			QRegExp regex_1( "ok(?!one)" );

			int pos_1 = regex_1.indexIn( strTarget );
			if( -1 != pos_1 )
			{
				g_pWnd->Log( QString( "regex_1 matched , the pos is : %1" ).arg( pos_1 ) );
			}

		}
	}

	namespace test_at_behind
	{		
		// __(?=__)
		void test()
		{
			g_pWnd->Log( "\n\n\ntest  is started ... --->" );

			QString strTarget( "okone, oktwo, okthree" );
			
			QRegExp regex_1( "ok(?=two)" );
			int pos_1 = regex_1.indexIn( strTarget );
			if( -1 != pos_1 )
			{
				g_pWnd->Log( QString( "regex_1 matched, the pos is: %1" ).arg( pos_1 ) );
			}
			else
			{
				g_pWnd->Log( "regex_1 failed ! ..." );
			}
		}
	}
}


namespace test_HugeEnumToString
{
	namespace first
	{		

		void test()
		{
			g_pWnd->Log( QString( "\n\n\ntest starting ... -------------->" ) );
			g_pWnd->LogAllEvents( CHugeEnumToString().GetEnumString( "events_file.cpp" ) );
		}
	}
}


// -------------------------------------------------------------------
// -------------------------------------------------------------------
void CTestor::Test()
{
	{
		using namespace test_event;
		qt_event_handler::test();
		//bind_event_with_QShortcut_QAction::test();
		//timer_event::test();
		//event_filter::test();
		{
			using namespace drag_event;
			//drag_file_out_of_app::test();
			//drag_item::test();
		}
	}

	{
		using namespace test_QRegExp;
		//test_word_boundary::test();
		//test_non_word_boundary::test();
		//test_no_behind::test();
		//test_at_behind::test();
	}

	{
		using namespace test_HugeEnumToString;
		//first::test();
	}
}