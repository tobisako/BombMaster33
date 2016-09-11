// BombMastarView.cpp : CBombMastarView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "BombMastar.h"

#include "BombMastarDoc.h"
#include "BombMastarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView

IMPLEMENT_DYNCREATE(CBombMastarView, CView)

BEGIN_MESSAGE_MAP(CBombMastarView, CView)
	//{{AFX_MSG_MAP(CBombMastarView)
	ON_COMMAND(ID_MENUITEM_START, OnMenuitemStart)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMSIZEL, OnMenuitemsizel)
	ON_COMMAND(ID_MENUITEMSIZES, OnMenuitemsizes)
	ON_COMMAND(ID_MENUITEMSIZEM, OnMenuitemsizem)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView クラスの構築/消滅

CBombMastarView::CBombMastarView()
{
	// TODO: この場所に構築用のコードを追加してください。

	//モードレスダイアログの作成
	m_pTimerDlg = new CTimerDlg;
	m_pScoreDlg = new CScoreDlg;

}

CBombMastarView::~CBombMastarView()
{
	//モードレスダイアログの削除
	delete(m_pTimerDlg);
	delete(m_pScoreDlg);
}

BOOL CBombMastarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView クラスの描画

void CBombMastarView::OnDraw(CDC* pDC)
{
	CBombMastarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。

	//リスト内にある情報をすべて描画する
	MYPaint(pDC);

	//終了フラグが終了状態になっている時
	if(pDoc->m_iEndFlg == FALSE)
	{
		//終了時の画面を追加
		MYPaintEnd(GetDC());
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView クラスの印刷

BOOL CBombMastarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CBombMastarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CBombMastarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView クラスの診断

#ifdef _DEBUG
void CBombMastarView::AssertValid() const
{
	CView::AssertValid();
}

void CBombMastarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBombMastarDoc* CBombMastarView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBombMastarDoc)));
	return (CBombMastarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView クラスのメッセージ ハンドラ

void CBombMastarView::OnMenuitemStart() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください


	//ドキュメントクラスのインスタンスのポインタを取得
	CBombMastarDoc* pDoc = (CBombMastarDoc*)this->GetDocument();
	//ウインドウのサイズ変更
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);


	//GAME開始後は処理を受け付けない
	if(this->GetDocument()->m_iStartFlg == TRUE)
	{
		//全リスト開放
		this->GetDocument()->m_cBombListCnt.MYBombAllDel();

		//全設定をデフォルト値をセット
		MYSetDefault();
		return;
	}

	//GAMEスタート判定用フラグをスタート状態に変更
	this->GetDocument()->m_iStartFlg = TRUE;

	//スコア表示用モードレスダイアログの表示
	m_pScoreDlg->Create(IDD_SUCOREDIALOG1);
	m_pScoreDlg->ShowWindow(SW_SHOW);

	//メインフレームのポインタを取得
	CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

	//メインフレームのスクリーン座標を取得
	CRect cFrameRect;
	pMFrame->GetWindowRect(&cFrameRect);

	//スコア表示用モードレスダイアログのサイズを取得<---使いたいのは幅だけ
	CRect cScoreDlgRect;
	m_pScoreDlg->GetClientRect(&cScoreDlgRect);

	//スコア用モードレスダイアログの表示位置の設定
	cScoreDlgRect.left		= cFrameRect.left;
	cScoreDlgRect.top		= cFrameRect.top	- cScoreDlgRect.bottom	-30;
	cScoreDlgRect.right		= cFrameRect.left	+ cScoreDlgRect.right;
	cScoreDlgRect.bottom	= cFrameRect.top	-30;

	//スコア用モードレスダイアログの表示位置の設定をセット
	m_pScoreDlg->SetWindowPos( NULL, cScoreDlgRect.left, cScoreDlgRect.top, -1, -1, SWP_NOSIZE );




	//タイマー用モードレスダイアログの表示   インスタンスはコンストラクタで作成
	m_pTimerDlg->Create(IDD_TIMERDIALOG1);
	m_pTimerDlg->ShowWindow(SW_SHOW);

	//タイマー表示用モードレスダイアログのサイズを取得<---使いたいのは幅だけ
	CRect cTimeDlgRect;
	m_pTimerDlg->GetClientRect(&cTimeDlgRect);

	//タイマー用モードレスダイアログの表示位置の設定
	cTimeDlgRect.left	= cScoreDlgRect.right	+35;
	cTimeDlgRect.top	= cFrameRect.top		- cTimeDlgRect.bottom	-30;
	cTimeDlgRect.right	= cScoreDlgRect.right	+ cTimeDlgRect.right	+35;
	cTimeDlgRect.bottom	= cFrameRect.top		-30;

	//タイマー用モードレスダイアログの表示位置の設定をセット
	m_pTimerDlg->SetWindowPos( NULL, cTimeDlgRect.left, cTimeDlgRect.top, -1, -1, SWP_NOSIZE );

	


	//ワーカースレッドの起動
	CWinThread* pThread = AfxBeginThread(	(AFX_THREADPROC) MYTimerThread1,
											(LPVOID)this,
											THREAD_PRIORITY_NORMAL
										);




}

