#ifndef _xfs_WidgetsStyle_h_
#define _xfs_WidgetsStyle_h_

#include <QtWidgets/QWidget>
class QVBoxLayout;
class QStyle;

class CWidgetsStyle : public QWidget
{
	Q_OBJECT
public:
	CWidgetsStyle( QWidget *_pParent = nullptr );

private:
	void Init();
	
private:
	void StyleSlider();
	void StyleGroupBox();


private:
	QWidget			*m_pWidget;
	QVBoxLayout		*m_pLay;

	QStyle			*m_pStyle;
};

#endif