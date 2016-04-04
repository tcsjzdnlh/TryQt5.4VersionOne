#include "TimerTicker.h"
#include <QtGui/QPainter>
#include <QtCore/QTimerEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>


CTimerTicker::CTimerTicker( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	m_offset = 0;
	m_TimerId = 0;

	int iWidth = qApp->desktop()->width() / 5;
	int iHeight = qApp->desktop()->height() / 2;

	int xPos = 4 * iWidth - 100;
	int yPos = 50;
	
	setGeometry( xPos, yPos, iWidth, iHeight );

	m_strText = "hello world !";
}

QString CTimerTicker::Text() const
{
	return m_strText;
}

void CTimerTicker::SetText( const QString &_strText )
{
	m_strText = _strText;

	update();
	updateGeometry();
}

QSize CTimerTicker::sizeHint() const
{
	return fontMetrics().size( 0, Text() );
}

void CTimerTicker::paintEvent( QPaintEvent *_pEvent )
{
	QPainter painter( this );

	int strWidth = fontMetrics().width( Text() );
	
	// 没有字符的情况
	if( strWidth < 1 ) return;
	
	int x = -m_offset;
	while( x < width() )
	{
		painter.drawText( x, 0, strWidth, height(), Qt::AlignLeft | Qt::AlignVCenter, m_strText );

		x += strWidth;
	}

}

void CTimerTicker::timerEvent( QTimerEvent *_pEvent )
{
	if( _pEvent->timerId() == m_TimerId )
	{
		++m_offset;
		if( m_offset > fontMetrics().width( Text() ) ) 
		{
			m_offset = 0;
		}
		
		update();
		//scroll( -1, 0 );
	}
	else
	{
		QWidget::timerEvent( _pEvent );
	}
}

void CTimerTicker::showEvent( QShowEvent *_pEvent )
{
	m_TimerId = startTimer( 30 );
}

void CTimerTicker::hideEvent( QHideEvent *_pEvent )
{
	killTimer( m_TimerId );
}
