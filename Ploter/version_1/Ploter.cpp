#include "Ploter.h"
#include <QtGui/QIcon>
#include <QtWidgets/QStylePainter>
#include <QtGui/QPen>
#include <QtCore/QMapIterator>
#include <QtWidgets/QStyleOptionFocusRect>
#include <QtCore/QFile>
#include <QtWidgets/QMessageBox>
#include <QtCore/QTextStream>
#include <QtCore/QString>


CPloter::CPloter( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	//  ---
	m_bRubberBandIsShow = false;

	// -------------
	m_pZoomIn = new QToolButton( this );
	m_pZoomIn->setIcon( QIcon( ":/actions/zoomin.png" ) );
	m_pZoomIn->adjustSize();
	connect( m_pZoomIn, SIGNAL( clicked() ), this, SLOT( ZoomIn() ) );
	m_pZoomIn->hide();

	m_pZoomOut = new QToolButton( this );
	m_pZoomOut->setIcon( QIcon( ":/actions/zoomout.png" ) );
	m_pZoomOut->adjustSize();
	connect( m_pZoomOut, SIGNAL( clicked() ), this, SLOT( ZoomOut() ) );
	m_pZoomOut->hide();

	// ---
	setBackgroundRole( QPalette::Dark );
	setAutoFillBackground( true );


	// ---
	setWindowIcon( QIcon( ":/window/window.ico" ) );
	setWindowTitle( tr( "ploter" ) );

	// ---
	setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	setFocusPolicy( Qt::StrongFocus );

	// ---
	//setMinimumSize( QSize( 6 * eMargin, 5 * eMargin ) );
	//resize( QSize( 12 * eMargin, 8 * eMargin ) );


	// ---
	
	SetPloterSettings( CPloterSettings() );
	
	InitCurveData( /*QString()*/ tr( ":/datas/datas.txt" ) );
	InitPloterSetting();

}

void CPloter::InitCurveData( const QString &_fn )
{
	if( !_fn.isEmpty() )
	{
		QFile file( _fn );
		if( !file.open(QIODevice::ReadOnly) )
		{
			QMessageBox::warning( this, tr( "title" ), tr( "open file: %1 failed !" ), QMessageBox::Ok );
			return ;
		}
		else
		{
			QVector<QPointF> datas[6];
			
			double factX = 0.0013;
			double offsetX = 0.0;

			double factY[6] = { 0.0008, 0.1, 0.2, 0.2, 0.1, 0.8 };
			double offsetY[6] = { +500, -55, +309, +308, 0, 0 };

			int pos[6] = { 3, 6, 7, 8, 9, 10 };

			QString strLine;
			QTextStream txtStream( &file );


			while( !txtStream.atEnd() )
			{
				strLine = txtStream.readLine();
				QStringList coords = strLine.split( " ", QString::SkipEmptyParts );

				if( coords.count() > 6 )
				{
					double x = factX * coords[0].toDouble();
					if( datas[0].isEmpty() )
					{
						offsetX = x;
					}

					for( int i = 0; i < 6; ++i )
					{
						double y = coords[pos[i]].toDouble();

						datas[i].append( QPointF( x - offsetX, factY[i] * ( y - offsetY[i] ) ) );
					}
				}
			}
		
			SetCurveData( 0, datas[0] );
			SetCurveData( 1, datas[1] );
			SetCurveData( 2, datas[2] );
			SetCurveData( 3, datas[3] );
			SetCurveData( 4, datas[4] );
			SetCurveData( 5, datas[5] );				
		}

	}
	else
	{
		const static int iCounts = 100;
		QVector<QPointF> points_1;
		QVector<QPointF> points_2;
		for( int i = 0; i < iCounts; ++i )
		{
			points_1.append( QPointF( i, uint( qrand() ) % iCounts ) );
			points_2.append( QPointF( i, uint( qrand() ) % iCounts ) );
		}

		SetCurveData( 0, points_1 );
		SetCurveData( 1, points_2 );
	}
}

void CPloter::InitPloterSetting()
{
	CPloterSettings settings;
	
	settings.m_dXMin = 0.0;
	settings.m_dXMax = 100.0;

	settings.m_dYMin = 0.0;
	settings.m_dYMax = 100.0;
	SetPloterSettings( settings );
}

void CPloter::SetPloterSettings( const CPloterSettings &_s )
{
	m_Settings.clear();
	m_Settings.append( _s );

	m_CurrentSetting = 0;

	m_pZoomIn->hide();
	m_pZoomOut->hide();

	
	RefreshOffScreenImage();
}

void CPloter::SetCurveData( int _id, QVector<QPointF> &_data )
{
	m_Curves[_id] = _data;
	RefreshOffScreenImage();
}

void CPloter::ClearCurve( int _id )
{
	m_Curves.remove( _id );
	RefreshOffScreenImage();
}

