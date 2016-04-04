#include "TrackItemDelegate.h"
#include <QtWidgets/QTimeEdit>

CTrackItemDelegate::CTrackItemDelegate( int _column, QObject *_pParent /*= nullptr */ )
	:QItemDelegate(_pParent), m_column(_column)
{

}

QWidget* CTrackItemDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	QWidget * pEditor = nullptr;

	if( index.column() == m_column )
	{		
		if( index.column() == m_column )
		{
			QTimeEdit *pTimeEditor = new QTimeEdit( parent );
			pTimeEditor->setDisplayFormat( tr( "mm:ss" ) );
			connect( pTimeEditor, SIGNAL( editingFinished() ), this, SLOT( commitDataAndcloseEditor() ) );


			pEditor = static_cast<QWidget*>( pTimeEditor );
		}
	}
	else
	{
		pEditor = QItemDelegate::createEditor( parent, option, index );
	}

	return pEditor;
}

void CTrackItemDelegate::setEditorData( QWidget *editor, const QModelIndex &index ) const
{
	if( index.column() == m_column )
	{
		int seconds = index.data().toInt();

		QTimeEdit *pTimeEditor = qobject_cast<QTimeEdit*>( editor );
		pTimeEditor->setTime( QTime( 0, seconds / 60, seconds % 60 ) );
	}
	else
	{
		QItemDelegate::setEditorData( editor, index );
	}
}

void CTrackItemDelegate::setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
	if( index.column() == m_column )
	{
		QTimeEdit *pTimeEditor = qobject_cast<QTimeEdit*>( editor );
		QTime duration = pTimeEditor->time();
		int seconds = duration.minute() * 60 + duration.second();

		model->setData( index, QVariant( seconds ) );
	}
	else
	{
		QItemDelegate::setModelData( editor, model, index );
	}
}

void CTrackItemDelegate::paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	if( index.column() == m_column )
	{
		int seconds = index.data().toInt();
		
		QString strDuration = QString( "%1:%2" ).arg( seconds / 60, 2, 10, QChar( '0' ) )
												.arg( seconds % 60, 2, 10, QChar( '0' ) );
		
		QStyleOptionViewItem option_ = option;
		option_.displayAlignment = Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter;

		drawDisplay( painter, option_, option_.rect, strDuration );
		drawFocus( painter, option_, option_.rect );
	}
	else
	{
		QItemDelegate::paint( painter, option, index );
	}
}

void CTrackItemDelegate::commitDataAndcloseEditor()
{
	QTimeEdit *pEditor = qobject_cast<QTimeEdit*>( sender() );

	emit commitData( pEditor );
	emit closeEditor( pEditor );
}
