#ifndef _xfs_FindDialog_h_
#define _xfs_FindDialog_h_

#include <QtWidgets/QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
class QCheckBox;


class CFindDialog : public QDialog
{
	Q_OBJECT
public:
	CFindDialog( QWidget *_pParent = nullptr );

private:
	QLabel		*m_pFindLabel;
	QLineEdit	*m_pFind;
	
	QCheckBox	*m_pCase;
	QCheckBox	*m_pFindBack;

	QPushButton	*m_pOk;
	QPushButton	*m_pCancel;

};



#endif