#include "MainWnd.h"
#include "SpreadSheet.h"
#include <QtGui/QPixmap>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtGui/QKeySequence>
#include <QtWidgets/QApplication>

#include <QtWidgets/QLabel>

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtGui/QCloseEvent>
#include <QtCore/QFileInfo>

#include "FindDialog.h"
#include "SortDialog.h"
#include "GoToCellDlg.h"

#include <QtWidgets/QTableWidgetSelectionRange>


CMainWnd::CMainWnd( QWidget *_pParent /*= nullptr */ )
	:QMainWindow(_pParent), m_pCentral( nullptr )
{
	Init();
}

void CMainWnd::closeEvent( QCloseEvent* _event )
{

	//QMessageBox::information( nullptr, "title", "closeEvent function called ..." );
	if( OkToContinue() )
	{
		WriteSettings();
		_event->accept();
	}
	else
	{
		_event->ignore();
	}
}

void CMainWnd::Init()
{
	//m_pCentral = new CSpreadSheet( 10, 5, this );

	m_pCentral = new CSpreadSheet( this );

	setCentralWidget( m_pCentral );
	resize( 600, 500 );
	// 传递 QPixmap 居然也行
	//setWindowIcon( QPixmap( ":/icons/window_icon.ico" ) );
	setWindowIcon( QIcon( ":/window/window.ico" ) );



	CreateActions();
	CreateMenus();
	CreateContextMenu();
	CreateToolbars();
	CreateStatusbar();

	ReadSettings();



	SetCurrentFile( "" );
}

