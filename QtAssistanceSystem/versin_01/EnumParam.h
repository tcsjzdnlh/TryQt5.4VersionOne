#ifndef _xfs_EnumParam_h_
#define _xfs_EnumParam_h_

#include <QtCore/QObject>

enum EAxisId
{
	Axis_X = 0x01,
	Axis_Y = 0x02,
	Axis_Z = 0x04,
	Axis_R = 0x08,
	Axis_T = 0x10
};

Q_DECLARE_FLAGS( EAxisIds, EAxisId );
//typedef QFlags<EAxisId> EAxisIds;

Q_DECLARE_OPERATORS_FOR_FLAGS( EAxisIds );
//EAxisIds operator|( EAxisId, EAxisId );

class CEnumParam : public QObject
{
	Q_OBJECT
public:

public:
	void Days( EAxisIds _e );

};



#endif