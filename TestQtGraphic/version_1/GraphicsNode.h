#ifndef _xfs_GraphicsNode_h_
#define _xfs_GraphicsNode_h_

#include <QtWidgets/QGraphicsItem>
#include <QtCore/QCoreApplication>
#include <QtCore/QSet>
#include <QtGui/QColor>

class CLink;

class CGraphicsNode : public QGraphicsItem
{
	Q_DECLARE_TR_FUNCTIONS(CGraphicsNode)
public:
	CGraphicsNode();
	~CGraphicsNode();

public:
	QRectF	boundingRect() const;
	QPainterPath shape() const;
	void paint( QPainter *_pPainter, const QStyleOptionGraphicsItem *_pStyleOption, QWidget *_pWidget );

private:
	QRectF	OutlineRect() const;
	int		Roundness( double _size ) const;

protected:
	void	 mouseDoubleClickEvent( QGraphicsSceneMouseEvent *_pEvent );
	QVariant itemChange( GraphicsItemChange _change, const QVariant &_value );


public:
	void	AddLink( CLink *_pLink );
	void	RemoveLink( CLink *_pLink );


public:
	QString Context() const;
	void	SetContext( const QString &_strContext );

	QColor  TextColor() const;
	void	SetTextColor( const QColor _color );

	QColor	BackgroundColor() const;
	void	SetBackgroundColor( const QColor &_color );

	QColor	OutlineColor() const;
	void	SetOutlineColor( const QColor &_color );

private:
	QSet<CLink*>			m_links;

	QString					m_strContext;
	
	enum ENodeColors { eTextColor = 0, eBackgroundColor, eOutlineColor };
	QColor					m_nodeColors[3];
};


#endif