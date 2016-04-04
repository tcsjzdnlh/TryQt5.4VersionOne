#ifndef _xfs_StyleWidgets_h_
#define _xfs_StyleWidgets_h_

#include <QtWidgets/QWidget>

class QVBoxLayout;

class CStyleWidgets : public QWidget
{
	Q_OBJECT
public:
	CStyleWidgets( QWidget *_pParent = nullptr );

private:
	void Init();
	void SetStyleSheet( const QString &_strFN );
private:
	void InitComboBox();

private:
	QVBoxLayout				*m_pLay_0;

};



#endif