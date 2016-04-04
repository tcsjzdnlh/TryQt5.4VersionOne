#include "Cell.h"


CCell::CCell()
{
	SetDirty();
}

QTableWidgetItem* CCell::clone()
{
	return new CCell( *this );
}

QString CCell::Formula() const
{
	return Data( Qt::EditRole ).toString();
}

void CCell::SetFormula( const QString &_formula )
{
	SetData( Qt::EditRole, _formula );
}

void CCell::SetData( int _role, const QVariant &_data )
{
	QTableWidgetItem::setData( _role, _data );
	if( Qt::EditRole == _role )
	{
		SetDirty();
	}
}

QVariant CCell::Data( int _role ) const
{
	if( Qt::DisplayRole == _role )
	{
		// 如果是 display role 则  计算 并显示值(如果该值有效)
		if( Value().isValid() )
		{
			return Value().toString();
		}
		else
		{
			return "####";
		}
	}
	else if( Qt::TextAlignmentRole == _role )
	{
		// 如果 是 TextAlignmentRole 则 调整排版
		if( Value().type() == QVariant::String )
		{
			return int( Qt::AlignLeft | Qt::AlignVCenter );
		}
		else
		{
			return int( Qt::AlignRight | Qt::AlignVCenter );
		}
	}
	else
	{
		// 除以上 外 返回 单元格 公式
		return QTableWidgetItem::data( _role );
	}
}

void CCell::SetDirty()
{
	m_bIsDirty = true;
}

QVariant CCell::Value() const
{
	static const QVariant Invalid;

	if( m_bIsDirty )
	{
		m_bIsDirty = false;

		QString strFormula = Formula();
		if( strFormula[0] == '\'' )
		{
			m_CatchedData = strFormula.mid( 1 );
			return m_CatchedData;
		}
		else if( strFormula.startsWith( '=' ) )
		{
			strFormula = strFormula.mid( 1 );
			m_CatchedData = Invalid;
			strFormula.replace( " ", "" );
			strFormula.append( QChar::Null );

			int _pos = 0;
			m_CatchedData = EvalExpression( strFormula, _pos );
			if( strFormula[_pos] != QChar::Null )
			{
				m_CatchedData = Invalid;
			}
		}
		else
		{
			// 数字 or 字符串
			bool bRslt = false;
			double d = strFormula.toDouble( &bRslt );
			
			if( bRslt )
			{
				m_CatchedData = d;
			}
			else
			{
				m_CatchedData = strFormula;
			}
		}
	}

	return m_CatchedData;
}

QVariant CCell::EvalExpression( const QString & _expression, int &_pos ) const
{
	static const QVariant Invalid;

	QVariant result = EvalTerm( _expression, _pos );
	while( _expression[_pos] != QChar::Null ) 
	{
		QChar op = _expression[_pos];
		if( op != '+' && op != '-' )
			return result;
		++_pos;

		QVariant term = EvalTerm( _expression, _pos );
		if( result.type() == QVariant::Double
			&& term.type() == QVariant::Double )
		{
			if( op == '+' ) 
			{
				result = result.toDouble() + term.toDouble();
			}
			else 
			{
				result = result.toDouble() - term.toDouble();
			}
		}
		else 
		{
			result = Invalid;
		}
	}
	return result;
}

QVariant CCell::EvalTerm( const QString & _expression, int &_pos ) const
{
	static const QVariant Invalid;


	QVariant result = EvalFactor( _expression, _pos );
	while( _expression[_pos] != QChar::Null ) 
	{
		QChar op = _expression[_pos];
		if( op != '*' && op != '/' )
			return result;
		++_pos;

		QVariant factor = EvalFactor( _expression, _pos );
		if( result.type() == QVariant::Double
			&& factor.type() == QVariant::Double ) 
		{
			if( op == '*' ) 
			{
				result = result.toDouble() * factor.toDouble();
			}
			else 
			{
				if( factor.toDouble() == 0.0 )
				{
					result = Invalid;
				}
				else
				{
					result = result.toDouble() / factor.toDouble();
				}
			}
		}
		else 
		{
			result = Invalid;
		}
	}
	return result;
}

QVariant CCell::EvalFactor( const QString &_expression, int &_pos ) const
{
	static const QVariant Invalid;


	QVariant result;
	bool negative = false;

	if( _expression[_pos] == '-' ) 
	{
		negative = true;
		++_pos;
	}

	if( _expression[_pos] == '(' ) 
	{
		++_pos;
		result = EvalExpression( _expression, _pos );
		if( _expression[_pos] != ')' )
			result = Invalid;
		++_pos;
	}
	else 
	{
		QRegExp regExp( "[A-Za-z][1-9][0-9]{0,2}" );
		QString token;

		while( _expression[_pos].isLetterOrNumber() || _expression[_pos] == '.' ) 
		{
			token += _expression[_pos];
			++_pos;
		}

		if( regExp.exactMatch( token ) ) 
		{
			int column = token[0].toUpper().unicode() - 'A';
			int row = token.mid( 1 ).toInt() - 1;

			CCell *c = static_cast<CCell *>(
				tableWidget()->item( row, column ) );
			if( c ) 
			{
				result = c->Value();
			}
			else 
			{
				result = 0.0;
			}
		}
		else 
		{
			bool ok;
			result = token.toDouble( &ok );
			if( !ok )
				result = Invalid;
		}
	}

	if( negative ) 
	{
		if( result.type() == QVariant::Double ) 
		{
			result = -result.toDouble();
		}
		else 
		{
			result = Invalid;
		}
	}
	return result;
}
