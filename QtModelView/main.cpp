#include <QtWidgets/QApplication>
#include "Testor.h"


int main( int argc, char *argv[] )
{
	QApplication a( argc, argv );

	CTestor testor;
	testor.Test();

	return a.exec();
}