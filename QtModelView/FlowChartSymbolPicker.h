#ifndef _xfs_FlowChartSymbolPicker_h_
#define _xfs_FlowChartSymbolPicker_h_

#include <QtWidgets/QDialog>
#include <QtCore/QMap>
#include <QtGui/QIcon>

class QListWidget;

class CFlowChartSymbolPikcer : public QDialog
{
	Q_OBJECT
public:
	CFlowChartSymbolPikcer( QWidget *_pParent = nullptr );
private:
	void Init();
	void InitDatas();

public:
	int SelectedId() const;
	void done( int _result );

	QIcon IconForSymbol( const QString &_fn );

private:
	QListWidget					*m_pListWidget;
	QMap<int, QString>			m_datas;
	int							m_id;
};



#endif