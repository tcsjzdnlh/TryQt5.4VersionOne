#include "SpreadSheet.h"

CSpreadSheet::CSpreadSheet( QWidget *_pParent )
	:QTableWidget( _pParent )
{

}

CSpreadSheet::CSpreadSheet( int _r, int _c, QWidget *_pParent /*= nullptr */ )
	: QTableWidget( _r, _c, _pParent )
{

}

QString CSpreadSheet::CurrentLocation() const
{
	return QString(tr("Current Location"));
}

QString CSpreadSheet::CurrentFormula() const
{
	return QString(tr("Current Formula"));
}

bool CSpreadSheet::ReadFile( const QString &_fn )
{
	return true;
}

bool CSpreadSheet::WriteFile( const QString &_fn )
{
	return true;
}

bool CSpreadSheet::AutoRecalculate() const
{
	return m_bRecalc;
}

bool CSpreadSheet::Sort( const CSpreadSheetCompare & _compare )
{
	return false;
}

QTableWidgetSelectionRange CSpreadSheet::SelectedRange() const
{
	return QTableWidgetSelectionRange();
}

void CSpreadSheet::Cut()
{

}

void CSpreadSheet::Copy()
{

}

void CSpreadSheet::Paste()
{

}

void CSpreadSheet::Del()
{

}

void CSpreadSheet::SelectCurrentRow()
{

}

void CSpreadSheet::SelectCurrentColumn()
{

}

void CSpreadSheet::SelectAll()
{

}

void CSpreadSheet::Recalculate()
{

}

void CSpreadSheet::SetAutoRecalculate( bool _b )
{
	m_bRecalc = _b;
}

void CSpreadSheet::FindNext( const QString &_str, Qt::CaseSensitivity _uorl )
{

}

void CSpreadSheet::FindPrevious( const QString &_str, Qt::CaseSensitivity _uorl )
{

}

void CSpreadSheet::SomethingChanged()
{

}




// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
bool CSpreadSheetCompare::operator()( const QStringList & _row_1, const QStringList & _row_2 ) const
{
	return true;
}
