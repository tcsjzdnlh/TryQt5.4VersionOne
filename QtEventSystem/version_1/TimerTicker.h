#ifndef _xfs_TimerTicker_h_
#define _xfs_TimerTicker_h_

#include <QtCore/QTimer>
#include <QtWidgets/QWidget>


class CTimerTicker : public QWidget
{
	Q_OBJECT
	Q_PROPERTY( QString strText READ Text WRITE SetText )
public:
	CTimerTicker( QWidget *_pParent = nullptr );

	QString Text() const;
	void SetText( const QString &_strText );

public:
	QSize sizeHint() const;

protected:
	void paintEvent( QPaintEvent *_pEvent );
	void timerEvent( QTimerEvent *_pEvent );
	void showEvent( QShowEvent *_pEvent );
	void hideEvent( QHideEvent *_pEvent );


private:
	QString		m_strText;
	int			m_TimerId;
	int			m_offset;
};

#endif