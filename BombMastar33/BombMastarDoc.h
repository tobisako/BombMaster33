// BombMastarDoc.h : CBombMastarDoc �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
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
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CBombMastarDoc();
	DECLARE_DYNCREATE(CBombMastarDoc)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:


//�I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CBombMastarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	int m_iRandamTimeHigh;	//���e�̐������ԂɃ����_���ɐݒ肳���l�̏��
	int m_iRandamTimeLow;	//���e�̐������ԂɃ����_���ɐݒ肳���l�̉���
	int m_iStartFlg;		//GAME�X�^�[�g����p�t���O
	int m_iBitmapSelect;	//���e�p�r�b�g�}�b�v�I��p�ϐ�
	int m_iEndFlg;			//�I������p�t���O GAME�I�����FALSE�ɂȂ�
	BOOL m_bDebugFlg1;		//�f�o�b�O�p�t���O FALSE�̎��I�����̏��������Ȃ�
	int m_iLevelUpScore;	//LevelUp����X�R�A�̊Ԋu
	int m_icurrentLevel;	//���݂�Level
	int m_iAddBomb;			//�ǉ����锚�e�̐�
	void MYToolbarbuttonChange(int iButtonFlg);
	void MYToolbarbuttonOn(int iBottonID);
	int m_iToolBarPutFlg;	//�ǉ����锚�e�̐��p�ϐ�
	int m_iScore;			//�X�R�A�p�ϐ�
	int m_iViewCorsor;		//�J�[�\���̃r�b�g�}�b�v�I��p�ϐ�
	int m_iRandMaxY;
	int m_iRandMaxX;
	int m_iRandMinY;
	int m_iRandMinX;
	int m_iListKosuu;		//���X�g�̍ő吔
	int m_iSizeY;
	int m_iSizeX;
	void MYChangexy(RECT* pRect);
	int m_iBombNo;			//�{��No�p�ϐ�
	int MYrand( int iMin, int iMax );

	//CBombListCnt�N���X�̃C���X�^���X�������o�ϐ��ɒǉ�
	CBombListCnt m_cBombListCnt;	//<--------�R��ǉ�
	virtual ~CBombMastarDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_BOMBMASTARDOC_H__8E2FD078_3AC9_4317_B1F8_C6871C6E9D08__INCLUDED_)
