#ifndef _xfs_MainWnd_h_
#define _xfs_MainWnd_h_

#include <QtCore/QStringList>
#include <QtWidgets/QMainWindow>

class QLabel;
class QAction;
class QMenu;
class QToolBar;
class QStatusBar;
class CSpreadSheet;


class CFindDialog;


class CMainWnd : public QMainWindow
{
	Q_OBJECT

public:
	CMainWnd( QWidget *_pParent = nullptr );

protected:
	// closeEvent 来自 QWidget, 已经覆盖了该虚函数，为什么还能关闭窗口？
	void closeEvent( QCloseEvent* _event );
private:
	void Init();

private:
	// -------
	void CreateActions();
	void CreateMenus();
	void CreateContextMenu();
	void CreateToolbars();
	void CreateStatusbar();

	// -------
	void ReadSettings();
	void WriteSettings();

	// -------
	bool OkToContinue();
	bool LoadFile( const QString &_fn );
	bool SaveFile( const QString &_fn );

	// -------
	void SetCurrentFile( const QString &_fn );
	void UpdateRecentFileActions();
	QString StrippedName( const QString &_fn );

private slots:
	// file menu
	void NewFile();
	void OpenFile();
	void OpenRecentFile();
	
	bool Save();
	bool SaveAs();
	

	void Exit();

	// edit menu
	void Find();
	void GoToCell();
	void Sort();

	// help menu
	void About();

	// miscellaneous
	void UpdateStatusBar();
	void SpreadSheetModified();



private:
	//  file actions
	QAction		*m_pNewFile;
	QAction		*m_pOpenFile;

	QAction		*m_pSave;
	QAction		*m_pSaveAs;

	QAction		*m_pFileSeparator_1;

	enum ENum { MaxRecentFiles = 5 };
	QAction		*m_pRecentFiles[ENum::MaxRecentFiles];


	QAction		*m_pFileSeparator_2;

	QAction		*m_pExit;

	// edit actions
	QAction		*m_pCut;
	QAction		*m_pCopy;
	QAction		*m_pPaste;
	QAction		*m_pDelete;
	
	QMenu		*m_pSelectSubMn;
	QAction		*m_pSelectRow;
	QAction		*m_pSelectColumn;
	QAction		*m_pSelectAll;
	
	QAction		*m_pFind;
	QAction		*m_pGoToCell;


	// tools actions
	QAction		*m_pRecalculate;
	QAction		*m_pSort;

	// options actions
	QAction		*m_pShowGrid;
	QAction		*m_pAutoReCalculate;


	// help actions
	QAction		*m_pAbout;
	QAction		*m_pAboutQt;

	// menus
	QMenu		*m_pFileMn;
	QMenu		*m_pEditMn;	
	QMenu		*m_pToolsMn;
	QMenu		*m_pOptionMn;
	QMenu		*m_pHelpMn;


	// toobars
	QToolBar		*m_pFileTB;
	QToolBar		*m_pEditTB;
	QToolBar		*m_pToolsTB;
	QToolBar		*m_pOptionTB;
	QToolBar		*m_pHelpTB;


	// statusbar
	QLabel			*m_pCellLabel;
	QLabel			*m_pFormulaLabel;
	QStatusBar		*m_pStatusBar;

	// central widget
	CSpreadSheet	*m_pCentral;


	// find dialog
	CFindDialog		*m_pFindDlg = nullptr;


	// current file name
	QString			m_CurrentFN;

	// name of recent files
	QStringList		m_ReCentFileList;
};



#endif