#include "testwidgets.h"
#include <QtWidgets/QMessageBox>

CTestWidgets::CTestWidgets(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CTestWidgets::~CTestWidgets()
{

}

void CTestWidgets::timeoutWork()
{
	QMessageBox::information( this, tr( "timeout signal triggered !" ), 
		tr( "timeout signal triggered !" ) );
}
