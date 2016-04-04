#ifndef _xfs_ProjectListWidget_h_
#define _xfs_ProjectListWidget_h_

#include <QtWidgets/QListWidget>
#include <QtCore/QPoint>

class CProjectListWidget : public QListWidget
{
	Q_OBJECT
public:
	CProjectListWidget( QWidget *_pParent = nullptr );

protected:
	void mousePressEvent( QMouseEvent *_pEvent );
	void mouseMoveEvent( QMouseEvent *_pEvent );
	void dragEnterEvent( QDragEnterEvent *_pEvent );
	void dragMoveEvent( QDragMoveEvent *_pEvent );
	void dropEvent( QDropEvent *_pEvent );

protected:
	void StartDrag();

private:
	QPoint		m_StartPos;
};


#endif