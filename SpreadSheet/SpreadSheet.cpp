#include "SpreadSheet.h"
#include "Cell.h"
#include <QtCore/QFile>
#include <QtCore/QDataStream>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTableWidgetSelectionRange>
#include <QtGui/QClipboard>


CSpreadSheet::CSpreadSheet( QWidget *_pParent )
	:QTableWidget( _pParent )
{
	setItemPrototype( new CCell );
	setSelectionMode( QAbstractItemView::ContiguousSelection );

	connect( this, SIGNAL( itemChanged( QTableWidgetItem * ) ), this, SLOT( SomethingChanged() ) );

	Clear();
}

CSpreadSheet::CSpreadSheet( int _r, int _c, QWidget *_pParent /*= nullptr */ )
	: QTableWidget( _r, _c, _pParent )
{

}

QString CSpreadSheet::CurrentLocation() const
{
	
	// 注意此句中 的  +  的用法
	return QChar( 'A' + currentColumn() ) + QString::number( currentRow() + 1 );
}

QString CSpreadSheet::CurrentFormula() const
{
	return Formula( currentRow(), currentColumn() );
}

bool CSpreadSheet::ReadFile( const QString &_fn )
{
	QFile file( _fn );
	if( !file.open( QIODevice::ReadOnly ) )
	{
		QMessageBox::warning( this, tr( "title" ),
					tr( "open file %1 failed ! %2" ).arg( file.fileName() ).arg( file.errorString() ) );

		return false;
	}

	quint32 iMagicNumber;

	QDataStream in( &file );
	in >> iMagicNumber;
	if( iMagicNumber != eMagicNumber )
	{
		QMessageBox::warning( this, tr( "title" ), tr( "this file is not SpreatSheet File" ) );
		return false;
	}

	Clear();

	QApplication::setOverrideCursor( Qt::WaitCursor );

	quint16 iRow;
	quint16 iColumn;
	QString strFormula;

	while( !in.atEnd() )
	{
		in >> iRow >> iColumn >> strFormula;
		SetFormula( iRow, iColumn, strFormula );
	}
	
	
	QApplication::restoreOverrideCursor();

	return true;
}

bool CSpreadSheet::WriteFile( const QString &_fn )
{
	QFile file( _fn );
	if( !file.open(QIODevice::WriteOnly) )
	{
		QMessageBox::critical( this, tr( "title" ), 
				tr( "open file %1 failed :  %2" ).arg( file.fileName() ).arg( file.errorString() ) );
		return false;
	}
	
	QDataStream out( &file );
	out.setVersion( QDataStream::Qt_5_4 );
	
	out << quint32( eMagicNumber );

	QApplication::setOverrideCursor( Qt::WaitCursor );

	
	for( int i = 0; i < eRowCount; ++i )
	{
		for( int j = 0; j < eColumnCount; ++j )
		{
			QString formula = Formula( i, j );
			if( !formula.isEmpty() )
			{
				out << quint16( i ) << quint16( j ) << formula;
			}			
		}
	}

	QApplication::restoreOverrideCursor();

	return true;
}

bool CSpreadSheet::AutoRecalculate() const
{
	return m_bRecalc;
}

void CSpreadSheet::Sort( const CSpreadSheetCompare & _compare )
{
	QTableWidgetSelectionRange rang = SelectedRange();

	QList<QStringList> Records;

	for( int i = 0; i < rang.rowCount(); ++i )
	{
		QStringList OneRow;

		for( int j = 0; j < rang.columnCount(); ++j )
		{
			
			OneRow.append( Formula( rang.topRow() +i, rang.leftColumn() + j ) );
		}

		Records.append( OneRow );
	}

	// -----
	qStableSort( Records.begin(), Records.end(), _compare );

	// -----
	for( int i = 0; i < rang.rowCount(); ++i )
	{		
		for( int j = 0; j < rang.columnCount(); ++j )
		{
			SetFormula( rang.topRow() + i, rang.leftColumn() + j, Records[i][j] );
		}
	}
	
	
	clearSelection();
	SomethingChanged();
	
	return;
}

QTableWidgetSelectionRange CSpreadSheet::SelectedRange() const
{
	QList<QTableWidgetSelectionRange> rangs = selectedRanges();

	if( rangs.isEmpty() )
	{
		return QTableWidgetSelectionRange();
	}
	
	return rangs.first();
}

CCell* CSpreadSheet::Cell( int _row, int _Column ) const
{
	return static_cast<CCell*>( item( _row, _Column ) );
}

QString CSpreadSheet::Text( int _row, int _Column ) const
{
	CCell *pC = Cell( _row, _Column );
	if( nullptr != pC )
	{
		return pC->text();
	}
	else
	{
		return QString();
	}
}

QString CSpreadSheet::Formula( int _row, int _Column ) const
{
	CCell *pC = Cell( _row, _Column );
	if( nullptr != pC )
	{
		return pC->Formula();
	}
	else
	{
		return QString();
	}
}

void CSpreadSheet::SetFormula( int _row, int _Column, QString & _formula )
{
	CCell *pC = Cell( _row, _Column );
	if( nullptr != pC )
	{
		pC->SetFormula( _formula );
	}
	else
	{
		pC = new CCell;
		setItem( _row, _Column, pC );
		pC->SetFormula( _formula );
	}
}

void CSpreadSheet::Cut()
{
	Copy();
	Del();
}

