#ifndef _xfs_MonitorSwitch_h_
#define _xfs_MonitorSwitch_h_

#include <vector>



struct SMonitor
{
	unsigned long		m_Id;
	bool				m_bPower;
};

class CMonitorSwitch
{
public:
	//enum EMonitorState
	//{
	//	Power_On = 1,
	//	Power_Off
	//};
public:
	CMonitorSwitch();
public:
	void Init();
	void TurnMonitor( SMonitor *_pMonitor, bool _bOn );
	
private:
	std::vector<SMonitor>		m_Monitors;
};



#endif
