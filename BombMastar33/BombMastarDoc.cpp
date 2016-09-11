// BombMastarDoc.cpp : CBombMastarDoc クラスの動作の定義を行います。
//

#include "stdafx.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc

IMPLEMENT_DYNCREATE(CBombMastarDoc, CDocument)

BEGIN_MESSAGE_MAP(CBombMastarDoc, CDocument)
	//{{AFX_MSG_MAP(CBombMastarDoc)
	ON_COMMAND(WM_USER_BOMB1, OnToolbarbutton1)
	ON_COMMAND(WM_USER_BOMB2, OnToolbarbutton2)
	ON_COMMAND(WM_USER_BOMB3, OnToolbarbutton3)
	ON_COMMAND(WM_USER_BOMB4, OnToolbarbutton4)
	ON_COMMAND(ID_MENUITEMBIT, OnMenuitembit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc クラスの構築/消滅

CBombMastarDoc::CBombMastarDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

	//ランダム関数用
	srand( (unsigned)time(NULL) );

	//ボムNoの初期化
	m_iBombNo = 0;

	//リストの最大数の初期設定
	m_iListKosuu = 12 * 6;

	//画面サイズの初期設定(サイズ：S)
	m_iSizeX = 384;
	m_iSizeY = 288;

	//Y座標のランダム値の幅のデフォルト値(サイズ：S)を設定
	m_iRandMinX = 0;
	m_iRandMaxX = 11;
	m_iRandMinY = 0;
	m_iRandMaxY = 5;
	
	//カーソルのビットマップ選択用変数の初期化
	m_iViewCorsor = 0;
	
	//スコアの初期化
	m_iScore = 0;

	//押しているボタンを示すフラグの初期化(数字は特に意味無し)
	m_iToolBarPutFlg = -1;

	//追加する爆弾の数の初期設定
	m_iAddBomb = 3;

	//LevelUpするスコア間隔の初期設定
	m_iLevelUpScore =10;

	//現在のLevelの初期値
	m_icurrentLevel =1;

	//爆弾の制限時間にランダムに設定される値の上限
	m_iRandamTimeHigh	= 20;

	//爆弾の制限時間にランダムに設定される値の下限
	m_iRandamTimeLow	= 15;

	//デバッグ用フラグ FALSEの時終了時の処理をしない
//	m_bDebugFlg1 = FALSE;
	m_bDebugFlg1 = TRUE;

	//GAME終了判定用フラグ、GAME終了後はFALSEになる
	m_iEndFlg = TRUE;

	//爆弾用ビットマップ選択用変数
	m_iBitmapSelect = 1;

	//ゲームスタート用フラグ
	m_iStartFlg = FALSE;

}

CBombMastarDoc::~CBombMastarDoc()
{


}

BOOL CBombMastarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc シリアライゼーション

void CBombMastarDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください。
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください。
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc クラスの診断

#ifdef _DEBUG
void CBombMastarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBombMastarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc コマンド

int CBombMastarDoc::MYrand( int iMin, int iMax)
{

	int iRenge = iMax-iMin + 1;

	return rand()%iRenge + iMin;

}

void CBombMastarDoc::MYChangexy(RECT *pRect)
{


	//左上X座標×(ビットマップの大きさ)
	pRect->left 	= (long)pRect->left/32;
	//左上Y座標×(ビットマップの大きさ)
	pRect->top		= (long)pRect->top/32;

	//左上X座標 = 右下X座標+32
	pRect->right	= (long)((pRect->left)/32);
	//左上Y座標 = 右下Y座標+32
	pRect->bottom	= (long)((pRect->top)/32);


}

void CBombMastarDoc::OnToolbarbutton1() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください

	//カーソルのビットマップの選択
	m_iViewCorsor = 1;

	//ボタンを押した状態にする<----やり方を変更したら効かなくなった
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON1);

	//カーソルのビットマップの選択
	m_iViewCorsor = 1;

	//ボタンの変更
	MYToolbarbuttonChange( 0 );

}



void CBombMastarDoc::OnToolbarbutton2() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください

	//ボタンを押した状態にする
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON2);

	//カーソルのビットマップの選択
	m_iViewCorsor = 2;

	//ボタンの変更
	MYToolbarbuttonChange( 1 );
}

void CBombMastarDoc::OnToolbarbutton3() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください

	//ボタンを押した状態にする
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON3);

	//カーソルのビットマップの選択
	m_iViewCorsor = 3;

	//ボタンの変更
	MYToolbarbuttonChange( 2 );

}

void CBombMastarDoc::OnToolbarbutton4() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください


	//ボタンを押した状態にする
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON4);

	//カーソルのビットマップの選択
	m_iViewCorsor = 4;

	//ボタンの変更
	MYToolbarbuttonChange( 3 );

}


//ボタンを押した状態にする関数<-------現在使用していない
void CBombMastarDoc::MYToolbarbuttonOn(int iBottonID)
{


	if(m_iToolBarPutFlg != iBottonID)
	{
		CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		//ボタン押す
		pMFrame->m_wndToolBar.GetToolBarCtrl().PressButton( iBottonID,TRUE );

		//前に選択されていたボタン戻す
		pMFrame->m_wndToolBar.GetToolBarCtrl().PressButton( m_iToolBarPutFlg,FALSE );
		//押しボタンフラグにID_TOOLBARBUTTON4を代入
		m_iToolBarPutFlg = iBottonID;
		
	}

}

//ツールバーのボタンを変更する関数
void CBombMastarDoc::MYToolbarbuttonChange(int iButtonFlg)
{
	

	if(m_iToolBarPutFlg != iButtonFlg)
	{
		CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

		//ボタンをツールバーから削除
		pMFrame->m_wndToolBar.GetToolBarCtrl().DeleteButton( iButtonFlg );

		//新しいボタンをツールバーに追加
		pMFrame->m_wndToolBar.GetToolBarCtrl().InsertButton( iButtonFlg, &pMFrame->m_kTbbutonOn[iButtonFlg]);


		//一回目は実施しない
		if(m_iToolBarPutFlg != -1)
		{
			//前に選択されていたボタンをツールバーから削除
			pMFrame->m_wndToolBar.GetToolBarCtrl().DeleteButton( m_iToolBarPutFlg );

			//前に選択されていたボタンの位置に新しいボタンをツールバーに追加
			pMFrame->m_wndToolBar.GetToolBarCtrl().InsertButton( m_iToolBarPutFlg, &pMFrame->m_kTbbutonDef[m_iToolBarPutFlg]);
		}

		//フラグに新しい値を代入
		m_iToolBarPutFlg = iButtonFlg;
	}



}

void CBombMastarDoc::OnMenuitembit() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	
	if(m_iBitmapSelect == 0)
	{
		m_iBitmapSelect = 1;
	}
	else if(m_iBitmapSelect == 1){
		m_iBitmapSelect = 0;
	}

}
