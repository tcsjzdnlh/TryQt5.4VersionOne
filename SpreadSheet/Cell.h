#ifndef _xfs_Cell_h_
#define _xfs_Cell_h_

#include <QtWidgets/QTableWidgetItem>
#include <QtCore/QVariant>

class CCell : public QTableWidgetItem
{
public:
	CCell();
public:
	QTableWidgetItem* clone();

	QString Formula() const;
	void SetFormula( const QString &_formula );

	void SetDirty();

private:
	void SetData( int _role, const QVariant &_data );
	QVariant Data( int _role ) const;

	

private:
	QVariant Value() const;

private:
	QVariant EvalExpression( const QString & _expression, int &_pos ) const;
	QVariant EvalTerm( const QString & _expression, int &_pos ) const;
	QVariant EvalFactor( const QString &_expression, int &_pos ) const;

private:
	mutable QVariant		m_CatchedData;
	mutable bool			m_bIsDirty;


};



#endif