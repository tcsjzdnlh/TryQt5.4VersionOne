#ifndef _xfs_TrackEditor_h_
#define _xfs_TrackEditor_h_

#include <QtCore/QList>
#include <QtWidgets/QDialog>

#include "TrackInfo.h"

class QTableWidget;

class CTrackEditor : public QDialog
{
	Q_OBJECT
public:
	CTrackEditor( QWidget *_pParent = nullptr );

private:
	void Init();
	void InitDatas();
private:
	QTableWidget			*m_pView;
	QList<CTrackInfo>		m_tracks;
};




#endif