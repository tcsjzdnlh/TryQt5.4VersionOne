#ifndef _xfs_EventFilterApp_h_
#define _xfs_EventFilterApp_h_

#include <QtWidgets/QApplication>

class CEventFilterApp : public QApplication
{
	Q_OBJECT
public:
	CEventFilterApp( int &argc, char **argv );
	bool notify( QObject *_pReceiver, QEvent *_pEvent );
};

#endif