#if !defined(AFX_TIMERDLG_H__521F4139_FC25_4453_8416_584CDC7CC09F__INCLUDED_)
#define AFX_TIMERDLG_H__521F4139_FC25_4453_8416_584CDC7CC09F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"
// TimerDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg �_�C�A���O

class CTimerDlg : public CDialog
{
// �R���X�g���N�V����
public:
	UINT m_iRoopTime;		//�^�C�}�̊Ԋu�ݒ�p�ϐ�
	UINT m_iDefaultTime;	//�^�C�}�̃f�t�H���g�ݒ�p�ϐ�
	UINT m_iTimer;			//�^�C�}�p�ϐ�
	CTimerDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTimerDlg)
	enum { IDD = IDD_TIMERDIALOG1 };
	CString	m_cTimer;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CTimerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTimerDlg)
	afx_msg void OnBombTimer1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_TIMERDLG_H__521F4139_FC25_4453_8416_584CDC7CC09F__INCLUDED_)
