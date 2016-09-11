
#include "stdafx.h"
#include "MainFrm.h"
#include "BombMastarView.h"


//マルチスレッドで動作させたい関数の呼び出しを行う。
UINT MYTimerThread1( LPVOID pvParam )
{


	//メインウィンドウのポインタの取得
	CBombMastarView* pBombMastarView = ( CBombMastarView* )pvParam;

	//MYSetTimer()関数呼び出し
	//MYSetTimer()の中でセットタイマーをする
	pBombMastarView->MYSetTimer(TRUE);



	return(0);
}