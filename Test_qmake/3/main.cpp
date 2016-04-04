#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>


int main( int argc, char *argv[] )
{
	QApplication a( argc, argv );
	
	QWidget w;
	
	QPushButton btn( QObject::tr( "hello world !" ), &w );
	btn.resize( 300, 300 );


	w.show();


	qDebug() << "hello world !";


	return a.exec();
}