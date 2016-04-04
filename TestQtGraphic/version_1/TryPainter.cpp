#include "TryPainter.h"
#include <QtGui/QPainter>

#include <QtGui/QPen>
#include <QtGui/QPainter>
#include <QtGui/QPalette>
#include <QtCore/QPointF>
#include <QtGui/QMouseEvent>
#include <QtWidgets/QApplication>
#include <QtCore/QRect>
#include <QtGui/QBrush>
#include <QtGui/QImage>
#include <QtGui/QPainterPath>
#include <QtGui/QLinearGradient>
#include <QtGui/QFont>


CTryPainter::CTryPainter( QWidget *_pParent /*= nullptr */ )
	:QWidget(_pParent)
{
	m_graphicOffScreen = QPixmap( size() );
	m_graphicOffScreen.fill( palette().window().color() );
}

CTryPainter::~CTryPainter()
{
	m_Points.clear();
}

void CTryPainter::paintEvent( QPaintEvent *_pEvent )
{
	DrawGraphicOffScreen();
	
	QPainter painter( this );
	painter.drawPixmap( 0, 0, m_graphicOffScreen );


	//QPainter painter( this );
	//painter.drawText( QRect(100, 100, 100, 100), Qt::AlignCenter, tr( "Qt\nProject" ) );
}

void CTryPainter::mousePressEvent( QMouseEvent *_pEvent )
{
	_pEvent->accept();
	m_Points.push_back( _pEvent->pos() );
}

void CTryPainter::mouseMoveEvent( QMouseEvent *_pEvent )
{
	int iDistance = ( _pEvent->pos() - m_startPt ).manhattanLength();
	if( iDistance >= QApplication::startDragDistance() )
	{
		_pEvent->accept();
		if( !m_Points.isEmpty() )
		{
			m_PrevPt = m_Points.last();
		}

		m_Points.push_back( _pEvent->pos() );
		
		//update();
	}
	
	
}

void CTryPainter::mouseReleaseEvent( QMouseEvent *_pEvent )
{
	_pEvent->accept();
	m_Points.push_back( _pEvent->pos() );

	update();
}

void CTryPainter::resizeEvent( QResizeEvent *_pEvent )
{
	m_graphicOffScreen = QPixmap( size() );
	m_graphicOffScreen.fill( palette().window().color() );
	
	DrawGraphicOffScreen();
	update();
}

void CTryPainter::DrawGraphicOffScreen()
{
	//DrawLine();
	//DrawRect();
	DrawCircle();
	//DrawText();
}

void CTryPainter::DrawLine()
{
	if( m_Points.isEmpty() )
	{
		return;
	}

	QPalette palette = this->palette();

	QPen pen;
	pen.setColor( palette.highlight().color() /*Qt::red*/ );
	pen.setStyle( Qt::PenStyle::SolidLine );
	pen.setWidth( 5 );
	pen.setCapStyle( Qt::PenCapStyle::FlatCap );
	//pen.setCapStyle( Qt::PenCapStyle::SquareCap );
	//pen.setCapStyle( Qt::PenCapStyle::RoundCap );
	//pen.setCapStyle( Qt::PenCapStyle::MPenCapStyle );


	//pen.setJoinStyle( Qt::PenJoinStyle::MiterJoin );
	//pen.setJoinStyle( Qt::PenJoinStyle::BevelJoin );
	pen.setJoinStyle( Qt::PenJoinStyle::RoundJoin );

	QPainter painter( &m_graphicOffScreen );
	painter.setRenderHint( QPainter::Antialiasing, true );
	painter.setPen( pen );
	//painter.drawLine( m_PrevPt, m_line.last() );
	//painter.drawLines( m_line );

	QVector<QPointF>::const_iterator cBeginIter = m_Points.cbegin();
	QVector<QPointF>::const_iterator cEndIter = m_Points.cend();

	auto iterPrev = cBeginIter++;
	while( cBeginIter != cEndIter )
	{
		painter.drawLine( *iterPrev, *cBeginIter );
		iterPrev = cBeginIter++;
	}
}

