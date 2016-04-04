#include <QtWidgets/QApplication>
#include "MainWnd.h"


int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );

	CMainWnd		mw;

	mw.show();

	return a.exec();
}
