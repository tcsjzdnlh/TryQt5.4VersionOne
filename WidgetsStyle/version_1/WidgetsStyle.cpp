#include "WidgetsStyle.h"
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include "MainWnd.h"
#include <QtWidgets/QStyleOptionSlider>
#include "ArthurStyle.h"
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGroupBox>

#include "XfsStyle.h"

extern CMainWnd *g_pWnd;

CWidgetsStyle::CWidgetsStyle( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	Init();
}

void CWidgetsStyle::Init()
{
	m_pStyle = new CXfsStyle;
	QPalette plt = m_pStyle->standardPalette();
	//m_pStyle = new ArthurStyle;
	
	setMinimumSize( 400, 300 );
	m_pLay = new QVBoxLayout;
	setLayout( m_pLay );

	StyleSlider();
	StyleGroupBox();
}

void CWidgetsStyle::StyleSlider()
{
	QFrame frame;
	QPushButton btn;
	QLabel  label;

	// -----------------------
	QSlider *pSlider = new QSlider;
	pSlider->setRange( 0, 100 );
	pSlider->setOrientation( Qt::Orientation::Horizontal );
	//pSlider->setLayoutDirection( Qt::LayoutDirection::LeftToRight );

	m_pLay->addWidget( pSlider );
		
	pSlider->setStyle( m_pStyle );
	//pSlider->setAttribute( Qt::WidgetAttribute::WA_Hover );
	//const QStyleOptionSlider *pStyle = qstyleoption_cast<const QStyleOptionSlider*>( pSlider->style());

}

void CWidgetsStyle::StyleGroupBox()
{
	QGroupBox *pGrpBx = new QGroupBox;
	m_pLay->addWidget( pGrpBx );

	pGrpBx->setTitle( "hello" );
	pGrpBx->setCheckable( true );
	//pGrpBx->setFlat( true );
	pGrpBx->setStyle( m_pStyle );	
}
