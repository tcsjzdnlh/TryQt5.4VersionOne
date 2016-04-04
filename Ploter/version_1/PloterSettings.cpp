#include "PloterSettings.h"

CPloterSettings::CPloterSettings()
{
	m_dXMin = 0.0;
	m_dXMax = 10.0;
	m_iXTicksNum = 5;

	m_dYMin = 0.0;
	m_dYMax = 10.0;
	m_iYTicksNum = 5.0;
}

void CPloterSettings::AdjustAxis( double &_min, double &_max, int &_iTicksNum )
{

}
