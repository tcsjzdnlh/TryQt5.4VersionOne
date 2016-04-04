#ifndef _xfs_EventReceiver_h_
#define _xfs_EventReceiver_h_

#include <QtWidgets/QWidget>
class QLineEdit;

class CEventReceiver : public QWidget
{
	Q_OBJECT
public:
	CEventReceiver( QWidget *_pParent = nullptr );

//protected:
public:
	void Init();
	void InitGeometry();
	bool eventFilter( QObject *_pTarget, QEvent *_pEvent );


private:
	enum { eLECount = 3 };
	QLineEdit	*m_pLE[eLECount];
};


#endif