#include "ImageAndPixelBlending.h"
#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtGui/QConicalGradient>
#include <QtGui/QPen>
#include <QtGui/QBrush>

CImageAndPixelBlending::CImageAndPixelBlending( QWidget *_pParent )
	:QWidget( _pParent )
{
	m_graphicOffScreen = QImage( size(), QImage::Format::Format_ARGB32_Premultiplied );
}

void CImageAndPixelBlending::paintEvent( QPaintEvent *_pEvent )
{	
	QPainter painter( this );
	painter.drawImage( 0, 0, m_graphicOffScreen );
}

void CImageAndPixelBlending::resizeEvent( QResizeEvent *_pEvent )
{
	Draw();

	QWidget::resizeEvent( _pEvent );
}

void CImageAndPixelBlending::Draw()
{
	m_graphicOffScreen = QImage( size(), QImage::Format::Format_ARGB32_Premultiplied );
	
	QPainter painter( &m_graphicOffScreen );
	painter.initFrom( this );
	painter.setRenderHint( QPainter::RenderHint::Antialiasing );
	painter.eraseRect( rect() );


	int side = qMin( width(), height() );

	painter.setViewport( ( width() - side ) / 2, ( height() - side ) / 2, side, side );
	painter.setWindow( -50, -50, 100, 100 );



	// draw something;
	DrawConical( &painter );


	painter.end();

}

void CImageAndPixelBlending::DrawConical( QPainter *_pPainter )
{
	//int side = qMin( width(), height() );

	//_pPainter->setViewport( ( width() - side ) / 2, ( height() - side ) / 2, side, side );
	//_pPainter->setWindow( -50, -50, 100, 100 );

	QColor niceBlue( 150, 150, 200 );
	QPen pen( palette().windowText().color() );
	pen.setWidth( 1 );
	
	QConicalGradient cGradient( 0, 0, -90.0 );
	cGradient.setColorAt( 0.0, Qt::GlobalColor::darkGray );
	cGradient.setColorAt( 0.2, niceBlue );
	cGradient.setColorAt( 0.5, Qt::GlobalColor::white );
	cGradient.setColorAt( 1.0, Qt::GlobalColor::darkGray );
	QBrush brush( cGradient );
		
	_pPainter->setPen( pen );
	_pPainter->setBrush( brush );
	_pPainter->drawEllipse( -49, -49, 98, 98 );

}

void CImageAndPixelBlending::BlendPixel()
{
//H[:]\XfsFile\WorkSpace\XfsWorkSpace\TryQt5[.]4[.]0\QtExamples\Qt [-] 5[.]4\.*Composition Modes
}
