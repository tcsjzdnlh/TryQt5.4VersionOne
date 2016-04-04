#include "FindDialog.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>




CFindDialog::CFindDialog( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{	
	m_pFind = new QLineEdit;

	m_pFindLabel = new QLabel( tr( "&Find What" ) );	
	m_pFindLabel->setBuddy( m_pFind );

	// ----
	m_pOk = new QPushButton( tr( "&Ok" ) );
	m_pOk->setDefault( true );
	
	m_pCancel = new QPushButton( tr( "&Cancel" ) );

	// ---
	m_pCase = new QCheckBox( tr( "CaseSensitive" ) );
	m_pFindBack = new QCheckBox( tr( "Find back" ) );


	QHBoxLayout *pLay_0_0_0 = new QHBoxLayout;
	pLay_0_0_0->addWidget( m_pFindLabel );
	pLay_0_0_0->addWidget( m_pFind );

	QVBoxLayout *pLay_0_0_1 = new QVBoxLayout;
	pLay_0_0_1->addWidget( m_pCase );
	pLay_0_0_1->addWidget( m_pFindBack );


	QVBoxLayout *pLay_0_0 = new QVBoxLayout;
	pLay_0_0->addLayout( pLay_0_0_0 );
	pLay_0_0->addLayout( pLay_0_0_1 );


	QVBoxLayout *pLay_0_1 = new QVBoxLayout;
	pLay_0_1->addWidget( m_pOk );
	pLay_0_1->addWidget( m_pCancel );

	QHBoxLayout *pLay_0 = new QHBoxLayout;
	pLay_0->addLayout( pLay_0_0 );
	pLay_0->addLayout( pLay_0_1 );

	setLayout( pLay_0 );


	setFixedHeight( sizeHint().height() );

}

