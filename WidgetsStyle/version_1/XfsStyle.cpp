#include "XfsStyle.h"
#include <QtWidgets/QStyleOptionSlider>
#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QtGui/QPen>

CXfsStyle::CXfsStyle()
{
	Q_INIT_RESOURCE( shared );
}

void CXfsStyle::polish( QPalette &_palette )
{
	_palette.setColor( QPalette::ColorRole::Window, QColor( 100, 100, 100 ) );
}

void CXfsStyle::polish( QWidget *_pWidget )
{
	if( qobject_cast<QSlider*>(_pWidget) )
	{
		_pWidget->setAttribute( Qt::WidgetAttribute::WA_Hover );
	}
}

void CXfsStyle::unpolish( QWidget *_pWidget )
{

}

void CXfsStyle::drawComplexControl( ComplexControl _cc, const QStyleOptionComplex *_pOption, QPainter *_pPainter, const QWidget *_pWidget /*= nullptr */ ) const
{

	switch( _cc )
	{
		case CC_Slider:
		{
			if( const QStyleOptionSlider *pSOSlider = qstyleoption_cast<const QStyleOptionSlider*>( _pOption ) )
			{
				QRect rcGroove = subControlRect( _cc, _pOption, SC_SliderGroove, _pWidget );
				QRect rcHandle = subControlRect( _cc, _pOption, SC_SliderHandle, _pWidget );

				_pPainter->save();

				QPen pen;
				pen.setColor( Qt::GlobalColor::red );
				pen.setWidth( 1 );
				_pPainter->setPen( pen );


				bool bHover = false;
				bHover = ( pSOSlider->state & State_Enabled ) && ( pSOSlider->state & State_MouseOver );
				
				if( bHover )
				{
					QRect hr = _pWidget->rect().adjusted( 0, 4, 0, -4 );
					DrawHoverRect( _pPainter, hr );
				}
				if( ( _pOption->subControls & SC_SliderGroove ) && rcGroove.isValid() )
				{
					QPixmap pmGroov( ":/res/images/slider_bar.png" );
					QRect rcGrooveAdjusted = rcGroove.adjusted( 5, 0, -10, 0 );
					_pPainter->drawPixmap( rcGrooveAdjusted, pmGroov );
					_pPainter->drawRect( rcGroove );
				}
				if( ( _pOption->subControls & SC_SliderHandle ) && rcHandle.isValid() )
				{
					QPixmap pmHandle( ":/res/images/slider_thumb_on.png" );
					_pPainter->drawPixmap( rcHandle.topLeft(), pmHandle );
					_pPainter->drawRect( rcHandle );
				}

				_pPainter->restore();

			}
			break;
		}
		case CC_GroupBox:
		{
			if( const QStyleOptionGroupBox *pSOGrpBx = qstyleoption_cast<const QStyleOptionGroupBox*>(_pOption) )
			{				
				QStyleOptionGroupBox soGrpBx( *pSOGrpBx );
				soGrpBx.subControls &= ~SC_GroupBoxLabel;
				QCommonStyle::drawComplexControl( _cc, &soGrpBx, _pPainter, _pWidget );
			}
			break;
		}
		default:
			QCommonStyle::drawComplexControl( _cc, _pOption, _pPainter, _pWidget );
			break;
	}

	return;
}

void CXfsStyle::drawControl( ControlElement _ce, const QStyleOption *_pOption, QPainter *_pPainter, const QWidget *_pWidget /*= nullptr */ ) const
{
	switch( _ce )
	{
		default:
			QCommonStyle::drawControl( _ce, _pOption, _pPainter, _pWidget );
			break;
	}

	return;
}

void CXfsStyle::drawPrimitive( PrimitiveElement _pe, const QStyleOption *_pOption, QPainter *_pPainter, const QWidget *_pWidget /*= nullptr */ ) const
{
	switch( _pe )
	{
		default:
			QCommonStyle::drawPrimitive( _pe, _pOption, _pPainter, _pWidget );
			break;
	}

	return;
}

QRect CXfsStyle::subElementRect( SubElement _se, const QStyleOption *_pOption /*= nullptr*/, const QWidget *_pWidget /*= nullptr */ ) const
{
	QRect rect;

	rect = QCommonStyle::subElementRect( _se, _pOption, _pWidget );

	return rect;
}

QRect CXfsStyle::subControlRect( ComplexControl _cc, const QStyleOptionComplex *_pOption, SubControl _sc, const QWidget *_pWidget ) const
{
	QRect rect;

	rect = QCommonStyle::subControlRect( _cc, _pOption, _sc, _pWidget );

	switch( _cc )
	{
		case CC_Slider:
		{
			switch( _sc )
			{
				case SC_SliderGroove:
				{
					rect.setHeight( EGeometry::e_slider_height / 3 );
					rect.moveTop( e_slider_height / 3 ); // positive numver moves down, negative number moves up
					break;
				}
				case SC_SliderHandle:
				{
					rect.setWidth( 13 );
					rect.setHeight( e_slider_height - 1 );
					break;
				}
			}
		}
		//case CC_GroupBox:
		//{
		//	break;
		//}
		default:			
			break;
	}

	return rect;
}

int CXfsStyle::pixelMetric( PixelMetric _pm, const QStyleOption *_pOption /*= nullptr*/, const QWidget *_pWidget /*= nullptr */ ) const
{
	if( _pm == PM_SliderLength )
	{
		return e_slider_length;
	}
	
	return QCommonStyle::pixelMetric( _pm, _pOption, _pWidget );
}

int CXfsStyle::styleHint( StyleHint _sh, const QStyleOption *_pOption /*= nullptr*/, const QWidget *_pWidget /*= nullptr*/, QStyleHintReturn *_pSHRet /*= nullptr */ ) const
{
	return QCommonStyle::styleHint( _sh, _pOption, _pWidget );
}

QSize CXfsStyle::sizeFromContents( ContentsType _ct, const QStyleOption *_pOption, const QSize &_size, const QWidget *_pWidget ) const
{
	QSize size;

	size = QCommonStyle::sizeFromContents( _ct, _pOption, _size, _pWidget );
	switch( _ct )
	{
		case CT_Slider:
			size.setHeight( EGeometry::e_slider_height );
			break;
		default:
			break;
	}

	return size;
}

void CXfsStyle::DrawHoverRect( QPainter *_pPainter, const QRect &_hr ) const
{
	qreal h = _hr.height();
	qreal h2 = _hr.height() / qreal( 2 );

	QPainterPath path;
	path.addRect( _hr.x() + h2, _hr.y(), _hr.width() - h2 * 2, h );
	path.addEllipse( _hr.x(), _hr.y(), h, h );
	path.addEllipse( _hr.topRight().x() - h, _hr.y(), h, h );
	path.setFillRule( Qt::FillRule::WindingFill );

	_pPainter->save();
	_pPainter->setPen( Qt::NoPen );
	_pPainter->setBrush( QColor(191, 215, 191) );
	_pPainter->setRenderHint( QPainter::RenderHint::Antialiasing );
	_pPainter->drawPath( path );

	_pPainter->restore();
}
