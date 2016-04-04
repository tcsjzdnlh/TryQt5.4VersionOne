#ifndef _xfs_SortFilterProxyModelDlg_h_
#define _xfs_SortFilterProxyModelDlg_h_

#include <QtWidgets/QDialog>

class QSortFilterProxyModel;
class QListView;
class QStringListModel;
class QComboBox;
class QLineEdit;

class CSortFilterProxyModelDlg : public QDialog
{
	Q_OBJECT
public:
	CSortFilterProxyModelDlg( QWidget *_pParent = nullptr );

private:
	void Init();
	

private slots:
	void ReSort();


private:
	QSortFilterProxyModel			*m_pProxy;
	QStringListModel				*m_pModel;
	QListView						*m_pView;


	QLineEdit						*m_pFilterString;
	QComboBox						*m_pSyntaxType;
};



#endif