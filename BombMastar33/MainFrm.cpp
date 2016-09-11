// MainFrm.cpp : CMainFrame クラスの動作の定義を行います。
//

#include "stdafx.h"
//#include "BombMastar.h"

#include "MainFrm.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ステータス ライン インジケータ
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの構築/消滅

CMainFrame::CMainFrame()
{
	// TODO: この位置にメンバの初期化処理コードを追加してください。

	

	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;


//	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
//		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
//		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
//	{
//		TRACE0("Failed to create toolbar\n");
//		return -1;      // 作成に失敗
//	}

	//最初にツールバーのビットマップイメージをロードしないように変更
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // 作成に失敗
	}



	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}


	int i = 0;


	//イメージリストに追加するイメージリストの情報
	for(i=0; i<4; i++)
	{
		m_kTbbutonDef[i].iBitmap	= i;
		m_kTbbutonDef[i].idCommand	= NULL;
		m_kTbbutonDef[i].fsState	= TBSTATE_ENABLED;
		m_kTbbutonDef[i].fsStyle	= TBSTYLE_CHECKGROUP;
		m_kTbbutonDef[i].dwData		= NULL;
		m_kTbbutonDef[i].iString	= NULL;

		m_kTbbutonOn[i].iBitmap		= i+4;
		m_kTbbutonOn[i].idCommand	= NULL;
		m_kTbbutonOn[i].fsState		= TBSTATE_PRESSED;
		m_kTbbutonOn[i].fsStyle		= TBSTYLE_BUTTON;
		m_kTbbutonOn[i].dwData		= NULL;
		m_kTbbutonOn[i].iString		= NULL;

	}

	m_kTbbutonDef[0].idCommand	= WM_USER_BOMB1;
	m_kTbbutonDef[1].idCommand	= WM_USER_BOMB2;
	m_kTbbutonDef[2].idCommand	= WM_USER_BOMB3;
	m_kTbbutonDef[3].idCommand	= WM_USER_BOMB4;
	m_kTbbutonOn[0].idCommand	= WM_USER_BOMB1;
	m_kTbbutonOn[1].idCommand	= WM_USER_BOMB2;
	m_kTbbutonOn[2].idCommand	= WM_USER_BOMB3;
	m_kTbbutonOn[3].idCommand	= WM_USER_BOMB4;

	//イメージリストにビットマップを追加
	m_wndToolBar.GetToolBarCtrl().AddBitmap(4, IDR_TOOLBAR1 );
	m_wndToolBar.GetToolBarCtrl().AddBitmap(4, IDR_TOOLBAR2 );

	//指定した場所にボタンを追加（表示）
	m_wndToolBar.GetToolBarCtrl().InsertButton( 0, &m_kTbbutonDef[0]);
	m_wndToolBar.GetToolBarCtrl().InsertButton( 1, &m_kTbbutonDef[1]);
	m_wndToolBar.GetToolBarCtrl().InsertButton( 2, &m_kTbbutonDef[2]);
	m_wndToolBar.GetToolBarCtrl().InsertButton( 3, &m_kTbbutonDef[3]);




	//ホット状態のイメージリストを作成
	//m_imlはCImageList型のメンバ変数
	m_iml.Create( IDR_TOOLBAR3, 32, 8, 0xc0c0c0 );

	//ホットイメージリストをツールバーに割り当てる
	m_wndToolBar.GetToolBarCtrl().SendMessage(	TB_SETHOTIMAGELIST,
												0,
												(LPARAM)m_iml.m_hImageList
											);



	//ボタンのサイズの設定
	SIZE kBottonSize;
	kBottonSize.cx = 32+7;
	kBottonSize.cy = 32+6;

	//ボタンのイメージのサイズの設定
	SIZE kBottonImage;
	kBottonImage.cx = 32;
	kBottonImage.cy = 32;

	//ボタンのサイズをセットすることでツールバーのサイズを変更
	m_wndToolBar.SetSizes(kBottonSize, kBottonImage);


	// TODO: ツール バーをドッキング可能にしない場合は以下の３行を削除
	//       してください。
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	CPoint point;
	point.x = 400;	//<------後で移動させるので意味はほとんど無い
	point.y = 350;	//<------後で移動させるので意味はほとんど無い

//start - 2001/09/24 Comment Out:フロート状態にしない事にした
	//ツールバーをフロート状態にする。
	//FloatControlBar( &m_wndToolBar ,point);
//End   - 2001/09/24 Comment Out:フロート状態にしない事にした

	//ステータスバーを非表示
	ShowControlBar( &m_wndStatusBar, FALSE, FALSE );

	//ウィンドウを画面中央に表示する。
	CenterWindow( GetDesktopWindow() );

	
//start - 2001/09/24 Comment Out:フロート状態にしない事にした
	//フローティングツールバーの位置変更
	//注意!!この位置じゃないとダメ、CenterWindow()の前にすると
	//毎回違う位置に表示される
	//MYFTBarSetPosition();
//End   - 2001/09/24 Comment Out:フロート状態にしない事にした

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{

	cs.x = 300;
	cs.y = 300;
	cs.cx = 384;
	cs.cy = 288;
	
	//サイズ変更のスタイルを外す
	cs.style = cs.style^WS_THICKFRAME;


	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: この位置で CREATESTRUCT cs を修正して、Window クラスやスタイルを
	//       修正してください。



	GetDesktopWindow();


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの診断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG



//========↓↓↓ここから山崎追加[フローティングツールバーの移動方法]===================
void CMainFrame::MYFTBarSetPosition()
{

	CWnd* pWnd = m_wndToolBar.GetParent()->GetParent();
	if( pWnd->GetSafeHwnd() != GetSafeHwnd() )
	{
		//ここで必要な処理をする
		CRect rcFrame( 338, -108, 0, 0 );
		ClientToScreen( rcFrame );
		pWnd->SetWindowPos( NULL, rcFrame.left, rcFrame.top, -1, -1, SWP_NOSIZE );
	}

	MYFTBarSetWidth();

}

//========↑↑↑ここまで山崎追加[フローティングツールバーの移動方法]===================


//========↓↓↓ここから山崎追加[フローティングツールバーの幅指定]=====================
void CMainFrame::MYFTBarSetWidth()
{
	m_wndToolBar.m_nMRUWidth = 600;
	ShowControlBar( &m_wndToolBar , TRUE , FALSE );
}

//========↑↑↑ここまで山崎追加[フローティングツールバーの幅指定]=====================



/////////////////////////////////////////////////////////////////////////////
// CMainFrame メッセージ ハンドラ
