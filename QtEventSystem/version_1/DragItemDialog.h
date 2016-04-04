#ifndef _xfs_DragItemDialog_h_
#define _xfs_DragItemDialog_h_

#include "ui_projectdialog.h"
#include <QtWidgets/QDialog>

class CDragItemDialog : public QDialog, public Ui::CProjectDialog
{
	Q_OBJECT
public:
	CDragItemDialog( QWidget *_pParent = nullptr );

protected:
	void mousePressEvent( QMouseEvent *_pEvent );

private:
	void InitListItem();

private slots:
	void on_m_pLeftBtn_clicked();
	void on_m_pRightBtn_clicked();

	void MoveCurrentItem( QListWidget *_pSource, QListWidget *_pTarget );

};



#endif