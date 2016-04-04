#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

#include "ui_GoToCellDialog.h"

int main( int argc, char * argv[] )
{
	QApplication a( argc, argv );

	Ui::CGoToCell ui;

	QDialog *pDlg = new QDialog;
	ui.setupUi( pDlg );

	pDlg->show();

	return a.exec();
}