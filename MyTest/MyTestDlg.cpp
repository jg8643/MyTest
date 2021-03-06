
// MyTestDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "MyTestDlg.h"
#include "afxdialogex.h"
#include "CTab1.h"
#include "CTab2.h"
#include "CTab3.h"
#include "CTab4.h"
#include "CTab5.h"
#include "Setting.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMyTestDlg 대화 상자



CMyTestDlg::CMyTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	set = new Setting();
}

void CMyTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CMyTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMyTestDlg::OnTcnSelchangeTab1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &CMyTestDlg::OnNMReleasedcaptureSlider2)
END_MESSAGE_MAP()


// CMyTestDlg 메시지 처리기

BOOL CMyTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// 탭
	m_tab.InsertItem(0, _T("달력"));
	m_tab.InsertItem(1, _T("일정"));
	m_tab.InsertItem(2, _T("메모"));
	m_tab.InsertItem(3, _T("스톱워치"));
	m_tab.InsertItem(4, _T("검색"));
	m_tab.SetCurSel(0);

	CRect rect;
	m_tab.GetWindowRect(&rect);
	pDlg1 = new CTab1;
	pDlg1->Create(IDD_DIALOG1, &m_tab);
	pDlg1->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg1->ShowWindow(SW_SHOW);

	pDlg2 = new CTab2;
	pDlg2->Create(IDD_DIALOG2, &m_tab);
	pDlg2->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg2->ShowWindow(SW_HIDE);

	pDlg3 = new CTab3;
	pDlg3->Create(IDD_DIALOG3, &m_tab);
	pDlg3->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg3->ShowWindow(SW_HIDE);

	pDlg4 = new CTab4;
	pDlg4->Create(IDD_DIALOG5, &m_tab);
	pDlg4->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg4->ShowWindow(SW_HIDE);
	
	pDlg5 = new CTab5;
	pDlg5->Create(IDD_DIALOG6, &m_tab);
	pDlg5->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg5->ShowWindow(SW_HIDE);


	// 슬라이더
	m_slider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
	if (m_slider)
	{
		m_slider->SetRange(60, 255, TRUE);
		m_slider->SetPos(255);

		m_nOpa = m_slider->GetPos();


		//해당윈도우에 투명도 속성 지정
		SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);
		UpdateOpa(); //투명도 업데이트
	}


	// 시계
	CWinThread *p1 = NULL;
	p1 = AfxBeginThread(TimeThread, this);

	if (p1 == NULL){
		AfxMessageBox(L"Error");
	}



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMyTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMyTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 탭 바뀔때
void CMyTestDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_tab.GetCurSel();

	switch (sel) {
	case 0:
		pDlg1->ShowWindow(SW_SHOW);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		break;
	case 1:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->UpdateList();
		pDlg2->ShowWindow(SW_SHOW);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		break;
	case 2:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_SHOW);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		break;
	case 3:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_SHOW);
		pDlg5->ShowWindow(SW_HIDE);
		break;
	case 4:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 슬라이더
void CMyTestDlg::OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	if (m_slider)
	{
		m_nOpa = m_slider->GetPos();
		UpdateOpa(); //투명도 업데이트
	}
	*pResult = 0;
}

void CMyTestDlg::UpdateOpa()
{
	SetLayeredWindowAttributes(RGB(0, 0, 255), m_nOpa, LWA_ALPHA | LWA_COLORKEY);
	
}

// 시간 표시
UINT CMyTestDlg::TimeThread(LPVOID _mothod)
{
	CMyTestDlg *dlg = (CMyTestDlg*)_mothod;
	while (1)
	{
		CTime cTime = CTime::GetCurrentTime();
		dlg->day.Format(L"%04d.%02d.%02d", cTime.GetYear(), cTime.GetMonth(), cTime.GetDay());
		dlg->time.Format(L"%02d:%02d:%02d", cTime.GetHour(), cTime.GetMinute(), cTime.GetSecond());
		dlg->SetDlgItemText(IDC_STATIC1, dlg->day);
		dlg->SetDlgItemText(IDC_STATIC2, dlg->time);
		Sleep(100);
	}
	return 0;
}
