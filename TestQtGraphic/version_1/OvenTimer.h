#ifndef _xfs_OvenTimer_h_
#define _xfs_OvenTimer_h_

#include <QtWidgets/QWidget>
#include <QtCore/QDateTime>

class QTimer;

class COvenTimer : public QWidget
{
	Q_OBJECT

public:
	COvenTimer( QWidget *_pParent = nullptr );

public:
	void SetDuaration( int _iSeconds );
	int Duration() const;

signals:
	void TimeOver();

protected:
	void paintEvent( QPaintEvent *_pEvent );
	void mousePressEvent( QMouseEvent *_pEvent );

private:
	void Draw( QPainter *_pPainter );

private:
	QDateTime		m_FinishTime;

	QTimer			*m_pUpdateTimer;
	QTimer			*m_pFinishTimer;
};



#endif