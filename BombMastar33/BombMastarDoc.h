// BombMastarDoc.h : CBombMastarDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMBMASTARDOC_H__8E2FD078_3AC9_4317_B1F8_C6871C6E9D08__INCLUDED_)
#define AFX_BOMBMASTARDOC_H__8E2FD078_3AC9_4317_B1F8_C6871C6E9D08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BombListCnt.h"

class CBombMastarDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CBombMastarDoc();
	DECLARE_DYNCREATE(CBombMastarDoc)

// アトリビュート
public:

// オペレーション
public:


//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CBombMastarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	int m_iRandamTimeHigh;	//爆弾の制限時間にランダムに設定される値の上限
	int m_iRandamTimeLow;	//爆弾の制限時間にランダムに設定される値の下限
	int m_iStartFlg;		//GAMEスタート判定用フラグ
	int m_iBitmapSelect;	//爆弾用ビットマップ選択用変数
	int m_iEndFlg;			//終了判定用フラグ GAME終了後はFALSEになる
	BOOL m_bDebugFlg1;		//デバッグ用フラグ FALSEの時終了時の処理をしない
	int m_iLevelUpScore;	//LevelUpするスコアの間隔
	int m_icurrentLevel;	//現在のLevel
	int m_iAddBomb;			//追加する爆弾の数
	void MYToolbarbuttonChange(int iButtonFlg);
	void MYToolbarbuttonOn(int iBottonID);
	int m_iToolBarPutFlg;	//追加する爆弾の数用変数
	int m_iScore;			//スコア用変数
	int m_iViewCorsor;		//カーソルのビットマップ選択用変数
	int m_iRandMaxY;
	int m_iRandMaxX;
	int m_iRandMinY;
	int m_iRandMinX;
	int m_iListKosuu;		//リストの最大数
	int m_iSizeY;
	int m_iSizeX;
	void MYChangexy(RECT* pRect);
	int m_iBombNo;			//ボムNo用変数
	int MYrand( int iMin, int iMax );

	//CBombListCntクラスのインスタンスをメンバ変数に追加
	CBombListCnt m_cBombListCnt;	//<--------山崎追加
	virtual ~CBombMastarDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CBombMastarDoc)
	afx_msg void OnToolbarbutton1();
	afx_msg void OnToolbarbutton2();
	afx_msg void OnToolbarbutton3();
	afx_msg void OnToolbarbutton4();
	afx_msg void OnMenuitembit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_BOMBMASTARDOC_H__8E2FD078_3AC9_4317_B1F8_C6871C6E9D08__INCLUDED_)
