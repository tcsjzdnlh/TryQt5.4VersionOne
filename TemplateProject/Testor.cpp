#include "Testor.h"
#include "MainWnd.h"

CMainWnd		*g_pWnd = nullptr;

CTestor::CTestor()
{
	Init();
}
void CTestor::Init()
{
	g_pWnd = new CMainWnd;
	g_pWnd->show();
}

namespace test_event
{
	namespace event_flow
	{
		// �ȱ���QTԴ���ʱ���ڲ鿴
	}
	namespace qt_event_handler
	{

	}
}


void CTestor::Test()
{

}