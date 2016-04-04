#ifndef _xfs_MainWnd_h_
#define _xfs_MainWnd_h_
#include <QtWidgets/QMainWindow>
#include "LogWnd.h"
#include "MonitorSwitch.h"


class CMainWnd : public QMainWindow
{
	Q_OBJECT
public:
	CMainWnd( QWidget *_pParent = nullptr );


private:
	CLogWnd				m_logWnd;
	CMonitorSwitch		m_monitorSWitch;
};





#endif