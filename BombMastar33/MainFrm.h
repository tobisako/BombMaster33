// MainFrm.h : CMainFrame �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__261B6B25_36D2_4DDF_B983_6B2EE8E6D2BA__INCLUDED_)
#define AFX_MAINFRM_H__261B6B25_36D2_4DDF_B983_6B2EE8E6D2BA__INCLUDED_

#include "TimerDlg.h"	// ClassView �ɂ���Ēǉ�����܂����B
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BombMastatToolBar.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:

	CTimerDlg* m_pTimerDlg;				//<------�R��ǉ�
	void MYFTBarSetPosition();			//<------�R��ǉ�
	void MYFTBarSetWidth();				//<------�R��ǉ�
	friend UINT MYTimerThread1(LPVOID);	//<------�R��ǉ�

	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �R���g���[�� �o�[�p�����o
	CStatusBar  m_wndStatusBar;
//	CBombMastatToolBar m_wndToolBar;  //<----protected����public�ɕύX �R��
public:
	TBBUTTON m_kTbbutonDef[4];
	TBBUTTON m_kTbbutonOn[4];
	CImageList m_iml;
	CBombMastatToolBar m_wndToolBar;

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MAINFRM_H__261B6B25_36D2_4DDF_B983_6B2EE8E6D2BA__INCLUDED_)
