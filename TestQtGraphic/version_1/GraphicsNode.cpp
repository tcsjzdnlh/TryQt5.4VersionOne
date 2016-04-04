#include "GraphicsNode.h"
#include <QtGui/QFont>
#include <QtWidgets/QApplication>
#include <QtGui/QFontMetricsF>
#include "Link.h"
#include <QtGui/QPen>
#include <QtWidgets/QStyleOptionGraphicsItem>
#include <QtGui/QPainter>
#include <QtWidgets/QInputDialog>

CGraphicsNode::CGraphicsNode()
{
	m_nodeColors[ENodeColors::eTextColor] = Qt::GlobalColor::darkGreen;
	m_nodeColors[ENodeColors::eOutlineColor] = Qt::GlobalColor::darkBlue;
	m_nodeColors[ENodeColors::eBackgroundColor] = Qt::GlobalColor::white;
	
	setFlags( QGraphicsItem::GraphicsItemFlag::ItemIsMovable 
		| QGraphicsItem::GraphicsItemFlag::ItemIsSelectable 
		| QGraphicsItem::GraphicsItemFlag::ItemSendsGeometryChanges );
}

CGraphicsNode::~CGraphicsNode()
{
	for( auto pLink : m_links )
	{
		delete pLink;
	}
}

QRectF CGraphicsNode::boundingRect() const
{
	static const int iMargin = 1;
	return OutlineRect().adjusted( -iMargin, -iMargin, +iMargin, +iMargin );
}

QPainterPath CGraphicsNode::shape() const
{
	QRectF rect = OutlineRect();
	QPainterPath path;
	path.addRoundRect( rect, Roundness( rect.width() ), Roundness( rect.height() ) );

	return path;
}

void CGraphicsNode::paint( QPainter *_pPainter, const QStyleOptionGraphicsItem *_pStyleOption, QWidget *_pWidget )
{
	QPen pen( m_nodeColors[ENodeColors::eOutlineColor] );
	if( _pStyleOption->state & QStyle::State_Selected  )
	{
		pen.setStyle( Qt::PenStyle::DotLine );
		pen.setWidth( 2 );
	}

	_pPainter->setPen( pen );
	_pPainter->setBrush( QBrush( m_nodeColors[ENodeColors::eBackgroundColor] ) );

	QRectF rect = OutlineRect();
	_pPainter->drawRoundRect( rect, Roundness( rect.width() ), Roundness(rect.height() ));


	_pPainter->setPen( QPen( ENodeColors::eTextColor ) );
	_pPainter->drawText( rect, Qt::AlignCenter, m_strContext );

}

void CGraphicsNode::mouseDoubleClickEvent( QGraphicsSceneMouseEvent *_pEvent )
{
	QString strInput = QInputDialog::getText( nullptr, tr( "title" ), tr( "label" ) );
	if( !strInput.isEmpty() )
	{
		SetContext( strInput );
	}
}

QVariant CGraphicsNode::itemChange( GraphicsItemChange _change, const QVariant &_value )
{
	if( _change == ItemPositionHasChanged )
	{
		for( auto pLink : m_links )
		{
			pLink->TrackNodes();
		}
	}
	
	return QGraphicsItem::itemChange( _change, _value );
}

void CGraphicsNode::AddLink( CLink *_pLink )
{
	m_links.insert( _pLink );
}

void CGraphicsNode::RemoveLink( CLink *_pLink )
{
	m_links.remove( _pLink );
}

QRectF CGraphicsNode::OutlineRect() const
{
	static const int iPadding = 8;
	
	QFontMetricsF fmf( qApp->font() );
	
	QRectF rect = fmf.boundingRect( m_strContext );
	rect.adjust( -iPadding, -iPadding, +iPadding, +iPadding );
	rect.translate( -rect.center() );

	return rect;
}

int CGraphicsNode::Roundness( double _size ) const
{
	static const int iDiameter = 12;
	return 100 * iDiameter / int( _size );
}

QString CGraphicsNode::Context() const
{
	return m_strContext;
}

void CGraphicsNode::SetContext( const QString &_strContext )
{
	// 可能改变外接矩形，这种情况必须调用prepareGeometryChange();
	prepareGeometryChange();
	m_strContext = _strContext;
	update();
}

QColor CGraphicsNode::TextColor() const
{
	return m_nodeColors[ENodeColors::eTextColor];
}
void CGraphicsNode::SetTextColor( const QColor _color )
{
	m_nodeColors[ENodeColors::eTextColor] = _color;
	update();
}
QColor CGraphicsNode::BackgroundColor() const
{
	return m_nodeColors[ENodeColors::eBackgroundColor];
}

void CGraphicsNode::SetBackgroundColor( const QColor &_color )
{
	m_nodeColors[ENodeColors::eBackgroundColor] = _color;
	update();
}

QColor CGraphicsNode::OutlineColor() const
{
	return m_nodeColors[ENodeColors::eOutlineColor];
}

void CGraphicsNode::SetOutlineColor( const QColor &_color )
{
	m_nodeColors[ENodeColors::eOutlineColor] = _color;
	update();
}
