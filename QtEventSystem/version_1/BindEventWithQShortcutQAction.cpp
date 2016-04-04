#include "BindEventWithQShortcutQAction.h"
#include <QtWidgets/QAction>
#include <QtWidgets/QShortcut>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QScrollBar>
#include <QtCore/QChar>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QApplication>

CWidget::CWidget( QWidget *_pParent /*= nullptr */ )
	:QMainWindow( _pParent )
{
	m_pCentral = new QTextEdit;
	setCentralWidget( m_pCentral );

	// QAction bind event handler
	m_pMoveScroll = new QAction( tr( "move scroll" ), this );
	//m_pMoveScroll->setShortcut( tr( "End" ) );
	//connect( m_pMoveScroll, SIGNAL( activated() ), this, SLOT( MoveScroll() ) );
	connect( m_pMoveScroll, SIGNAL( triggered() ), this, SLOT( MoveScroll() ) );
	//connect( m_pCentral, SIGNAL( textChanged() ), this, SLOT( MoveScroll() ) );

	menuBar()->addMenu( tr( "&File" ) )->addAction( m_pMoveScroll );



	// QShortcut bind event handler
	QShortcut *pEnd = new QShortcut( tr("F6")/*QKeySequence::MoveToEndOfDocument*/, this );
	connect( pEnd, SIGNAL( activated() ), this, SLOT(MoveScroll()) );




	QString strText( 9999, QChar( 65u ) );
	m_pCentral->setText( strText );



	int xPos = qApp->desktop()->width() / 5;
	int yPos = 50;
	setGeometry( 4 * xPos - 30, yPos, xPos, qApp->desktop()->height() - 100 );
}

void CWidget::MoveScroll()
{
	m_pCentral->verticalScrollBar()->setValue( m_pCentral->verticalScrollBar()->maximum() );
}