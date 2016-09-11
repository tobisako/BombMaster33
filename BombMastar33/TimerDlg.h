#if !defined(AFX_TIMERDLG_H__521F4139_FC25_4453_8416_584CDC7CC09F__INCLUDED_)
#define AFX_TIMERDLG_H__521F4139_FC25_4453_8416_584CDC7CC09F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"
// TimerDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg ダイアログ

class CTimerDlg : public CDialog
{
// コンストラクション
public:
	UINT m_iRoopTime;		//タイマの間隔設定用変数
	UINT m_iDefaultTime;	//タイマのデフォルト設定用変数
	UINT m_iTimer;			//タイマ用変数
	CTimerDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CTimerDlg)
	enum { IDD = IDD_TIMERDIALOG1 };
	CString	m_cTimer;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CTimerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CTimerDlg)
	afx_msg void OnBombTimer1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_TIMERDLG_H__521F4139_FC25_4453_8416_584CDC7CC09F__INCLUDED_)
