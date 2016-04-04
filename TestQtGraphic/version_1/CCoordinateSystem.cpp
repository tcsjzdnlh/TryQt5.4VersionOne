#include "CCoordinateSystem.h"
#include <QtGui/QPainter>
#include <QtCore/QRect>
#include "MainWnd.h"
#include <QtGui/QRegion>

extern CMainWnd *g_pWnd;

CCoordinateSystem::CCoordinateSystem( QWidget *_pParent /*= nullptr */ )
	:QWidget(_pParent)
{
	resize( 200, 200 );


	m_GraphicOffScreen = QPixmap( 200, 200 );
}

void CCoordinateSystem::paintEvent( QPaintEvent *_pEvent )
{
	
	//DrawOffScreen();
	//DrawOnWindow();
	//DrawLine();
	TestCoordinateSystem();
}

void CCoordinateSystem::showEvent( QShowEvent *_pEvent )
{
	//TestCoordinateSystem();
	QWidget::showEvent( _pEvent );
}

void CCoordinateSystem::resizeEvent( QResizeEvent *_pEvent )
{
	QWidget::resizeEvent( _pEvent );
}

void CCoordinateSystem::DrawOffScreen()
{
	QPainter painter( &m_GraphicOffScreen );
	//painter.setWindow( 50, 50, 100, 100 );
	//painter.drawRect( 0, 0, 100, 100 );
	painter.setWindow( -50, -50, 100, 100 );
	painter.drawRect( -50, -50, 50, 50 );



	QPainter painter_window( this );
	painter_window.drawPixmap( 0, 0, m_GraphicOffScreen );
}

void CCoordinateSystem::DrawOnWindow()
{
	QPainter painter( this );
	
	//painter.drawRect( 0, 0, 100, 100 );

	painter.setWindow( -50, -50, 100, 100 );
	painter.drawRect( -50, -50, 50, 50 );

}

void CCoordinateSystem::DrawLine()
{
	
	QPixmap backPic = QPixmap( 100, 100 );	
	backPic.load( ":/window/crystal.png" );

	QPainter painter( &backPic );
	painter.setViewport( QRect( 20, 20, 50, 50 ) );
	//painter.drawLine( 10, 10, 100, 100 );
	

	//QPixmap backPic( ":/window/crystal.png" );

	QPainter painter_widget( this );
	//painter_widget.setViewport( QRect(20, 20, 30, 30) );
	painter_widget.drawPixmap( 0, 0, backPic );
	//painter_widget.drawPixmap( QPoint( 10, 10 ), backPic, QRect( 0, 0, 50, 50 ) );
}

void CCoordinateSystem::TestCoordinateSystem()
{
	QPainter painter( this );

	QRegion clipArea;
	if( painter.hasClipping() )
	{
		g_pWnd->Log( QString( "painter initially has clip ..." ) );
		//clipArea = painter.clipRegion();
	}
	else
	{		
		g_pWnd->Log( QString( "painter initially has no clip, and now we set it true ... " ) );
		painter.setClipRect( painter.window(), Qt::ClipOperation::IntersectClip );
	}



	QRect windowRect;
	QRect viewportRect;

	//windowRect = painter.window();
	//viewportRect = painter.viewport();

	//g_pWnd->Log( QString( "null painter.window() value is : \n x=%1, y=%2, width=%3, height=%4,"
	//					).arg( windowRect.x() ).arg( windowRect.y() )
	//					.arg( windowRect.width() ).arg( windowRect.height() ) );

	//g_pWnd->Log( QString( "null painter.viewport() value is : \n x=%1, y=%2, width=%3, height=%4,"
	//					).arg( viewportRect.x() ).arg( viewportRect.y() )
	//					.arg( viewportRect.width() ).arg( viewportRect.height() ) );
	//
	//painter.drawPixmap( 0, 0, QPixmap( ":/window/crystal.png" ) );

	// //-------------
	//g_pWnd->Log( QString( "------------------------------------>" ) );

	//painter.setViewport( 0, 0, 200, 200 );
	//painter.setWindow( -100, -100, 200, 200 );
	windowRect = painter.window();
	viewportRect = painter.viewport();
	
	g_pWnd->Log( QString( "null painter.window() value is : \n x=%1, y=%2, width=%3, height=%4,"
						).arg( windowRect.x() ).arg( windowRect.y() )
						.arg( windowRect.width() ).arg( windowRect.height() ) );


	g_pWnd->Log( QString( "null painter.viewport() value is : \n x=%1, y=%2, width=%3, height=%4,"
						).arg( viewportRect.x() ).arg( viewportRect.y() )
						.arg( viewportRect.width() ).arg( viewportRect.height() ) );
	
	painter.drawPixmap( 0, 0, QPixmap( ":/window/crystal.png" ) );

	g_pWnd->Log( QString( "------------------------------------>" ) );
}