void CBombMastarView::MYSetTimer( BOOL bTimeONOFF )
{
	if(bTimeONOFF == TRUE)
	{
		SetTimer((UINT)1, (UINT)1000, NULL);

	}
	else{
		KillTimer((UINT)1);

	}

}


void CBombMastarView::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	CBombMastarDoc* pBomDoc = GetDocument();

	if(m_pTimerDlg->m_iTimer == 0)
	{
		//タイマーが０になった時はデフォルトの値に戻す。
		m_pTimerDlg->m_iTimer = m_pTimerDlg->m_iRoopTime;


		//=======↓↓↓リストの追加に関する記述===========
	
		BOMBLIST kAddBombListInfo;

		int i = 0;
		int iListKosuu;
		//データ追加前のデータ数
		pBomDoc->m_cBombListCnt.MYBombKosuu( &iListKosuu );
	
		//爆弾を５個(初期値)追加
		while(( i < pBomDoc->m_iAddBomb )&&( iListKosuu<pBomDoc->m_iListKosuu ))
		{
			i++;

			//爆弾Noの設定
			pBomDoc->m_iBombNo++;
			kAddBombListInfo.iBombNo = pBomDoc->m_iBombNo;

			//爆弾の種類に1～4の値をランダムに設定
			kAddBombListInfo.iBombKind = pBomDoc->MYrand((int)1, (int)4 );


		
			//爆弾の座標の設定
			int iRandamX;
			int iRandamY;
			BOMBLIST* pOutCurrent;
			BOMBLIST* pOutOld;
			int iDetectFlg = 1;

			while(iDetectFlg)
			{
				iRandamX = pBomDoc->MYrand( pBomDoc->m_iRandMinX, pBomDoc->m_iRandMaxX );
				iRandamY = pBomDoc->MYrand( pBomDoc->m_iRandMinY, pBomDoc->m_iRandMaxY );


				if(FALSE == pBomDoc->m_cBombListCnt.MYBombDetect(
								iRandamX, iRandamY, &pOutCurrent,&pOutOld))
				{
					//リストの中に同じ座標のデータがなければフラグを0にする。
					iDetectFlg = 0;

				}

			}


			//変換後に座標をリストに加える構造体に書き込む
			kAddBombListInfo.iBombX = iRandamX;
			kAddBombListInfo.iBombY = iRandamY;

			//爆弾の持ち時間に15～20の値をランダムに設定
			kAddBombListInfo.iBombTime = pBomDoc->MYrand(	pBomDoc->m_iRandamTimeLow,
															pBomDoc->m_iRandamTimeHigh);

			//データをリストに登録
			pBomDoc->m_cBombListCnt.MYBombListAdd(&kAddBombListInfo);

			//追加後のリストデータ数
			pBomDoc->m_cBombListCnt.MYBombKosuu(&iListKosuu);


		}//<-----roop end

		//デバイスコンテキストの表示
		MYPaint(GetDC());

	}


	//スタティックテキストへのタイマーの表示
	m_pTimerDlg->m_cTimer.Format( "%d", m_pTimerDlg->m_iTimer );
	m_pTimerDlg->UpdateData(FALSE);



	//タイマが０になった時にデータ格納用の器を用意
	BOMBLIST *pOutTimeCurrent;

	//リストのタイマ値のデクリメントと０になっていないかのチェック
	if(!pBomDoc->m_cBombListCnt.MYBombTimerCheck( &pOutTimeCurrent ))
	{
		//画面の更新
		MYPaint(GetDC());

		//デバッグ用の記述->m_DebugFlg1 == FALSEの時はタイマが0になっても終了しない
		if(pBomDoc->m_bDebugFlg1 == TRUE)
		{
			//タイマが０になった時の処理をここに書く
			//終了時のビットマップを表示
			MYPaintEnd(GetDC());
			//タイマの停止
			MYSetTimer(FALSE);
			//GAME終了フラグを終了状態にする
			pBomDoc->m_iEndFlg = FALSE;
			//爆発した爆弾のビットマップをGameEnd時のビットマップに変更
			pOutTimeCurrent->iBombGameEndFlg = 1;
			//爆発した爆弾のビットマップを表示するためにViewの更新をする
			MYPaint(GetDC());

		}
	}

	//タイマーダイアログの数値のデクリメント
	m_pTimerDlg->m_iTimer--;

	//GAME終了直後の画面の更新により終了画面が上書きされるのを防ぐ
	if(pBomDoc->m_iEndFlg == TRUE)
	{
		//画面の更新
		MYPaint(GetDC());
	}

	
	CView::OnTimer(nIDEvent);
}



