#include "DirTree.h"
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QList>

CDirTree::CDirTree( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	Init();
}

void CDirTree::Init()
{
	m_pDires = new QTreeWidget;
	m_pDires->setColumnCount( 2 );
	m_pDires->setHeaderLabels( QStringList() << tr( "x" ) << tr( "y" ) );
	
	QTreeWidgetItem *pItem_0 = new QTreeWidgetItem( m_pDires );
	pItem_0->setText( 0, tr( "hello" ) );

	QTreeWidgetItem *pItem_1 = new QTreeWidgetItem( m_pDires );
	pItem_1->setText( 0, tr( "world" ) );

	QTreeWidgetItem *pItem_2 = new QTreeWidgetItem( m_pDires );
	pItem_2->setText( 0, tr( "ok" ) );

	QTreeWidgetItem *pItem_2_0 = new QTreeWidgetItem( pItem_2 );
	pItem_2_0->setText( 0, tr( "pItem_2_0" ) );

	QList<QTreeWidgetItem*> items;
	items.append( pItem_0 );
	items.push_back( pItem_1 );
	items << pItem_2;
	
	//m_pDires->addTopLevelItems( items );
	m_pDires->insertTopLevelItems( 0, items );
	//m_pDires->insertTopLevelItems( 1, items );
	//m_pDires->addTopLevelItem( pItem_0 );
	//m_pDires->addTopLevelItem( pItem_1 );
	//m_pDires->insertTopLevelItem( 0, pItem_0 );
	//m_pDires->insertTopLevelItem( 0, pItem_1 );
	
	

	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pDires );
	setLayout( pLay_0 );
}
