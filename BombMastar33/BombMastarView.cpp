// BombMastarView.cpp : CBombMastarView �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "BombMastar.h"

#include "BombMastarDoc.h"
#include "BombMastarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView

IMPLEMENT_DYNCREATE(CBombMastarView, CView)

BEGIN_MESSAGE_MAP(CBombMastarView, CView)
	//{{AFX_MSG_MAP(CBombMastarView)
	ON_COMMAND(ID_MENUITEM_START, OnMenuitemStart)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEMSIZEL, OnMenuitemsizel)
	ON_COMMAND(ID_MENUITEMSIZES, OnMenuitemsizes)
	ON_COMMAND(ID_MENUITEMSIZEM, OnMenuitemsizem)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView �N���X�̍\�z/����

CBombMastarView::CBombMastarView()
{
	// TODO: ���̏ꏊ�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B

	//���[�h���X�_�C�A���O�̍쐬
	m_pTimerDlg = new CTimerDlg;
	m_pScoreDlg = new CScoreDlg;

}

CBombMastarView::~CBombMastarView()
{
	//���[�h���X�_�C�A���O�̍폜
	delete(m_pTimerDlg);
	delete(m_pScoreDlg);
}

BOOL CBombMastarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView �N���X�̕`��

void CBombMastarView::OnDraw(CDC* pDC)
{
	CBombMastarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B

	//���X�g���ɂ���������ׂĕ`�悷��
	MYPaint(pDC);

	//�I���t���O���I����ԂɂȂ��Ă��鎞
	if(pDoc->m_iEndFlg == FALSE)
	{
		//�I�����̉�ʂ�ǉ�
		MYPaintEnd(GetDC());
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView �N���X�̈��

BOOL CBombMastarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �f�t�H���g�̈������
	return DoPreparePrinting(pInfo);
}

void CBombMastarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CBombMastarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView �N���X�̐f�f

#ifdef _DEBUG
void CBombMastarView::AssertValid() const
{
	CView::AssertValid();
}

void CBombMastarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBombMastarDoc* CBombMastarView::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBombMastarDoc)));
	return (CBombMastarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBombMastarView �N���X�̃��b�Z�[�W �n���h��

void CBombMastarView::OnMenuitemStart() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������


	//�h�L�������g�N���X�̃C���X�^���X�̃|�C���^���擾
	CBombMastarDoc* pDoc = (CBombMastarDoc*)this->GetDocument();
	//�E�C���h�E�̃T�C�Y�ύX
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);


	//GAME�J�n��͏������󂯕t���Ȃ�
	if(this->GetDocument()->m_iStartFlg == TRUE)
	{
		//�S���X�g�J��
		this->GetDocument()->m_cBombListCnt.MYBombAllDel();

		//�S�ݒ���f�t�H���g�l���Z�b�g
		MYSetDefault();
		return;
	}

	//GAME�X�^�[�g����p�t���O���X�^�[�g��ԂɕύX
	this->GetDocument()->m_iStartFlg = TRUE;

	//�X�R�A�\���p���[�h���X�_�C�A���O�̕\��
	m_pScoreDlg->Create(IDD_SUCOREDIALOG1);
	m_pScoreDlg->ShowWindow(SW_SHOW);

	//���C���t���[���̃|�C���^���擾
	CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

	//���C���t���[���̃X�N���[�����W���擾
	CRect cFrameRect;
	pMFrame->GetWindowRect(&cFrameRect);

	//�X�R�A�\���p���[�h���X�_�C�A���O�̃T�C�Y���擾<---�g�������͕̂�����
	CRect cScoreDlgRect;
	m_pScoreDlg->GetClientRect(&cScoreDlgRect);

	//�X�R�A�p���[�h���X�_�C�A���O�̕\���ʒu�̐ݒ�
	cScoreDlgRect.left		= cFrameRect.left;
	cScoreDlgRect.top		= cFrameRect.top	- cScoreDlgRect.bottom	-30;
	cScoreDlgRect.right		= cFrameRect.left	+ cScoreDlgRect.right;
	cScoreDlgRect.bottom	= cFrameRect.top	-30;

	//�X�R�A�p���[�h���X�_�C�A���O�̕\���ʒu�̐ݒ���Z�b�g
	m_pScoreDlg->SetWindowPos( NULL, cScoreDlgRect.left, cScoreDlgRect.top, -1, -1, SWP_NOSIZE );




	//�^�C�}�[�p���[�h���X�_�C�A���O�̕\��   �C���X�^���X�̓R���X�g���N�^�ō쐬
	m_pTimerDlg->Create(IDD_TIMERDIALOG1);
	m_pTimerDlg->ShowWindow(SW_SHOW);

	//�^�C�}�[�\���p���[�h���X�_�C�A���O�̃T�C�Y���擾<---�g�������͕̂�����
	CRect cTimeDlgRect;
	m_pTimerDlg->GetClientRect(&cTimeDlgRect);

	//�^�C�}�[�p���[�h���X�_�C�A���O�̕\���ʒu�̐ݒ�
	cTimeDlgRect.left	= cScoreDlgRect.right	+35;
	cTimeDlgRect.top	= cFrameRect.top		- cTimeDlgRect.bottom	-30;
	cTimeDlgRect.right	= cScoreDlgRect.right	+ cTimeDlgRect.right	+35;
	cTimeDlgRect.bottom	= cFrameRect.top		-30;

	//�^�C�}�[�p���[�h���X�_�C�A���O�̕\���ʒu�̐ݒ���Z�b�g
	m_pTimerDlg->SetWindowPos( NULL, cTimeDlgRect.left, cTimeDlgRect.top, -1, -1, SWP_NOSIZE );

	


	//���[�J�[�X���b�h�̋N��
	CWinThread* pThread = AfxBeginThread(	(AFX_THREADPROC) MYTimerThread1,
											(LPVOID)this,
											THREAD_PRIORITY_NORMAL
										);




}

