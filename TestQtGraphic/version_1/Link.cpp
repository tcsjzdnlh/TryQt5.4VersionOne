#include "Link.h"
#include "GraphicsNode.h"
#include <QtCore/QLineF>
#include <QtGui/QPen>

CLink::CLink(CGraphicsNode *_pStart, CGraphicsNode *_pEnd)
{		
	m_pStartNode = _pStart;
	m_pEndNode = _pEnd;

	m_pStartNode->AddLink( this );
	m_pEndNode->AddLink( this );

	m_lineColor = Qt::GlobalColor::black;

	setFlags( QGraphicsItem::ItemIsSelectable );
	setZValue( -1 );
	SetColor( Qt::GlobalColor::darkRed );

	TrackNodes();
}

CLink::~CLink()
{
	m_pStartNode->RemoveLink( this );
	m_pEndNode->RemoveLink( this );
}

void CLink::TrackNodes()
{
	setLine( QLineF( m_pStartNode->pos(), m_pEndNode->pos() ) );
	//update();
}

QColor CLink::Color() const
{
	return m_lineColor;
}

void CLink::SetColor( const QColor &_color )
{
	m_lineColor = _color;
	setPen( m_lineColor );
}
