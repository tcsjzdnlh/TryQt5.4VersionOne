#ifndef _xfs_SortDialog_h_
#define _xfs_SortDialog_h_

#include <QtWidgets/QDialog>

#include "ui_SortDialog.h"


class CSortDialog : public QDialog, public Ui::CSortDialog
{
	Q_OBJECT
public:
	CSortDialog( QWidget *_pParent = nullptr );
	void SetColumnRange( QChar first, QChar last );
};



#endif