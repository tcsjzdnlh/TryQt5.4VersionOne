#include <QtWidgets/QApplication>
#include "GoToCellDialog.h"


int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );


	CGoToCellDialog dlg;
	dlg.show();


	return a.exec();
}