// TimerDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "BombMastar.h"
#include "TimerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg �_�C�A���O


CTimerDlg::CTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimerDlg)
	m_cTimer = _T("0");
	//}}AFX_DATA_INIT



	m_iDefaultTime = 0;		//�^�C�}�[�̏����l�̐ݒ�
	m_iRoopTime = 5;		//�^�C�}�[�̌J��Ԃ��Ԋu�̐ݒ�
	m_iTimer = m_iDefaultTime;	//�����l�̃Z�b�g

}


void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimerDlg)
	DDX_Text(pDX, IDC_BombTimer1, m_cTimer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimerDlg, CDialog)
	//{{AFX_MSG_MAP(CTimerDlg)
	ON_BN_CLICKED(IDC_BombTimer1, OnBombTimer1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg ���b�Z�[�W �n���h��

void CTimerDlg::OnBombTimer1() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	
}
