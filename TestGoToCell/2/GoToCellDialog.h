#ifndef _xfs_GoToCellDialog_h_
#define _xfs_GoToCellDialog_h_

#include <QtWidgets/QDialog>
#include "ui_GoToCellDialog.h"


class CGoToCellDialog : public QDialog, public Ui::CGoToCell
{
	Q_OBJECT

public:
	CGoToCellDialog( QWidget *pParent = nullptr );

private slots:
	void on_m_pCellLocation_textChanged();
};





#endif