void CMainWnd::CreateActions()
{
	// --------file actions
	m_pNewFile = new QAction( tr( "&new file" ), this );
	m_pNewFile->setIcon( QIcon( ":/actions/new.ico" ) );
	m_pNewFile->setShortcut( QKeySequence::New );
	m_pNewFile->setStatusTip( tr( "create a new spreadsheet file" ) );
	connect( m_pNewFile, SIGNAL( triggered() ), this, SLOT( NewFile() ) );

	m_pOpenFile = new QAction( tr( "&open file" ), this );
	m_pOpenFile->setIcon( QIcon( ":/actions/open.ico" ) );
	m_pOpenFile->setShortcut( QKeySequence::Open );
	m_pOpenFile->setStatusTip( tr( "open a file" ) );
	connect( m_pOpenFile, SIGNAL( triggered() ), this, SLOT( OpenFile() ) );


	m_pSave = new QAction( tr( "&Save" ), this );
	m_pSave->setIcon( QIcon( ":/actions/save.ico" ) );
	m_pSave->setShortcut( QKeySequence::Save );
	m_pSave->setStatusTip( tr( "save file" ) );
	connect( m_pSave, SIGNAL( triggered() ), this, SLOT( Save() ) );

	m_pSaveAs = new QAction( tr( "Save as" ), this );
	m_pSaveAs->setIcon( QIcon( ":/actions/save_as.ico" ) );
	m_pSaveAs->setShortcut( QKeySequence::SaveAs );
	m_pSaveAs->setStatusTip( tr( "save file as " ) );
	connect( m_pSaveAs, SIGNAL( triggered() ), this, SLOT( SaveAs() ) );


	


	for( int i = 0; i < ENum::MaxRecentFiles; ++i )
	{
		m_pRecentFiles[i] = new QAction( this );
		m_pRecentFiles[i]->setVisible( false );

		connect( m_pRecentFiles[i], SIGNAL( triggered() ), this, SLOT( OpenRecentFile() ) );
	}


	m_pExit = new QAction( tr( "&Exit" ), this );
	m_pExit->setIcon( QIcon( ":/actions/exit.ico" ) );
	m_pExit->setShortcut( tr( "Ctrl+Q" ) );
	m_pExit->setStatusTip( tr( "exit application" ) );
	connect( m_pExit, SIGNAL( triggered() ), this, SLOT( close() ) );

	
	
	
	// --------edit actions
	m_pCut = new QAction( tr( "Cut" ), this );
	m_pCut->setIcon( QIcon( ":/actions/cut.ico" ) );
	m_pCut->setShortcut( QKeySequence::Cut );
	m_pCut->setStatusTip( tr( "cut the current select contents to the clipboard" ) );
	connect( m_pCut, SIGNAL( triggered() ), m_pCentral, SLOT( Cut() ) );

	m_pCopy = new QAction( tr( "Copy" ), this );
	m_pCopy->setIcon( QIcon( ":/actions/copy.ico" ) );
	m_pCopy->setShortcut( QKeySequence::Copy );
	m_pCopy->setStatusTip( tr( "copy the current select contents to the clipboard" ) );
	connect( m_pCopy, SIGNAL( triggered() ), m_pCentral, SLOT( Copy() ) );


	m_pPaste = new QAction( tr( "Paste" ), this );
	m_pPaste->setIcon( QIcon( ":/actions/paste.ico" ) );
	m_pPaste->setShortcut( QKeySequence::Paste );
	m_pPaste->setStatusTip( tr( "paste the contents in clipboard to the spreadsheet" ) );
	connect( m_pPaste, SIGNAL( triggered() ), m_pCentral, SLOT( Paste() ) );


	m_pDelete = new QAction( tr( "Delete" ), this );
	m_pDelete->setIcon( QIcon( ":/actions/del.ico" ) );
	m_pDelete->setShortcut( QKeySequence::Delete );
	m_pDelete->setStatusTip( tr( "delete the current content" ) );
	connect( m_pDelete, SIGNAL( triggered() ), m_pCentral, SLOT( Del() ) );


	m_pSelectRow = new QAction( tr( "Select Row" ), this );
	m_pSelectRow->setStatusTip( tr( "select current row" ) );
	connect( m_pSelectRow, SIGNAL( triggered() ), m_pCentral, SLOT( SelectCurrentRow() ) );


	m_pSelectColumn = new QAction( tr( "Select Column" ), this );
	m_pSelectColumn->setStatusTip( tr( "Select current column" ) );
	connect( m_pSelectColumn, SIGNAL( triggered() ), m_pCentral, SLOT( SelectCurrentColumn() ) );

	m_pSelectAll = new QAction( tr( "Select All" ), this );
	m_pSelectAll->setShortcut( QKeySequence::SelectAll );
	m_pSelectAll->setStatusTip( tr( "Select all contents" ) );
	connect( m_pSelectAll, SIGNAL( triggered() ), m_pCentral, SLOT( selectAll() ) );

	m_pFind = new QAction( tr( "&Find" ), this );
	m_pFind->setIcon( QIcon( ":/actions/find.ico" ) );
	m_pFind->setShortcut( QKeySequence::Find );
	m_pFind->setStatusTip( tr( "Find something in spreadsheet" ) );
	connect( m_pFind, SIGNAL( triggered() ), this, SLOT( Find() ) );

	m_pGoToCell = new QAction( tr( "Go To Cell" ), this );
	m_pGoToCell->setStatusTip( tr( "Go to cell dialog" ) );
	connect( m_pGoToCell, SIGNAL( triggered() ), this, SLOT( GoToCell() ) );

	// --------tools actions

	m_pRecalculate = new QAction( tr( "&Recalculate" ), this );
	m_pRecalculate->setShortcut( tr( "F9" ) );
	m_pRecalculate->setStatusTip( tr( "recalculate" ) );
	connect( m_pRecalculate, SIGNAL( triggered() ), m_pCentral, SLOT( Recalculate() ) );

	
	m_pSort = new QAction( tr( "&Sort..." ), this );
	m_pSort->setStatusTip( tr( "sort the select contents" ) );
	connect( m_pSort, SIGNAL( triggered() ), this, SLOT( Sort() ) );
	
	// --------option actions
	m_pShowGrid = new QAction( tr( "Show Grid" ), this );
	m_pShowGrid->setCheckable( true );
	m_pShowGrid->setChecked( m_pCentral->showGrid() ); // 状态同步
	m_pShowGrid->setStatusTip( tr( "show or hide the spreadsheet's grid" ) );
	connect( m_pShowGrid, SIGNAL( toggled( bool ) ), m_pCentral, SLOT( setShowGrid( bool ) ) );

	m_pAutoReCalculate = new QAction( tr( "&Auto-Recalculate" ), this );
	m_pAutoReCalculate->setCheckable( true );
	m_pAutoReCalculate->setChecked( m_pCentral->AutoRecalculate() );
	m_pAutoReCalculate->setStatusTip( tr( "switch the auto recalculate on or off" ) );;
	connect( m_pAutoReCalculate, SIGNAL( toggled( bool ) ), m_pCentral, SLOT( SetAutoRecalculate( bool ) ) );

	// help actions
	m_pAboutQt = new QAction( tr( "about Qt" ), this );
	m_pAboutQt->setStatusTip( tr( "show the Qt library's about box" ) );
	connect( m_pAboutQt, SIGNAL( triggered() ), qApp, SLOT( aboutQt() ) );


	



}

