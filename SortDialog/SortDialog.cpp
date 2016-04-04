#include "SortDialog.h"

CSortDialog::CSortDialog( QWidget *_pParent )
	:QDialog( _pParent )
{
	setupUi( this );

	m_pSkGB->hide();
	m_pTkGB->hide();

	layout()->setSizeConstraint( QLayout::SetFixedSize );

	SetColumnRange( 'A', 'Z' );
}

void CSortDialog::SetColumnRange( QChar first, QChar last )
{
	m_pPColumnCB->clear();
	m_pSColumnCB->clear();
	m_pTColumnCB->clear();

	m_pSColumnCB->addItem( tr( "None" ) );
	m_pTColumnCB->addItem( tr( "None" ) );
	m_pPColumnCB->setMinimumSize( m_pSColumnCB->sizeHint() );


	while( first <= last )
	{
		m_pPColumnCB->addItem( QString(first) );
		m_pSColumnCB->addItem( QString( first ) );
		m_pTColumnCB->addItem( QString( first ) );

		first = first.unicode() + 1;
	}

}
