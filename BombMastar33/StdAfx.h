// stdafx.h : 標準のシステム インクルード ファイル、
//            または参照回数が多く、かつあまり変更されない
//            プロジェクト専用のインクルード ファイルを記述します。
//

#if !defined(AFX_STDAFX_H__6B5A1050_847C_4A2A_97B7_EABE2068281D__INCLUDED_)
#define AFX_STDAFX_H__6B5A1050_847C_4A2A_97B7_EABE2068281D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows ヘッダーから殆ど使用されないスタッフを除外します。

#include <afxwin.h>         // MFC のコアおよび標準コンポーネント
#include <afxext.h>         // MFC の拡張部分
#include <afxdisp.h>        // MFC のオートメーション クラス
#include <afxdtctl.h>		// MFC の Internet Explorer 4 コモン コントロール サポート
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC の Windows コモン コントロール サポート
#endif // _AFX_NO_AFXCMN_SUPPORT


#include "TimerDlg.h"
#include "BombMastar.h"
#include "BombMastarDoc.h"
#include <stdlib.h>
#include "Resource.h"
#include "BombMastarView.h"
#include "MainFrm.h"


#define WM_USER_BOMB1 WM_USER+1
#define WM_USER_BOMB2 WM_USER+2
#define WM_USER_BOMB3 WM_USER+3
#define WM_USER_BOMB4 WM_USER+4

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_STDAFX_H__6B5A1050_847C_4A2A_97B7_EABE2068281D__INCLUDED_)