void CMainWnd::CreateMenus()
{
	// ------menus---------------------------------------------------------------
	// ------menus---------------------------------------------------------------
	// file menu
	m_pFileMn = menuBar()->addMenu( "&File" );
	m_pFileMn->addAction( m_pNewFile );
	m_pFileMn->addAction( m_pOpenFile );
	m_pFileMn->addAction( m_pSave );
	m_pFileMn->addAction( m_pSaveAs );
	m_pFileSeparator_1 = m_pFileMn->addSeparator();

	for( auto & a : m_pRecentFiles )
	{
		m_pFileMn->addAction( a );
	}

	m_pFileSeparator_2 = m_pFileMn->addSeparator();
	m_pFileMn->addAction( m_pExit );


	// edit menu
	m_pEditMn = menuBar()->addMenu( tr( "Edit" ) );
	m_pEditMn->addAction( m_pCut );
	m_pEditMn->addAction( m_pCopy );
	m_pEditMn->addAction( m_pPaste );
	m_pEditMn->addAction( m_pDelete );
	
	m_pSelectSubMn = m_pEditMn->addMenu( tr( "Select" ) );
	m_pSelectSubMn->addAction( m_pSelectRow );
	m_pSelectSubMn->addAction( m_pSelectColumn );
	m_pSelectSubMn->addAction( m_pSelectAll );

	m_pEditMn->addSeparator();
	
	m_pEditMn->addAction( m_pFind );
	m_pEditMn->addAction( m_pGoToCell );


	// tools menu
	m_pToolsMn = menuBar()->addMenu( tr( "Tools" ) );
	m_pToolsMn->addAction( m_pRecalculate );
	m_pToolsMn->addAction( m_pSort );


	// option menu
	m_pOptionMn = menuBar()->addMenu( tr( "&Option" ) );
	m_pOptionMn->addAction( m_pShowGrid );
	m_pOptionMn->addAction( m_pAutoReCalculate );


	// add a separator
	menuBar()->addSeparator();

	// help menu
	m_pHelpMn = menuBar()->addMenu( tr( "&Help" ) );
	m_pHelpMn->addAction( m_pAboutQt );
}

void CMainWnd::CreateContextMenu()
{
	m_pCentral->addAction( m_pCut );
	m_pCentral->addAction( m_pCopy );
	m_pCentral->addAction( m_pPaste );
	m_pCentral->addAction( m_pDelete );

	m_pCentral->setContextMenuPolicy( Qt::ActionsContextMenu );
}

void CMainWnd::CreateToolbars()
{
	// -------toolbars
	// file tool bar
	m_pFileTB = addToolBar( tr( "&File" ) );
	m_pFileTB->addAction( m_pOpenFile );
	m_pFileTB->addAction( m_pNewFile );
	m_pFileTB->addAction( m_pSave );
	m_pFileTB->addAction( m_pSaveAs );

	// edit tool bar
	m_pEditTB = addToolBar( tr( "&Edit" ) );
	m_pEditTB->addAction( m_pCut );
	m_pEditTB->addAction( m_pCopy );
	m_pEditTB->addAction( m_pPaste );
	m_pEditTB->addAction( m_pDelete );
	m_pEditTB->addSeparator();
	m_pEditTB->addAction( m_pFind );
	m_pEditTB->addAction( m_pGoToCell );



}

