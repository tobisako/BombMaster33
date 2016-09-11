// BombListCnt.cpp: CBombListCnt �N���X�̃C���v�������e�[�V����
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BombMastar.h"
#include "BombListCnt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

CBombListCnt::CBombListCnt()
{
	//���X�g�̐擪�|�C���^�̏�����
	pHead = NULL;
}

CBombListCnt::~CBombListCnt()
{
	//CBombListCnt�N���X�폜���ɑS���X�g���J��
	MYBombAllDel();
}

void CBombListCnt::MYBombListAdd(BOMBLIST *pkBombInfo)
{

	//�\���̂̒�`�̓w�b�_�t�@�C���ɋL��
	//	typedef struct kBombList{
	//		int iBombNo;		���eNo
	//		int iBombKind;		���e�̎��
	//		int iBombX;			���eX���W
	//		int iBombY;			���eY���W
	//		int iBombTime;		�^�C�}�[
	//		int iBombHeadFlg;	�擪����t���O
	//		struct kBombList* ptr;
	//	} BOMBLIST;


	//���݂̃|�C���^
	BOMBLIST* pCurrent;

	//pHead�̓��X�g�̐擪�|�C���^
	//pHead��CBombListCnt�N���X��BOMBLIST*�^�̃����o�ϐ�
	pCurrent = pHead;

		
	//ptr ==NULL�̂ɂȂ�܂Ń��X�g�����ǂ�

	if(pHead == NULL)
	{
		//�ǉ����̃��X�g�̗̈�m��
		pHead = new(BOMBLIST);
		//�m�ۂ����̈�ɏ����R�s�[
		pHead->iBombNo			= pkBombInfo->iBombNo;
		pHead->iBombKind		= pkBombInfo->iBombKind;
		pHead->iBombX			= pkBombInfo->iBombX;
		pHead->iBombY			= pkBombInfo->iBombY;
		pHead->iBombTime		= pkBombInfo->iBombTime;
		pHead->iBombHeadFlg		= (int)1;
		pHead->iBombGameEndFlg	= (int)0;
		pHead->ptr				= NULL;

	}
	else{

		//���X�g�����ǂ�
		while(pCurrent->ptr != NULL)
		{
			pCurrent = pCurrent->ptr;
			

		}

		//�ǉ����̃��X�g�̗̈�m��
		pCurrent->ptr = new(BOMBLIST);

		//�m�ۂ����̈�ɏ����R�s�[
		pCurrent->ptr->iBombNo			= pkBombInfo->iBombNo;
		pCurrent->ptr->iBombKind		= pkBombInfo->iBombKind;
		pCurrent->ptr->iBombX			= pkBombInfo->iBombX;
		pCurrent->ptr->iBombY			= pkBombInfo->iBombY;
		pCurrent->ptr->iBombTime		= pkBombInfo->iBombTime;
		pCurrent->ptr->iBombHeadFlg		= (int)0;
		pCurrent->ptr->iBombGameEndFlg	= (int)0;
		pCurrent->ptr->ptr				= NULL;
	}


}

BOOL CBombListCnt::MYBombDetect(int iX, int iY, BOMBLIST **pOutCurrent, BOMBLIST **pOutOld)
{

	//���݂̃|�C���^
	BOMBLIST* pCurrent;

	//pHead�̓��X�g�̐擪�|�C���^
	//pHead��CBombListCnt�N���X��BOMBLIST*�^�̃����o�ϐ�
	pCurrent = pHead;

	//*pOutOld�̏����l
	*pOutOld = pHead;
	
	if(pHead == NULL){
		return FALSE;
	}

	//ptr ==NULL�̂ɂȂ�܂Ń��X�g�����ǂ�
	while(pCurrent != NULL)
	{
		
		//�������锚�e�̍��W�ƈ�v����f�[�^��T��
		if( ( pCurrent->iBombX == iX )&&( pCurrent->iBombY == iY ) )
		{
			
			//��v����f�[�^�̃|�C���^��Ԃ�
			*pOutCurrent = pCurrent;
			//��v����f�[�^�������������͖߂�l��^�ɂ���
			return TRUE;

		}

		//�P�O�̃f�[�^�̃|�C���^��ۑ����Ă�������
		*pOutOld = pCurrent;

		//���̃f�[�^�̃|�C���^��pCurrent�ɑ��
		pCurrent = pCurrent->ptr;
	}

	*pOutCurrent = pCurrent;
	//��v����f�[�^��������Ȃ��������͖߂�l���U�ɂ���
	return FALSE;

}

