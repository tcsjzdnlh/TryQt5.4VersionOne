#ifndef _xfs_ButtonStyle_h_
#define _xfs_ButtonStyle_h_

#include <QtWidgets/QWidget>

class CFakeButton : public QWidget
{
	Q_OBJECT
public:
	CFakeButton( QWidget *_pParent = nullptr );

protected:
	void paintEvent( QPaintEvent *pEvent );

private:
	void Init();
};


#endif