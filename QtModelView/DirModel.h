#ifndef _xfs_DirModel_h_
#define _xfs_DirModel_h_

#include <QtWidgets/QDialog>

class QFileSystemModel;
class QTreeView;

class CDirModelDlg : public QDialog
{
	Q_OBJECT
public:
	CDirModelDlg( QWidget *_pParent = nullptr );

private:
	void Init();

private slots:
	void AddDir();
	void Delete();


private:
	QFileSystemModel		*m_pModel;
	QTreeView				*m_pView;
};


#endif