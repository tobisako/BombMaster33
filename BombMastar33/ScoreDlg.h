#if !defined(AFX_SCOREDLG_H__0B51C399_C155_4BAE_8429_8C3C282A3256__INCLUDED_)
#define AFX_SCOREDLG_H__0B51C399_C155_4BAE_8429_8C3C282A3256__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg ダイアログ

class CScoreDlg : public CDialog
{
// コンストラクション
public:
	CScoreDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CScoreDlg)
	enum { IDD = IDD_SUCOREDIALOG1 };
	CString	m_ScoreStr;
	CString	m_LevelStr;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CScoreDlg)
		// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SCOREDLG_H__0B51C399_C155_4BAE_8429_8C3C282A3256__INCLUDED_)
