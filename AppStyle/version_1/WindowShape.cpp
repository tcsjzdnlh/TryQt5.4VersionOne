#include "WindowShape.h"

CWindowShape::CWindowShape( QWidget *_pParent /*= nullptr */ )
	:QWidget(_pParent)
{
	Init();
}

void CWindowShape::Init()
{	
	setWindowFlags( Qt::WindowType::FramelessWindowHint );
	
	setWindowOpacity( 1.0 );
	setAttribute( Qt::WidgetAttribute::WA_TranslucentBackground );
	
	setMouseTracking( true );
}
