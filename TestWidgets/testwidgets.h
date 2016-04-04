#ifndef TESTWIDGETS_H
#define TESTWIDGETS_H

#include <QtWidgets/QWidget>
#include "ui_testwidgets.h"

class CTestWidgets : public QWidget
{
	Q_OBJECT

public:
	CTestWidgets(QWidget *parent = 0);
	~CTestWidgets();


public slots:
	void timeoutWork();


private:
	Ui::CTestWidgetsClass ui;
};

#endif // TESTWIDGETS_H
