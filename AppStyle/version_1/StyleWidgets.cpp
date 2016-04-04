#include "StyleWidgets.h"
#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>


CStyleWidgets::CStyleWidgets( QWidget *_pParent /*= nullptr */ )
	:QWidget(_pParent)
{
	Init();
}

void CStyleWidgets::Init()
{
	resize( 300, 300 );
	m_pLay_0 = new QVBoxLayout;
	setLayout( m_pLay_0 );
	
	// -------------
	InitComboBox();	
	SetStyleSheet( "StyleComboBox.qss" );


}

void CStyleWidgets::SetStyleSheet( const QString &_strFN )
{
	QString strStyle;
	
	QFile file( _strFN );
	if( !file.open( QFile::ReadOnly ) )
	{
		return;
	}
	QTextStream in( &file );
	strStyle = in.readAll();
	
	this->setStyleSheet( strStyle );
}

void CStyleWidgets::InitComboBox()
{
	QComboBox *pBox = new QComboBox;
	pBox->addItem( tr( "France" ) );
	pBox->addItem( tr( "Germany" ) );
	pBox->addItem( tr( "United States of America" ) );
	pBox->addItem( tr( "United Kingdom" ) );
	pBox->addItem( tr( "Other" ) );


	m_pLay_0->addWidget( pBox );
}
