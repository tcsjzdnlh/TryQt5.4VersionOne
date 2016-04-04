#ifndef _xfs_WindowShape_h_
#define _xfs_WindowShape_h_

#include <QtWidgets/QWidget>

class CWindowShape : public QWidget
{
	Q_OBJECT
public:
	CWindowShape( QWidget *_pParent = nullptr );

private:
	void Init();
};


#endif