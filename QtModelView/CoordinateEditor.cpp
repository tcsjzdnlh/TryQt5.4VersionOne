#include "CoordinateEditor.h"
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>


CCoordinateEditor::CCoordinateEditor( QWidget *_pParent )
	:QDialog( _pParent )
{
	Init();
}

void CCoordinateEditor::done( int _result )
{
	if( _result == QDialog::Accepted )
	{
		m_coordinates.clear();
		for( int row = 0; row < m_pTable->rowCount(); ++row )
		{
			double x = m_pTable->item( row, 0 )->text().toDouble();
			double y = m_pTable->item( row, 1 )->text().toDouble();
			m_coordinates.append( QPointF( x, y ) );
		}
	}
	
	QDialog::done( _result );
}

void CCoordinateEditor::Init()
{
	InitDatas();

	QPushButton *pAddRowBtn = new QPushButton( "&Add Row" );
	connect( pAddRowBtn, SIGNAL( clicked() ), this, SLOT( AddRow() ) );

	QDialogButtonBox *pDlgBtnBox = new QDialogButtonBox;
	pDlgBtnBox->addButton( pAddRowBtn, QDialogButtonBox::ActionRole );
	pDlgBtnBox->addButton( QDialogButtonBox::Ok );
	pDlgBtnBox->addButton( QDialogButtonBox::Cancel );

	//connect( pAddRowBtn, SIGNAL( clicked() ), this, SLOT( AddRow() ) );
	connect( pDlgBtnBox, SIGNAL( accepted() ), this, SLOT( accept() ) );
	connect( pDlgBtnBox, SIGNAL( rejected() ), this, SLOT( reject() ) );


	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pTable );
	pLay_0->addWidget( pDlgBtnBox );

	setLayout( pLay_0 );

}

void CCoordinateEditor::InitDatas()
{
	m_pTable = new QTableWidget( 0, 2 );
	m_pTable->setHorizontalHeaderLabels( QStringList() << tr( "x" ) << tr( "y" ) );

	QPointF points[] = 
	{
		QPointF( 0.0, 0.9 ),
		QPointF( 0.2, 11.0 ),
		QPointF( 0.4, 15.4 ),
		QPointF( 0.6, 12.9 ),
		QPointF( 0.8, 8.5 ),
		QPointF( 1.0, 7.1 ),
		QPointF( 1.2, 4.0 ),
		QPointF( 1.4, 13.6 ),
		QPointF( 1.6, 22.2 ),
		QPointF( 1.8, 22.2 )
	};

	int iSize = sizeof( points ) / sizeof(points[0]);
	
	for( int i = 0; i < iSize; ++i )
	{
		m_coordinates << points[i];
		
		m_pTable->insertRow( i );
		QTableWidgetItem *pItem = new QTableWidgetItem[2];
		pItem->setText( QString::number( points[i].x() ) );
		pItem->setTextAlignment( Qt::AlignRight | Qt::AlignVCenter );
		m_pTable->setItem( i, 0, pItem );

		( ++pItem )->setText( QString::number( points[i].y() ) );
		pItem->setTextAlignment( Qt::AlignLeft | Qt::AlignVCenter );
		m_pTable->setItem( i, 1, pItem );
	}
}

void CCoordinateEditor::AddRow()
{
	int iRowCount = m_pTable->rowCount();

	m_pTable->insertRow( iRowCount );
		
	m_pTable->setItem( iRowCount, 0, new QTableWidgetItem );
	m_pTable->setItem( iRowCount, 1, new QTableWidgetItem );

	m_pTable->setCurrentCell( iRowCount, 0 );
}
