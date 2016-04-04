#ifndef _xfs_ParitiesModel_h_
#define _xfs_ParitiesModel_h_

#include <QtWidgets/QTableView>
#include <QtCore/QAbstractTableModel>
#include <QtCore/QMap>

class CParitiesModel : public QAbstractTableModel
{
public:
	CParitiesModel( QObject *_pParent = nullptr );
	
public:
	int rowCount( const QModelIndex &parent = QModelIndex()  ) const;
	int columnCount( const QModelIndex &parent = QModelIndex()  ) const;
	QVariant data( const QModelIndex &index, int role = Qt::DisplayRole  ) const;
	QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole  ) const;


private:
	void Init();

private:
	QMap<QString, double>			m_parities;
	
};


#endif