void CBombMastarView::MYSetTimer( BOOL bTimeONOFF )
{
	if(bTimeONOFF == TRUE)
	{
		SetTimer((UINT)1, (UINT)1000, NULL);

	}
	else{
		KillTimer((UINT)1);

	}

}


void CBombMastarView::OnTimer(UINT nIDEvent) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	CBombMastarDoc* pBomDoc = GetDocument();

	if(m_pTimerDlg->m_iTimer == 0)
	{
		//�^�C�}�[���O�ɂȂ������̓f�t�H���g�̒l�ɖ߂��B
		m_pTimerDlg->m_iTimer = m_pTimerDlg->m_iRoopTime;


		//=======���������X�g�̒ǉ��Ɋւ���L�q===========
	
		BOMBLIST kAddBombListInfo;

		int i = 0;
		int iListKosuu;
		//�f�[�^�ǉ��O�̃f�[�^��
		pBomDoc->m_cBombListCnt.MYBombKosuu( &iListKosuu );
	
		//���e���T��(�����l)�ǉ�
		while(( i < pBomDoc->m_iAddBomb )&&( iListKosuu<pBomDoc->m_iListKosuu ))
		{
			i++;

			//���eNo�̐ݒ�
			pBomDoc->m_iBombNo++;
			kAddBombListInfo.iBombNo = pBomDoc->m_iBombNo;

			//���e�̎�ނ�1�`4�̒l�������_���ɐݒ�
			kAddBombListInfo.iBombKind = pBomDoc->MYrand((int)1, (int)4 );


		
			//���e�̍��W�̐ݒ�
			int iRandamX;
			int iRandamY;
			BOMBLIST* pOutCurrent;
			BOMBLIST* pOutOld;
			int iDetectFlg = 1;

			while(iDetectFlg)
			{
				iRandamX = pBomDoc->MYrand( pBomDoc->m_iRandMinX, pBomDoc->m_iRandMaxX );
				iRandamY = pBomDoc->MYrand( pBomDoc->m_iRandMinY, pBomDoc->m_iRandMaxY );


				if(FALSE == pBomDoc->m_cBombListCnt.MYBombDetect(
								iRandamX, iRandamY, &pOutCurrent,&pOutOld))
				{
					//���X�g�̒��ɓ������W�̃f�[�^���Ȃ���΃t���O��0�ɂ���B
					iDetectFlg = 0;

				}

			}


			//�ϊ���ɍ��W�����X�g�ɉ�����\���̂ɏ�������
			kAddBombListInfo.iBombX = iRandamX;
			kAddBombListInfo.iBombY = iRandamY;

			//���e�̎������Ԃ�15�`20�̒l�������_���ɐݒ�
			kAddBombListInfo.iBombTime = pBomDoc->MYrand(	pBomDoc->m_iRandamTimeLow,
															pBomDoc->m_iRandamTimeHigh);

			//�f�[�^�����X�g�ɓo�^
			pBomDoc->m_cBombListCnt.MYBombListAdd(&kAddBombListInfo);

			//�ǉ���̃��X�g�f�[�^��
			pBomDoc->m_cBombListCnt.MYBombKosuu(&iListKosuu);


		}//<-----roop end

		//�f�o�C�X�R���e�L�X�g�̕\��
		MYPaint(GetDC());

	}


	//�X�^�e�B�b�N�e�L�X�g�ւ̃^�C�}�[�̕\��
	m_pTimerDlg->m_cTimer.Format( "%d", m_pTimerDlg->m_iTimer );
	m_pTimerDlg->UpdateData(FALSE);



	//�^�C�}���O�ɂȂ������Ƀf�[�^�i�[�p�̊��p��
	BOMBLIST *pOutTimeCurrent;

	//���X�g�̃^�C�}�l�̃f�N�������g�ƂO�ɂȂ��Ă��Ȃ����̃`�F�b�N
	if(!pBomDoc->m_cBombListCnt.MYBombTimerCheck( &pOutTimeCurrent ))
	{
		//��ʂ̍X�V
		MYPaint(GetDC());

		//�f�o�b�O�p�̋L�q->m_DebugFlg1 == FALSE�̎��̓^�C�}��0�ɂȂ��Ă��I�����Ȃ�
		if(pBomDoc->m_bDebugFlg1 == TRUE)
		{
			//�^�C�}���O�ɂȂ������̏����������ɏ���
			//�I�����̃r�b�g�}�b�v��\��
			MYPaintEnd(GetDC());
			//�^�C�}�̒�~
			MYSetTimer(FALSE);
			//GAME�I���t���O���I����Ԃɂ���
			pBomDoc->m_iEndFlg = FALSE;
			//�����������e�̃r�b�g�}�b�v��GameEnd���̃r�b�g�}�b�v�ɕύX
			pOutTimeCurrent->iBombGameEndFlg = 1;
			//�����������e�̃r�b�g�}�b�v��\�����邽�߂�View�̍X�V������
			MYPaint(GetDC());

		}
	}

	//�^�C�}�[�_�C�A���O�̐��l�̃f�N�������g
	m_pTimerDlg->m_iTimer--;

	//GAME�I������̉�ʂ̍X�V�ɂ��I����ʂ��㏑�������̂�h��
	if(pBomDoc->m_iEndFlg == TRUE)
	{
		//��ʂ̍X�V
		MYPaint(GetDC());
	}

	
	CView::OnTimer(nIDEvent);
}



