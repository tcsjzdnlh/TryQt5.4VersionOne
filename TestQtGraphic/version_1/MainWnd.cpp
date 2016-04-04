#include "MainWnd.h"

#include <QtWidgets/QTextEdit>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QMessageBox>
#include <QtGui/QFont>

CMainWnd::CMainWnd( QWidget *_pParent )
	:QSplitter( _pParent )
{
	setOrientation( Qt::Horizontal );

	QFont newFont = font();
	newFont.setPixelSize( 25 );
	setFont( newFont );
		
	setWindowTitle( tr( "Logger" ) );
	setWindowIcon( QIcon( ":/window/images/window.ico" ) );

	m_pRightLogger = new QTextEdit;
	m_pLeftLogger = new QTextEdit;

	m_pRightLogger->setObjectName( tr( "m_pRightLogger" ) );
	m_pLeftLogger->setObjectName( tr( "m_pLeftLogger" ) );
	//m_pLogger->setFocus( Qt::FocusReason::OtherFocusReason );

	//connect( m_pLeftLogger, SIGNAL( textChanged() ), SLOT( MoveScrollToBottom() ) );
	//connect( m_pRightLogger, SIGNAL( textChanged() ), SLOT( MoveScrollToBottom() ) );
	
	addWidget( m_pLeftLogger );
	addWidget( m_pRightLogger );

	setStretchFactor( 1, 1 );


	QAction *pClear = new QAction( QObject::tr( "clear all the logs" ), this );
	connect( pClear, SIGNAL( triggered() ), m_pRightLogger, SLOT( clear() ) );
	connect( pClear, SIGNAL( triggered() ), this, SLOT( ClearLog() ) );
	
	QMenuBar *pMenuBar = new QMenuBar( this );
	pMenuBar->addMenu( tr( "&File" ) )->addAction( pClear );

	connect( this, SIGNAL( XfsCloseWnd() ), qApp, SLOT( quit() ) );


	Log( tr( "main window initialized ... " ) );
}

void CMainWnd::SetEventsMap( const EventMaps &_events )
{
	m_events = _events;
}

QString CMainWnd::CurrentEvent( int _type ) const
{	
	return m_events.value( _type );	
}

CMainWnd* CMainWnd::Log( const QString &_strContents )
{
	return LogRight( _strContents );
}

CMainWnd* CMainWnd::LogLeft( const QString &_strContents )
{
	static QString strLogs( "starting logs ... \n" );

	strLogs += _strContents;

	if( !strLogs.endsWith( "\n" ) )
	{
		strLogs += "\n";
	}

	m_pLeftLogger->setText( strLogs );

	m_pLeftLogger->verticalScrollBar()->triggerAction( QAbstractSlider::SliderToMaximum );

	return this;
}

CMainWnd* CMainWnd::LogRight( const QString &_strContents )
{	
	if( m_strLogs.isEmpty() )
	{
		m_strLogs += "starting logs ... \n";
	}

	m_strLogs += _strContents;

	if( !m_strLogs.endsWith( "\n" ) )
	{
		m_strLogs += "\n";
	}

	m_pRightLogger->setText( m_strLogs );
	
	// 两种方法都可以
	m_pRightLogger->verticalScrollBar()->setValue( m_pRightLogger->verticalScrollBar()->maximum() );
	//m_pRightLogger->verticalScrollBar()->triggerAction( QAbstractSlider::SliderToMaximum );
	
	
	return this;
}

void CMainWnd::LogAllEvents()
{	
	LogAllEvents( m_events );
}

void CMainWnd::LogAllEvents( const EventMaps &_events )
{
	QString strText("all events : \n\n");
	QMapIterator<int, QString> iter( _events );
	
	while( iter.hasNext() )
	{
		iter.next();
		strText += QString( "key: % 1, value : % 2 \n" ).arg( iter.key() ).arg( iter.value() );
	}
	LogLeft( strText );
}

//void CMainWnd::XfsCloseWnd()
//{
//
//}

void CMainWnd::closeEvent( QCloseEvent* _event )
{
	emit XfsCloseWnd();
	QSplitter::closeEvent( _event );
}

void CMainWnd::ClearLog()
{
	m_strLogs.clear();
}

void CMainWnd::MoveScrollToBottom()
{
	QString strWho( "initial none" );
	
	QTextEdit *pSender = qobject_cast<QTextEdit*>( sender() );
	//QTextEdit *pSender = static_cast<QTextEdit*>( sender() );
	//QTextEdit *pSender = dynamic_cast<QTextEdit*>( sender() );

	if( pSender != nullptr )
	{	
		if( pSender == m_pRightLogger )
		{
			strWho = "m_pRightLogger got a signal";
		}
		else if( pSender == m_pLeftLogger )
		{
			strWho = "m_pLeftLogger got a signal";
		}
		else
		{
			strWho = "pSend is none of left or right logger";
		}
	}

	strWho += QString( " the sender object name is : %1" ).arg( pSender->objectName() );

	LogLeft( strWho );

	//QMessageBox::information( nullptr, tr( "title" ), pSender->objectName() );
	//QMessageBox::information( this, tr( "title" ), strWho, QMessageBox::Ok );


	// 总是不行, 放在其他地方就起作用了
	//pSender->verticalScrollBar()->setValue( pSender->verticalScrollBar()->maximum() );
	//pSender->verticalScrollBar()->triggerAction( QAbstractSlider::SliderToMaximum );	
}
