// CTab1.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "CTab1.h"
#include "afxdialogex.h"
#include "CChange.h"
#include "Setting.h"
#include "MyTestDlg.h"
#include <time.h>
// CTab1 대화 상자

IMPLEMENT_DYNAMIC(CTab1, CDialogEx)

CTab1::CTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	pmytestdlg = (CMyTestDlg*)AfxGetMainWnd();
	set = pmytestdlg->set;
}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, *calendar);
}


BEGIN_MESSAGE_MAP(CTab1, CDialogEx)
	ON_NOTIFY(MCN_SELECT, IDC_MONTHCALENDAR1, &CTab1::OnMcnSelectMonthcalendar1)
END_MESSAGE_MAP()


// CTab1 메시지 처리기


BOOL CTab1::OnInitDialog()
{
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	calendar = (CMonthCalCtrl*)GetDlgItem(IDC_MONTHCALENDAR1);
	calendar->SetColor(MCSC_BACKGROUND, RGB(125,125,125));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 날짜 선택시 change 다이얼로그 생성
void CTab1::OnMcnSelectMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTime currentTime;
	CString str;
	calendar->GetCurSel(currentTime);
	str.Format(L"%04d%02d%02d", currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay());
	CChange change(str);
	change.DoModal();
	change.DestroyWindow();
	*pResult = 0;
}
