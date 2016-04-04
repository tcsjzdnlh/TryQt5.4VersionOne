#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtCore/QFile>
#include <QtUiTools/QUiLoader>
#include <QtWidgets/QLayout>
#include <QtWidgets/QGroupBox>


int main( int argc, char* argv[] )
{
	QApplication a( argc, argv );

	QFile file( ":/forms/SortDialog.ui" );
	file.open( QFile::ReadOnly );


	QUiLoader loader;

	QWidget *pWnd = loader.load( &file );

	
	pWnd->findChild<QGroupBox*>( "m_pSkGB" )->hide();
	pWnd->findChild<QGroupBox*>( "m_pTkGB" )->hide();
	
	pWnd->layout()->setSizeConstraint( QLayout::SetFixedSize );


	if( pWnd )
	{
		pWnd->show();
	}

	file.close();

	return a.exec();
}