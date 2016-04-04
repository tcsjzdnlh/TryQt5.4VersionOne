#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>


int main( int argc, char * argv [] )
{
    QApplication a( argc, argv );

    QLabel *pLabel = new QLabel("hello");
    pLabel->show();

    return a.exec();

}