void CBombMastarView::MYPaint(CDC *pDC)
{

	//CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������

	CBombMastarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B


	CDC dcPhoto;
	CBitmap Bitmap_Obj1, Bitmap_Obj2, Bitmap_Obj3, Bitmap_Obj4,
			Bitmap_ObjWhite,
			Bitmap_ObjEnd1, Bitmap_ObjEnd2, Bitmap_ObjEnd3, Bitmap_ObjEnd4;
	CBitmap *pjBtMem;
	
	//�r�b�g�}�b�v�p�̃f�o�C�X�R���e�L�X�g�̍쐬
	dcPhoto.CreateCompatibleDC(pDC);


	//���݂̃|�C���^
	BOMBLIST* pCurrent;

	//pHead�̓��X�g�̐擪�|�C���^
	//pHead��CBombListCnt�N���X��BOMBLIST*�^�̃����o�ϐ�
	pCurrent = pDoc->m_cBombListCnt.pHead;
		

	//Cbitmap�^��jbmArea�Ƀr�b�g�}�b�v�����[�h
	if(pDoc->m_iBitmapSelect == 0)
	{
		//�r�b�g�}�b�v�̑I��m_iBitmapSelect == 0�̎��̓s���Y�̃r�b�g�}�b�v
		Bitmap_Obj1.LoadBitmap( IDB_BOMB1 );
		Bitmap_Obj2.LoadBitmap( IDB_BOMB2 );
		Bitmap_Obj3.LoadBitmap( IDB_BOMB3 );
		Bitmap_Obj4.LoadBitmap( IDB_BOMB4 );
	}
	else if(pDoc->m_iBitmapSelect == 1){
		//�r�b�g�}�b�v�̑I��m_iBitmapSelect == 1�̎��̓J���[�̔��e�r�b�g�}�b�v

		//���e���������ĂȂ���Ԃ̃r�b�g�}�b�v�����[�h
		Bitmap_Obj1.LoadBitmap( IDB_BOMB5 );
		Bitmap_Obj2.LoadBitmap( IDB_BOMB6 );
		Bitmap_Obj3.LoadBitmap( IDB_BOMB7 );
		Bitmap_Obj4.LoadBitmap( IDB_BOMB8 );

		//���e��������̃r�b�g�}�b�v�����[�h
		Bitmap_ObjEnd1.LoadBitmap( IDB_BOMBEND1 );
		Bitmap_ObjEnd2.LoadBitmap( IDB_BOMBEND2 );
		Bitmap_ObjEnd3.LoadBitmap( IDB_BOMBEND3 );
		Bitmap_ObjEnd4.LoadBitmap( IDB_BOMBEND4 );
	}

	Bitmap_ObjWhite.LoadBitmap( IDB_WHITE );


	//�u����������C���X�^���X�̃|�C���^�̕ۑ�
	pjBtMem = dcPhoto.SelectObject(&Bitmap_Obj1);



	//ptr ==NULL�̂ɂȂ�܂Ń��X�g�����ǂ�
	while(pCurrent != NULL)
	{
		if(pCurrent->iBombGameEndFlg == 0 )
		{
			switch(pCurrent->iBombKind)
			{
				case 1: 
					//�r�b�g�}�b�v�̃������f�o�C�X�R���e�L�X�g�ւ̓W�J
					dcPhoto.SelectObject(&Bitmap_Obj1);
					break;

				case 2:
					dcPhoto.SelectObject(&Bitmap_Obj2);
					break;

				case 3:
					dcPhoto.SelectObject(&Bitmap_Obj3);
					break;

				case 4:
					dcPhoto.SelectObject(&Bitmap_Obj4);
					break;

				case 5:
					dcPhoto.SelectObject(&Bitmap_ObjWhite);
					break;

				default:
						;
			}
		}
		else{
			switch(pCurrent->iBombKind)
			{
				case 1: 
					//�r�b�g�}�b�v�̃������f�o�C�X�R���e�L�X�g�ւ̓W�J
					dcPhoto.SelectObject(&Bitmap_ObjEnd1);
					break;

				case 2:
					dcPhoto.SelectObject(&Bitmap_ObjEnd2);
					break;

				case 3:
					dcPhoto.SelectObject(&Bitmap_ObjEnd3);
					break;

				case 4:
					dcPhoto.SelectObject(&Bitmap_ObjEnd4);
					break;

				case 5:
					dcPhoto.SelectObject(&Bitmap_ObjWhite);
					break;

				default:
						;
			}
		}


		MYPaintBit( pDC, &dcPhoto, pCurrent);
	
		//���̃��X�g�̐擪�|�C���^��pCurrent�ɓ����
		pCurrent = pCurrent->ptr;

	}

	

	//�㏈��
	if(NULL != pDoc->m_cBombListCnt.pHead)
	{
		//�������f�o�C�X�R���e�L�X�g�̏���
		dcPhoto.DeleteDC();
		//�r�b�g�}�b�v�̃I�u�W�F�N�g������
		Bitmap_Obj1.DeleteObject();
		//�u��������ꂽ�C���X�^���X�̃|�C���^�����ɖ߂�
		pDC->SelectObject(pjBtMem);
	}


	// �`��p���b�Z�[�W�Ƃ��� CView::OnPaint() ���Ăяo���Ă͂����܂���
}


