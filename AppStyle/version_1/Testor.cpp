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
#include "FirstStyleSheet.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtWidgets/QPushButton>
#include <QtCore/QVariant>
#include "WindowShape.h"
#include "StyleWidgets.h"
#include "ButtonStyle.h"
#include <QtWidgets/QStyleFactory>


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
namespace test_style
{
	namespace style_sheet
	{
		namespace first_style_sheet
		{
			void test()
			{
				CFirstStyleSheet *pWnd = new CFirstStyleSheet;
				pWnd->resize( 300, 300 );
				pWnd->show();

				QString strStyle;

				//qApp->setStyleSheet( QString( " QDialog{ background-color:darkCyan; } " ) );
				//qApp->setStyleSheet( QString( " CFirstStyleSheet{ background-color:darkCyan; } " ) );
				//pWnd->setStyleSheet( "background-color:darkBlue;" );

				//strStyle = "QDialog, QPushButton{ background-color: darkGreen; }";
				//strStyle = "QDialog { background-color: darkGreen; }";
				//strStyle = "*{ background-color: darkGreen; }";
				//strStyle = "{ background-color: darkGreen; }";
				//strStyle = "QDialog{ background-image: url(:/crystal.png) }";
				//strStyle = "QDialog{ background-image: url(:/window.ico) }";
				//strStyle = "QDialog{ background-image: url(:/images/window.ico) }";
				
				//strStyle = "QPushButton{ color:rgb(0, 88, 52);  background-color:yellow; }";
				//strStyle = "QDialog{ background-color:#080901; }";
				//strStyle = "QDialog{ background-color: rgba(90%, 20%, 10%, %50); }";
				//strStyle = "*{ background-color: rgba(90%, 20%, 10%, %50); }";
				//strStyle = "QDialog{ background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop: 0 white, stop: 0.4 gray, stop: 1 green); }";
				//strStyle = "QDialog{ background-image:url(:/crystal.png); background-position:top right; background-repeat: repeat-x; }";
				//strStyle = "QDialog{ background-image:url(:/crystal.png); background-position:bottom left; background-repeat: repeat-y; }";
				//strStyle = "QDialog{ background-image:url(:/crystal.png); background-position:bottom left; background-repeat: repeat-y;}";
				
				pWnd->setStyleSheet( strStyle );
			}
		}

		namespace style_sheet_selector
		{
			void test()
			{
				CFirstStyleSheet *pWnd = new CFirstStyleSheet;				
				
				QFile file( "AppStyleSheet_Selector.qss" );
				if( !file.open(QFile::ReadOnly))
				{
					return;
				}
				QTextStream in( &file );
				QString strStyleSheet = in.readAll();
				pWnd->setStyleSheet( strStyleSheet );
								
				
				//pWnd->GetBtn()->setProperty( "mandatoryField", true );
				pWnd->show();

				// 该句 表明了 属性-stylesheet 的滞后性，stylesheet 不会注意到修改，但是前面那一句可以起作用
				pWnd->GetBtn()->setProperty( "mandatoryField", true );				
			}
		}

		namespace style_sheet_subcontrol
		{
			void test()
			{
				QString strStyle;

				CFirstStyleSheet *pWnd = new CFirstStyleSheet;

				QFile file( "AppStyleSheet_SubControl.qss" );
				if( !file.open(QFile::ReadOnly))
				{
					return;
				}
				QTextStream in( &file );
				strStyle = in.readAll();
				pWnd->setStyleSheet( strStyle );

				pWnd->show();
			}
		}
		namespace style_sheet_state
		{
			void test()
			{
				QString strStyle;

				CFirstStyleSheet *pWnd = new CFirstStyleSheet;

				QFile file( "AppStyleSheet_State.qss" );
				if( !file.open( QFile::ReadOnly ) )
				{
					return;
				}
				QTextStream in( &file );
				strStyle = in.readAll();
				pWnd->setStyleSheet( strStyle );

				pWnd->show();
			}
		}
		namespace style_sheet_geometry
		{
			void test()
			{
				// AppStyleSheet_Geometry.qss
				QString strStyle;

				CFirstStyleSheet *pWnd = new CFirstStyleSheet;

				QFile file( "AppStyleSheet_Geometry.qss" );
				if( !file.open( QFile::ReadOnly ) )
				{
					return;
				}
				QTextStream in( &file );
				strStyle = in.readAll();
				pWnd->setStyleSheet( strStyle );

				pWnd->show();
			}
		}

		namespace style_sheet_candy
		{
			void test()
			{
				QString strStyle;

				CFirstStyleSheet *pWnd = new CFirstStyleSheet;

				QFile file( "AppStyleSheet_Candy_1.qss" );
				if( !file.open( QFile::ReadOnly ) )
				{
					return;
				}
				QTextStream in( &file );
				strStyle = in.readAll();
				pWnd->setStyleSheet( strStyle );

				pWnd->show();
			}
		}

		namespace style_widgets
		{
			void test()
			{
				CStyleWidgets *pWnd = new CStyleWidgets;
				pWnd->show();
			}
		}
	}

	namespace subclass_from_QStyle
	{
		namespace first_style
		{
			void test()
			{
				CFakeButton *pWnd = new CFakeButton;
				pWnd->show();


				QStringList lstStyles = QStyleFactory::keys();
				QString strStyles = lstStyles.join( " \n" );
				g_pWnd->Log( strStyles );
			}
		}
	}

	namespace window_shape
	{
		namespace window_frameless
		{
			void test()
			{
				CWindowShape *pWnd = new CWindowShape;
				pWnd->show();
			}
		}
	}
}

// -------------------------------------------------------------------
// -------------------------------------------------------------------
void CTestor::Test()
{
	{
		using namespace test_style;
		//style_sheet::first_style_sheet::test();
		//style_sheet::style_sheet_selector::test();
		//style_sheet::style_sheet_subcontrol::test();
		//style_sheet::style_sheet_state::test();
		//style_sheet::style_sheet_candy::test();
		//style_sheet::style_widgets::test();

		subclass_from_QStyle::first_style::test();

		//window_shape::window_frameless::test();
	}
}