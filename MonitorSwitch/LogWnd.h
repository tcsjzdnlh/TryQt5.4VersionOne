#ifndef _xfs_LogWnd_h_
#define _xfs_LogWnd_h_
#include <QtWidgets/QTextEdit>


class CLogWnd : public QTextEdit
{
	Q_OBJECT
public:
	CLogWnd( QWidget *_pParent = nullptr );

public:
	void Debug();
};




#endif