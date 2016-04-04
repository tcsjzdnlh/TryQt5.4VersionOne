#include "GoToCellDialog.h"
#include <QtCore/QRegExp>
#include <QtGui/QRegExpValidator>
#include <QtWidgets/QMessageBox>

CGoToCellDialog::CGoToCellDialog( QWidget *pParent /*= nullptr */ )
	:QDialog( pParent )
{
	setupUi( this );

	QRegExp regExp( "-?\\d{1,3}" );		// "[A-Za-z][1-9][0-9]{0-2}"
	m_pCellLocation->setValidator( static_cast<QValidator*>( new QRegExpValidator( regExp, this ) ) );

	connect( m_pOkBtn, SIGNAL( clicked() ), this, SLOT( accept() ) );
	connect( m_pCancelBtn, SIGNAL( clicked() ), this, SLOT( reject() ) );

	//m_pOkBtn->setEnabled( false );

	emit m_pCellLocation->textChanged( m_pCellLocation->text() );
}

void CGoToCellDialog::on_m_pCellLocation_textChanged()
{
	m_pOkBtn->setEnabled( m_pCellLocation->hasAcceptableInput() );	
}
