#include <QtWidgets/QApplication>
#include "SortDialog.h"


int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );

	CSortDialog dlg;

	dlg.show();


	return a.exec();
}