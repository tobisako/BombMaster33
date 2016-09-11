// BombMastatToolBar.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "BombMastar.h"
#include "BombMastatToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBombMastatToolBar

CBombMastatToolBar::CBombMastatToolBar()
{
}

CBombMastatToolBar::~CBombMastatToolBar()
{
}


BEGIN_MESSAGE_MAP(CBombMastatToolBar, CToolBar)
	//{{AFX_MSG_MAP(CBombMastatToolBar)
	ON_WM_CHILDACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBombMastatToolBar メッセージ ハンドラ

void CBombMastatToolBar::OnChildActivate() 
{
	CToolBar::OnChildActivate();
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	
	//ツールバーがフロート状態の時
	CWnd* pWnd = GetParent()->GetParent();
	if(pWnd->GetSafeHwnd() != GetOwner()->GetSafeHwnd())
	{
		//ツールバーのタイトルバーにある「閉じる」ボタンを消す
		pWnd->ModifyStyle(WS_SYSMENU, 0);

		//ツールバーのタイトルバーを消す
		//pWnd->ModifyStyle(WS_CAPTION, 0);

		//ツールバーのリサイズ不可
		pWnd->ModifyStyle(WS_THICKFRAME, 0);

	}

}
