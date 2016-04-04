#ifndef _xfs_TrackItemDelegate_h_
#define _xfs_TrackItemDelegate_h_

#include <QtWidgets/QItemDelegate>


class CTrackItemDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	CTrackItemDelegate( int _column, QObject *_pParent = nullptr );

	QWidget* createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
	void setEditorData( QWidget *editor, const QModelIndex &index ) const;
	void setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
	void paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const;

private slots:
	void commitDataAndcloseEditor();

private:
	int		m_column;
};



#endif