void CBombMastarView::MYPaint(CDC *pDC)
{

	//CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください

	CBombMastarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。


	CDC dcPhoto;
	CBitmap Bitmap_Obj1, Bitmap_Obj2, Bitmap_Obj3, Bitmap_Obj4,
			Bitmap_ObjWhite,
			Bitmap_ObjEnd1, Bitmap_ObjEnd2, Bitmap_ObjEnd3, Bitmap_ObjEnd4;
	CBitmap *pjBtMem;
	
	//ビットマップ用のデバイスコンテキストの作成
	dcPhoto.CreateCompatibleDC(pDC);


	//現在のポインタ
	BOMBLIST* pCurrent;

	//pHeadはリストの先頭ポインタ
	//pHeadはCBombListCntクラスのBOMBLIST*型のメンバ変数
	pCurrent = pDoc->m_cBombListCnt.pHead;
		

	//Cbitmap型のjbmAreaにビットマップをロード
	if(pDoc->m_iBitmapSelect == 0)
	{
		//ビットマップの選択m_iBitmapSelect == 0の時はピンズのビットマップ
		Bitmap_Obj1.LoadBitmap( IDB_BOMB1 );
		Bitmap_Obj2.LoadBitmap( IDB_BOMB2 );
		Bitmap_Obj3.LoadBitmap( IDB_BOMB3 );
		Bitmap_Obj4.LoadBitmap( IDB_BOMB4 );
	}
	else if(pDoc->m_iBitmapSelect == 1){
		//ビットマップの選択m_iBitmapSelect == 1の時はカラーの爆弾ビットマップ

		//爆弾が爆発してない状態のビットマップをロード
		Bitmap_Obj1.LoadBitmap( IDB_BOMB5 );
		Bitmap_Obj2.LoadBitmap( IDB_BOMB6 );
		Bitmap_Obj3.LoadBitmap( IDB_BOMB7 );
		Bitmap_Obj4.LoadBitmap( IDB_BOMB8 );

		//爆弾が爆発後のビットマップをロード
		Bitmap_ObjEnd1.LoadBitmap( IDB_BOMBEND1 );
		Bitmap_ObjEnd2.LoadBitmap( IDB_BOMBEND2 );
		Bitmap_ObjEnd3.LoadBitmap( IDB_BOMBEND3 );
		Bitmap_ObjEnd4.LoadBitmap( IDB_BOMBEND4 );
	}

	Bitmap_ObjWhite.LoadBitmap( IDB_WHITE );


	//置き換えられるインスタンスのポインタの保存
	pjBtMem = dcPhoto.SelectObject(&Bitmap_Obj1);



	//ptr ==NULLのになるまでリストをたどる
	while(pCurrent != NULL)
	{
		if(pCurrent->iBombGameEndFlg == 0 )
		{
			switch(pCurrent->iBombKind)
			{
				case 1: 
					//ビットマップのメモリデバイスコンテキストへの展開
					dcPhoto.SelectObject(&Bitmap_Obj1);
					break;

				case 2:
					dcPhoto.SelectObject(&Bitmap_Obj2);
					break;

				case 3:
					dcPhoto.SelectObject(&Bitmap_Obj3);
					break;

				case 4:
					dcPhoto.SelectObject(&Bitmap_Obj4);
					break;

				case 5:
					dcPhoto.SelectObject(&Bitmap_ObjWhite);
					break;

				default:
						;
			}
		}
		else{
			switch(pCurrent->iBombKind)
			{
				case 1: 
					//ビットマップのメモリデバイスコンテキストへの展開
					dcPhoto.SelectObject(&Bitmap_ObjEnd1);
					break;

				case 2:
					dcPhoto.SelectObject(&Bitmap_ObjEnd2);
					break;

				case 3:
					dcPhoto.SelectObject(&Bitmap_ObjEnd3);
					break;

				case 4:
					dcPhoto.SelectObject(&Bitmap_ObjEnd4);
					break;

				case 5:
					dcPhoto.SelectObject(&Bitmap_ObjWhite);
					break;

				default:
						;
			}
		}


		MYPaintBit( pDC, &dcPhoto, pCurrent);
	
		//次のリストの先頭ポインタをpCurrentに入れる
		pCurrent = pCurrent->ptr;

	}

	

	//後処理
	if(NULL != pDoc->m_cBombListCnt.pHead)
	{
		//メモリデバイスコンテキストの消去
		dcPhoto.DeleteDC();
		//ビットマップのオブジェクトを消去
		Bitmap_Obj1.DeleteObject();
		//置き換えられたインスタンスのポインタを元に戻す
		pDC->SelectObject(pjBtMem);
	}


	// 描画用メッセージとして CView::OnPaint() を呼び出してはいけません
}


