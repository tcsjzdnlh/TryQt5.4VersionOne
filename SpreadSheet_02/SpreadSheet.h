#ifndef _xfs_SpreadSheet_h_
#define _xfs_SpreadSheet_h_

#include <QtWidgets/QTableWidget>
#include <QtCore/Qt>

class CSpreadSheetCompare;

class CSpreadSheet : public QTableWidget
{
	Q_OBJECT
public:
	CSpreadSheet( QWidget *_pParent = nullptr );
	CSpreadSheet( int _r, int _c, QWidget *_pParent = nullptr );

public:
	QString CurrentLocation() const;
	QString CurrentFormula() const;

	bool ReadFile( const QString &_fn );
	bool WriteFile( const QString &_fn );
	
	bool AutoRecalculate() const;


	bool Sort( const CSpreadSheetCompare & _compare );

	QTableWidgetSelectionRange SelectedRange() const;


public slots:
	void Cut();
	void Copy();
	void Paste();
	void Del();

	void SelectCurrentRow();
	void SelectCurrentColumn();
	void SelectAll();
	
	void Recalculate();
	void SetAutoRecalculate( bool _b );

	void FindNext( const QString &_str, Qt::CaseSensitivity _uorl );
	void FindPrevious( const QString &_str, Qt::CaseSensitivity _uorl );

	// Signals are public access functions and can be emitted from anywhere, 
	// but we recommend to only emit them from the class that defines the signal and its subclasses
signals:
	void Modified();
	
	

private slots:
	void SomethingChanged();

private:
	bool		m_bRecalc;
};

class CSpreadSheetCompare
{
public:
	bool operator()( const QStringList & _row_1, const QStringList & _row_2 ) const;

	enum { KeyCount = 3 };
	int m_Keys[KeyCount];
	bool m_bAscending[KeyCount];
};


#endif