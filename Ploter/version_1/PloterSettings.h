#ifndef _xfs_PloterSettings_h_
#define _xfs_PloterSettings_h_

class CPloterSettings
{
public:
	CPloterSettings();

private:
	static void AdjustAxis( double &_min, double &_max, int &_iTicksNum );

public:
	void Scroll( int _dx, int _dy );
	void Adjust();

public:
	double XSpan() const
	{
		return m_dXMax - m_dXMin;
	}
	double YSpan() const
	{
		return m_dYMax - m_dYMin;
	}

public:
	double		m_dXMin;
	double		m_dXMax;
	int			m_iXTicksNum;


	double		m_dYMin;
	double		m_dYMax;
	int			m_iYTicksNum;
};


#endif