void CBombMastarView::MYPaintBit( CDC* pDC, CDC* dcPhoto, BOMBLIST* pCurrent)
{


	//ビットマップをメモリデバイスコンテキストからディスプレイのデバイスコンテキストへ
	pDC->BitBlt( pCurrent->iBombX*32 , pCurrent->iBombY*48 , (pCurrent->iBombX+1)*32 , (pCurrent->iBombY+1)*32 , dcPhoto , 0 , 0 , SRCCOPY );
		
	//タイマーの表示
	CString cBombTimeStr;
	if(!(pCurrent->iBombKind == 5))
	{

		cBombTimeStr.Format("%4d", pCurrent->iBombTime);

	}
	else{

		//爆弾を消去する時は白で上書き
		cBombTimeStr.Format("    ");

	}

	//テキストを表示する領域の設定
	CRect cTextRect;
	cTextRect.left		= pCurrent->iBombX*32;
	cTextRect.top		= pCurrent->iBombY*48+ 32;
	cTextRect.right		= pCurrent->iBombX*32+ 32;
	cTextRect.bottom	= pCurrent->iBombY*48+ 32+ 16;

	//テキストの色の設定用変数
	COLORREF crColor;
	if(pCurrent->iBombTime <= 5)
	{
		//赤を設定
		crColor = 0x000000ff;
	}
	else if( (5< pCurrent->iBombTime)&&(pCurrent->iBombTime < 11) ){

		//黒色を設定
		crColor = 0x00000000;

	}
	else{

		//緑色を設定
		crColor = 0x0000ff00;
	}

	//テキストの色をセット
	pDC->SetTextColor(crColor);

	//テキストの描画
	pDC->DrawText(cBombTimeStr, cTextRect, DT_RIGHT);


}



//サイズL用 20×10 640×480
void CBombMastarView::OnMenuitemsizel() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください

	CBombMastarDoc* pDoc = GetDocument();

	//Viewのサイズの設定
	pDoc->m_iSizeX = 640;
	pDoc->m_iSizeY = 480;

	//リストデータ(爆弾)の最大数の設定
	pDoc->m_iListKosuu = 20 * 10;

	//X,Y座標のランダム値の幅を設定
	pDoc->m_iRandMinX = 0;
	pDoc->m_iRandMaxX = 19;
	pDoc->m_iRandMinY = 0;
	pDoc->m_iRandMaxY = 9;


	//ウインドウのサイズ変更
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);

}


