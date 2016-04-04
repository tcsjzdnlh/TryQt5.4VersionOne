#include "MainWnd.h"
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include <Qtcore/QString>

CMainWnd::CMainWnd( QWidget *_pParent /* = nullptr */ )
	:QMainWindow( _pParent )
{
	QSplitter *pCentral = new QSplitter( Qt::Horizontal );	
	setCentralWidget( pCentral );


	m_pControl = new QWidget;
	m_pLogger = new QTextEdit;



	//QSizePolicy policy;
	//policy.setHorizontalStretch( 0 );
	//policy.setVerticalStretch( 0 );
	//m_pControl->setSizePolicy( policy );


	pCentral->addWidget( m_pControl );
	pCentral->addWidget( m_pLogger );



	//pCentral->setStretchFactor( 0, 0 );
	pCentral->setStretchFactor( 1, 1 );
}

QTextEdit* CMainWnd::Logger() const
{
	return m_pLogger;
}

void CMainWnd::Log( const QString &_strContents )
{
	// 暂时不支持多线程
	static QString logs("start logs !\n");
	
	QString strNewContent = _strContents;
	
	if( !strNewContent.endsWith( "\n" ) )
	{
		strNewContent.append( "\n" );
	}
	
	logs += strNewContent;

	m_pLogger->setText( logs );
}
