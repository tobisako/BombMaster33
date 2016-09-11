// BombMastar.h : BOMBMASTAR アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_BOMBMASTAR_H__C889A404_190C_4131_A658_59F534209D04__INCLUDED_)
#define AFX_BOMBMASTAR_H__C889A404_190C_4131_A658_59F534209D04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル
#include "ScoreDlg.h"	// ClassView によって追加されました。

/////////////////////////////////////////////////////////////////////////////
// CBombMastarApp:
// このクラスの動作の定義に関しては BombMastar.cpp ファイルを参照してください。
//

class CBombMastarApp : public CWinApp
{
public:
	//スコア用モードレスダイアログ用変数
//	CScoreDlg* m_pScoreDlg;	//<-------山崎追加

	CBombMastarApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CBombMastarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CBombMastarApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_BOMBMASTAR_H__C889A404_190C_4131_A658_59F534209D04__INCLUDED_)
