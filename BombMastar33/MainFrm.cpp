// MainFrm.cpp : CMainFrame �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
//#include "BombMastar.h"

#include "MainFrm.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̍\�z/����

CMainFrame::CMainFrame()
{
	// TODO: ���̈ʒu�Ƀ����o�̏����������R�[�h��ǉ����Ă��������B

	

	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;


//	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
//		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
//		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
//	{
//		TRACE0("Failed to create toolbar\n");
//		return -1;      // �쐬�Ɏ��s
//	}

	//�ŏ��Ƀc�[���o�[�̃r�b�g�}�b�v�C���[�W�����[�h���Ȃ��悤�ɕύX
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // �쐬�Ɏ��s
	}



	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}


	int i = 0;


	//�C���[�W���X�g�ɒǉ�����C���[�W���X�g�̏��
	for(i=0; i<4; i++)
	{
		m_kTbbutonDef[i].iBitmap	= i;
		m_kTbbutonDef[i].idCommand	= NULL;
		m_kTbbutonDef[i].fsState	= TBSTATE_ENABLED;
		m_kTbbutonDef[i].fsStyle	= TBSTYLE_CHECKGROUP;
		m_kTbbutonDef[i].dwData		= NULL;
		m_kTbbutonDef[i].iString	= NULL;

		m_kTbbutonOn[i].iBitmap		= i+4;
		m_kTbbutonOn[i].idCommand	= NULL;
		m_kTbbutonOn[i].fsState		= TBSTATE_PRESSED;
		m_kTbbutonOn[i].fsStyle		= TBSTYLE_BUTTON;
		m_kTbbutonOn[i].dwData		= NULL;
		m_kTbbutonOn[i].iString		= NULL;

	}

	m_kTbbutonDef[0].idCommand	= WM_USER_BOMB1;
	m_kTbbutonDef[1].idCommand	= WM_USER_BOMB2;
	m_kTbbutonDef[2].idCommand	= WM_USER_BOMB3;
	m_kTbbutonDef[3].idCommand	= WM_USER_BOMB4;
	m_kTbbutonOn[0].idCommand	= WM_USER_BOMB1;
	m_kTbbutonOn[1].idCommand	= WM_USER_BOMB2;
	m_kTbbutonOn[2].idCommand	= WM_USER_BOMB3;
	m_kTbbutonOn[3].idCommand	= WM_USER_BOMB4;

	//�C���[�W���X�g�Ƀr�b�g�}�b�v��ǉ�
	m_wndToolBar.GetToolBarCtrl().AddBitmap(4, IDR_TOOLBAR1 );
	m_wndToolBar.GetToolBarCtrl().AddBitmap(4, IDR_TOOLBAR2 );

	//�w�肵���ꏊ�Ƀ{�^����ǉ��i�\���j
	m_wndToolBar.GetToolBarCtrl().InsertButton( 0, &m_kTbbutonDef[0]);
	m_wndToolBar.GetToolBarCtrl().InsertButton( 1, &m_kTbbutonDef[1]);
	m_wndToolBar.GetToolBarCtrl().InsertButton( 2, &m_kTbbutonDef[2]);
	m_wndToolBar.GetToolBarCtrl().InsertButton( 3, &m_kTbbutonDef[3]);




	//�z�b�g��Ԃ̃C���[�W���X�g���쐬
	//m_iml��CImageList�^�̃����o�ϐ�
	m_iml.Create( IDR_TOOLBAR3, 32, 8, 0xc0c0c0 );

	//�z�b�g�C���[�W���X�g���c�[���o�[�Ɋ��蓖�Ă�
	m_wndToolBar.GetToolBarCtrl().SendMessage(	TB_SETHOTIMAGELIST,
												0,
												(LPARAM)m_iml.m_hImageList
											);



	//�{�^���̃T�C�Y�̐ݒ�
	SIZE kBottonSize;
	kBottonSize.cx = 32+7;
	kBottonSize.cy = 32+6;

	//�{�^���̃C���[�W�̃T�C�Y�̐ݒ�
	SIZE kBottonImage;
	kBottonImage.cx = 32;
	kBottonImage.cy = 32;

	//�{�^���̃T�C�Y���Z�b�g���邱�ƂŃc�[���o�[�̃T�C�Y��ύX
	m_wndToolBar.SetSizes(kBottonSize, kBottonImage);


	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�͈ȉ��̂R�s���폜
	//       ���Ă��������B
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	CPoint point;
	point.x = 400;	//<------��ňړ�������̂ňӖ��͂قƂ�ǖ���
	point.y = 350;	//<------��ňړ�������̂ňӖ��͂قƂ�ǖ���

//start - 2001/09/24 Comment Out:�t���[�g��Ԃɂ��Ȃ����ɂ���
	//�c�[���o�[���t���[�g��Ԃɂ���B
	//FloatControlBar( &m_wndToolBar ,point);
//End   - 2001/09/24 Comment Out:�t���[�g��Ԃɂ��Ȃ����ɂ���

	//�X�e�[�^�X�o�[���\��
	ShowControlBar( &m_wndStatusBar, FALSE, FALSE );

	//�E�B���h�E����ʒ����ɕ\������B
	CenterWindow( GetDesktopWindow() );

	
//start - 2001/09/24 Comment Out:�t���[�g��Ԃɂ��Ȃ����ɂ���
	//�t���[�e�B���O�c�[���o�[�̈ʒu�ύX
	//����!!���̈ʒu����Ȃ��ƃ_���ACenterWindow()�̑O�ɂ����
	//����Ⴄ�ʒu�ɕ\�������
	//MYFTBarSetPosition();
//End   - 2001/09/24 Comment Out:�t���[�g��Ԃɂ��Ȃ����ɂ���

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{

	cs.x = 300;
	cs.y = 300;
	cs.cx = 384;
	cs.cy = 288;
	
	//�T�C�Y�ύX�̃X�^�C�����O��
	cs.style = cs.style^WS_THICKFRAME;


	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C�����āAWindow �N���X��X�^�C����
	//       �C�����Ă��������B



	GetDesktopWindow();


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̐f�f

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG



//========��������������R��ǉ�[�t���[�e�B���O�c�[���o�[�̈ړ����@]===================
void CMainFrame::MYFTBarSetPosition()
{

	CWnd* pWnd = m_wndToolBar.GetParent()->GetParent();
	if( pWnd->GetSafeHwnd() != GetSafeHwnd() )
	{
		//�����ŕK�v�ȏ���������
		CRect rcFrame( 338, -108, 0, 0 );
		ClientToScreen( rcFrame );
		pWnd->SetWindowPos( NULL, rcFrame.left, rcFrame.top, -1, -1, SWP_NOSIZE );
	}

	MYFTBarSetWidth();

}

//========�����������܂ŎR��ǉ�[�t���[�e�B���O�c�[���o�[�̈ړ����@]===================


//========��������������R��ǉ�[�t���[�e�B���O�c�[���o�[�̕��w��]=====================
void CMainFrame::MYFTBarSetWidth()
{
	m_wndToolBar.m_nMRUWidth = 600;
	ShowControlBar( &m_wndToolBar , TRUE , FALSE );
}

//========�����������܂ŎR��ǉ�[�t���[�e�B���O�c�[���o�[�̕��w��]=====================



/////////////////////////////////////////////////////////////////////////////
// CMainFrame ���b�Z�[�W �n���h��
