#ifndef _xfs_MainWnd_h_
#define _xfs_MainWnd_h_

#include <QtWidgets/QSplitter>
#include <QtCore/QMultiMap>

class QTextEdit;
class CHugeEnumToString;

class CMainWnd : public QSplitter
{
	Q_OBJECT

public:
	CMainWnd( QWidget * _pParent = nullptr );

public:
	typedef QMultiMap<int, QString> EventMaps;
	void SetEventsMap( const EventMaps &_events );
	QString CurrentEvent( int _type ) const;
	
public:
	CMainWnd* Log( const QString &_strContents );

	CMainWnd* LogLeft( const QString &_strContents );
	CMainWnd* LogRight( const QString &_strContents );


public:
	void LogAllEvents();
	void LogAllEvents( const EventMaps &_events );

	
signals:
	void XfsCloseWnd();

public :
	void closeEvent( QCloseEvent* _event );

private slots:
	void ClearLog();
	void MoveScrollToBottom();

private:
	QString			m_strLogs;
	QTextEdit		*m_pRightLogger;
	QTextEdit		*m_pLeftLogger;

private:
	EventMaps		m_events;
};



#endif