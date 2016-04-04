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
#include "WidgetsStyle.h"

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
namespace widgets_style
{
	namespace style_slider
	{
		void test()
		{
			CWidgetsStyle *pWnd = new CWidgetsStyle;
			pWnd->show();
		}
	}
}

// -------------------------------------------------------------------
// -------------------------------------------------------------------
void CTestor::Test()
{
	{
		using namespace widgets_style;
		style_slider::test();
	}
}