//サイズM用 16×8 512×384
void CBombMastarView::OnMenuitemsizem() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください

	CBombMastarDoc* pDoc = GetDocument();

	//Viewのサイズの設定
	pDoc->m_iSizeX = 512;
	pDoc->m_iSizeY = 384;

	//リストデータ(爆弾)の最大数の設定
	pDoc->m_iListKosuu = 16 * 8;

	//X,Y座標のランダム値の幅を設定
	pDoc->m_iRandMinX = 0;
	pDoc->m_iRandMaxX = 15;
	pDoc->m_iRandMinY = 0;
	pDoc->m_iRandMaxY = 7;

	//ウインドウのサイズ変更
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);


}

//サイズS用 12×6 384×288
void CBombMastarView::OnMenuitemsizes() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	
	CBombMastarDoc* pDoc = GetDocument();

	//Viewのサイズの設定
	pDoc->m_iSizeX = 384;
	pDoc->m_iSizeY = 288;

	//リストデータ(爆弾)の最大数の設定
	pDoc->m_iListKosuu = 12 * 6;

	//X,Y座標のランダム値の幅を設定
	pDoc->m_iRandMinX = 0;
	pDoc->m_iRandMaxX = 11;
	pDoc->m_iRandMinY = 0;
	pDoc->m_iRandMaxY = 5;

	//ウインドウのサイズ変更
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);

}


void CBombMastarView::MYSizeChange(int iWidthX, int iWidthY)
{

	CRect kViewRect;
	CRect kMainRect;

	//ビューの座標の取得
	this->GetWindowRect( kViewRect );
	//ウィンドゥ（メインフレーム）の座標の取得
	CFrameWnd* pcFrame = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
	pcFrame->GetWindowRect( kMainRect );

	//再設定するウィンドゥの座標の設定
	kMainRect.right		= kMainRect.left + (kMainRect.right - kViewRect.right) + (kViewRect.left - kMainRect.left) + iWidthX + 4;
	kMainRect.bottom	= kMainRect.top + (kViewRect.top - kMainRect.top) + (kMainRect.bottom - kViewRect.bottom) + iWidthY + 4;

	//サイズの変更
	AfxGetApp()->m_pMainWnd->MoveWindow( kMainRect );



}




BOOL CBombMastarView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CBombMastarDoc* pDoc = GetDocument();



	if(pDoc->m_iStartFlg == TRUE)
	{


		if(pDoc->m_iBitmapSelect == 0)
		{

			switch(pDoc->m_iViewCorsor)
			{
			case 1:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR1 ));	
				break;

			case 2:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR2 ));
				break;

			case 3:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR3 ));
				break;

			case 4:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR4 ));
				break;

			default:
			;
			}

		}
		else if(pDoc->m_iBitmapSelect == 1){

			switch(pDoc->m_iViewCorsor)
			{
			case 1:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW1 ));	
				break;

			case 2:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW2 ));
				break;

			case 3:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW3 ));
				break;

			case 4:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW4 ));
				break;

			default:
				;
			}
		}

		return TRUE;

	}
	else{

		return CView::OnSetCursor(pWnd, nHitTest, message);
	}

}

