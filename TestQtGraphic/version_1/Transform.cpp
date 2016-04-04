#include "Transform.h"
#include <QtGui/QTransform>
#include <QtGui/QPainter>
#include "MainWnd.h"

extern CMainWnd *g_pWnd;

CTransform::CTransform( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	resize( 400, 400 );
}

void CTransform::paintEvent( QPaintEvent *_pEvent )
{
	static QString strContext( "hello" );
	
	QPainter painter( this );

	QFont ft = font();
	ft.setPixelSize( 100 );
	ft.setBold( true );
	setFont( ft );


	QFontMetrics fm = QFontMetrics( ft );
	QRect rect = fm.boundingRect( strContext );

	g_pWnd->Log( QString( "draw rect is x = %1, y = %2, width = %3, height = %4" )
							.arg( rect.x() ).arg( rect.y() ).arg( rect.width() ).arg( rect.height() ) );



	QTransform trans;
	trans.translate( 100, 200 );
	//trans.rotate( +45.0 );
	trans.scale( 2, 2 );
	trans.shear( -1, 1 );
	painter.setTransform( trans );
	
	//painter.translate( 100, 200 );
	//painter.rotate( +45.0 );
	//painter.scale( 0.2, 0.2 );
	painter.setRenderHint( QPainter::RenderHint::Antialiasing );
	painter.drawText( rect, Qt::AlignCenter, strContext );


}
