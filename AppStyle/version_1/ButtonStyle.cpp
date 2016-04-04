#include "ButtonStyle.h"
#include <QtWidgets/QStyle>
#include <QtWidgets/QStyleOptionButton>
#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>
#include <QtWidgets/QStyleOptionFocusRect>

CFakeButton::CFakeButton( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	Init();
}

void CFakeButton::paintEvent( QPaintEvent *pEvent )
{
	QPainter painter( this );
	
	QStyleOptionButton option;
	option.initFrom( this );
	
	option.features |= QStyleOptionButton::Flat;
	option.text = "hello";
	

	QStyleOptionButton *pOption = qstyleoption_cast<QStyleOptionButton*>( &option );
	
	style()->drawControl( QStyle::ControlElement::CE_PushButton, &option, &painter, this );

	// ----------------
	//QStyleOptionFocusRect frOption( 1 );
}

void CFakeButton::Init()
{

}
