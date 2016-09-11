// BombMastarDoc.cpp : CBombMastarDoc �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc

IMPLEMENT_DYNCREATE(CBombMastarDoc, CDocument)

BEGIN_MESSAGE_MAP(CBombMastarDoc, CDocument)
	//{{AFX_MSG_MAP(CBombMastarDoc)
	ON_COMMAND(WM_USER_BOMB1, OnToolbarbutton1)
	ON_COMMAND(WM_USER_BOMB2, OnToolbarbutton2)
	ON_COMMAND(WM_USER_BOMB3, OnToolbarbutton3)
	ON_COMMAND(WM_USER_BOMB4, OnToolbarbutton4)
	ON_COMMAND(ID_MENUITEMBIT, OnMenuitembit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc �N���X�̍\�z/����

CBombMastarDoc::CBombMastarDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

	//�����_���֐��p
	srand( (unsigned)time(NULL) );

	//�{��No�̏�����
	m_iBombNo = 0;

	//���X�g�̍ő吔�̏����ݒ�
	m_iListKosuu = 12 * 6;

	//��ʃT�C�Y�̏����ݒ�(�T�C�Y�FS)
	m_iSizeX = 384;
	m_iSizeY = 288;

	//Y���W�̃����_���l�̕��̃f�t�H���g�l(�T�C�Y�FS)��ݒ�
	m_iRandMinX = 0;
	m_iRandMaxX = 11;
	m_iRandMinY = 0;
	m_iRandMaxY = 5;
	
	//�J�[�\���̃r�b�g�}�b�v�I��p�ϐ��̏�����
	m_iViewCorsor = 0;
	
	//�X�R�A�̏�����
	m_iScore = 0;

	//�����Ă���{�^���������t���O�̏�����(�����͓��ɈӖ�����)
	m_iToolBarPutFlg = -1;

	//�ǉ����锚�e�̐��̏����ݒ�
	m_iAddBomb = 3;

	//LevelUp����X�R�A�Ԋu�̏����ݒ�
	m_iLevelUpScore =10;

	//���݂�Level�̏����l
	m_icurrentLevel =1;

	//���e�̐������ԂɃ����_���ɐݒ肳���l�̏��
	m_iRandamTimeHigh	= 20;

	//���e�̐������ԂɃ����_���ɐݒ肳���l�̉���
	m_iRandamTimeLow	= 15;

	//�f�o�b�O�p�t���O FALSE�̎��I�����̏��������Ȃ�
//	m_bDebugFlg1 = FALSE;
	m_bDebugFlg1 = TRUE;

	//GAME�I������p�t���O�AGAME�I�����FALSE�ɂȂ�
	m_iEndFlg = TRUE;

	//���e�p�r�b�g�}�b�v�I��p�ϐ�
	m_iBitmapSelect = 1;

	//�Q�[���X�^�[�g�p�t���O
	m_iStartFlg = FALSE;

}

CBombMastarDoc::~CBombMastarDoc()
{


}

BOOL CBombMastarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc �V���A���C�[�[�V����

void CBombMastarDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc �N���X�̐f�f

#ifdef _DEBUG
void CBombMastarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBombMastarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBombMastarDoc �R�}���h

int CBombMastarDoc::MYrand( int iMin, int iMax)
{

	int iRenge = iMax-iMin + 1;

	return rand()%iRenge + iMin;

}

void CBombMastarDoc::MYChangexy(RECT *pRect)
{


	//����X���W�~(�r�b�g�}�b�v�̑傫��)
	pRect->left 	= (long)pRect->left/32;
	//����Y���W�~(�r�b�g�}�b�v�̑傫��)
	pRect->top		= (long)pRect->top/32;

	//����X���W = �E��X���W+32
	pRect->right	= (long)((pRect->left)/32);
	//����Y���W = �E��Y���W+32
	pRect->bottom	= (long)((pRect->top)/32);


}

void CBombMastarDoc::OnToolbarbutton1() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������

	//�J�[�\���̃r�b�g�}�b�v�̑I��
	m_iViewCorsor = 1;

	//�{�^������������Ԃɂ���<----������ύX����������Ȃ��Ȃ���
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON1);

	//�J�[�\���̃r�b�g�}�b�v�̑I��
	m_iViewCorsor = 1;

	//�{�^���̕ύX
	MYToolbarbuttonChange( 0 );

}



void CBombMastarDoc::OnToolbarbutton2() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������

	//�{�^������������Ԃɂ���
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON2);

	//�J�[�\���̃r�b�g�}�b�v�̑I��
	m_iViewCorsor = 2;

	//�{�^���̕ύX
	MYToolbarbuttonChange( 1 );
}

void CBombMastarDoc::OnToolbarbutton3() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������

	//�{�^������������Ԃɂ���
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON3);

	//�J�[�\���̃r�b�g�}�b�v�̑I��
	m_iViewCorsor = 3;

	//�{�^���̕ύX
	MYToolbarbuttonChange( 2 );

}

void CBombMastarDoc::OnToolbarbutton4() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������


	//�{�^������������Ԃɂ���
	//MYToolbarbuttonOn(ID_TOOLBARBUTTON4);

	//�J�[�\���̃r�b�g�}�b�v�̑I��
	m_iViewCorsor = 4;

	//�{�^���̕ύX
	MYToolbarbuttonChange( 3 );

}


//�{�^������������Ԃɂ���֐�<-------���ݎg�p���Ă��Ȃ�
void CBombMastarDoc::MYToolbarbuttonOn(int iBottonID)
{


	if(m_iToolBarPutFlg != iBottonID)
	{
		CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		//�{�^������
		pMFrame->m_wndToolBar.GetToolBarCtrl().PressButton( iBottonID,TRUE );

		//�O�ɑI������Ă����{�^���߂�
		pMFrame->m_wndToolBar.GetToolBarCtrl().PressButton( m_iToolBarPutFlg,FALSE );
		//�����{�^���t���O��ID_TOOLBARBUTTON4����
		m_iToolBarPutFlg = iBottonID;
		
	}

}

//�c�[���o�[�̃{�^����ύX����֐�
void CBombMastarDoc::MYToolbarbuttonChange(int iButtonFlg)
{
	

	if(m_iToolBarPutFlg != iButtonFlg)
	{
		CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

		//�{�^�����c�[���o�[����폜
		pMFrame->m_wndToolBar.GetToolBarCtrl().DeleteButton( iButtonFlg );

		//�V�����{�^�����c�[���o�[�ɒǉ�
		pMFrame->m_wndToolBar.GetToolBarCtrl().InsertButton( iButtonFlg, &pMFrame->m_kTbbutonOn[iButtonFlg]);


		//���ڂ͎��{���Ȃ�
		if(m_iToolBarPutFlg != -1)
		{
			//�O�ɑI������Ă����{�^�����c�[���o�[����폜
			pMFrame->m_wndToolBar.GetToolBarCtrl().DeleteButton( m_iToolBarPutFlg );

			//�O�ɑI������Ă����{�^���̈ʒu�ɐV�����{�^�����c�[���o�[�ɒǉ�
			pMFrame->m_wndToolBar.GetToolBarCtrl().InsertButton( m_iToolBarPutFlg, &pMFrame->m_kTbbutonDef[m_iToolBarPutFlg]);
		}

		//�t���O�ɐV�����l����
		m_iToolBarPutFlg = iButtonFlg;
	}



}

void CBombMastarDoc::OnMenuitembit() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������
	
	if(m_iBitmapSelect == 0)
	{
		m_iBitmapSelect = 1;
	}
	else if(m_iBitmapSelect == 1){
		m_iBitmapSelect = 0;
	}

}
