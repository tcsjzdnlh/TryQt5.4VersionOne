#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>


int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );

	QWidget w;

	QPushButton btn( QObject::tr( "mybike" ), &w );
	btn.resize( 300, 200 );

	w.show();

	return a.exec();
}