#ifndef _xfs_TrackInfo_h_
#define _xfs_TrackInfo_h_

#include <QtCore/QString>

class CTrackInfo
{
public:
	CTrackInfo( const QString &_strName = QString(), int _duration = 0 );

	QString			m_name;
	int				m_duration;
};



#endif