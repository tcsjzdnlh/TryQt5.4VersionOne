#include "ModelString.h"
#include <QtCore/QStringListModel>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

CModelString::CModelString( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	Init();
}

void CModelString::Init()
{
	InitDatas();

	m_pView = new QListView;
	m_pView->setModel( m_pModel );
	m_pView->setEditTriggers( QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked );

	QDialogButtonBox *pDlgBtnBox = new QDialogButtonBox;
	QPushButton *pInsertRow = new QPushButton( tr( "Insert Row" ) );
	QPushButton *pDeleteRow = new QPushButton( tr( "Delete Row" ) );
	pDlgBtnBox->addButton( pInsertRow, QDialogButtonBox::ButtonRole::ActionRole );
	pDlgBtnBox->addButton( pDeleteRow, QDialogButtonBox::ButtonRole::ActionRole );
	pDlgBtnBox->addButton( QDialogButtonBox::Ok );
	pDlgBtnBox->addButton( QDialogButtonBox::Cancel );

	connect( pInsertRow, SIGNAL( clicked() ), this, SLOT( InsertRow() ) );
	connect( pDeleteRow, SIGNAL( clicked() ), this, SLOT( DeleteRow() ) );
	connect( pDlgBtnBox, SIGNAL( accepted() ), this, SLOT( accept() ) );
	connect( pDlgBtnBox, SIGNAL( rejected() ), this, SLOT( reject() ) );



	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pView );
	pLay_0->addWidget( pDlgBtnBox );

	setLayout( pLay_0 );
}

void CModelString::InitDatas()
{
	QStringList leaders;
	leaders << "Stooge Viller" << "Littleface" << "B-B Eyes"
		<< "Pruneface" << "Mrs. Pruneface" << "The Brow"
		<< "Vitamin Flintheart" << "Flattop Sr." << "Shakey"
		<< "Breathless Mahoney" << "Mumbles" << "Shoulders"
		<< "Sketch Paree";

	m_pModel = new QStringListModel;
	m_pModel->setStringList( leaders );
}

QStringList CModelString::Leaders()
{
	return m_pModel->stringList();
}

void CModelString::InsertRow()
{
	int iRow = m_pView->currentIndex().row();
	m_pModel->insertRows( iRow, 1 );

	QModelIndex index = m_pModel->index( iRow, 0 );
	m_pView->setCurrentIndex( index );
	m_pView->edit( index );
}

void CModelString::DeleteRow()
{
	m_pModel->removeRows( m_pView->currentIndex().row(), 1 );
}
