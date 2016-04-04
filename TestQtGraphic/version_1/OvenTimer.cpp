#include "OvenTimer.h"
#include <QtCore/QTimer>
#include <QtGui/QFont>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <QtGui/QBrush>



//#define _USE_MATH_DEFINES
//#include <cmath>

#define M_PI 3.14159265358979323846

const double g_DegreesPerMinute = 7.0;
const double g_DegreesPerSecond = g_DegreesPerMinute / 60;

const int g_MaxMinutes = 45;
const int g_MaxSeconds = g_MaxMinutes * 60;

const int g_UpdateInterval = 5;




COvenTimer::COvenTimer( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	m_FinishTime = QDateTime::currentDateTime();

	m_pUpdateTimer = new QTimer( this );
	connect( m_pUpdateTimer, SIGNAL( timeout() ), this, SLOT( update() ) );


	m_pFinishTimer = new QTimer( this );
	m_pFinishTimer->setSingleShot( true );
	connect( m_pFinishTimer, SIGNAL( timeout() ), m_pUpdateTimer, SLOT( stop() ) );
	connect( m_pFinishTimer, SIGNAL( timeout() ), this, SIGNAL( TimeOver() ) );


	QFont font;
	font.setPointSize( 8 );
	setFont( font );
}

void COvenTimer::SetDuaration( int _iSeconds )
{
	_iSeconds = qBound( 0, _iSeconds, g_MaxSeconds );

	m_FinishTime = QDateTime::currentDateTime().addSecs( _iSeconds );

	if( _iSeconds > 0 )
	{
		m_pUpdateTimer->start( g_UpdateInterval * 1000 );
		m_pFinishTimer->start( _iSeconds * 1000 );
	}
	else
	{
		m_pUpdateTimer->stop();
		m_pFinishTimer->stop();
	}


	update();
}

int COvenTimer::Duration() const
{
	int iSeconds = QDateTime::currentDateTime().secsTo( m_FinishTime );
	if( iSeconds < 0 )
	{
		iSeconds = 0;
	}

	return iSeconds;
}

void COvenTimer::paintEvent( QPaintEvent *_pEvent )
{
	QPainter painter( this );
	painter.setRenderHint( QPainter::RenderHint::Antialiasing );

	int side = qMin( width(), height() );
	painter.setViewport( ( width() - side ) / 2, ( height() - side ) / 2, side, side );
	painter.setWindow( -50, -50, 100, 100 );

	Draw( &painter );
}

void COvenTimer::mousePressEvent( QMouseEvent *_pEvent )
{
	QPoint pt = _pEvent->pos() - rect().center();
	//int theta = atan2( -pt.y(), -pt.x() ) * 180 / M_PI;
	int theta = atan2( -pt.x(), - pt.y() ) * 180 / M_PI;

	SetDuaration( Duration() + int( theta / g_DegreesPerSecond ) );
}

void COvenTimer::Draw( QPainter *_pPainter )
{
	static const int triangle[3][2] = 
	{
		{ -2, -49 },
		{ +2, -49 },
		{ 0, -47 }
	};

	QPen thickPen( palette().windowText().color(), 1.5 );
	QPen thinPen( palette().windowText().color(), 0.5 );

	QColor niceBlue( 150, 150, 200 );

	_pPainter->setPen( thinPen );
	_pPainter->setBrush( palette().windowText() );
	_pPainter->drawPolygon( QPolygon(3, &triangle[0][0]) );


	QConicalGradient cGradient( 0, 0, -90.0 );
	cGradient.setColorAt( 0.0, Qt::darkGray /*Qt::red*/ );
	cGradient.setColorAt( 0.2, niceBlue );
	cGradient.setColorAt( 0.5, Qt::white );
	cGradient.setColorAt( 1.0, Qt::darkGray );
	_pPainter->setBrush( cGradient );
	_pPainter->drawEllipse( -46, -46, 92, 92 );


	QRadialGradient haloGradient( 0, 0, 20, 0, 0 );
	haloGradient.setColorAt( 0.0, Qt::lightGray );
	haloGradient.setColorAt( 0.8, Qt::darkGray );
	haloGradient.setColorAt( 0.9, Qt::white );	
	haloGradient.setColorAt( 1.0, Qt::black );
	//_pPainter->setPen( Qt::PenStyle::NoPen );
	_pPainter->setBrush( haloGradient );
	_pPainter->drawEllipse( -20, -20, 40, 40 );



	QLinearGradient knobGradient( -7, -25, 7, -25 );
	knobGradient.setColorAt( 0.0, Qt::black );
	knobGradient.setColorAt( 0.2, niceBlue );
	knobGradient.setColorAt( 0.3, Qt::lightGray );
	knobGradient.setColorAt( 0.8, Qt::white );
	knobGradient.setColorAt( 1.0, Qt::black );
	_pPainter->setBrush( knobGradient );
	_pPainter->setPen( thinPen );
	_pPainter->rotate( Duration() * g_DegreesPerSecond );
	_pPainter->drawRoundedRect( -7, -25, 14, 50, 99, 49 );


	for( int i = 0; i <= g_MaxMinutes; ++i )
	{
		_pPainter->save();
		_pPainter->rotate( -i * g_DegreesPerMinute );

		if( i % 5 == 0 )
		{
			_pPainter->setPen( thickPen );
			_pPainter->drawLine( 0, -41, 0, -44 );
			_pPainter->drawText( -15, -41, 30, 30, Qt::AlignHCenter | Qt::AlignTop, QString::number( i ) );
		}
		else
		{
			_pPainter->setPen( thinPen );
			_pPainter->drawLine( 0, -42, 0, -44 );
		}


		_pPainter->restore();
	}

}
