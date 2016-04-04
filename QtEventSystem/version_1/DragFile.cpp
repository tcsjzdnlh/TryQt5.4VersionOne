#include "DragFile.h"

#include <QtWidgets/QTextEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include "Mainwnd.h"
#include <QtCore/QMimeData>
#include <QtCore/QList>
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDropEvent>
#include <QtCore/QUrl>

extern CMainWnd *g_pWnd;

CDragWnd::CDragWnd( QWidget *_pParent )
	:QWidget(_pParent)
{
	m_pText = new QTextEdit;

	QHBoxLayout *pLay_0 = new QHBoxLayout;
	pLay_0->addWidget( m_pText );
	setLayout( pLay_0 );
	
	m_pText->setAcceptDrops( false );
	this->setAcceptDrops( true );

	InitGeometry();
}

void CDragWnd::dragEnterEvent( QDragEnterEvent *_pEvent )
{
	if( _pEvent->mimeData()->hasFormat( QString("text/uri-list") ) )
	{
		_pEvent->acceptProposedAction();
	}
}

void CDragWnd::dropEvent( QDropEvent *_pEvent )
{
	QList<QUrl> files = _pEvent->mimeData()->urls();
	if( files.isEmpty() )
	{
		return;
	}
	QString strFileName = files.first().toLocalFile();
	if( strFileName.isEmpty() )
	{
		return;
	}
	
	ReadFile( strFileName );
	setWindowTitle( QString( "%1 - %2" ).arg( strFileName ).arg( tr( "Drag File" ) ) );

	//accept()
}

void CDragWnd::InitGeometry()
{
	int width = ( qApp->desktop()->width() / 3 ) - 50;
	int height = 9 * qApp->desktop()->height() / 10;

	int xPos = 2 * width;
	int yPos = 30;

	setGeometry( xPos, yPos, width, height );
}

bool CDragWnd::ReadFile( const QString &_fn )
{
	QString strContents;

	if( !_fn.isEmpty() )
	{
		QFile file( _fn );
		if( !file.open(QIODevice::ReadOnly))
		{
			g_pWnd->LogLeft( QString( "open file: %1 failed" ).arg( _fn ) );
			return false;
		}

		QTextStream in( &file );
		strContents = in.readAll();
	}
	
	m_pText->setText( strContents );

	return true;
}
