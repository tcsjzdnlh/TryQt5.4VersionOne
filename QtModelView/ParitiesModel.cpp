#include "ParitiesModel.h"

CParitiesModel::CParitiesModel( QObject *_pParent /*= nullptr */ )
	:QAbstractTableModel( _pParent )
{
	Init();
}

int CParitiesModel::rowCount( const QModelIndex &parent /*= QModelIndex() */ ) const
{
	return m_parities.count();
}

int CParitiesModel::columnCount( const QModelIndex &parent /*= QModelIndex() */ ) const
{
	return m_parities.count();
}

QVariant CParitiesModel::data( const QModelIndex &index, int role /*= Qt::DisplayRole */ ) const
{
	QVariant rslt;

	if( !index.isValid() )
	{
		return QVariant();
	}

	if( role == Qt::ItemDataRole::TextAlignmentRole )
	{
		rslt = int( Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter );
	}
	else if( role == Qt::ItemDataRole::DisplayRole )
	{
		double numerator = ( m_parities.begin() + index.column() ).value();
		double denominator = ( m_parities.begin() + index.row() ).value();
		
		//if( index.row() == 0 || index.column == 0 )
		//{
		//	rslt = QString( "###" );
		//}


		rslt = QString( "%1" ).arg( numerator / denominator, 0, 'f', 4 );									
	}

	return rslt;
}

QVariant CParitiesModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
{
	QVariant header;

	if( role == Qt::DisplayRole )
	{
		header = ( m_parities.begin() + section ).key();		
	}

	return header;
}

void CParitiesModel::Init()
{
	m_parities.insert( "AUD", 1.3259 );
	m_parities.insert( "CHF", 1.2970 );
	m_parities.insert( "CZK", 24.510 );
	m_parities.insert( "DKK", 6.2168 );
	m_parities.insert( "EUR", 0.8333 );
	m_parities.insert( "GBP", 0.5661 );
	m_parities.insert( "HKD", 7.7562 );
	m_parities.insert( "JPY", 112.92 );
	m_parities.insert( "NOK", 6.5200 );
	m_parities.insert( "NZD", 1.4697 );
	m_parities.insert( "SEK", 7.8180 );
	m_parities.insert( "SGD", 1.6901 );
	m_parities.insert( "USD", 1.0000 );
}
