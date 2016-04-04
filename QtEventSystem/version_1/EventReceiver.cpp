#include "EventReceiver.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include "MainWnd.h"
#include <QtGui/QKeyEvent>

extern CMainWnd *g_pWnd;

CEventReceiver::CEventReceiver( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	Init();
}

void CEventReceiver::Init()
{
	QVBoxLayout *pLay_0 = new QVBoxLayout;

	int i = eLECount;
	while( i != 0 )
	{
		--i;
		m_pLE[i] = new QLineEdit;
		m_pLE[i]->installEventFilter( this );

		pLay_0->addWidget( m_pLE[i] );
	}

	setLayout( pLay_0 );

	InitGeometry();
}

void CEventReceiver::InitGeometry()
{
	int iWidth = qApp->desktop()->width() / 5;
	int iHeight = qApp->desktop()->height() / 2;

	int xPos = 4 * iWidth - 100;
	int yPos = 50;

	setGeometry( xPos, yPos, iWidth, iHeight );
}

bool CEventReceiver::eventFilter( QObject *_pTarget, QEvent *_pEvent )
{
	int i = eLECount;
	
	while( i != 0 )
	{
		--i;
		if( _pTarget == m_pLE[i] )
		{
			if( _pEvent->type() == QEvent::KeyPress )
			{
				QKeyEvent *pKeyEvent = dynamic_cast<QKeyEvent*>( _pEvent );
				if( pKeyEvent->key() == Qt::Key_Space )
				{
					focusNextChild();
					g_pWnd->LogLeft( QString( "m_pLE[%1] has a Key_Space event ..." ).arg( i ) );
					return true;
				}				
			}			
		}
	}

	return QWidget::eventFilter( _pTarget, _pEvent );
}
