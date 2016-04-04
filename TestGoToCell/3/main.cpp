#include "GoToCellDlg.h"
#include <QtWidgets/QApplication>

int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );


	CGoToCellDialog dlg;

	dlg.show();


	return a.exec();
}