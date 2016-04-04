#ifndef _xfs_DirTree_h_
#define _xfs_DirTree_h_

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QDialog>

class CDirTree : public QDialog
{
	Q_OBJECT
public:
	CDirTree( QWidget *_pParent = nullptr );

private:
	void Init();

private:
	QTreeWidget			*m_pDires;
};

#endif