// CChange.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "CChange.h"
#include "afxdialogex.h"
#include "Setting.h"
#include "MyTestDlg.h"
#include "Memo.h"
#include "CTab2.h"
// CChange 대화 상자

IMPLEMENT_DYNAMIC(CChange, CDialogEx)

CChange::CChange(CString date, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
	this->date = date;
	pmytestdlg = (CMyTestDlg*)AfxGetMainWnd();
	set = pmytestdlg->set;
}

CChange::CChange(CWnd * pParent)
	:CDialogEx(IDD_DIALOG4, pParent)
{
	pmytestdlg = (CMyTestDlg*)AfxGetMainWnd();
	set = pmytestdlg->set;
}

CChange::~CChange()
{
}

void CChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChange, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChange::OnBnClickedOk)
END_MESSAGE_MAP()


// CChange 메시지 처리기


BOOL CChange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int i;
	pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit1->SetWindowText(date);

	i = set->SearchFile(date);
	if (i != -1) {
		set->memo[i]->str.Replace(L"☆", L"\r\n");
		pEdit2->SetWindowText(set->memo[i]->str);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CChange::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int i;
	CString date;
	pEdit1->GetWindowText(date);
	i = set->SearchFile(date);
	CString str;
	pEdit2->GetWindowText(str);
	// data에 날짜가 없으면
	if (i == -1) {
		str.Replace(L"\r\n", L"☆");
		set->memo[set->count++] = new Memo(date, str);
		set->WriteDataFile();
	}

	// data에 날짜가 존재 하면
	else {
		str.Replace(L"\r\n", L"☆");
		set->memo[i]->str = str;
		set->WriteDataFile();
	}
	CDialogEx::OnOK();
}
