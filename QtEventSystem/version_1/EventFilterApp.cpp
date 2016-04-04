#include "EventFilterApp.h"
#include "MainWnd.h"

extern CMainWnd *g_pWnd;
extern void *g_pEventTarget;

CEventFilterApp::CEventFilterApp( int &argc, char **argv )
	: QApplication( argc, argv )
{

}

bool CEventFilterApp::notify( QObject *_pReceiver, QEvent *_pEvent )
{
	if( g_pEventTarget != nullptr && g_pWnd != nullptr )
	{
		if( _pReceiver == static_cast<QObject*>( g_pEventTarget) )
		{			
			g_pWnd->Log( ( QString( "g_pEventTarget has a event from QApplication::notify() ....event is spontaneous : %1  " ).arg( _pEvent->spontaneous() )
				+ g_pWnd->CurrentEvent( _pEvent->type() ) ) );
		}
	}
	return QApplication::notify( _pReceiver, _pEvent );
}
