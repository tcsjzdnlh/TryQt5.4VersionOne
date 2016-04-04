#include <QtWidgets/QApplication>
#include <QtUiTools/QUiLoader>
#include <QtCore/QFile>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>


int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );

	QDialog dlg;

	QFile file( ":/forms/SortDialog.ui" );
	file.open( QFile::ReadOnly );

	QUiLoader loader;
	QWidget *pWnd = loader.load( &file, &dlg );

	if( !pWnd )
	{
		QMessageBox::information( nullptr, QString( "title" ), "loader return failed" );
	}
	else
	{
		pWnd->show();
	}

	dlg.show();

	return a.exec();
}