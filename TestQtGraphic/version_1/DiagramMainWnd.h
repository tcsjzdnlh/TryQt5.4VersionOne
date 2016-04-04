#ifndef _xfs_DiagramMainWnd_h_
#define _xfs_DiagramMainWnd_h_

#include <QtWidgets/QGraphicsView>
#include <QtCore/QPair>

class QGraphicsScene;
class CGraphicsNode;
class QAction;
class QMenuBar;
class QToolBar;
class CLink;

class CDiagramMainWnd : public QGraphicsView
{
	Q_OBJECT
public:
	CDiagramMainWnd( QWidget *_pParent = nullptr );

private slots:
	void AddNode();
	void AddLink();

	void BringToFront();
	void SendToBack();

	void Properties();
	
	// -------------------
private slots:
	void Cut();
	void Copy();
	void Paste();
	void Del();

	void UpdateActions();

private:
	void CreateActions();
	void CreateMenus();
	void CreateToolBars();

private:
	void Init();

	void SetupNode( CGraphicsNode *_pNode );
	void SetZValue( int _z );
	CGraphicsNode* SelectedNode();

	typedef QPair<CGraphicsNode*, CGraphicsNode*> NodePair;
	CLink* SelectedLink() const;
	NodePair SelectedNodePair() const;

private:
	QGraphicsScene			*m_pScene;

	int						m_iNumber;
	int						m_minZValue;
	int						m_maxZValue;

private:
	enum EActions { eCut = 0, eCopy, ePaste, eDel };
	QAction				*m_pCutAction;
	QAction				*m_pCopyAction;
	QAction				*m_pPasteAction;
	QAction				*m_pDelAction;

	QAction				*m_pAddNode;
	QAction				*m_pAddLink;

	QMenuBar			*m_pMenuBar;

};



#endif