void CBombMastarView::MYPaintBit( CDC* pDC, CDC* dcPhoto, BOMBLIST* pCurrent)
{


	//�r�b�g�}�b�v���������f�o�C�X�R���e�L�X�g����f�B�X�v���C�̃f�o�C�X�R���e�L�X�g��
	pDC->BitBlt( pCurrent->iBombX*32 , pCurrent->iBombY*48 , (pCurrent->iBombX+1)*32 , (pCurrent->iBombY+1)*32 , dcPhoto , 0 , 0 , SRCCOPY );
		
	//�^�C�}�[�̕\��
	CString cBombTimeStr;
	if(!(pCurrent->iBombKind == 5))
	{

		cBombTimeStr.Format("%4d", pCurrent->iBombTime);

	}
	else{

		//���e���������鎞�͔��ŏ㏑��
		cBombTimeStr.Format("    ");

	}

	//�e�L�X�g��\������̈�̐ݒ�
	CRect cTextRect;
	cTextRect.left		= pCurrent->iBombX*32;
	cTextRect.top		= pCurrent->iBombY*48+ 32;
	cTextRect.right		= pCurrent->iBombX*32+ 32;
	cTextRect.bottom	= pCurrent->iBombY*48+ 32+ 16;

	//�e�L�X�g�̐F�̐ݒ�p�ϐ�
	COLORREF crColor;
	if(pCurrent->iBombTime <= 5)
	{
		//�Ԃ�ݒ�
		crColor = 0x000000ff;
	}
	else if( (5< pCurrent->iBombTime)&&(pCurrent->iBombTime < 11) ){

		//���F��ݒ�
		crColor = 0x00000000;

	}
	else{

		//�ΐF��ݒ�
		crColor = 0x0000ff00;
	}

	//�e�L�X�g�̐F���Z�b�g
	pDC->SetTextColor(crColor);

	//�e�L�X�g�̕`��
	pDC->DrawText(cBombTimeStr, cTextRect, DT_RIGHT);


}



//�T�C�YL�p 20�~10 640�~480
void CBombMastarView::OnMenuitemsizel() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������

	CBombMastarDoc* pDoc = GetDocument();

	//View�̃T�C�Y�̐ݒ�
	pDoc->m_iSizeX = 640;
	pDoc->m_iSizeY = 480;

	//���X�g�f�[�^(���e)�̍ő吔�̐ݒ�
	pDoc->m_iListKosuu = 20 * 10;

	//X,Y���W�̃����_���l�̕���ݒ�
	pDoc->m_iRandMinX = 0;
	pDoc->m_iRandMaxX = 19;
	pDoc->m_iRandMinY = 0;
	pDoc->m_iRandMaxY = 9;


	//�E�C���h�E�̃T�C�Y�ύX
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);

}


//�T�C�YM�p 16�~8 512�~384
void CBombMastarView::OnMenuitemsizem() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������

	CBombMastarDoc* pDoc = GetDocument();

	//View�̃T�C�Y�̐ݒ�
	pDoc->m_iSizeX = 512;
	pDoc->m_iSizeY = 384;

	//���X�g�f�[�^(���e)�̍ő吔�̐ݒ�
	pDoc->m_iListKosuu = 16 * 8;

	//X,Y���W�̃����_���l�̕���ݒ�
	pDoc->m_iRandMinX = 0;
	pDoc->m_iRandMaxX = 15;
	pDoc->m_iRandMinY = 0;
	pDoc->m_iRandMaxY = 7;

	//�E�C���h�E�̃T�C�Y�ύX
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);


}

//�T�C�YS�p 12�~6 384�~288
void CBombMastarView::OnMenuitemsizes() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������
	
	CBombMastarDoc* pDoc = GetDocument();

	//View�̃T�C�Y�̐ݒ�
	pDoc->m_iSizeX = 384;
	pDoc->m_iSizeY = 288;

	//���X�g�f�[�^(���e)�̍ő吔�̐ݒ�
	pDoc->m_iListKosuu = 12 * 6;

	//X,Y���W�̃����_���l�̕���ݒ�
	pDoc->m_iRandMinX = 0;
	pDoc->m_iRandMaxX = 11;
	pDoc->m_iRandMinY = 0;
	pDoc->m_iRandMaxY = 5;

	//�E�C���h�E�̃T�C�Y�ύX
	MYSizeChange(pDoc->m_iSizeX, pDoc->m_iSizeY);

}


