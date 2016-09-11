// BombListCnt.h: CBombListCnt �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMBLISTCNT_H__348EF86D_26B1_409B_9D4B_BD8DB7CB7A9D__INCLUDED_)
#define AFX_BOMBLISTCNT_H__348EF86D_26B1_409B_9D4B_BD8DB7CB7A9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//���X�g�p�\����
typedef struct kBombList{
		int iBombNo;
		int iBombKind;
		int iBombX;
		int iBombY;
		int iBombTime;
		int iBombHeadFlg;		//�擪����t���O
		int iBombGameEndFlg;	//���e���������������肷��t���O
		struct kBombList* ptr;
} BOMBLIST;


class CBombListCnt  
{
public:
	void MYBombAllDel();
	void MYBombKosuu( int* piOutBombKosuu );
	BOOL MYBombTimerCheck( BOMBLIST** pOutCurrent );
	void MYBombListDel( BOMBLIST* pOutCurrent, BOMBLIST* pOutOldPtr );
	BOOL MYBombDetect( int iX, int iY ,BOMBLIST** pOutCurrent, BOMBLIST** pOutOld);

	BOMBLIST* pHead;
	void MYBombListAdd(BOMBLIST* pkBombInfo);
	CBombListCnt();
	virtual ~CBombListCnt();

};

#endif // !defined(AFX_BOMBLISTCNT_H__348EF86D_26B1_409B_9D4B_BD8DB7CB7A9D__INCLUDED_)
