#include "Testor.h"
#include "MainWnd.h"
#include <QtWidgets/QWidget>
#include <QtCore/QEvent>
#include <QtCore/QVariant>
#include <QtCore/QRegExp>
//#include "HugeEnumToString.h"
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QRect>
#include <QtWidgets/QApplication>
#include <QtGui/QKeyEvent>
#include "FlowChartSymbolPicker.h"
#include "CoordinateEditor.h"
#include "DirTree.h"
#include "ModelString.h"
#include "DirModel.h"
#include "SortFilterProxyModelDlg.h"
#include "ParitiesModel.h"
#include "TrackEditor.h"


CMainWnd		*g_pWnd = nullptr;


CTestor::CTestor()
{
	Init();
}
void CTestor::Init()
{	
	g_pWnd = new CMainWnd;	
	
	//g_pWnd->SetEventsMap( CHugeEnumToString().GetEnumString( "events_file.cpp" ) );
	
	int width =  qApp->desktop()->width() / 2;
	int height = 9 * qApp->desktop()->height() / 10;

	g_pWnd->setGeometry( QRect( 10, 30, width, height ) );
	g_pWnd->show();
}


// -------------------------------------------------------------------
// -------------------------------------------------------------------
namespace test_model_view
{
	namespace list_widget
	{
		void test()
		{
			CFlowChartSymbolPikcer *pWnd = new CFlowChartSymbolPikcer;
			pWnd->show();
		}
	}
	namespace table_widget
	{
		void test()
		{
			CCoordinateEditor *pDlg = new CCoordinateEditor;
			pDlg->show();
		}
	}
	namespace tree_widget
	{
		void test()
		{
			CDirTree *pDlg = new CDirTree;
			pDlg->show();
		}
	}

	namespace model_string
	{
		void test()
		{
			CModelString *pWnd = new CModelString;
			pWnd->show();
		}
	}
	namespace model_dir
	{
		void test()
		{
			CDirModelDlg *pDlg = new CDirModelDlg;
			pDlg->show();
		}
	}

	namespace proxy_model
	{
		void test()
		{
			CSortFilterProxyModelDlg *pDlg = new CSortFilterProxyModelDlg;
			pDlg->show();
		}
	}

	namespace parities_model
	{		
		void test()
		{
			CParitiesModel *pModel = new CParitiesModel;
			QTableView *pView = new QTableView;
			pView->setModel( pModel );

			pView->show();
		}
	}

	namespace item_delegate
	{
		void test()
		{
			CTrackEditor *pEditor = new CTrackEditor;
			pEditor->show();
		}
	}
}

// -------------------------------------------------------------------
// -------------------------------------------------------------------
void CTestor::Test()
{
	{
		using namespace test_model_view;
		//list_widget::test();
		//table_widget::test();
		//tree_widget::test();
		//model_string::test();
		//model_dir::test();
		//proxy_model::test();
		//parities_model::test();
		item_delegate::test();
	}
}