#ifndef _xfs_FirstStyleSheet_h_
#define _xfs_FirstStyleSheet_h_

#include <QtWidgets/QDialog>

class QPushButton;

class CFirstStyleSheet : public QDialog
{
	Q_OBJECT
public:
	CFirstStyleSheet( QWidget *_pParent = nullptr );
	QPushButton* GetBtn() const;


private:
	void Init();
	void InitFirst();
	void InitSecond();

private:
	QPushButton				*m_pBtn;

};


#endif