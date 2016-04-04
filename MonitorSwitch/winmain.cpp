
#include <lowlevelmonitorconfigurationapi.h>
#include <windows.h>
#include <vector>

const BYTE PowerMode = 0xD6;
const DWORD PowerOn = 0x01;
const DWORD PowerOff = 0x04;

/*
* Monitor description struct
*/
struct MonitorDesc
{
	HANDLE hdl;
	RECT rc;
	DWORD lastTick;
	DWORD power;
};


/*
* Monitor enumeration callback
*/
BOOL CALLBACK MonitorEnumProc( HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData )
{
	std::vector<MonitorDesc>* pMonitors = reinterpret_cast< std::vector<MonitorDesc>* >( dwData );

	DWORD nMonitorCount;
	if( GetNumberOfPhysicalMonitorsFromHMONITOR( hMonitor, &nMonitorCount ) )
	{
		PHYSICAL_MONITOR* pMons = new PHYSICAL_MONITOR[nMonitorCount];

		if( GetPhysicalMonitorsFromHMONITOR( hMonitor, nMonitorCount, pMons ) )
		{
			for( DWORD i = 0; i<nMonitorCount; i++ )
			{
				MonitorDesc desc;
				desc.hdl = pMons[i].hPhysicalMonitor;
				desc.rc = *lprcMonitor;

				pMonitors->push_back( desc );
			}
		}
		delete[] pMons;
	}

	return TRUE;
}


/*
* Switch monitor power
*/
void MonitorSwitch( MonitorDesc& monitor, DWORD mode )
{
	if( monitor.power == mode )
		return;

	SetVCPFeature( monitor.hdl, PowerMode, mode );
	monitor.power = mode;
}



/*
* Main
*/
int APIENTRY wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
	// Idle time
	DWORD IdleTime = 10 * 60 * 1000;

	std::vector<MonitorDesc> monitors;
	EnumDisplayMonitors( NULL, NULL, &MonitorEnumProc, reinterpret_cast<LPARAM>( &monitors ) );


	DWORD tick = GetTickCount();

	// Init
	for( auto& monitor : monitors )
	{
		monitor.power = PowerOn;
		monitor.lastTick = tick;
	}

	// Last cursor position
	POINT lastPos;
	GetCursorPos( &lastPos );


	while( 1 )
	{
		DWORD tick = GetTickCount();

		POINT pt;
		GetCursorPos( &pt );

		// Check cursor move
		bool move = false;
		if( pt.x != lastPos.x || pt.y != lastPos.y )
		{
			move = true;
		}

		lastPos = pt;

		if( move )
		{
			// Check which monitor status should be updateted
			for( auto& monitor : monitors )
			{
				if( pt.x >= monitor.rc.left && pt.x < monitor.rc.right && pt.y >= monitor.rc.top && pt.y < monitor.rc.bottom )
				{
					monitor.lastTick = tick;
					break;
				}
			}
		}

		for( auto& monitor : monitors )
		{
			// Check idle time
			DWORD delta = ( tick - monitor.lastTick );
			if( delta >= IdleTime )
			{
				// turn off
				if( monitor.power == PowerOn )
				{
					MonitorSwitch( monitor, PowerOff );
				}
			}
			else
			{
				// turn on
				if( monitor.power == PowerOff )
				{
					MonitorSwitch( monitor, PowerOn );
				}
			}
		}

		Sleep( 50 );
	}


	return 0;
}
