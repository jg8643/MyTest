// CTab3.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "CTab3.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "MyTestDlg.h"

// CTab3 대화 상자

IMPLEMENT_DYNAMIC(CTab3, CDialogEx)

CTab3::CTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
	pmytestdlg = (CMyTestDlg*)AfxGetMainWnd();
	set = pmytestdlg->set;
}

CTab3::~CTab3()
{
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab3, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTab3::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CTab3 메시지 처리기


BOOL CTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CEdit *pEdit;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	set->temp_memo.Replace(L"☆", L"\r\n");
	CFont font;
	font.CreatePointFont(120, L"Arial");
	pEdit->SetFont(&font);
	pEdit->SetWindowText(set->temp_memo);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTab3::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	CEdit *pEdit;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->GetWindowText(set->temp_memo);
	set->WriteMemoFile();
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
