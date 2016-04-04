#include "SortFilterProxyModelDlg.h"
#include <QtCore/QSortFilterProxyModel>
#include <QtCore/QStringListModel>
#include <QtWidgets/QListView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtGui/QColor>
#include <QtCore/QRegExp>


CSortFilterProxyModelDlg::CSortFilterProxyModelDlg( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	Init();
}

void CSortFilterProxyModelDlg::Init()
{
	m_pModel = new QStringListModel( this );
	m_pModel->setStringList( QColor::colorNames() );

	m_pProxy = new QSortFilterProxyModel( this );
	m_pProxy->setSourceModel( m_pModel );
	m_pProxy->setFilterKeyColumn( 0 );	


	m_pView = new QListView;
	m_pView->setModel( m_pProxy );
	//m_pView->setEditTriggers( QAbstractItemView::NoEditTriggers );
	m_pView->setEditTriggers( QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked );


	QLabel *pLabel_1 = new QLabel( tr( "Filter string" ) );
	m_pFilterString = new QLineEdit;
	m_pFilterString->setText( tr( "RegExp" ) );
	pLabel_1->setBuddy( m_pFilterString );

	QLabel *pLabel_2 = new QLabel( tr( "filter syntax" ) );
	m_pSyntaxType = new QComboBox;
	m_pSyntaxType->addItem( tr( "RegExp" ), QRegExp::PatternSyntax::RegExp );
	m_pSyntaxType->addItem( tr( "Wildcard" ), QRegExp::PatternSyntax::Wildcard );
	m_pSyntaxType->addItem( tr( "FixedString" ), QRegExp::PatternSyntax::FixedString );
	pLabel_2->setBuddy( m_pSyntaxType );


	QGridLayout *pLay_0 = new QGridLayout;
	pLay_0->addWidget( m_pView, 0, 0, 1, 2 );
	pLay_0->addWidget( pLabel_1, 1, 0 );
	pLay_0->addWidget( m_pFilterString, 1, 1 );
	pLay_0->addWidget( pLabel_2, 2, 0 );
	pLay_0->addWidget( m_pSyntaxType, 2, 1 );


	setLayout( pLay_0 );


	connect( m_pFilterString, SIGNAL( textChanged( const QString& ) ), this, SLOT( ReSort() ) );
	connect( m_pSyntaxType, SIGNAL( currentIndexChanged( int ) ), this, SLOT( ReSort() ) );
}

void CSortFilterProxyModelDlg::ReSort()
{
	QRegExp::PatternSyntax type 
		= QRegExp::PatternSyntax( m_pSyntaxType->itemData( m_pSyntaxType->currentIndex() ).toInt() );

	QRegExp regexp( m_pFilterString->text(), Qt::CaseInsensitive, type );

	m_pProxy->setFilterRegExp( regexp );
}
