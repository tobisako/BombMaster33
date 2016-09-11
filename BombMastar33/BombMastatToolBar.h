#if !defined(AFX_BOMBMASTATTOOLBAR_H__A0C15DA3_AFEB_11D5_829C_0090CC0851BE__INCLUDED_)
#define AFX_BOMBMASTATTOOLBAR_H__A0C15DA3_AFEB_11D5_829C_0090CC0851BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BombMastatToolBar.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CBombMastatToolBar ウィンドウ

class CBombMastatToolBar : public CToolBar
{
// コンストラクション
public:
	CBombMastatToolBar();

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CBombMastatToolBar)
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CBombMastatToolBar();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CBombMastatToolBar)
	afx_msg void OnChildActivate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_BOMBMASTATTOOLBAR_H__A0C15DA3_AFEB_11D5_829C_0090CC0851BE__INCLUDED_)
