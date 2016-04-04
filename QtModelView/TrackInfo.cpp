#include "TrackInfo.h"

CTrackInfo::CTrackInfo( const QString &_strName /*= QString()*/, int _duration /*= 0 */ )
{
	m_name = _strName;
	m_duration = _duration;
}
