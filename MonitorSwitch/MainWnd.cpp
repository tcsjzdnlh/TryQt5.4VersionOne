#include "MainWnd.h"

CMainWnd::CMainWnd( QWidget *_pParent /*= nullptr */ )
	:QMainWindow( _pParent )
{
	setCentralWidget( &m_logWnd );
}
