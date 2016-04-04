#include "DragItemDialog.h"
#include <QtGui/QMouseEvent>
#include "MainWnd.h"


extern CMainWnd		*g_pWnd;

CDragItemDialog::CDragItemDialog( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	setupUi( this );

	InitListItem();
}

void CDragItemDialog::InitListItem()
{
	m_pAListItem->addItem( "Giosue Carducci" );
	m_pAListItem->addItem( "Eyvind Johnson" );
	m_pAListItem->addItem( "Sally Prudhomme" );
	m_pAListItem->addItem( "Henryk Sienkiewicz" );
	m_pAListItem->addItem( "Carl Spitteler" );
	m_pAListItem->addItem( "Rabindranath Tagore" );
	m_pAListItem->addItem( "Kawabata Yasunari" );

	m_pBListItem->addItem( "Rudolf Eucken" );
	m_pBListItem->addItem( "Anatole France" );
	m_pBListItem->addItem( "Rudyard Kipling" );
	m_pBListItem->addItem( "Thomas Mann" );
	m_pBListItem->addItem( "Eugene O'Neill" );
	m_pBListItem->addItem( "Sigrid Undset" );
}

void CDragItemDialog::on_m_pLeftBtn_clicked()
{
	MoveCurrentItem( m_pBListItem, m_pAListItem );
}

void CDragItemDialog::on_m_pRightBtn_clicked()
{
	MoveCurrentItem( m_pAListItem, m_pBListItem );
}

void CDragItemDialog::MoveCurrentItem( QListWidget *_pSource, QListWidget *_pTarget )
{
	if( _pSource->currentItem() )
	{
		auto pItem = _pSource->currentItem()->clone();
		_pTarget->addItem( pItem );
		_pTarget->setCurrentItem( pItem );

		delete _pSource->currentItem();
	}
}

void CDragItemDialog::mousePressEvent( QMouseEvent *_pEvent )
{
	if( _pEvent->button() == Qt::LeftButton )
	{
		// 若想要这种 main board窗口 探测到 child widget 是否 被 点击，
		// 则不能重新实现child widget的 mousePressEvent 事件处理函数
		if( m_pALabel->underMouse() )
		{
			g_pWnd->Log( "mouse pressed in child widget : m_pAListItem" );
		}
	}

	QDialog::mousePressEvent( _pEvent );
}
