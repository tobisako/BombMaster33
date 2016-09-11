// TimerDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "BombMastar.h"
#include "TimerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg ダイアログ


CTimerDlg::CTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimerDlg)
	m_cTimer = _T("0");
	//}}AFX_DATA_INIT



	m_iDefaultTime = 0;		//タイマーの初期値の設定
	m_iRoopTime = 5;		//タイマーの繰り返し間隔の設定
	m_iTimer = m_iDefaultTime;	//初期値のセット

}


void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimerDlg)
	DDX_Text(pDX, IDC_BombTimer1, m_cTimer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimerDlg, CDialog)
	//{{AFX_MSG_MAP(CTimerDlg)
	ON_BN_CLICKED(IDC_BombTimer1, OnBombTimer1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg メッセージ ハンドラ

void CTimerDlg::OnBombTimer1() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	
}
