#include "MainWnd.h"

#include <QtWidgets/QTextEdit>
#include <QtGui/QIcon>

CMainWnd::CMainWnd( QWidget *_pParent )
	:QSplitter( _pParent )
{
	setOrientation( Qt::Horizontal );
		
	setWindowTitle( tr( "Logger" ) );
	setWindowIcon( QIcon( ":/window/images/window.ico" ) );

	m_pLogger = new QTextEdit;
	//m_pLogger->setFocus( Qt::FocusReason::OtherFocusReason );
	
	addWidget( new QTextEdit );
	addWidget( m_pLogger );

	setStretchFactor( 1, 1 );


	Log( tr( "main window initialized ... " ) );
}

void CMainWnd::Log( const QString &_strContents )
{
	static QString strLogs( "starting logs ... \n" );

	strLogs += _strContents;

	if( !strLogs.endsWith("\n") )
	{
		strLogs += "\n";
	}

	m_pLogger->setText( strLogs );

}