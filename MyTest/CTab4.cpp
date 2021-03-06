// CTab4.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "CTab4.h"
#include "afxdialogex.h"


// CTab4 대화 상자

IMPLEMENT_DYNAMIC(CTab4, CDialogEx)

CTab4::CTab4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{
	count = 0;
}

CTab4::~CTab4()
{
}

void CTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}


BEGIN_MESSAGE_MAP(CTab4, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CTab4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTab4::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTab4::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTab4::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTab4 메시지 처리기


BOOL CTab4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CFont font;
	font.CreatePointFont(100, L"Arial");
	m_listctrl.SetFont(&font);
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->SetFont(&font);

	// 리스트 컨트롤 목록 지정
	CRect rt;
	m_listctrl.GetWindowRect(&rt);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl.InsertColumn(0, TEXT("순서"), LVCFMT_LEFT, rt.Width()*0.4);
	m_listctrl.InsertColumn(1, TEXT("시간"), LVCFMT_LEFT, rt.Width()*0.59);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTab4::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString str;
	str.Format(L"%02d : %02d : %02d ", min, sec, m_sec);
	pEdit->SetWindowText(str);

	UpdateData();
	m_sec += 1;
	if (m_sec == 65) {
		m_sec = 1;
		sec += 1;
		if (sec == 60) {
			sec = 0;
			min += 1;
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

// 시작
void CTab4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1, 1, NULL);
}

// 정지
void CTab4::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(1);
}

// 초기화
void CTab4::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_sec = 0; sec = 0; min = 0;
	CString str1;
	str1.Format(L"%02d : %02d : %02d ", min, sec, m_sec);
	pEdit->SetWindowText(str1);
	m_listctrl.DeleteAllItems();
	count = 0;
}

// 기록
void CTab4::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str2, str3;
	str2.Format(L"%02d", count + 1);
	str3.Format(L"%02d : %02d : %02d ", min, sec, m_sec);
	m_listctrl.InsertItem(count, str2);
	m_listctrl.SetItem(count++, 1, LVIF_TEXT, str3, NULL, NULL, NULL, NULL);
	
}