void CBombMastarView::MYSizeChange(int iWidthX, int iWidthY)
{

	CRect kViewRect;
	CRect kMainRect;

	//�r���[�̍��W�̎擾
	this->GetWindowRect( kViewRect );
	//�E�B���h�D�i���C���t���[���j�̍��W�̎擾
	CFrameWnd* pcFrame = (CFrameWnd*)AfxGetApp()->m_pMainWnd;
	pcFrame->GetWindowRect( kMainRect );

	//�Đݒ肷��E�B���h�D�̍��W�̐ݒ�
	kMainRect.right		= kMainRect.left + (kMainRect.right - kViewRect.right) + (kViewRect.left - kMainRect.left) + iWidthX + 4;
	kMainRect.bottom	= kMainRect.top + (kViewRect.top - kMainRect.top) + (kMainRect.bottom - kViewRect.bottom) + iWidthY + 4;

	//�T�C�Y�̕ύX
	AfxGetApp()->m_pMainWnd->MoveWindow( kMainRect );



}




BOOL CBombMastarView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	CBombMastarDoc* pDoc = GetDocument();



	if(pDoc->m_iStartFlg == TRUE)
	{


		if(pDoc->m_iBitmapSelect == 0)
		{

			switch(pDoc->m_iViewCorsor)
			{
			case 1:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR1 ));	
				break;

			case 2:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR2 ));
				break;

			case 3:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR3 ));
				break;

			case 4:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSOR4 ));
				break;

			default:
			;
			}

		}
		else if(pDoc->m_iBitmapSelect == 1){

			switch(pDoc->m_iViewCorsor)
			{
			case 1:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW1 ));	
				break;

			case 2:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW2 ));
				break;

			case 3:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW3 ));
				break;

			case 4:
				::SetCursor(AfxGetApp()->LoadCursor( IDC_CURSORNEW4 ));
				break;

			default:
				;
			}
		}

		return TRUE;

	}
	else{

		return CView::OnSetCursor(pWnd, nHitTest, message);
	}

}

void CBombMastarView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	CBombMastarDoc* pDoc = GetDocument();

	CRect cViewRect;

	this->GetClientRect( cViewRect );

	int iX = point.x/32;
	int iY = point.y/48;
	

	BOMBLIST *pOutCurrent;
	BOMBLIST *pOutOld;

	if(FALSE == pDoc->m_cBombListCnt.MYBombDetect( iX, iY, &pOutCurrent, &pOutOld))
	{
		//��v����f�[�^�������ꍇ�͏��������Ȃ�
		return;
	}


	if(this->GetDocument()->m_iEndFlg == FALSE)
	{
		//GAME�I����͏��������Ȃ�
		return;
	}

	if(pDoc->m_iViewCorsor == 0)
	{
		//�܂��J�[�\����������Ԃ̂܂܂̎��͏��������Ȃ�
		return;

	}

	if(!(pOutCurrent->iBombKind == pDoc->m_iViewCorsor))
	{
		//���e�̎�ނ��J�[�\���̎�ނƈ�v���Ă��Ȃ���Ώ������I��
		
		MYPaintEnd(GetDC());
		//�^�C�}�̒�~
		MYSetTimer(FALSE);
		//GAME�I���t���O���I����Ԃɂ���
		this->GetDocument()->m_iEndFlg = FALSE;
		//�����������e�̃r�b�g�}�b�v��GameEnd���̂��̂ɕύX
		pOutCurrent->iBombGameEndFlg = 1;
		//�����������e�̃r�b�g�}�b�v��\�����邽�߂ɍĕ`��
		MYPaint( GetDC() );

		return;
	}




	//�X�R�A+1
	pDoc->m_iScore++;

	//���x���A�b�v�`�F�b�N --- �X�R�A��m_iLevelUpScore�̔{���̎�
	
	if( (pDoc->m_iScore)%(pDoc->m_iLevelUpScore) == 0 )
	{

		//���x���A�b�v
		pDoc->m_icurrentLevel++;

		//���񃌃x���A�b�v���̃X�R�A
		pDoc->m_iLevelUpScore += 5*(pDoc->m_icurrentLevel);
		
		//���x���̕\��
		m_pScoreDlg->m_LevelStr.Format("���x��%d", pDoc->m_icurrentLevel);


//		if(pDoc->m_icurrentLevel%2 == 0)
//		{
			//���x�����Q�̔{���̎��̂ݒǉ�����锚�e�̐���ǉ�
			pDoc->m_iAddBomb++;
//		}
//		else{
			//�^�C�}�[�̒l������炷
//			if((m_pTimerDlg->m_iRoopTime) > 2)
//			{
//				m_pTimerDlg->m_iRoopTime--;
//			}
//		}

	}

	//�X�R�A�̕\��
	m_pScoreDlg->m_ScoreStr.Format("%d", pDoc->m_iScore);
	m_pScoreDlg->UpdateData(FALSE);



	//���e�̎�ނɏ����A�C�e��������5����
	pOutCurrent->iBombKind = 5;
	//�������e�̏��𔒂œh��Ȃ����ׂɍĕ`��
	MYPaint( GetDC() );
	//�Y������f�[�^�����X�g����폜
	pDoc->m_cBombListCnt.MYBombListDel(pOutCurrent, pOutOld);




	CView::OnLButtonDown(nFlags, point);
}



