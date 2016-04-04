#include "GoToCellDlg.h"
#include <QtWidgets/QPushButton>
#include <QtCore/QRegExp>
#include <QtGui/QRegExpValidator>



CGoToCellDialog::CGoToCellDialog( QWidget *_pParent /* = nullptr */ )
	:QDialog( _pParent )
{
	setupUi( this );

	connect( m_pBtnBox, SIGNAL( accepted() ), this, SLOT( accept() ) );
	connect( m_pBtnBox, SIGNAL( rejected() ), this, SLOT( reject() ) );
	

	QRegExp rx( "-?\\d{1,3}" );
	m_pCellLocation->setValidator( new QRegExpValidator( rx, this ) );

	emit m_pCellLocation->textChanged( m_pCellLocation->text() );
}

void CGoToCellDialog::on_m_pCellLocation_textChanged()
{
	m_pBtnBox->button( QDialogButtonBox::Ok )->setEnabled( m_pCellLocation->hasAcceptableInput() );
}