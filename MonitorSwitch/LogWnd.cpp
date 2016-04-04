#include "LogWnd.h"

#include <Windows.h>
#include <Physicalmonitorenumerationapi.h>
#pragma comment(lib, "user32.lib")


BOOL CALLBACK XfsMonitorEnumProc(
								HMONITOR hMonitor,
								HDC      hdcMonitor,
								LPRECT   lprcMonitor,
								LPARAM   dwData
								)
{
	DWORD num = 0;
	if( GetNumberOfPhysicalMonitorsFromHMONITOR( hMonitor, &num ) )
	{
	}
	
	return true;
}



CLogWnd::CLogWnd( QWidget *_pParent /*= nullptr */ )
	:QTextEdit( _pParent )
{
	Debug();
}

void CLogWnd::Debug()
{
	int num = ::GetSystemMetrics( SM_CMONITORS );

	//QString first( "visible monitors number is : %1" );
	//first.arg( num );

	QString txt = tr( "visible monitors number is : %1" ).arg( num );
	setPlainText( txt );


	::EnumDisplayMonitors( NULL, NULL, XfsMonitorEnumProc, NULL );
}
