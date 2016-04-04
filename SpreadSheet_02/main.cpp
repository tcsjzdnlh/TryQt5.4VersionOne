#include <QtWidgets/QApplication>
#include "MainWnd.h"

#include <QtWidgets/QSplashScreen>
#include <QtGui/QPixmap>
#include <thread>
#include <QtCore/QDir>

int main( int argc, char* argv[] )
{		
	QApplication a( argc, argv );

	Q_INIT_RESOURCE( SpreadSheet );


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