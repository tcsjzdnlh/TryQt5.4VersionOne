#ifndef _xfs_BindEventWithQShortcutQAction_h_
#define _xfs_BindEventWithQShortcutQAction_h_

#include <QtWidgets/QMainWindow>


class QTextEdit;
class QAction;


class CWidget : public QMainWindow
{
	Q_OBJECT
public:
	CWidget( QWidget *_pParent = nullptr );

public slots :
	void MoveScroll();

private:
	QAction		*m_pMoveScroll;
	QTextEdit	*m_pCentral;
};



#endif