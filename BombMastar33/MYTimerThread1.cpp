
#include "stdafx.h"
#include "MainFrm.h"
#include "BombMastarView.h"


//�}���`�X���b�h�œ��삳�������֐��̌Ăяo�����s���B
UINT MYTimerThread1( LPVOID pvParam )
{


	//���C���E�B���h�E�̃|�C���^�̎擾
	CBombMastarView* pBombMastarView = ( CBombMastarView* )pvParam;

	//MYSetTimer()�֐��Ăяo��
	//MYSetTimer()�̒��ŃZ�b�g�^�C�}�[������
	pBombMastarView->MYSetTimer(TRUE);



	return(0);
}