void CBombMastarView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	CBombMastarDoc* pDoc = GetDocument();

	CRect cViewRect;

	this->GetClientRect( cViewRect );

	int iX = point.x/32;
	int iY = point.y/48;
	

	BOMBLIST *pOutCurrent;
	BOMBLIST *pOutOld;

	if(FALSE == pDoc->m_cBombListCnt.MYBombDetect( iX, iY, &pOutCurrent, &pOutOld))
	{
		//一致するデータが無い場合は処理をしない
		return;
	}


	if(this->GetDocument()->m_iEndFlg == FALSE)
	{
		//GAME終了後は処理をしない
		return;
	}

	if(pDoc->m_iViewCorsor == 0)
	{
		//まだカーソルが初期状態のままの時は処理をしない
		return;

	}

	if(!(pOutCurrent->iBombKind == pDoc->m_iViewCorsor))
	{
		//爆弾の種類がカーソルの種類と一致していなければ処理を終了
		
		MYPaintEnd(GetDC());
		//タイマの停止
		MYSetTimer(FALSE);
		//GAME終了フラグを終了状態にする
		this->GetDocument()->m_iEndFlg = FALSE;
		//爆発した爆弾のビットマップをGameEnd時のものに変更
		pOutCurrent->iBombGameEndFlg = 1;
		//爆発した爆弾のビットマップを表示するために再描画
		MYPaint( GetDC() );

		return;
	}




	//スコア+1
	pDoc->m_iScore++;

	//レベルアップチェック --- スコアがm_iLevelUpScoreの倍数の時
	
	if( (pDoc->m_iScore)%(pDoc->m_iLevelUpScore) == 0 )
	{

		//レベルアップ
		pDoc->m_icurrentLevel++;

		//次回レベルアップ時のスコア
		pDoc->m_iLevelUpScore += 5*(pDoc->m_icurrentLevel);
		
		//レベルの表示
		m_pScoreDlg->m_LevelStr.Format("レベル%d", pDoc->m_icurrentLevel);


//		if(pDoc->m_icurrentLevel%2 == 0)
//		{
			//レベルが２の倍数の時のみ追加される爆弾の数を追加
			pDoc->m_iAddBomb++;
//		}
//		else{
			//タイマーの値を一つ減らす
//			if((m_pTimerDlg->m_iRoopTime) > 2)
//			{
//				m_pTimerDlg->m_iRoopTime--;
//			}
//		}

	}

	//スコアの表示
	m_pScoreDlg->m_ScoreStr.Format("%d", pDoc->m_iScore);
	m_pScoreDlg->UpdateData(FALSE);



	//爆弾の種類に消すアイテムを示す5を代入
	pOutCurrent->iBombKind = 5;
	//消す爆弾の所を白で塗りなおす為に再描画
	MYPaint( GetDC() );
	//該当するデータをリストから削除
	pDoc->m_cBombListCnt.MYBombListDel(pOutCurrent, pOutOld);




	CView::OnLButtonDown(nFlags, point);
}



LRESULT CBombMastarView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	
	return CView::DefWindowProc(message, wParam, lParam);
}



void CBombMastarView::MYPaintEnd(CDC *pDC)
{

	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください

	CBombMastarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。


	CDC dcPhoto1, dcPhoto2;
	CBitmap Bitmap_Obj1, Bitmap_Obj2;
	CBitmap *pjBtMem1,*pjBtMem2;
	
	//ビットマップ用のデバイスコンテキストの作成
	dcPhoto1.CreateCompatibleDC(pDC);
	dcPhoto2.CreateCompatibleDC(pDC);

	//Cbitmap型のjbmAreaにビットマップをロード
	Bitmap_Obj1.LoadBitmap( IDB_GAMEEND1 );
	Bitmap_Obj2.LoadBitmap( IDB_WHITE );

	//置き換えられるインスタンスのポインタの保存
	pjBtMem1 = dcPhoto1.SelectObject(&Bitmap_Obj1);
	pjBtMem2 = dcPhoto2.SelectObject(&Bitmap_Obj2);


	CRect kViewRect;

	//ビューの座標の取得
	this->GetWindowRect( kViewRect );



	//m_iEndFlgはGAME終了後、最初に呼ばれた時のみFALSEのままで、
	//2回目以降OnDrow等でコールされた時はTRUEとなっている
	if(pDoc->m_iEndFlg == TRUE)
	{
		int i;

		//終了画面の拡大
		for(i=1 ;i<20 ;i++)
		{
			//0.1秒間隔でビットマップ拡大

			pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16*i,
								(kViewRect.bottom - kViewRect.top)/2-16*i,
								32*i ,32*i , &dcPhoto1, 0 , 0 ,32 ,32, SRCCOPY );


			Sleep(50);
		}

		//終了画面の縮小
		for(i=20 ;i>0 ;i--)
		{
			//0.1秒間隔でビットマップ縮小

			//画面をリフレッシュ
			if(i==1)
			{
				//白のビットマップを拡大して表示することにより画面をリフレッシュ
				pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16*20,
									(kViewRect.bottom - kViewRect.top)/2-16*20,
									32*20 ,32*20 , &dcPhoto2, 0 , 0 ,32 ,32, SRCCOPY );
			

				//リスト内の爆弾を描画
				MYPaint(GetDC());
		
			}

			//終了画面を描画
			pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16*i,
								(kViewRect.bottom - kViewRect.top)/2-16*i,
								32*i ,32*i , &dcPhoto1, 0 , 0 ,32 ,32, SRCCOPY );

			
			Sleep(50);
		}


		//終了画面表示部分を白く描画
		pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16,
							(kViewRect.bottom - kViewRect.top)/2-16,
							32 ,32 , &dcPhoto2, 0 , 0 ,32 ,32, SRCCOPY );

	}


	//画面の更新--リストの中身の表示
	MYPaint(GetDC());


	//メモリデバイスコンテキストの消去
	dcPhoto1.DeleteDC();
	dcPhoto2.DeleteDC();
	//ビットマップのオブジェクトを消去
	Bitmap_Obj1.DeleteObject();
	Bitmap_Obj2.DeleteObject();
	//置き換えられたインスタンスのポインタを元に戻す
	pDC->SelectObject(pjBtMem1);
	pDC->SelectObject(pjBtMem2);

}

