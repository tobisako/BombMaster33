// BombListCnt.cpp: CBombListCnt クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BombMastar.h"
#include "BombListCnt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

CBombListCnt::CBombListCnt()
{
	//リストの先頭ポインタの初期化
	pHead = NULL;
}

CBombListCnt::~CBombListCnt()
{
	//CBombListCntクラス削除時に全リストを開放
	MYBombAllDel();
}

void CBombListCnt::MYBombListAdd(BOMBLIST *pkBombInfo)
{

	//構造体の定義はヘッダファイルに記載
	//	typedef struct kBombList{
	//		int iBombNo;		爆弾No
	//		int iBombKind;		爆弾の種類
	//		int iBombX;			爆弾X座標
	//		int iBombY;			爆弾Y座標
	//		int iBombTime;		タイマー
	//		int iBombHeadFlg;	先頭判定フラグ
	//		struct kBombList* ptr;
	//	} BOMBLIST;


	//現在のポインタ
	BOMBLIST* pCurrent;

	//pHeadはリストの先頭ポインタ
	//pHeadはCBombListCntクラスのBOMBLIST*型のメンバ変数
	pCurrent = pHead;

		
	//ptr ==NULLのになるまでリストをたどる

	if(pHead == NULL)
	{
		//追加分のリストの領域確保
		pHead = new(BOMBLIST);
		//確保した領域に情報をコピー
		pHead->iBombNo			= pkBombInfo->iBombNo;
		pHead->iBombKind		= pkBombInfo->iBombKind;
		pHead->iBombX			= pkBombInfo->iBombX;
		pHead->iBombY			= pkBombInfo->iBombY;
		pHead->iBombTime		= pkBombInfo->iBombTime;
		pHead->iBombHeadFlg		= (int)1;
		pHead->iBombGameEndFlg	= (int)0;
		pHead->ptr				= NULL;

	}
	else{

		//リストをたどる
		while(pCurrent->ptr != NULL)
		{
			pCurrent = pCurrent->ptr;
			

		}

		//追加分のリストの領域確保
		pCurrent->ptr = new(BOMBLIST);

		//確保した領域に情報をコピー
		pCurrent->ptr->iBombNo			= pkBombInfo->iBombNo;
		pCurrent->ptr->iBombKind		= pkBombInfo->iBombKind;
		pCurrent->ptr->iBombX			= pkBombInfo->iBombX;
		pCurrent->ptr->iBombY			= pkBombInfo->iBombY;
		pCurrent->ptr->iBombTime		= pkBombInfo->iBombTime;
		pCurrent->ptr->iBombHeadFlg		= (int)0;
		pCurrent->ptr->iBombGameEndFlg	= (int)0;
		pCurrent->ptr->ptr				= NULL;
	}


}

BOOL CBombListCnt::MYBombDetect(int iX, int iY, BOMBLIST **pOutCurrent, BOMBLIST **pOutOld)
{

	//現在のポインタ
	BOMBLIST* pCurrent;

	//pHeadはリストの先頭ポインタ
	//pHeadはCBombListCntクラスのBOMBLIST*型のメンバ変数
	pCurrent = pHead;

	//*pOutOldの初期値
	*pOutOld = pHead;
	
	if(pHead == NULL){
		return FALSE;
	}

	//ptr ==NULLのになるまでリストをたどる
	while(pCurrent != NULL)
	{
		
		//検索する爆弾の座標と一致するデータを探す
		if( ( pCurrent->iBombX == iX )&&( pCurrent->iBombY == iY ) )
		{
			
			//一致するデータのポインタを返す
			*pOutCurrent = pCurrent;
			//一致するデータが見つかった時は戻り値を真にする
			return TRUE;

		}

		//１個前のデータのポインタを保存しておくため
		*pOutOld = pCurrent;

		//次のデータのポインタをpCurrentに代入
		pCurrent = pCurrent->ptr;
	}

	*pOutCurrent = pCurrent;
	//一致するデータが見つからなかった時は戻り値を偽にする
	return FALSE;

}

void CBombListCnt::MYBombListDel(BOMBLIST *pOutCurrent, BOMBLIST *pOutOldPtr)
{

	int iBombKosuu;

	MYBombKosuu( &iBombKosuu );

	//先頭ポインタの判定　iBombHeadFlgが1の時先頭データである事を示す。
	if(pOutCurrent->iBombHeadFlg)
	{
		BOMBLIST* pHeadbk;
		//先頭ポインタの保存
		pHeadbk = pHead;
		//pHeadに次のリストのポインタを代入
		pHead = pHead->ptr;
		//次のリストの先頭判定フラグを1にする
		if(iBombKosuu > 1)
		{
			pHead->iBombHeadFlg	= (int)1;
		}
		//保存したリストの先頭データの領域開放
		delete(pHeadbk);
		pHeadbk = NULL;

	
	//先頭ポインタではないとき
	}
	else{

		//前のリストのポインタと次のリストのポインタをつなぐ
		pOutOldPtr->ptr = pOutCurrent->ptr;

		//現在のリストの領域を開放
		delete(pOutCurrent);
		pOutCurrent = NULL;

	}

}

BOOL CBombListCnt::MYBombTimerCheck(BOMBLIST **pOutCurrent)
{

	//現在のポインタ
	BOMBLIST* pCurrent;

	//タイマーフラグ ０になった時、FALSEになる
	BOOL bTimeFlg = TRUE;

	//pHeadはリストの先頭ポインタ
	//pHeadはCBombListCntクラスのBOMBLIST*型のメンバ変数
	pCurrent = pHead;

		
	//ptr ==NULLのになるまでリストをたどる
	while(pCurrent != NULL)
	{
		//タイマーが０より大きいはデクリメントを実行
		if(pCurrent->iBombTime >0)
		{
			pCurrent->iBombTime--;
		}

		//タイマーが０になった時の初めのポインタを返す
		if (( pCurrent->iBombTime <= 0 )&&( bTimeFlg == TRUE))
		{
			*pOutCurrent = pCurrent;
			bTimeFlg = FALSE;

		}

		pCurrent = pCurrent->ptr;

	}


	//０にならずに全てのタイマーをデクリメントできれば戻り値は真
	return bTimeFlg;

}

void CBombListCnt::MYBombKosuu(int *piOutBombKosuu)
{

	//個数
	int iKosuu = 0;

	//現在のポインタ
	BOMBLIST* pCurrent = pHead;


	//リストをたどる
	while(pCurrent != NULL)
	{
		pCurrent = pCurrent->ptr;
		iKosuu++;
	}


	*piOutBombKosuu = iKosuu;


}

void CBombListCnt::MYBombAllDel()
{

	int iBombKosuu;
	MYBombKosuu( &iBombKosuu );

	//先頭ポインタがNULLになるまで削除をくり返す
	while(pHead != NULL)
	{
		MYBombKosuu( &iBombKosuu );

		BOMBLIST* pHeadbk;
		//先頭ポインタの保存
		pHeadbk = pHead;
		//pHeadに次のリストのポインタを代入
		pHead = pHead->ptr;
		//次のリストの先頭判定フラグを1にする
		if(iBombKosuu > 1)
		{
			pHead->iBombHeadFlg	= (int)1;
		}
		//保存したリストの先頭データの領域開放
		delete(pHeadbk);
		pHeadbk = NULL;
	}


}
