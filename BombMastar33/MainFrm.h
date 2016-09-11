// MainFrm.h : CMainFrame クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__261B6B25_36D2_4DDF_B983_6B2EE8E6D2BA__INCLUDED_)
#define AFX_MAINFRM_H__261B6B25_36D2_4DDF_B983_6B2EE8E6D2BA__INCLUDED_

#include "TimerDlg.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BombMastatToolBar.h"

class CMainFrame : public CFrameWnd
{
	
protected: // シリアライズ機能のみから作成します。
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:

	CTimerDlg* m_pTimerDlg;				//<------山崎追加
	void MYFTBarSetPosition();			//<------山崎追加
	void MYFTBarSetWidth();				//<------山崎追加
	friend UINT MYTimerThread1(LPVOID);	//<------山崎追加

	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // コントロール バー用メンバ
	CStatusBar  m_wndStatusBar;
//	CBombMastatToolBar m_wndToolBar;  //<----protectedからpublicに変更 山崎
public:
	TBBUTTON m_kTbbutonDef[4];
	TBBUTTON m_kTbbutonOn[4];
	CImageList m_iml;
	CBombMastatToolBar m_wndToolBar;

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MAINFRM_H__261B6B25_36D2_4DDF_B983_6B2EE8E6D2BA__INCLUDED_)
