#if !defined(AFX_SCOREDLG_H__0B51C399_C155_4BAE_8429_8C3C282A3256__INCLUDED_)
#define AFX_SCOREDLG_H__0B51C399_C155_4BAE_8429_8C3C282A3256__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg �_�C�A���O

class CScoreDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CScoreDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CScoreDlg)
	enum { IDD = IDD_SUCOREDIALOG1 };
	CString	m_ScoreStr;
	CString	m_LevelStr;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CScoreDlg)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SCOREDLG_H__0B51C399_C155_4BAE_8429_8C3C282A3256__INCLUDED_)
