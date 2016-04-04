#ifndef _xfs_CoordinateEditor_h_
#define _xfs_CoordinateEditor_h_

#include <QtWidgets/QDialog>
#include <QtCore/QList>
#include <QtCore/QPointF>
class QTableWidget;

class CCoordinateEditor : public QDialog
{
	Q_OBJECT
public:
	CCoordinateEditor( QWidget *_pParent = nullptr );

	void done( int _result );

private:
	void Init();
	void InitDatas();

private slots:
	void AddRow();

private:
	QTableWidget			*m_pTable;

	QList<QPointF>			m_coordinates;
};


#endif