#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include "TrackEditor.h"
#include "TrackItemDelegate.h"


CTrackEditor::CTrackEditor( QWidget *_pParent /*= nullptr */ )
	:QDialog( _pParent )
{
	Init();
}

void CTrackEditor::Init()
{
	InitDatas();


	// ---------------------------------------------------
	m_pView = new QTableWidget( m_tracks.count(), 2 );	
	m_pView->setItemDelegate( new CTrackItemDelegate( 1 ) );
	m_pView->setHorizontalHeaderLabels( QStringList() << tr( "track name" ) << tr( "duaration" ) );

	for( int i = 0; i < m_tracks.count(); ++i )
	{
		CTrackInfo info = m_tracks.at( i );
		QTableWidgetItem *pItem_0 = new QTableWidgetItem( info.m_name );
	
		QTableWidgetItem *pItem_1 = new QTableWidgetItem( QString::number( info.m_duration) );
		pItem_1->setTextAlignment( Qt::AlignmentFlag::AlignRight );

		m_pView->setItem( i, 0, pItem_0 );
		m_pView->setItem( i, 1, pItem_1 );
	}
	
	
	// ---------------------------------------------------
	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pView );
	setLayout( pLay_0 );

	// -------------------------------------------------
	m_pView->resizeColumnToContents( 0 );
}

void CTrackEditor::InitDatas()
{
	m_tracks << CTrackInfo( "The Flying Dutchman: Overture", 630 )
		<< CTrackInfo( "The Flying Dutchman: Wie aus der Fern laengst "
		"vergangner Zeiten", 374 )
		<< CTrackInfo( "The Flying Dutchman: Steuermann, lass die Wacht",
		152 )
		<< CTrackInfo( "Die Walkuere: Ride of the Valkyries", 286 )
		<< CTrackInfo( "Tannhaeuser: Freudig begruessen wir die edle "
		"Halle", 384 )
		<< CTrackInfo( "Tannhaeuser: Wie Todesahnung - O du mein holder "
		"Abendstern", 257 )
		<< CTrackInfo( "Lohengrin: Treulich gefuert ziehet dahnin", 294 )
		<< CTrackInfo( "Lohengrin: In fernem Land", 383 )
		<< CTrackInfo( "Die Meistersinger von Nuernberg: Overture", 543 )
		<< CTrackInfo( "Die Meistersinger von Nuernberg: Verachtet mir "
		"die Meister nicht", 200 )
		<< CTrackInfo( "Die Meistersinger von Nuernberg: Ehrt eure "
		"deutschen Meister", 112 )
		<< CTrackInfo( "Goetterdaemmerung: Funeral Music", 469 )
		<< CTrackInfo( "Tristan und Isolde: Mild und leise, wie er "
		"laechelt", 375 );
}