void CMainWnd::CreateStatusbar()
{
	
	m_pCellLabel = new QLabel( tr( "W999" ) );
	m_pCellLabel->setAlignment( Qt::AlignHCenter );
	m_pCellLabel->setMinimumSize( m_pCellLabel->sizeHint() );

	m_pFormulaLabel = new QLabel( tr( "" ) );
	m_pFormulaLabel->setIndent( 30 );

	// ------statusbar	
	m_pStatusBar = statusBar();
	m_pStatusBar->addWidget( m_pCellLabel );
	m_pStatusBar->addWidget( m_pFormulaLabel, 1 );

	connect( m_pCentral, SIGNAL( currentCellChanged( int, int, int, int )), this, SLOT( UpdateStatusBar() ) );
	connect( m_pCentral, SIGNAL( Modified() ), this, SLOT( SpreadSheetModified() ) );



	UpdateStatusBar();
}

void CMainWnd::ReadSettings()
{

}

void CMainWnd::WriteSettings()
{

}

bool CMainWnd::OkToContinue()
{
	if( isWindowModified() )
	{
		int r = QMessageBox::warning( this, tr( "title" ),
										tr( "the document has changed \n. do you want save your changes?" ),
										QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel );

		if( r == QMessageBox::Yes )
		{
			return Save();
		}
		else if( r == QMessageBox::Cancel )
		{
			return false;
		}
	}
	
	return true;
}

bool CMainWnd::LoadFile( const QString &_fn )
{
	if( m_pCentral->ReadFile( _fn ) )
	{
		statusBar()->showMessage( tr( "load file : %1 succeed!" ).arg( _fn ), 5000 );
		SetCurrentFile( _fn );
		return true;
	}
	
	statusBar()->showMessage( tr( "load file : %1 failed !" ).arg( _fn ), 5000 );
	return false;
}

bool CMainWnd::SaveFile( const QString &_fn )
{
	// 首先应该判断是否 内容有  modified
	if( m_pCentral->WriteFile( _fn ) )
	{
		SetCurrentFile( _fn );
		statusBar()->showMessage( tr( "save file : %1 succeed!" ).arg( _fn ), 5000 );
		return true;
	}
	else
	{
		statusBar()->showMessage( tr( "save file : %1 failed!" ).arg( _fn ), 5000 );
		return false;
	}		
}

void CMainWnd::SetCurrentFile( const QString &_fn )
{
	m_CurrentFN = _fn;

	setWindowModified( false );
	
	QString strCaption( tr("Untitled") );
	if( !m_CurrentFN.isEmpty() )
	{
		strCaption = StrippedName( m_CurrentFN );

		m_ReCentFileList.removeAll( m_CurrentFN );
		m_ReCentFileList.prepend( m_CurrentFN );

		UpdateRecentFileActions();
	}


	setWindowTitle( tr( "%1 [*] - Spread Sheet" ).arg( strCaption ) );

}

void CMainWnd::UpdateRecentFileActions()
{
	QMutableStringListIterator iter( m_ReCentFileList );
	while( !iter.hasNext() )
	{
		if( !QFile::exists(iter.next()) )
		{
			iter.remove();
		}
	}
	
	for( int i = 0; i < ENum::MaxRecentFiles; ++i )
	{
		if( i < m_ReCentFileList.count() )
		{
			static QString file_name;
			file_name = tr( "&%1 %2" ).arg( i + 1 ).arg( StrippedName( m_ReCentFileList[i] ) );

			m_pRecentFiles[i]->setText( file_name );
			m_pRecentFiles[i]->setData( m_ReCentFileList[i] );

			m_pRecentFiles[i]->setVisible( true );
		}
		else
		{
			m_pRecentFiles[i]->setVisible( false );
		}
	}

	if( !m_ReCentFileList.isEmpty() )
	{
		m_pFileSeparator_1->setVisible( true );
	}
	
}