QSize CPloter::minimumSizeHint() const
{
	static QSize size( 6 * eMargin, 4 * eMargin );
	return size;
}

QSize CPloter::sizeHint() const
{
	static  QSize size( 12 * eMargin, 8 * eMargin );
	return size;
}

void CPloter::DrawGrid( QPainter *_pPainter )
{
	QRect rect = QRect( eMargin, eMargin, width() - 2 * eMargin, height() - 2 * eMargin );
	if( !rect.isValid() )
	{
		return;
	}


	// ---
	QPen quiteDark = palette().dark().color().light();
	QPen light = palette().light().color();



	CPloterSettings settings = m_Settings[m_CurrentSetting];
	for( int i = 0; i <= settings.m_iXTicksNum; ++i )
	{
		int x = rect.left() + i * ( ( rect.width() /*- 1*/ ) / settings.m_iXTicksNum );
		
		_pPainter->setPen( quiteDark );
		_pPainter->drawLine( x, rect.top(), x, rect.bottom() );
		
		_pPainter->setPen( light );
		_pPainter->drawLine( x, rect.bottom(), x, rect.bottom() + 10 );

		//_pPainter->drawText( x - 30, rect.bottom() + 10, 60, 20,
		//					Qt::AlignHCenter | Qt::AlignTop,
		//					QString::number( x - rect.left() ) );



		double dLabel = settings.m_dXMin + i * ( settings.XSpan() / settings.m_iXTicksNum );
		_pPainter->drawText( x - 50, rect.bottom() + 10, 100, 20, 
							Qt::AlignHCenter | Qt::AlignTop,
							QString::number( dLabel ) );
	}


	for( int i = 0; i <= settings.m_iYTicksNum; ++i )
	{
		int y = rect.top() + i * ( ( rect.height() /*- 1*/ ) / settings.m_iYTicksNum );
		_pPainter->setPen( quiteDark );
		_pPainter->drawLine( rect.left() - 5, y, rect.right(), y );

		double dLabel = settings.m_dYMax - i * ( settings.YSpan() / settings.m_iYTicksNum );
		_pPainter->drawText( rect.left() - 55, y - 10, 50, 20,
							Qt::AlignRight | Qt::AlignVCenter,
							QString::number( dLabel ) );

	}


	_pPainter->drawRect( rect );
}

void CPloter::DrawCurves( QPainter *_pPainter )
{
	static QColor colors[] = { Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, Qt::magenta };

	CPloterSettings settings = m_Settings[m_CurrentSetting];

	QRect rect( eMargin, eMargin, width() - 2 * eMargin, height() - 2 * eMargin );
	if( !rect.isValid() )
	{
		return;
	}


	QMapIterator<int, QVector<QPointF>> iter( m_Curves );
	
	while( iter.hasNext() )
	{
		iter.next();
		int id = iter.key();
		QVector<QPointF> points = iter.value();

		QPolygonF curve( points.count() );

		for( int i = 0; i < points.count(); ++i )
		{
			double dx = points[i].x();
			double dy = points[i].y();

			double x = rect.left() + dx * ( rect.width() / settings.XSpan() );
			double y = rect.bottom() - dy * ( rect.height() / settings.YSpan() );
			curve[i] = QPointF( x, y );
		}

		_pPainter->setPen( colors[uint( id ) % 6] );
		_pPainter->drawPolyline( curve );
	}

}

void CPloter::RefreshOffScreenImage()
{
	m_PloterBackBuffer = QPixmap( size() );
	m_PloterBackBuffer.fill( this, 0, 0 );


	QPainter painter( &m_PloterBackBuffer );
	painter.initFrom( this );
	
	DrawGrid( &painter );
	DrawCurves( &painter );

	update();
}

void CPloter::paintEvent( QPaintEvent *_pEvent )
{
	QStylePainter painter( this );

	painter.drawPixmap( 0, 0, m_PloterBackBuffer );

	if( hasFocus() )
	{
		QStyleOptionFocusRect focusOption;
		focusOption.initFrom( this );
		focusOption.backgroundColor = palette().dark().color();
		painter.drawPrimitive( QStyle::PE_FrameFocusRect, focusOption );
	}

}

void CPloter::resizeEvent( QResizeEvent *_pEvent )
{
	RefreshOffScreenImage();
}

void CPloter::keyPressEvent( QKeyEvent *_pEvent )
{

}

void CPloter::mousePressEvent( QMouseEvent *_pEvent )
{

}

void CPloter::mouseMoveEvent( QMouseEvent *_pEvent )
{

}

void CPloter::mouseReleaseEvent( QMouseEvent *_pEvent )
{

}

void CPloter::wheelEvent( QWheelEvent *_pEvent )
{

}

void CPloter::ZoomIn()
{

}

void CPloter::ZoomOut()
{

}
