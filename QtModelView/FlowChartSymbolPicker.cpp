#include "FlowChartSymbolPicker.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidgetItem>
#include <QtCore/QMapIterator>

CFlowChartSymbolPikcer::CFlowChartSymbolPikcer( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	Init();
}

void CFlowChartSymbolPikcer::Init()
{	
	InitDatas();
	m_id = -1;
	// --------------------------
	m_pListWidget = new QListWidget;
	m_pListWidget->setIconSize( QSize( 60, 60 ) );
	
	QMapIterator<int, QString> iter( m_datas );
	while( iter.hasNext() )
	{
		iter.next();
		QListWidgetItem *pItem = new QListWidgetItem( iter.value(), m_pListWidget );
		pItem->setIcon( IconForSymbol(iter.value()) );
		pItem->setData( Qt::UserRole, iter.key() );
	}

	// -----------------------
	QDialogButtonBox *pDlgBtnBox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Cancel );
	connect( pDlgBtnBox, SIGNAL( accepted() ), this, SLOT( accept() ) );
	connect( pDlgBtnBox, SIGNAL( rejected() ), this, SLOT( reject() ) );


	// ---------------------
	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pListWidget );
	pLay_0->addWidget( pDlgBtnBox );

	
	
	setLayout( pLay_0 );

}

void CFlowChartSymbolPikcer::InitDatas()
{
	m_datas.insert( 132, QObject::tr( "Data" ) );
	m_datas.insert( 135, QObject::tr( "Decision" ) );
	m_datas.insert( 137, QObject::tr( "Document" ) );
	m_datas.insert( 138, QObject::tr( "Manual Input" ) );
	m_datas.insert( 139, QObject::tr( "Manual Operation" ) );
	m_datas.insert( 141, QObject::tr( "On Page Reference" ) );
	m_datas.insert( 142, QObject::tr( "Predefined Process" ) );
	m_datas.insert( 145, QObject::tr( "Preparation" ) );
	m_datas.insert( 150, QObject::tr( "Printer" ) );
	m_datas.insert( 152, QObject::tr( "Process" ) );
}

int CFlowChartSymbolPikcer::SelectedId() const
{
	return m_id;
}

void CFlowChartSymbolPikcer::done( int _result )
{
	if( _result == QDialog::Accepted )
	{
		QListWidgetItem *pItem = m_pListWidget->currentItem();
		if( pItem )
		{
			m_id = pItem->data( Qt::UserRole ).toInt();
		}
	}
	
	return QDialog::done( _result );
}

QIcon CFlowChartSymbolPikcer::IconForSymbol( const QString &_fn )
{
	QString strFileName( ":/images/" );
	strFileName += _fn.toLower();
	strFileName += ".png";
	strFileName.replace( " ", "-" );

	return QIcon( strFileName );
}
