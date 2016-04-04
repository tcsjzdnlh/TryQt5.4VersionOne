#ifndef _xfs_Transform_h_
#define _xfs_Transform_h_

#include <QtWidgets/QWidget>

class CTransform : public QWidget
{
	Q_OBJECT
public:
	CTransform( QWidget *_pParent = nullptr );

protected:

	// When the paintdevice is a widget, 
	// QPainter can only be used inside a paintEvent() function 
	// or in a function called by paintEvent().
	void paintEvent( QPaintEvent *_pEvent );
};



#endif