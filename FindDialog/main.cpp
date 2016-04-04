#include <QtWidgets/QApplication>
#include "FindDialog.h"


int main( int argc, char *argv[] )
{
	QApplication a( argc, argv );

	CFindDialog dlg;
	dlg.show();

	return a.exec();
}