void CBombListCnt::MYBombListDel(BOMBLIST *pOutCurrent, BOMBLIST *pOutOldPtr)
{

	int iBombKosuu;

	MYBombKosuu( &iBombKosuu );

	//�擪�|�C���^�̔���@iBombHeadFlg��1�̎��擪�f�[�^�ł��鎖�������B
	if(pOutCurrent->iBombHeadFlg)
	{
		BOMBLIST* pHeadbk;
		//�擪�|�C���^�̕ۑ�
		pHeadbk = pHead;
		//pHead�Ɏ��̃��X�g�̃|�C���^����
		pHead = pHead->ptr;
		//���̃��X�g�̐擪����t���O��1�ɂ���
		if(iBombKosuu > 1)
		{
			pHead->iBombHeadFlg	= (int)1;
		}
		//�ۑ��������X�g�̐擪�f�[�^�̗̈�J��
		delete(pHeadbk);
		pHeadbk = NULL;

	
	//�擪�|�C���^�ł͂Ȃ��Ƃ�
	}
	else{

		//�O�̃��X�g�̃|�C���^�Ǝ��̃��X�g�̃|�C���^���Ȃ�
		pOutOldPtr->ptr = pOutCurrent->ptr;

		//���݂̃��X�g�̗̈���J��
		delete(pOutCurrent);
		pOutCurrent = NULL;

	}

}

BOOL CBombListCnt::MYBombTimerCheck(BOMBLIST **pOutCurrent)
{

	//���݂̃|�C���^
	BOMBLIST* pCurrent;

	//�^�C�}�[�t���O �O�ɂȂ������AFALSE�ɂȂ�
	BOOL bTimeFlg = TRUE;

	//pHead�̓��X�g�̐擪�|�C���^
	//pHead��CBombListCnt�N���X��BOMBLIST*�^�̃����o�ϐ�
	pCurrent = pHead;

		
	//ptr ==NULL�̂ɂȂ�܂Ń��X�g�����ǂ�
	while(pCurrent != NULL)
	{
		//�^�C�}�[���O���傫���̓f�N�������g�����s
		if(pCurrent->iBombTime >0)
		{
			pCurrent->iBombTime--;
		}

		//�^�C�}�[���O�ɂȂ������̏��߂̃|�C���^��Ԃ�
		if (( pCurrent->iBombTime <= 0 )&&( bTimeFlg == TRUE))
		{
			*pOutCurrent = pCurrent;
			bTimeFlg = FALSE;

		}

		pCurrent = pCurrent->ptr;

	}


	//�O�ɂȂ炸�ɑS�Ẵ^�C�}�[���f�N�������g�ł���Ζ߂�l�͐^
	return bTimeFlg;

}

void CBombListCnt::MYBombKosuu(int *piOutBombKosuu)
{

	//��
	int iKosuu = 0;

	//���݂̃|�C���^
	BOMBLIST* pCurrent = pHead;


	//���X�g�����ǂ�
	while(pCurrent != NULL)
	{
		pCurrent = pCurrent->ptr;
		iKosuu++;
	}


	*piOutBombKosuu = iKosuu;


}

void CBombListCnt::MYBombAllDel()
{

	int iBombKosuu;
	MYBombKosuu( &iBombKosuu );

	//�擪�|�C���^��NULL�ɂȂ�܂ō폜������Ԃ�
	while(pHead != NULL)
	{
		MYBombKosuu( &iBombKosuu );

		BOMBLIST* pHeadbk;
		//�擪�|�C���^�̕ۑ�
		pHeadbk = pHead;
		//pHead�Ɏ��̃��X�g�̃|�C���^����
		pHead = pHead->ptr;
		//���̃��X�g�̐擪����t���O��1�ɂ���
		if(iBombKosuu > 1)
		{
			pHead->iBombHeadFlg	= (int)1;
		}
		//�ۑ��������X�g�̐擪�f�[�^�̗̈�J��
		delete(pHeadbk);
		pHeadbk = NULL;
	}


}
