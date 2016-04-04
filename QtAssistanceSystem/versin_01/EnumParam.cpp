#include "EnumParam.h"
#include <iostream>
#include "MainWnd.h"

extern CMainWnd *g_pWnd;
void CEnumParam::Days( EAxisIds _e )
{
	//std::cout << __FUNCSIG__ << std::endl;
	g_pWnd->Log( __FUNCSIG__ );
}
