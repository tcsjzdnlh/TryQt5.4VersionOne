#ifndef _xfs_CoordinateSystem_h_
#define _xfs_CoordinateSystem_h_

#include <QtWidgets/QWidget>
#include <QtGui/QPixmap>

class CCoordinateSystem : public QWidget
{
	Q_OBJECT
public:
	CCoordinateSystem( QWidget *_pParent = nullptr );

protected:
	void paintEvent( QPaintEvent *_pEvent );
	void showEvent( QShowEvent *_pEvent );
	void resizeEvent( QResizeEvent *_pEvent );

private:
	void DrawOffScreen();
	void DrawOnWindow();
	void DrawLine();

private:
	void TestCoordinateSystem();

private:
	QPixmap			m_GraphicOffScreen;
};


#endif