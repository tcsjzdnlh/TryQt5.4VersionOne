#include "Test.h"
#include "TestWidgets.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtGui/QPalette>
#include <QtGui/QColor>
#include <QtGui/QFont>
#include <QtWidgets/QLabel>
#include <QtCore/QDateTime>
#include <QtCore/QTimer>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTableView>
#include <QtSql/QSqlTableModel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QFont>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLineEdit>
#include <QtCore/QRegExp>
#include <QtGui/QRegExpValidator>



CTestWidgets	*g_pWnd = nullptr;
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
CTestor::CTestor()
{
	m_pWnd = new CTestWidgets;
	m_pWnd->show();
	
	g_pWnd = m_pWnd;
}

CTestor::~CTestor()
{
	if( nullptr != m_pWnd )
	{
		delete m_pWnd;
		m_pWnd = nullptr;
		g_pWnd = nullptr;
	}
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

namespace test_widgets
{
	namespace test_buttons
	{
		namespace pushbutton
		{
			void test()
			{
				QPushButton *pStartBtn = new QPushButton( QObject::tr( "start" ), g_pWnd );
				pStartBtn->show();

				// relative to it's parent and excluding the window frame
				pStartBtn->setGeometry( 10, 10, 100, 50 );

				QPalette BtnPalette = pStartBtn->palette();
				BtnPalette.setColor( QPalette::Window, QColor( Qt::blue ) );

				pStartBtn->setAutoFillBackground( true );
				pStartBtn->setPalette( BtnPalette );
				
				
				pStartBtn->setText( QObject::tr( "hello" ) );
				pStartBtn->setFont( QFont("times", 18, QFont::Bold) );

				QObject::connect( pStartBtn, SIGNAL( clicked() ), qApp, SLOT( quit() ) );



				g_pWnd->setGeometry( 10, 30, 300, 300 );
				
			}
		}
	}
	namespace input_widgets
	{
		namespace datetime
		{
			void test()
			{
				QLabel *pTimeLabel = new QLabel( g_pWnd );
				QDateTime time( QDateTime::currentDateTime() );
				pTimeLabel->setText( time.date().toString() );


				pTimeLabel->setGeometry( 20, 20, 100, 50 );
				pTimeLabel->show();
			}
		}
		namespace timer
		{
			void test()
			{
				QLabel *pTimeLabel = new QLabel( g_pWnd );
				
				QTimer *pTimer = new QTimer( g_pWnd );
				pTimer->setInterval( 800 );
				pTimer->setSingleShot( true );

				QObject::connect( pTimer, SIGNAL( timeout() ), g_pWnd, SLOT( timeoutWork() ) );

				pTimer->start();

			}
			
		}
		namespace textbrowser
		{
			void test()
			{
				QTextBrowser *pTextBrowser = new QTextBrowser( g_pWnd );
				pTextBrowser->show();
				pTextBrowser->setGeometry( g_pWnd->rect() );
				
			}
		}
	}
	namespace container_widgets
	{
		namespace widget
		{
			void test()
			{
				QWidget *pW = new QWidget( g_pWnd );			
				pW->setWindowFlags( Qt::Window );
				pW->show();
			}
		}
	}
	namespace item_views
	{
		namespace table_view
		{
			void test()
			{

				QSqlTableModel *pSqlModel = new QSqlTableModel( g_pWnd );
				
				QTableView *pTableView = new QTableView( g_pWnd );
				// setModel 的 model , 必须用 new ，否则 view 中的数据变动不能更新到 model 中去
				pTableView->setModel( pSqlModel );	

				pTableView->setGeometry( g_pWnd->rect() );
				pTableView->show();

			}
		}
		
	}
	namespace item_widgets
	{
		namespace table_widget
		{
			void test()
			{
				QTableWidget *pTableWnd = new QTableWidget( 10, 5, g_pWnd );
				pTableWnd->setGeometry( g_pWnd->rect() );

				pTableWnd->show();
			}
		}
		namespace tree_widget
		{
			void test()
			{
				QTreeWidget *pTreeWnd = new QTreeWidget( g_pWnd );
				
				QTreeWidgetItem *pTreeItem = new QTreeWidgetItem( pTreeWnd );
				pTreeItem->setText( 0 /*0*/, QObject::tr( "hello" ) );
				pTreeItem->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable );
				//pTreeItem->setCheckState( 0, Qt::Checked );
				pTreeItem->setCheckState( 0, Qt::Unchecked );
				pTreeItem->setCheckState( 3, Qt::Unchecked );



				pTreeWnd->show();
			}
		}
	}

	namespace window_flags
	{
		void test()
		{
			
			// ------------------
			QGroupBox *pWndTypeGroup = new QGroupBox( g_pWnd );
			pWndTypeGroup->setTitle( QObject::tr( "WindowType" ) );						// WindowType
			
			QCheckBox *pWidgetType = new QCheckBox( "Widget", pWndTypeGroup );
			QCheckBox *pWindowType = new QCheckBox( "Window", pWndTypeGroup );
			QCheckBox *pDialogType = new QCheckBox( "Dialog", pWndTypeGroup );
			QCheckBox *pMacintoshSheet = new QCheckBox( "MacintoshSheet", pWndTypeGroup );
			QCheckBox *pMacintoshDrawer = new QCheckBox( "MacintoshDrawer", pWndTypeGroup );
			QCheckBox *pPopupWindowType = new QCheckBox( "PopupWindow", pWndTypeGroup );
			QCheckBox *pToolWindowType = new QCheckBox( "ToolWindow", pWndTypeGroup );
			QCheckBox *pToolTipWindowType = new QCheckBox( "ToolTipWindow", pWndTypeGroup );
			QCheckBox *pSplashScreenType = new QCheckBox( "SplashScreen", pWndTypeGroup );
			QCheckBox *pDesktopType = new QCheckBox( "DeskTop", pWndTypeGroup );
			QCheckBox *pSubWindowType = new QCheckBox( "SubWindow", pWndTypeGroup );

			QGridLayout *pWndTypeLay = new QGridLayout( pWndTypeGroup );
			pWndTypeLay->addWidget( pWidgetType, 0, 0 );
			pWndTypeLay->addWidget( pWindowType, 0, 1 );
			pWndTypeLay->addWidget( pDialogType, 0, 2 );
			pWndTypeLay->addWidget( pMacintoshSheet, 0, 3 );
			pWndTypeLay->addWidget( pMacintoshDrawer, 0, 4 );
			pWndTypeLay->addWidget( pPopupWindowType, 1, 0 );
			pWndTypeLay->addWidget( pToolWindowType, 1, 1 );
			pWndTypeLay->addWidget( pToolTipWindowType, 1, 2 );
			pWndTypeLay->addWidget( pSplashScreenType, 1, 3 );
			pWndTypeLay->addWidget( pDesktopType, 1, 4 );
			pWndTypeLay->addWidget( pSubWindowType, 2, 0 );

			//// ------------------

			QGroupBox *pWndHintGroup = new QGroupBox( g_pWnd );			
			pWndHintGroup->setTitle( QObject::tr( "WindowHint" ) );
			
			QCheckBox *pMSWindowsFiredSizeDialogHint 
				= new QCheckBox( QObject::tr( "MSWindowsFiredSizeDialog" ), pWndHintGroup );
			QCheckBox *pMSWindowsOwnDC = new QCheckBox( QObject::tr( "MSWindowsOwnDC" ), pWndHintGroup );
			QCheckBox *pX11BypassWindowManagerHint
				= new QCheckBox( QObject::tr( "X11BypassWindowManager" ), pWndHintGroup );
			
			
			
			
			
			QGridLayout *pWndHintLay = new QGridLayout( pWndHintGroup );
			pWndHintLay->addWidget( pMSWindowsFiredSizeDialogHint, 0, 0 );
			pWndHintLay->addWidget( pMSWindowsOwnDC, 0, 1 );
			pWndHintLay->addWidget( pX11BypassWindowManagerHint, 0, 2 );







			// ---------------------
			QVBoxLayout *pLay_0 = new QVBoxLayout;
			pLay_0->addWidget( pWndTypeGroup );
			pLay_0->addWidget( pWndHintGroup );

			g_pWnd->setLayout( pLay_0 );
			g_pWnd->show();

			


			//QWidget *pEffectWnd = new QWidget;
			//pEffectWnd->setGeometry( 100, 100, 300, 300 );
			//pEffectWnd->show();
		}
	}

	namespace splitter
	{
		void test()
		{
			

			
			QSplitter *pMainView = new QSplitter( Qt::Horizontal );

			QTextEdit *pTextEdit_0_1 = new QTextEdit( pMainView );
			pTextEdit_0_1->setAlignment( Qt::AlignCenter );

			QSplitter *pSplitter_0_2 = new QSplitter( Qt::Vertical, pMainView );
			pSplitter_0_2->setOpaqueResize( false );
			QTextEdit *pTextEdit_0_2_1 = new QTextEdit( pSplitter_0_2 );
			QTextEdit *pTextEdit_0_2_2 = new QTextEdit( pSplitter_0_2 );

			
			pMainView->setStretchFactor( 0, 1 );
			pMainView->setStretchFactor( 1, 2 );
			

			QFont font( "ZYSong18030", 20, QFont::Bold );
			pMainView->setFont( font );

			pMainView->show();
		}
	}

	namespace dockwidget
	{
		void test()
		{
			
			// QDockWidget 只能 Dock 到 QMainWindow 内
			QMainWindow *pmain = new QMainWindow;
			QTextEdit *pTextEditCentral = new QTextEdit;
			pmain->setCentralWidget( pTextEditCentral );


			QDockWidget *pDocWnd_0_1 = new QDockWidget( QObject::tr( "DockWnd_01_1" ) );
			pDocWnd_0_1->setFeatures( QDockWidget::DockWidgetClosable 
									| QDockWidget::DockWidgetFloatable
									| QDockWidget::DockWidgetMovable );
			pDocWnd_0_1->setAllowedAreas( Qt::AllDockWidgetAreas );
			
			QTextEdit *pTextEdit_1 = new QTextEdit/*( pDocWnd_0_1 )*/; //
			pTextEdit_1->setAlignment( Qt::AlignCenter );
			pDocWnd_0_1->setWidget( pTextEdit_1 );
			

			pmain->addDockWidget( Qt::LeftDockWidgetArea, pDocWnd_0_1 );
			pmain->show();

		}
	}

	namespace listwidget_stackwidget
	{
		void test()
		{
			QFrame *pFrame = new QFrame;
			pFrame->setWindowTitle( QObject::tr( "frame window" ) );
			pFrame->setFrameStyle( QFrame::Panel | QFrame::Raised );

			// ------
			QListWidget *pListWnd = new QListWidget;
			pListWnd->insertItem( 0, QObject::tr( "first" ) );
			pListWnd->insertItem( 1, QObject::tr("second") );
			pListWnd->insertItem( 2, QObject::tr( "three" ) );

			// -------
			QStackedWidget *pStackWnd = new QStackedWidget;
			QLabel *pfirstLabel = new QLabel( "first label" );
			QLabel *pSecondLabel = new QLabel( "second label" );
			QLabel *pThreeLabel = new QLabel( "three label " );
			pStackWnd->addWidget( pfirstLabel );
			pStackWnd->addWidget( pSecondLabel );
			pStackWnd->addWidget( pThreeLabel );
			
			// -----------
			QObject::connect( pListWnd, SIGNAL( currentRowChanged( int ) ), pStackWnd, SLOT( setCurrentIndex( int ) ) );

			// -----------
			QHBoxLayout *pLay_0 = new QHBoxLayout;
			
			pLay_0->addWidget( pListWnd );
			pLay_0->addWidget( pStackWnd );
			
			pLay_0->setMargin( 100 );
			pLay_0->setSpacing( 50 );
			

			pLay_0->setStretchFactor( pListWnd, 1 );
			pLay_0->setStretchFactor( pStackWnd, 3 );



			pFrame->setLayout( pLay_0 );
			pFrame->show();
		}
	}
	namespace label
	{
		void test()
		{
			//QLabel *pLabel = new QLabel( "hello" );
			//QLabel *pLabel = new QLabel( "<h2>\
			//								<i>\
			//									hello\
			//								 </i>\
			//								 \<font color=red>QT</font>\
			//							 </h2>" );

			//QLabel *pLabel = new QLabel( "<h2>hello<font color=red>QT</font></h2>" );
			QLabel *pLabel = new QLabel( "<h1>hello</h1>" );
			pLabel->show();
		}
		
	}
	
	namespace quitbutton
	{
		void test()
		{
			QPushButton *pQuitBtn = new QPushButton( "quit" );
			// click quitbutton or push space key will exit application
			QObject::connect( pQuitBtn, SIGNAL( clicked() ), qApp, SLOT( quit() ) );


			pQuitBtn->show();
		}
	}

	namespace spinbox_slider
	{
		void test()
		{
			QWidget *pMain = new QWidget;
			pMain->setWindowTitle( "spinbox_slider" );

			QSpinBox *pSpBxAge = new QSpinBox;
			pSpBxAge->setRange( 0, 300 );

			QSlider *pSldAge = new QSlider( Qt::Horizontal );
			pSldAge->setRange( 0, 300 );

			QObject::connect( pSpBxAge, SIGNAL( valueChanged( int ) ), pSldAge, SLOT( setValue( int ) ) );
			QObject::connect( pSldAge, SIGNAL( valueChanged( int ) ), pSpBxAge, SLOT( setValue( int ) ) );


			QHBoxLayout *pLay_0 = new QHBoxLayout;
			pLay_0->setDirection( QBoxLayout::RightToLeft );
			pLay_0->addWidget( pSpBxAge );
			pLay_0->addWidget( pSldAge );


			pMain->setLayout( pLay_0 );


			pMain->show();

		}
	}

	namespace findbox
	{
		void test()
		{
			QWidget *pBaseBoard = new QWidget;
			pBaseBoard->setWindowTitle( QObject::tr( "base board" ) );

			QHBoxLayout *pLay_0 = new QHBoxLayout;
			pBaseBoard->setLayout( pLay_0 );


			// ------------------
			QLabel *pLabelAge = new QLabel( "&Age : " );
			QLineEdit *pLineEdit = new QLineEdit;

			pLabelAge->setBuddy( pLineEdit );

			QRegExp reg( "[A-Za-z][1-9][0-9]{0-2}" );
			pLineEdit->setValidator( new QRegExpValidator( reg, pLineEdit ) );

			


			QHBoxLayout *pLay_0_1 = new QHBoxLayout;
			pLay_0_1->addWidget( pLabelAge );
			pLay_0_1->addWidget( pLineEdit );

			// ------------------
			QPushButton *pOk = new QPushButton( "ok" );
			QPushButton *pCancel = new QPushButton( "cancel" );

			pOk->setDefault( true );

			
			QVBoxLayout *pLay_0_2 = new QVBoxLayout;
			pLay_0_2->addWidget( pOk );
			pLay_0_2->addWidget( pCancel );
			pLay_0_2->addStretch();
			

			// -------------------
			QCheckBox *pCase = new QCheckBox( "CaseSensitive" );
			QCheckBox *pBackDirection = new QCheckBox( "BackDirection" );
			QVBoxLayout *pLay_0_3 = new QVBoxLayout;
			
			pLay_0_3->addLayout( pLay_0_1 );
			pLay_0_3->addWidget( pCase );
			pLay_0_3->addWidget( pBackDirection );
			

			// -------------------			
			pLay_0->addLayout( pLay_0_3 );
			pLay_0->addLayout( pLay_0_2 );
			
			
			//QObject::connect( pLineEdit, SIGNAL( textChanged( const QString & ) ), pOk, SLOT( setEnabled() ) );



			pBaseBoard->show();
			pBaseBoard->setFixedHeight( pBaseBoard->sizeHint().height() );

		}
	}
}





void CTestor::Test()
{
	{
		using namespace test_widgets::test_buttons;
		//pushbutton::test();

	}
	{
		using namespace test_widgets::input_widgets;
		//datetime::test();
		//timer::test();
		//textbrowser::test();

	}
	{
		using namespace test_widgets::container_widgets;
		//widget::test();
	}
	{
		using namespace test_widgets::item_views;
		//table_view::test();
		
	}
	{
		using namespace test_widgets::item_widgets;
		//table_widget::test();
		//tree_widget::test();
	}
	{
		using namespace test_widgets;
		//window_flags::test();
		//splitter::test();
		//dockwidget::test();
		//listwidget_stackwidget::test();
		//label::test();
		//quitbutton::test();
		//spinbox_slider::test();
		findbox::test();
	}




}


//template <typename ThisObject> 
//inline void qt_check_for_QOBJECT_macro( const ThisObject &_q_argument ) const
//{ int i = qYouForgotTheQ_OBJECT_Macro( this, &_q_argument ); i = i + 1; }