LRESULT CBombMastarView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	
	return CView::DefWindowProc(message, wParam, lParam);
}



void CBombMastarView::MYPaintEnd(CDC *pDC)
{

	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������

	CBombMastarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B


	CDC dcPhoto1, dcPhoto2;
	CBitmap Bitmap_Obj1, Bitmap_Obj2;
	CBitmap *pjBtMem1,*pjBtMem2;
	
	//�r�b�g�}�b�v�p�̃f�o�C�X�R���e�L�X�g�̍쐬
	dcPhoto1.CreateCompatibleDC(pDC);
	dcPhoto2.CreateCompatibleDC(pDC);

	//Cbitmap�^��jbmArea�Ƀr�b�g�}�b�v�����[�h
	Bitmap_Obj1.LoadBitmap( IDB_GAMEEND1 );
	Bitmap_Obj2.LoadBitmap( IDB_WHITE );

	//�u����������C���X�^���X�̃|�C���^�̕ۑ�
	pjBtMem1 = dcPhoto1.SelectObject(&Bitmap_Obj1);
	pjBtMem2 = dcPhoto2.SelectObject(&Bitmap_Obj2);


	CRect kViewRect;

	//�r���[�̍��W�̎擾
	this->GetWindowRect( kViewRect );



	//m_iEndFlg��GAME�I����A�ŏ��ɌĂ΂ꂽ���̂�FALSE�̂܂܂ŁA
	//2��ڈȍ~OnDrow���ŃR�[�����ꂽ����TRUE�ƂȂ��Ă���
	if(pDoc->m_iEndFlg == TRUE)
	{
		int i;

		//�I����ʂ̊g��
		for(i=1 ;i<20 ;i++)
		{
			//0.1�b�Ԋu�Ńr�b�g�}�b�v�g��

			pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16*i,
								(kViewRect.bottom - kViewRect.top)/2-16*i,
								32*i ,32*i , &dcPhoto1, 0 , 0 ,32 ,32, SRCCOPY );


			Sleep(50);
		}

		//�I����ʂ̏k��
		for(i=20 ;i>0 ;i--)
		{
			//0.1�b�Ԋu�Ńr�b�g�}�b�v�k��

			//��ʂ����t���b�V��
			if(i==1)
			{
				//���̃r�b�g�}�b�v���g�債�ĕ\�����邱�Ƃɂ���ʂ����t���b�V��
				pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16*20,
									(kViewRect.bottom - kViewRect.top)/2-16*20,
									32*20 ,32*20 , &dcPhoto2, 0 , 0 ,32 ,32, SRCCOPY );
			

				//���X�g���̔��e��`��
				MYPaint(GetDC());
		
			}

			//�I����ʂ�`��
			pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16*i,
								(kViewRect.bottom - kViewRect.top)/2-16*i,
								32*i ,32*i , &dcPhoto1, 0 , 0 ,32 ,32, SRCCOPY );

			
			Sleep(50);
		}


		//�I����ʕ\�������𔒂��`��
		pDC->StretchBlt(	(kViewRect.right - kViewRect.left)/2-16,
							(kViewRect.bottom - kViewRect.top)/2-16,
							32 ,32 , &dcPhoto2, 0 , 0 ,32 ,32, SRCCOPY );

	}


	//��ʂ̍X�V--���X�g�̒��g�̕\��
	MYPaint(GetDC());


	//�������f�o�C�X�R���e�L�X�g�̏���
	dcPhoto1.DeleteDC();
	dcPhoto2.DeleteDC();
	//�r�b�g�}�b�v�̃I�u�W�F�N�g������
	Bitmap_Obj1.DeleteObject();
	Bitmap_Obj2.DeleteObject();
	//�u��������ꂽ�C���X�^���X�̃|�C���^�����ɖ߂�
	pDC->SelectObject(pjBtMem1);
	pDC->SelectObject(pjBtMem2);

}

