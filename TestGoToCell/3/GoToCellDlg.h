#ifndef _xfs_GoToCellDialog_h_
#define _xfs_GoToCellDialog_h_

#include "ui_GoToCellDialog.h"
#include <QtWidgets/QDialog>

class CGoToCellDialog : public QDialog, public Ui::CGoToCell
{
	Q_OBJECT
public:
	CGoToCellDialog( QWidget *_pParent = nullptr );

private slots:
	void on_m_pCellLocation_textChanged();
};



#endif