void CSpreadSheet::Copy()
{
	QString Records;

	QTableWidgetSelectionRange rang = SelectedRange();

	for( int i = 0; i < rang.rowCount(); ++i )
	{
		if( i >0 )
			Records += '\n';

		for( int j = 0; j < rang.columnCount(); ++j )
		{
			if( j > 0 )
				Records += '\t';

			Records += Formula( rang.topRow() + i, rang.leftColumn() + j );
		}
			
		
	}

	QApplication::clipboard()->setText( Records );

}

void CSpreadSheet::Paste()
{
	QString strContents = QApplication::clipboard()->text();

	if( strContents.isEmpty() )
	{
		return;
	}
	
	

	int iRow = currentRow();
	int iColumn = currentColumn();

	QStringList Records = strContents.split( '\n' );
	int iRows = Records.count();
	int iColumns = Records.first().count( '\t' ) + 1;


	int Pos[2] = { 0 };

	Pos[0] = eRowCount - ( iRow + 1 );	
	if( Pos[0] < iRows )
	{
		Pos[0] = ( iRow - ( iRows - Pos[0] ) ) +1;
	}
	else
	{
		Pos[0] = iRow;
	}

	Pos[1] = eColumnCount - ( iColumn + 1 );
	if( Pos[1] < iColumns )
	{
		Pos[1] = ( iColumn - ( iColumns - Pos[1] ) ) + 1;
	}
	else
	{
		Pos[1] = iColumn;
	}

	for( int i = 0; i < iRows; ++i )
	{
		QStringList OneRecord = Records[i].split( '\t' );
		for( int j = 0; j < iColumns; ++j )
		{
			SetFormula( Pos[0] + i, Pos[1] + j, OneRecord[j] );
		}
	}
		
	
	SomethingChanged();
}

void CSpreadSheet::Del()
{
	QList<QTableWidgetItem*> items = selectedItems();
	if( !items.isEmpty() )
	{
		for( auto item : items )
		{
			delete item;
		}
	}

	return;
}

void CSpreadSheet::SelectCurrentRow()
{
	selectRow( currentRow() );
}

void CSpreadSheet::SelectCurrentColumn()
{
	selectColumn( currentColumn() );
}

//void CSpreadSheet::SelectAll()
//{
//	selectAll();
//}

void CSpreadSheet::Recalculate()
{
	for( int i = 0; i < eRowCount; ++i )
	{
		for( int j = 0; j < eColumnCount; ++ j )
		{
			if( Cell( i, j ) )
			{
				 Cell( i, j )->SetDirty();
			}
		}
	}

	viewport()->update();
}

void CSpreadSheet::SetAutoRecalculate( bool _b )
{
	m_bRecalc = _b;
	if( m_bRecalc )
	{
		Recalculate();
	}
}

void CSpreadSheet::FindNext( const QString &_str, Qt::CaseSensitivity _uorl )
{
	int iRow = currentRow();
	int iColumn = currentColumn();

	//for( int i = iRow; i < eRowCount; ++i )
	//{
	//	for( int j = iColumn; i < eColumnCount; ++j )
	//	{

	//	}


	//}

	while( iRow < eRowCount )
	{
		while( iColumn < eColumnCount )
		{
			if( Text( iRow, iColumn ).contains( _str, _uorl ) )
			{
				clearSelection();

				setCurrentCell( iRow, iColumn );
				activateWindow();
				
				return;
			}

			++iColumn;
		}

		iColumn = 0;

		++iRow;
	}


	QApplication::beep();
}

void CSpreadSheet::FindPrevious( const QString &_str, Qt::CaseSensitivity _uorl )
{
	int iRow = currentRow();
	int iColumn = currentColumn();

	while( iRow >= 0 )
	{
		while( iColumn >= 0 )
		{
			if( Text(iRow, iColumn).contains( _str, _uorl ) )
			{
				clearSelection();
				setCurrentCell( iRow, iColumn );
				activateWindow();

				return;
			}

			--iColumn;
		}
		iColumn = eColumnCount - 1;
		--iRow;
	}

	QApplication::beep();
}

void CSpreadSheet::Clear()
{
	setColumnCount( 0 );
	setRowCount( 0 );

	setColumnCount( eColumnCount );
	setRowCount( eRowCount );

	for( int i = 0; i < eColumnCount; ++i )
	{
		//QTableWidgetItem *pItem = item( 0, i );
		//pItem->setText( QString( QChar( 'A' + 1 ) ) );

		QTableWidgetItem *pItem = new QTableWidgetItem;
		pItem->setText( QString( QChar( 'A' + i ) ) );
		setHorizontalHeaderItem( i, pItem );
	}

}

void CSpreadSheet::SomethingChanged()
{
	if( m_bRecalc )
	{
		Recalculate();
	}

	emit Modified();
}




// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
bool CSpreadSheetCompare::operator()( const QStringList & _row_1, const QStringList & _row_2 ) const
{
	
	for( int i = 0; i < eKeys; ++i )
	{
		int iColumn = m_Keys[i];
		if( iColumn != -1 )
		{
			if( _row_1[iColumn] != _row_2[iColumn] )
			{
				if( m_bAscending[i] )
				{
					return _row_1[iColumn] < _row_2[iColumn];
				}
				else
				{
					return _row_1[iColumn] > _row_2[iColumn];
				}
			}
		}
	}
	
	return false; // 该两条记录的对应的三个键分别拥有相同的值，没有进行排序
}
