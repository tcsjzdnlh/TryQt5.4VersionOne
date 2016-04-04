#ifndef _xfs_Test_h_
#define _xfs_Test_h_


class CTestWidgets;

class CTestor
{
public:
	CTestor();
	virtual ~CTestor();
public:
	void Test();
	//static CTestWidgets* Wnd();
	
private:
	CTestWidgets		*m_pWnd = nullptr;
};



#endif