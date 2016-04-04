#include "MonitorSwitch.h"


CMonitorSwitch::CMonitorSwitch()
{
	Init();
}

void CMonitorSwitch::Init()
{
	// get all the monitor
}

void CMonitorSwitch::TurnMonitor( SMonitor *_pMonitor, bool _bOn )
{
	for( auto & monitor : m_Monitors )
	{
		if( monitor.m_Id == _pMonitor->m_Id )
		{
			_pMonitor = &monitor;
			_pMonitor->m_bPower = _bOn;

			break;
		}
	}

	
}
