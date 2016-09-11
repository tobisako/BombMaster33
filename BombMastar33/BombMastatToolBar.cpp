// BombMastatToolBar.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "BombMastar.h"
#include "BombMastatToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBombMastatToolBar

CBombMastatToolBar::CBombMastatToolBar()
{
}

CBombMastatToolBar::~CBombMastatToolBar()
{
}


BEGIN_MESSAGE_MAP(CBombMastatToolBar, CToolBar)
	//{{AFX_MSG_MAP(CBombMastatToolBar)
	ON_WM_CHILDACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBombMastatToolBar ���b�Z�[�W �n���h��

void CBombMastatToolBar::OnChildActivate() 
{
	CToolBar::OnChildActivate();
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	
	//�c�[���o�[���t���[�g��Ԃ̎�
	CWnd* pWnd = GetParent()->GetParent();
	if(pWnd->GetSafeHwnd() != GetOwner()->GetSafeHwnd())
	{
		//�c�[���o�[�̃^�C�g���o�[�ɂ���u����v�{�^��������
		pWnd->ModifyStyle(WS_SYSMENU, 0);

		//�c�[���o�[�̃^�C�g���o�[������
		//pWnd->ModifyStyle(WS_CAPTION, 0);

		//�c�[���o�[�̃��T�C�Y�s��
		pWnd->ModifyStyle(WS_THICKFRAME, 0);

	}

}
