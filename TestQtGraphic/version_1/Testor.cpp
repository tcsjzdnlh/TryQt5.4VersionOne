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
#include "TryPainter.h"
#include <QtGui/QPen>
#include <QtGui/QPainter>
#include <QtGui/QPalette>
#include <QtCore/QPointF>
#include "CCoordinateSystem.h"
#include "Transform.h"
#include "OvenTimer.h"
#include "ImageAndPixelBlending.h"
#include "GraphicsNode.h"
#include "DiagramMainWnd.h"

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

namespace test_qt_graphic
{
	namespace painter_device
	{
		namespace desktop_device_property
		{
			void test()
			{
				QDesktopWidget *pWnd = new QDesktopWidget;
				pWnd->show();
				
				QString strLog = QString( "desktop width: %1, height: %2 ..." ).arg( pWnd->width() ).arg( pWnd->height() );
				g_pWnd->Log( strLog );

				strLog = QString( "desktop widthMM: %1, heightMM: %2 ..." ).arg( pWnd->widthMM() ).arg( pWnd->heightMM() );
				g_pWnd->Log( strLog );


				strLog = QString( "desktop LogicalDpiX: %1, LogicalDpiY: %2" ).arg( pWnd->logicalDpiX() ).arg( pWnd->logicalDpiY() );
				g_pWnd->Log( strLog );


				strLog = QString( "desktop PhysicalDpiX: %1, PhysicalDpiY: %2 ..." ).arg( pWnd->physicalDpiX() ).arg( pWnd->physicalDpiY() );
				g_pWnd->Log( strLog );

				strLog = QString( "desktop color count is : %1 ..." ).arg( pWnd->colorCount() );
				g_pWnd->Log( strLog );


				strLog = QString( "desktop device pixel ratio is : %1 ..." ).arg( pWnd->devicePixelRatio() );
				g_pWnd->Log( strLog );

			}
		}
		namespace TryPainter_device_metrics
		{
			void test()
			{
				CTryPainter *pWnd = new CTryPainter;
				pWnd->show();

				QString strLog = QString( "CTryPainter width: %1, height: %2 ..." ).arg( pWnd->width() ).arg( pWnd->height() );
				g_pWnd->Log( strLog );

				strLog = QString( "CTryPainter widthMM: %1, heightMM: %2 ..." ).arg( pWnd->widthMM() ).arg( pWnd->heightMM() );
				g_pWnd->Log( strLog );


				strLog = QString( "CTryPainter LogicalDpiX: %1, LogicalDpiY: %2" ).arg( pWnd->logicalDpiX() ).arg( pWnd->logicalDpiY() );
				g_pWnd->Log( strLog );


				strLog = QString( "CTryPainter PhysicalDpiX: %1, PhysicalDpiY: %2 ..." ).arg( pWnd->physicalDpiX() ).arg( pWnd->physicalDpiY() );
				g_pWnd->Log( strLog );

				strLog = QString( "CTryPainter color count is : %1 ..." ).arg( pWnd->colorCount() );
				g_pWnd->Log( strLog );


				strLog = QString( "CTryPainter device pixel ratio is : %1 ..." ).arg( pWnd->devicePixelRatio() );
				g_pWnd->Log( strLog );
			}
		}
	}

	namespace painting_geometric_shapes
	{
		namespace painting_base_pen
		{
			void test()
			{
				CTryPainter *pWnd = new CTryPainter;
				pWnd->show();								
			}
		}
		namespace painting_base_brush
		{
			void test()
			{

			}
		}
	}

	namespace painting_resolution
	{
		void test()
		{

		}
	}
	namespace painting_coordinate_system
	{
		void test()
		{
			CCoordinateSystem *pWnd = new CCoordinateSystem;
			pWnd->show();
		}
	}

	namespace painting_transform
	{
		void test()
		{
			CTransform *pWnd = new CTransform;
			pWnd->show();
		}
	}

	namespace oven_timer_transform
	{
		void test()
		{
			COvenTimer *pWnd = new COvenTimer;
			pWnd->show();
		}
	}

	namespace image_and_pixel_blending
	{
		void test()
		{
			CImageAndPixelBlending *pWnd = new CImageAndPixelBlending;
			pWnd->show();
		}
	}

	namespace graphics_diagram
	{
		void test()
		{
			CDiagramMainWnd *pWnd = new CDiagramMainWnd;
			pWnd->show();
		}
	}
}


// -------------------------------------------------------------------
// -------------------------------------------------------------------
void CTestor::Test()
{
	{
		using namespace test_qt_graphic;
		//painter_device::desktop_device_property::test();
		//painter_device::TryPainter_device_metrics::test();
		//painting_geometric_shapes::painting_base_pen::test();
		//painting_resolution::test();
		//painting_coordinate_system::test();
		//painting_transform::test();
		//oven_timer_transform::test();
		//image_and_pixel_blending::test();
		graphics_diagram::test();
	}
}