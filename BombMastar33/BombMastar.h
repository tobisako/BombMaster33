// BombMastar.h : BOMBMASTAR �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_BOMBMASTAR_H__C889A404_190C_4131_A658_59F534209D04__INCLUDED_)
#define AFX_BOMBMASTAR_H__C889A404_190C_4131_A658_59F534209D04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��
#include "ScoreDlg.h"	// ClassView �ɂ���Ēǉ�����܂����B

/////////////////////////////////////////////////////////////////////////////
// CBombMastarApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� BombMastar.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CBombMastarApp : public CWinApp
{
public:
	//�X�R�A�p���[�h���X�_�C�A���O�p�ϐ�
//	CScoreDlg* m_pScoreDlg;	//<-------�R��ǉ�

	CBombMastarApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CBombMastarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CBombMastarApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_BOMBMASTAR_H__C889A404_190C_4131_A658_59F534209D04__INCLUDED_)
