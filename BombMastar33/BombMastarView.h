// BombMastarView.h : CBombMastarView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMBMASTARVIEW_H__F86687C7_5A7F_4953_BC46_F671A50099C9__INCLUDED_)
#define AFX_BOMBMASTARVIEW_H__F86687C7_5A7F_4953_BC46_F671A50099C9__INCLUDED_

#include "ScoreDlg.h"	// ClassView �ɂ���Ēǉ�����܂����B
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBombMastarView : public CView
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CBombMastarView();
	DECLARE_DYNCREATE(CBombMastarView)

// �A�g���r���[�g
public:
	CBombMastarDoc* GetDocument();



// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CBombMastarView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	void MYSetDefault();
	void MYPaintEnd(CDC *pDC);
	
	void MYPaintBit( CDC* pDC, CDC* dcPhoto, BOMBLIST* pCurrent);
	void MYSizeChange( int iWidthX, int iWidthY );
	void MYPaint(CDC* pDC);
	void MYSetTimer(BOOL bTimeONOFF);
	CTimerDlg* m_pTimerDlg;				//<------�R��ǉ�
	CScoreDlg* m_pScoreDlg;				//<------�R��ǉ�
	friend UINT MYTimerThread1(LPVOID);	//<------�R��ǉ�
	virtual ~CBombMastarView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CBombMastarView)
	afx_msg void OnMenuitemStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuitemsizel();
	afx_msg void OnMenuitemsizes();
	afx_msg void OnMenuitemsizem();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // BombMastarView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CBombMastarDoc* CBombMastarView::GetDocument()
   { return (CBombMastarDoc*)m_pDocument; }
#endif





/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_BOMBMASTARVIEW_H__F86687C7_5A7F_4953_BC46_F671A50099C9__INCLUDED_)
