#include "DiagramMainWnd.h"
#include "GraphicsNode.h"
#include "Link.h"
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtCore/QTime>


CDiagramMainWnd::CDiagramMainWnd( QWidget *_pParent /*= nullptr */ )
	:QGraphicsView( _pParent )
{
	Init();
}

void CDiagramMainWnd::AddNode()
{
	CGraphicsNode *pNode = new CGraphicsNode;
	pNode->SetContext( QString( "node %1" ).arg( m_iNumber + 1 ) );

	SetupNode( pNode );

}

void CDiagramMainWnd::AddLink()
{
	NodePair linkEnds = SelectedNodePair();
	if( linkEnds == NodePair() ) return;
	
	CLink *pLink = new CLink( linkEnds.first, linkEnds.second );
	m_pScene->addItem( pLink );
}

void CDiagramMainWnd::BringToFront()
{
	++m_maxZValue;
	SetZValue( m_maxZValue );
}

void CDiagramMainWnd::SendToBack()
{

}

void CDiagramMainWnd::Properties()
{

}

void CDiagramMainWnd::Cut()
{


}

void CDiagramMainWnd::Copy()
{

}

void CDiagramMainWnd::Paste()
{

}

void CDiagramMainWnd::Del()
{

}

void CDiagramMainWnd::UpdateActions()
{

}

void CDiagramMainWnd::Init()
{		
	//m_pScene = new QGraphicsScene( this );
	m_pScene = new QGraphicsScene( 0, 0, 600, 500 );
	setScene( m_pScene );
	setDragMode( QGraphicsView::DragMode::RubberBandDrag );
	setRenderHints( QPainter::Antialiasing | QPainter::TextAntialiasing );
	setContextMenuPolicy( Qt::ActionsContextMenu );

	m_iNumber = 0;
	m_minZValue = 0;
	m_maxZValue = 0;


	CreateActions();
	CreateMenus();
	CreateToolBars();

	//AddNode();
	//AddNode();

	for( int i = 0; i < 5000; ++i )
	{
		AddNode();
	}
}

void CDiagramMainWnd::SetupNode( CGraphicsNode *_pNode )
{
	//_pNode->setPos( 80 + 100 * ( m_iNumber % 5 ), 
	//				80 + 50  * ( m_iNumber / 5 ) % 7 );


	const int Margin = 80;
	qsrand( QTime::currentTime().msec() );
	_pNode->setPos( Margin + qrand() % 600, Margin + qrand() % 500 );


	m_pScene->addItem( _pNode );
	m_pScene->clearSelection();
	_pNode->setSelected( true );
	
	BringToFront();

	++m_iNumber;	
}

void CDiagramMainWnd::SetZValue( int _z )
{
	CGraphicsNode *pNode =SelectedNode();
	if( pNode )
	{
		pNode->setZValue( _z );
	}
}

CGraphicsNode* CDiagramMainWnd::SelectedNode()
{
	QList<QGraphicsItem*> nodes = m_pScene->selectedItems();

	if( /*!nodes.isEmpty()*/ 1 == nodes.count() )
	{
		return dynamic_cast<CGraphicsNode*>( nodes.first() );
	}

	return nullptr;
}

CLink* CDiagramMainWnd::SelectedLink() const
{
	return nullptr;
}

CDiagramMainWnd::NodePair CDiagramMainWnd::SelectedNodePair() const
{
	QList<QGraphicsItem*> nodes = m_pScene->selectedItems();

	if( nodes.count() == 2 )
	{
		CGraphicsNode *pFirst = dynamic_cast<CGraphicsNode*>( nodes.first());
		CGraphicsNode *pLast = dynamic_cast<CGraphicsNode*>( nodes.last() );

		if( pFirst && pLast )
		{
			return NodePair( pFirst, pLast );
		}
	}
	
	return NodePair();
}

void CDiagramMainWnd::CreateActions()
{
//#define ToString( exp ) #exp
//#define ToStringMedia( exp ) ToString( exp )
//	EActions e = eCopy;
//	while( e < eDel )
//	{
//		m_pActions[e] = new QAction( tr( ToString( e )), this );
//	}


	m_pAddNode = new QAction( tr( "New Node" ), this );
	m_pAddNode->setShortcut( QKeySequence::New );
	connect( m_pAddNode, SIGNAL( triggered() ), this, SLOT( AddNode() ) );

	m_pAddLink = new QAction( tr( "New Link" ), this );
	//m_pAddLink->setShortcut(tr(""))
	connect( m_pAddLink, SIGNAL( triggered() ), this, SLOT( AddLink() ) );


	m_pCutAction = new QAction( tr( "Cut" ), this );
	m_pCutAction->setShortcut( QKeySequence::Cut );
	connect( m_pCutAction, SIGNAL( triggered() ), this, SLOT( Cut() ) );

	m_pCopyAction = new QAction( tr( "Copy" ), this );
	m_pCopyAction->setShortcut( QKeySequence::Copy );
	connect( m_pCopyAction, SIGNAL( triggered() ), this, SLOT( Copy() ) );

	m_pPasteAction = new QAction( tr( "Paste" ), this );
	m_pPasteAction->setShortcut( QKeySequence::Paste );
	connect( m_pPasteAction, SIGNAL( triggered() ), this, SLOT( Paste() ) );

	m_pDelAction = new QAction( tr( "Del" ), this );
	m_pDelAction->setShortcut( QKeySequence::Delete );
	connect( m_pDelAction, SIGNAL( triggered() ), this, SLOT( Del() ) );


	addAction( m_pAddNode );
	addAction( m_pAddLink );
	addAction( m_pCutAction );
	addAction( m_pCopyAction );
	addAction( m_pPasteAction );
	addAction( m_pDelAction );
}

void CDiagramMainWnd::CreateMenus()
{
	m_pMenuBar = new QMenuBar( this );
	QMenu *pFileMenu = m_pMenuBar->addMenu( tr( "File" ) );
	QMenu *pEditMenu = m_pMenuBar->addMenu( tr( "Edit" ) );

	pFileMenu->addAction( m_pAddNode );
	pFileMenu->addAction( m_pAddLink );

	pEditMenu->addAction( m_pCutAction );
	pEditMenu->addAction( m_pCopyAction );
	pEditMenu->addAction( m_pPasteAction );
	pEditMenu->addAction( m_pDelAction );
}

void CDiagramMainWnd::CreateToolBars()
{
	//QToolBar *pEditToolBar = new QToolBar( this );
	//pEditToolBar->addAction( m_pCutAction );
	//pEditToolBar->addAction( m_pCopyAction );
	//pEditToolBar->addAction( m_pPasteAction );
	//pEditToolBar->addAction( m_pDelAction );

	
}