void CBombMastarView::MYSetDefault()
{


	CBombMastarDoc* pDoc = (CBombMastarDoc*)this->GetDocument();

	//ボムNoの初期化
	pDoc->m_iBombNo = 0;

	//リストの最大数の初期設定
//	m_iListKosuu = 12 * 6;

	//画面サイズの初期設定(サイズ：S)
//	m_iSizeX = 384;
//	m_iSizeY = 288;

	//Y座標のランダム値の幅のデフォルト値(サイズ：S)を設定
//	m_iRandMinX = 0;
//	m_iRandMaxX = 11;
//	m_iRandMinY = 0;
//	m_iRandMaxY = 5;
	
	//カーソルのビットマップ選択用変数の初期化
//	pDoc->m_iViewCorsor = 0;
	
	//スコアの初期化
	pDoc->m_iScore = 0;

	//押しているボタンを示すフラグの初期化(数字は特に意味無し)
//	m_iToolBarPutFlg = -1;

	//追加する爆弾の数の初期設定
	pDoc->m_iAddBomb = 3;

	//LevelUpするスコア間隔の初期設定
	pDoc->m_iLevelUpScore =10;

	//現在のLevelの初期値
	pDoc->m_icurrentLevel =1;

	//爆弾の制限時間にランダムに設定される値の上限
//	pDoc->m_iRandamTimeHigh	= 20;

	//爆弾の制限時間にランダムに設定される値の下限
//	pDoc->m_iRandamTimeLow	= 15;

	//デバッグ用フラグ FALSEの時終了時の処理をしない
	pDoc->m_bDebugFlg1 = TRUE;

	//GAME終了判定用フラグ、GAME終了後はFALSEになる
	pDoc->m_iEndFlg = TRUE;

	//爆弾用ビットマップ選択用変数
//	pDoc->m_iBitmapSelect = 1;

	//ゲームスタート用フラグ
	pDoc->m_iStartFlg = TRUE;

	//スコアダイアログの表示の初期化
//	CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	
	//スコアの初期化
	pDoc->m_iScore = 0;
	//スコアの表示
	m_pScoreDlg->m_ScoreStr.Format("%d", pDoc->m_iScore);
	m_pScoreDlg->UpdateData(FALSE);

	//レベルの初期化
	pDoc->m_icurrentLevel = 1;
	//レベルの表示
	m_pScoreDlg->m_LevelStr.Format("レベル%d", pDoc->m_icurrentLevel);
	m_pScoreDlg->UpdateData(FALSE);

	//タイマのセット
	MYSetTimer(TRUE);
	
	//タイマをデフォルト状態に戻す
	m_pTimerDlg->m_iTimer = m_pTimerDlg->m_iDefaultTime;
	m_pTimerDlg->m_cTimer.Format( "%d", m_pTimerDlg->m_iTimer );
	m_pTimerDlg->UpdateData(FALSE);

	//Viewの更新
	AfxGetApp()->m_pMainWnd->RedrawWindow();



}
