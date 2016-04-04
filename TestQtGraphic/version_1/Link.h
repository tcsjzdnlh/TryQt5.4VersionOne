#ifndef _xfs_Link_h_
#define _xfs_Link_h_

#include <QtWidgets/QGraphicsLineItem>
#include <QtGui/QColor>

class CGraphicsNode;
class CLink : public QGraphicsLineItem
{
public:
	CLink( CGraphicsNode *_pStart, CGraphicsNode *_pEnd  );
	~CLink();

protected:
	
public:
	void TrackNodes();

	QColor Color() const;
	void SetColor( const QColor &_color );

private:
	CGraphicsNode		*m_pStartNode;
	CGraphicsNode		*m_pEndNode;

	QColor				m_lineColor;
};



#endif