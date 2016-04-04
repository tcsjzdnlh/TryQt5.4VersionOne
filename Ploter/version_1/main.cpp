#include <QtWidgets/QApplication>
#include "Ploter.h"

int main( int argc, char *argv[] )
{
	QApplication a( argc, argv );

	CPloter ploter;
	ploter.show();


	return a.exec();
}

