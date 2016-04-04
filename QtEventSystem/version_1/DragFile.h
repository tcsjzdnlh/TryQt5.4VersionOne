#ifndef _xfs_DragFile_h_
#define _xfs_DragFile_h_

#include <QtWidgets/QWidget>

class QTextEdit;
class QDragEnterEvent;
class QDropEvent;

class CDragWnd : public QWidget
{
public:
	CDragWnd( QWidget *_pParent = nullptr );

protected:
	void dragEnterEvent( QDragEnterEvent *_pEvent );
	void dropEvent( QDropEvent *_pEvent );

	void InitGeometry();

private:
	bool ReadFile( const QString &_fn );

private:
	QTextEdit		*m_pText;
};



#endif