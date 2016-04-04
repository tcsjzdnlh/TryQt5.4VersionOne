#ifndef _xfs_ImageAndPixelBlending_h_
#define _xfs_ImageAndPixelBlending_h_

#include <QtWidgets/QWidget>
#include <QtGui/QImage>

class QPainter;

class CImageAndPixelBlending : public QWidget
{
	Q_OBJECT
public:
	CImageAndPixelBlending( QWidget *_pParent = nullptr );

protected:
	void paintEvent( QPaintEvent *_pEvent );
	void resizeEvent( QResizeEvent *_pEvent );

private:
	void Draw();
	void DrawConical( QPainter *_pPainter );;
	void BlendPixel();

private:
	QImage		m_graphicOffScreen;
};


#endif