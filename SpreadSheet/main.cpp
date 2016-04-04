#include <QtWidgets/QApplication>
#include "MainWnd.h"

#include <QtWidgets/QSplashScreen>
#include <QtGui/QPixmap>
#include <thread>

int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );

	QSplashScreen splash;
	splash.setPixmap( QPixmap( ":/splash/crystal.png" ) );
	splash.show();


	splash.showMessage( QObject::tr( "creating main window ..." ), Qt::AlignRight | Qt::AlignTop, Qt::white );
	

	std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

	CMainWnd w;
	w.show();

	splash.finish( &w );


	return a.exec();
}