#ifndef _xfs_ModelString_h_
#define _xfs_ModelString_h_

#include <QtWidgets/QDialog>

class QStringListModel;
class QListView;

class CModelString : public QDialog
{
	Q_OBJECT
public:
	CModelString( QWidget *_pParent = nullptr );

private:
	void Init();
	void InitDatas();

	QStringList Leaders();

private slots:
	void InsertRow();
	void DeleteRow();

private:
	QStringListModel			*m_pModel;
	QListView					*m_pView;
};

#endif