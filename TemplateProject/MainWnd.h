#ifndef _xfs_MainWnd_h_
#define _xfs_MainWnd_h_

#include <QtWidgets/QSplitter>

class QTextEdit;

class CMainWnd : public QSplitter
{
	Q_OBJECT

public:
	CMainWnd( QWidget * _pParent = nullptr );

	void Log( const QString &_strContents );

private:
	QTextEdit		*m_pLogger;
};



#endif