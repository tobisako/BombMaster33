// BombMastarView.h : CBombMastarView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMBMASTARVIEW_H__F86687C7_5A7F_4953_BC46_F671A50099C9__INCLUDED_)
#define AFX_BOMBMASTARVIEW_H__F86687C7_5A7F_4953_BC46_F671A50099C9__INCLUDED_

#include "ScoreDlg.h"	// ClassView によって追加されました。
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBombMastarView : public CView
{
protected: // シリアライズ機能のみから作成します。
	CBombMastarView();
	DECLARE_DYNCREATE(CBombMastarView)

// アトリビュート
public:
	CBombMastarDoc* GetDocument();



// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CBombMastarView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	void MYSetDefault();
	void MYPaintEnd(CDC *pDC);
	
	void MYPaintBit( CDC* pDC, CDC* dcPhoto, BOMBLIST* pCurrent);
	void MYSizeChange( int iWidthX, int iWidthY );
	void MYPaint(CDC* pDC);
	void MYSetTimer(BOOL bTimeONOFF);
	CTimerDlg* m_pTimerDlg;				//<------山崎追加
	CScoreDlg* m_pScoreDlg;				//<------山崎追加
	friend UINT MYTimerThread1(LPVOID);	//<------山崎追加
	virtual ~CBombMastarView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CBombMastarView)
	afx_msg void OnMenuitemStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuitemsizel();
	afx_msg void OnMenuitemsizes();
	afx_msg void OnMenuitemsizem();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // BombMastarView.cpp ファイルがデバッグ環境の時使用されます。
inline CBombMastarDoc* CBombMastarView::GetDocument()
   { return (CBombMastarDoc*)m_pDocument; }
#endif





/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_BOMBMASTARVIEW_H__F86687C7_5A7F_4953_BC46_F671A50099C9__INCLUDED_)
