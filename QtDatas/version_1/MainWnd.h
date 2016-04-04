#ifndef _xfs_MainWnd_h_
#define _xfs_MainWnd_h_

#include <QtWidgets/QMainWindow>


class QTextEdit;
class QWidget;

class CMainWnd : public QMainWindow
{
	Q_OBJECT
public:
	CMainWnd( QWidget *_pParent = nullptr );

	QTextEdit*	Logger() const;
	void Log( const QString &_strContents );

private:	
	QTextEdit		*m_pLogger;
	QWidget			*m_pControl;
};



#endif