void CBombMastarView::MYSetDefault()
{


	CBombMastarDoc* pDoc = (CBombMastarDoc*)this->GetDocument();

	//�{��No�̏�����
	pDoc->m_iBombNo = 0;

	//���X�g�̍ő吔�̏����ݒ�
//	m_iListKosuu = 12 * 6;

	//��ʃT�C�Y�̏����ݒ�(�T�C�Y�FS)
//	m_iSizeX = 384;
//	m_iSizeY = 288;

	//Y���W�̃����_���l�̕��̃f�t�H���g�l(�T�C�Y�FS)��ݒ�
//	m_iRandMinX = 0;
//	m_iRandMaxX = 11;
//	m_iRandMinY = 0;
//	m_iRandMaxY = 5;
	
	//�J�[�\���̃r�b�g�}�b�v�I��p�ϐ��̏�����
//	pDoc->m_iViewCorsor = 0;
	
	//�X�R�A�̏�����
	pDoc->m_iScore = 0;

	//�����Ă���{�^���������t���O�̏�����(�����͓��ɈӖ�����)
//	m_iToolBarPutFlg = -1;

	//�ǉ����锚�e�̐��̏����ݒ�
	pDoc->m_iAddBomb = 3;

	//LevelUp����X�R�A�Ԋu�̏����ݒ�
	pDoc->m_iLevelUpScore =10;

	//���݂�Level�̏����l
	pDoc->m_icurrentLevel =1;

	//���e�̐������ԂɃ����_���ɐݒ肳���l�̏��
//	pDoc->m_iRandamTimeHigh	= 20;

	//���e�̐������ԂɃ����_���ɐݒ肳���l�̉���
//	pDoc->m_iRandamTimeLow	= 15;

	//�f�o�b�O�p�t���O FALSE�̎��I�����̏��������Ȃ�
	pDoc->m_bDebugFlg1 = TRUE;

	//GAME�I������p�t���O�AGAME�I�����FALSE�ɂȂ�
	pDoc->m_iEndFlg = TRUE;

	//���e�p�r�b�g�}�b�v�I��p�ϐ�
//	pDoc->m_iBitmapSelect = 1;

	//�Q�[���X�^�[�g�p�t���O
	pDoc->m_iStartFlg = TRUE;

	//�X�R�A�_�C�A���O�̕\���̏�����
//	CMainFrame* pMFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	
	//�X�R�A�̏�����
	pDoc->m_iScore = 0;
	//�X�R�A�̕\��
	m_pScoreDlg->m_ScoreStr.Format("%d", pDoc->m_iScore);
	m_pScoreDlg->UpdateData(FALSE);

	//���x���̏�����
	pDoc->m_icurrentLevel = 1;
	//���x���̕\��
	m_pScoreDlg->m_LevelStr.Format("���x��%d", pDoc->m_icurrentLevel);
	m_pScoreDlg->UpdateData(FALSE);

	//�^�C�}�̃Z�b�g
	MYSetTimer(TRUE);
	
	//�^�C�}���f�t�H���g��Ԃɖ߂�
	m_pTimerDlg->m_iTimer = m_pTimerDlg->m_iDefaultTime;
	m_pTimerDlg->m_cTimer.Format( "%d", m_pTimerDlg->m_iTimer );
	m_pTimerDlg->UpdateData(FALSE);

	//View�̍X�V
	AfxGetApp()->m_pMainWnd->RedrawWindow();



}
