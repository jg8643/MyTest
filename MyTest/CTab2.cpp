// CTab2.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "CTab2.h"
#include "afxdialogex.h"
#include "MyTestDlg.h"
#include "Setting.h"
#include "Memo.h"
#include "CChange.h"
// CTab2 대화 상자

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)

CTab2::CTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	pmytestdlg = (CMyTestDlg*)AfxGetMainWnd();
	set = pmytestdlg->set;
}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTab2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTab2 메시지 처리기


BOOL CTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CFont font;
	font.CreatePointFont(120, L"Arial");
	m_listctrl.SetFont(&font);


	// 리스트 컨트롤 목록 지정
	CRect rt;
	m_listctrl.GetWindowRect(&rt);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl.InsertColumn(0, TEXT("일정"), LVCFMT_LEFT, rt.Width()*0.4);
	m_listctrl.InsertColumn(1, TEXT("내용"), LVCFMT_LEFT, rt.Width()*0.59);


	UpdateList();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 리스트 컨트롤 업데이트
void CTab2::UpdateList()
{
	m_listctrl.DeleteAllItems();
	CString str1, str2, temp;
	int result;

	for (int i = 0; i < set->count; i++) {
		m_listctrl.InsertItem(i, set->memo[i]->date);
		m_listctrl.SetItem(i, 1, LVIF_TEXT, set->memo[i]->str, NULL, NULL, NULL, NULL);
	}
	count = m_listctrl.GetItemCount();
	
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			str1 = m_listctrl.GetItemText(i, 0);
			str2 = m_listctrl.GetItemText(j, 0);
			result = wcscmp(str1, str2);

			if (result < 0) {
				for (int k = 0; k < 2; k++) {
					temp = m_listctrl.GetItemText(i, k);
					m_listctrl.SetItemText(i, k, m_listctrl.GetItemText(j, k));
					m_listctrl.SetItemText(j, k, temp);
				}
			}
		}
	}
}

// 추가
void CTab2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CChange change;
	change.DoModal();
	change.DestroyWindow();
	UpdateList();
}

// 삭제
void CTab2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int select = m_listctrl.GetSelectionMark();

	if (select >= 0) {
		for (int i = 0; i < set->count; i++) {
			if (m_listctrl.GetItemText(select, 0) == set->memo[i]->date) {
				for (int j = i; j < set->count; j++) {
					set->memo[j] = set->memo[j + 1];
				}
				set->count--;
			}
		}
		m_listctrl.DeleteItem(select);
		set->WriteDataFile();
	}
	else
		AfxMessageBox(L"삭제할 일정을 선택하여 주십시오.");
}
