#ifndef _xfs_MacFlags_h_
#define _xfs_MacFlags_h_

#include <QtCore/QObject>

class CMacFlags : public QObject
{
	Q_OBJECT
public:
	enum EAxisId
	{
		Axis_X = 0x01,
		Axis_Y = 0x02,
		Axis_Z = 0x04,
		Axis_R = 0x08,
		Axis_T = 0x10
	};

	Q_DECLARE_FLAGS( EAxisIds, EAxisId )
		Q_FLAGS( EAxisIds )
		Q_ENUMS( EAxisId )
		//Q_ENUMS( EAxisIds )
};


#endif