QString CMainWnd::StrippedName( const QString &_fn )
{
	return QFileInfo( _fn ).fileName();
}

void CMainWnd::NewFile()
{
	if( OkToContinue() )
	{
		m_pCentral->Clear();
		SetCurrentFile( "" );
	}
}

void CMainWnd::OpenFile()
{
	if( OkToContinue() )
	{
		QString fn
			= QFileDialog::getOpenFileName( this, tr( "title" ), ".",
								tr( "spreadsheet file (*.spf);;qt resource(*.qrc);;source file(*.h *.cpp)" ) );

		if( !fn.isEmpty() )
		{
			LoadFile( fn );
		}
	}
}

void CMainWnd::OpenRecentFile()
{
	if( OkToContinue() )
	{
		QAction *pRecentFile = qobject_cast<QAction*>( sender() );
		if( pRecentFile )
		{
			LoadFile( pRecentFile->data().toString() );
		}

	}	
}

bool CMainWnd::Save()
{
	if( !m_CurrentFN.isEmpty() )
	{
		return SaveFile( m_CurrentFN );
	}
	else
	{
		return SaveAs();
	}
}

bool CMainWnd::SaveAs()
{
	m_CurrentFN = QFileDialog::getSaveFileName( this, tr( "title" ), ".",
									tr( "spread sheet file(*.spf *ssf);;source file(*.h *.cpp)" ) );
	if( m_CurrentFN.isEmpty() )
	{
		return false;
	}
	
	return SaveFile( m_CurrentFN );
}

void CMainWnd::Exit()
{

}

void CMainWnd::Find()
{
	if( nullptr == m_pFindDlg )
	{
		m_pFindDlg = new CFindDialog( this );
	}
	

	connect( m_pFindDlg, SIGNAL( FindNext( const QString&, Qt::CaseSensitivity ) ),
		m_pCentral, SLOT( FindNext( const QString &, Qt::CaseSensitivity ) ) );

	connect( m_pFindDlg, SIGNAL( FindPrevious( const QString &, Qt::CaseSensitivity ) ),
		m_pCentral, SLOT( FindPrevious( const QString &, Qt::CaseSensitivity ) ) );

	
	m_pFindDlg->show();
	//m_pFindDlg->raise();
	m_pFindDlg->activateWindow();

}

void CMainWnd::GoToCell()
{
	CGoToCellDialog dlg( this );
	if( dlg.exec() )
	{
		QString str = dlg.m_pCellLocation->text().toUpper();
		m_pCentral->setCurrentCell( str.mid( 1 ).toInt() - 1, str[0].unicode() - 'A' );
	}
	
	
}

void CMainWnd::Sort()
{
	CSortDialog dlg( this );
	QTableWidgetSelectionRange range = m_pCentral->SelectedRange();

	dlg.SetColumnRange( 'A' + range.leftColumn(), 'A' + range.rightColumn() );
	

	if( dlg.exec() )
	{
		CSpreadSheetCompare compare;

		compare.m_Keys[0] = dlg.m_pPColumnCB->currentIndex();
		compare.m_Keys[1] = dlg.m_pSColumnCB->currentIndex() - 1;
		compare.m_Keys[2] = dlg.m_pTColumnCB->currentIndex() - 1;

		compare.m_bAscending[0] = ( 0 == dlg.m_pPOrderCB->currentIndex() );
		compare.m_bAscending[1] = ( 0 == dlg.m_pSOrderCB->currentIndex() );
		compare.m_bAscending[2] = ( 0 == dlg.m_pTOrderCB->currentIndex() );
		

		m_pCentral->Sort( compare );
	}
		
}

void CMainWnd::About()
{

}

void CMainWnd::UpdateStatusBar()
{
	m_pCellLabel->setText( m_pCentral->CurrentLocation() );
	m_pFormulaLabel->setText( m_pCentral->CurrentFormula() );
}

void CMainWnd::SpreadSheetModified()
{
	setWindowModified( true );
	UpdateStatusBar();
}
