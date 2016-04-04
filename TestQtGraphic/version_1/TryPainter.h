#ifndef _xfs_TryPainter_h_
#define _xfs_TryPainter_h_

#include <QtWidgets/QWidget>
#include <QtCore/QPointF>
#include <QtCore/QVector>
#include <QtGui/QPixmap>

class CTryPainter : public QWidget
{
	Q_OBJECT
public:
	CTryPainter( QWidget *_pParent = nullptr );
	~CTryPainter();

protected:
	void paintEvent( QPaintEvent *_pEvent );
	void mousePressEvent( QMouseEvent *_pEvent );
	void mouseMoveEvent( QMouseEvent *_pEvent );
	void mouseReleaseEvent( QMouseEvent *_pEvent );
	void resizeEvent( QResizeEvent *_pEvent );

private:
	void DrawGraphicOffScreen();
	void DrawLine();
	void DrawRect();
	void DrawCircle();
	void DrawText();


private:
	QPointF				m_startPt;
	QPointF				m_endPt;
	QPointF				m_PrevPt;
	QVector<QPointF>	m_Points;
	QPixmap				m_graphicOffScreen;
};

#endif