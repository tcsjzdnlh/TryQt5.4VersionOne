#include "DirModel.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QFileSystemModel>
#include <QtCore/QDir>
#include <QtCore/QModelIndex>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QDialogButtonBox>

CDirModelDlg::CDirModelDlg( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	Init();
}

void CDirModelDlg::Init()
{
	// -------------
	m_pModel = new QFileSystemModel;
	//m_pModel->setRootPath( QDir::currentPath() );
	m_pModel->setRootPath( "" );
	m_pModel->setReadOnly( false );
	
	// -------------
	m_pView = new QTreeView;
	m_pView->setModel( m_pModel );
	//m_pView->header()->setClickable( true );

	// -------------
	QModelIndex index = m_pModel->index( QDir::currentPath() );
	m_pView->setCurrentIndex( index );
	m_pView->expand( index );
	m_pView->scrollTo( index );
	m_pView->resizeColumnToContents( 0 );

	// -------------
	QPushButton *pAddDirBtn = new QPushButton(tr("Add a Directory"));
	QPushButton *pDeleteBtn = new QPushButton(tr("Delete"));
	
	QDialogButtonBox *pDlgBtnBox = new QDialogButtonBox;
	pDlgBtnBox->addButton( QDialogButtonBox::Ok );
	pDlgBtnBox->addButton( QDialogButtonBox::Cancel );
	pDlgBtnBox->addButton( pAddDirBtn, QDialogButtonBox::ActionRole );
	pDlgBtnBox->addButton( pDeleteBtn, QDialogButtonBox::ActionRole );

	connect( pAddDirBtn, SIGNAL( clicked() ), this, SLOT( AddDir() ) );
	connect( pDeleteBtn, SIGNAL( clicked() ), this, SLOT( Delete() ) );
	connect( pDlgBtnBox, SIGNAL( accepted() ), this, SLOT( accept() ) );
	connect( pDlgBtnBox, SIGNAL( rejected() ), this, SLOT( reject() ) );


	// -------------
	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pView );
	pLay_0->addWidget( pDlgBtnBox );

	setLayout( pLay_0 );

}

void CDirModelDlg::AddDir()
{
	//QModelIndex index = m_pModel->index(  );
	QString strDirName = QInputDialog::getText( this, tr( "title" ), tr( "input a directory name : " ) );
	if( !strDirName.isEmpty() )
	{
		m_pModel->mkdir( m_pView->currentIndex(), strDirName );
	}		
}

void CDirModelDlg::Delete()
{
	QModelIndex index = m_pView->currentIndex();
	bool bOk = false;
	if( m_pModel->fileInfo( index ).isDir() )
	{
		bOk = m_pModel->rmdir( index );
	}
	else
	{
		bOk = m_pModel->remove( index );
	}

	if( !bOk )
	{
		QMessageBox::information( this, tr( "title" ), 
									QString( "delete %1 failed !" ).arg( m_pModel->fileName( index ) ) );
	}
}
