#include "ProjectListWidget.h"
#include <QtGui/QMouseEvent>
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDropEvent>
#include <QtWidgets/QApplication>
#include <QtCore/QMimeData>
#include <QtGui/QDrag>
#include <QtGui/QPixMap>

CProjectListWidget::CProjectListWidget( QWidget *_pParent /*= nullptr */ )
	:QListWidget(_pParent)
{
	setAcceptDrops( true );
}

void CProjectListWidget::mousePressEvent( QMouseEvent *_pEvent )
{
	if( _pEvent->button() == Qt::LeftButton )
	{
		m_StartPos = _pEvent->pos();
	}

	QListWidget::mousePressEvent( _pEvent );
}

void CProjectListWidget::mouseMoveEvent( QMouseEvent *_pEvent )
{
	if( _pEvent->buttons() & Qt::LeftButton )
	{
		int idistance = ( _pEvent->pos() - m_StartPos ).manhattanLength();
		if( idistance >= QApplication::startDragDistance() )
		{
			StartDrag();
		}
	}
	
	QListWidget::mouseMoveEvent( _pEvent );
}

void CProjectListWidget::dragEnterEvent( QDragEnterEvent *_pEvent )
{
	CProjectListWidget *pWidget = qobject_cast<decltype( pWidget )>( _pEvent->source() );
	if( pWidget && pWidget != this )
	{
		//_pEvent->setDropAction( Qt::MoveAction );
		_pEvent->accept();
	}
}

void CProjectListWidget::dragMoveEvent( QDragMoveEvent *_pEvent )
{
	CProjectListWidget *pWidget = qobject_cast<decltype( pWidget )>( _pEvent->source() );
	if( pWidget && pWidget != this )
	{
		//_pEvent->setDropAction( Qt::MoveAction );
		_pEvent->accept();
	}
}

void CProjectListWidget::dropEvent( QDropEvent *_pEvent )
{
	decltype( this ) pWidget = qobject_cast<decltype( pWidget )>( _pEvent->source() );
	if( pWidget && pWidget != this )
	{
		
		
		addItem( _pEvent->mimeData()->text() );

		_pEvent->setDropAction( /*Qt::MoveAction*/ Qt::LinkAction );
		_pEvent->accept();
	}
}

void CProjectListWidget::StartDrag()
{
	QListWidgetItem *pItem = currentItem();
	if( nullptr != pItem )
	{
		QMimeData *pData = new QMimeData;
		pData->setText( pItem->text() );
		
		// The QDrag must be constructed on the heap with a parent QObject to ensure that 
		// Qt can clean up after the drag and drop operation has been completed.
		QDrag *pDrag = new QDrag( this );
		pDrag->setMimeData( pData );
		pDrag->setPixmap( QPixmap( ":/images/person.png" ) );

		if( pDrag->exec(Qt::MoveAction /*Qt::CopyAction*/ ) == Qt::MoveAction )
		{
			delete pItem;
		}
	}
}