void CTryPainter::DrawRect()
{
	if( m_Points.isEmpty() )
	{
		return;
	}

	QPainter painter( &m_graphicOffScreen );

	QPen pen;
	pen.setWidth( 20 );
	pen.setColor( palette().windowText().color() );
	pen.setStyle( Qt::PenStyle::DashDotDotLine );
	pen.setJoinStyle( Qt::PenJoinStyle::RoundJoin );
	pen.setCapStyle( Qt::PenCapStyle::RoundCap );	
		
	
	QBrush brush;
	brush.setColor( palette().highlight().color() );
	//brush.setStyle( Qt::BrushStyle::BDiagPattern );
	//brush.setStyle( Qt::BrushStyle::DiagCrossPattern );
	brush.setStyle( Qt::BrushStyle::TexturePattern );
	brush.setTextureImage( QImage( ":/window/crystal.png" ) );

	
	painter.setPen( pen );
	painter.setBrush( brush );
	painter.setRenderHint( QPainter::RenderHint::Antialiasing );
	painter.drawRect( QRect( m_Points.first().toPoint(), m_Points.last().toPoint() ) );


	QPainterPath path;
	path.moveTo( 80, 320 );
	path.cubicTo( 200, 80, 320, 80, 480, 320 );
	painter.drawPath( path );
}

void CTryPainter::DrawCircle()
{
	if( m_Points.isEmpty() )
	{
		return;
	}

	QPen pen;
	pen.setColor( palette().window().color() );
	pen.setWidth( 1 );
	pen.setStyle( Qt::PenStyle::DashDotDotLine );
	pen.setCapStyle( Qt::PenCapStyle::SquareCap );
	pen.setJoinStyle( Qt::PenJoinStyle::MiterJoin );


	QLinearGradient linearGradient( 300, 300, 500, 500 );
	linearGradient.setColorAt( 0.0, Qt::red );
	linearGradient.setColorAt( 0.2, Qt::green );
	linearGradient.setColorAt( 0.8, Qt::yellow );
	linearGradient.setColorAt( 1.0, Qt::blue );

	
	
	QConicalGradient conicalGradient( 300, 300, 90 );
	conicalGradient.setColorAt( 0.0, Qt::darkGreen );
	conicalGradient.setColorAt( 0.3, Qt::white );
	conicalGradient.setColorAt( 1.0, Qt::white );
	
	
	QRadialGradient RadialGradient( m_Points.first(), 800, m_Points.last() );
	RadialGradient.setSpread( QGradient::Spread::ReflectSpread );
	RadialGradient.setColorAt( 0.0, Qt::darkGreen );
	RadialGradient.setColorAt( 0.3, Qt::white );
	RadialGradient.setColorAt( 1.0, Qt::white );
	
	//QBrush brush( linearGradient );
	//QBrush brush( conicalGradient );
	QBrush brush( RadialGradient );
	brush.setColor( Qt::darkGreen );
	brush.setStyle( Qt::BrushStyle::LinearGradientPattern );
	
	
	
	QPainter painter( &m_graphicOffScreen );
	painter.setRenderHint( QPainter::Antialiasing );
	painter.setPen( pen );
	painter.setBrush( brush );
	painter.drawEllipse( QRect( m_Points.first().toPoint(), m_Points.last().toPoint() ) );
	


}

void CTryPainter::DrawText()
{
	if( m_Points.isEmpty() )
	{
		return;
	}

	QPen pen;
	pen.setColor( palette().highlight().color() );
	pen.setWidth( 1 );
	pen.setStyle( Qt::PenStyle::DashDotDotLine );
	pen.setCapStyle( Qt::PenCapStyle::SquareCap );
	pen.setJoinStyle( Qt::PenJoinStyle::MiterJoin );


	QLinearGradient linearGradient( 300, 300, 500, 500 );
	linearGradient.setColorAt( 0.0, Qt::red );
	linearGradient.setColorAt( 0.2, Qt::green );
	linearGradient.setColorAt( 0.8, Qt::yellow );
	linearGradient.setColorAt( 1.0, Qt::blue );



	QConicalGradient conicalGradient( 300, 300, 90 );
	conicalGradient.setColorAt( 0.0, Qt::darkGreen );
	conicalGradient.setColorAt( 0.3, Qt::white );
	conicalGradient.setColorAt( 1.0, Qt::white );

	//QBrush brush( linearGradient );
	QBrush brush( conicalGradient );
	brush.setColor( Qt::green );
	brush.setStyle( Qt::BrushStyle::LinearGradientPattern );


	QFont serifFont( "Times", 50, QFont::Bold );

	QPainter painter( &m_graphicOffScreen );
	painter.setRenderHint( QPainter::Antialiasing );
	painter.setPen( pen );
	painter.setBrush( brush );
	painter.setFont( serifFont );


	
	//painter.drawText( m_Points.first().toPoint(), QString( "hello world !" ) );
	
	painter.drawText( QRectF( m_Points.first(), m_Points.last() ), Qt::AlignCenter, QString( "hello world !" ) );
	//painter.drawText( QPoint(100, 100), QString( "hello world !" ) );
}
