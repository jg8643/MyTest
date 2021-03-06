// CTab5.cpp: 구현 파일
//

#include "stdafx.h"
#include "MyTest.h"
#include "CTab5.h"
#include "afxdialogex.h"


// CTab5 대화 상자

IMPLEMENT_DYNAMIC(CTab5, CDialogEx)

CTab5::CTab5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CTab5::~CTab5()
{
}

void CTab5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}


BEGIN_MESSAGE_MAP(CTab5, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab5::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab5 메시지 처리기


BOOL CTab5::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CFont font;
	font.CreatePointFont(100, L"Arial");

	pEdit = (CEdit *)GetDlgItem(IDC_EDIT1);
	pEdit->SetFont(&font);

	// 콤보 박스
	m_combo.SetFont(&font);
	m_combo.AddString(L"네이버");
	m_combo.AddString(L"구글");
	m_combo.AddString(L"다음");
	m_combo.AddString(L"유튜브");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 검색
void CTab5::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str1, str2;
	pEdit->GetWindowText(str1);

	m_combo.GetLBText(m_combo.GetCurSel(),str2);
	str1.Replace(L" ", L"+");
	
	
	if (str2 == L"구글") {
		str1.Format(L"https://google.co.kr/search?q=%s", str1);
	}
	else if (str2 == L"네이버") {
		str1.Format(L"https://search.naver.com/search.naver?sm=top_hty&fbm=1&ie=utf8&query=%s", str1);
	}
	else if(str2 == L"다음"){
		str1.Format(L"https://search.daum.net/search?w=tot&DA=YZR&t__nil_searchbox=btn&sug=&sugo=&q=%s", str1);
	}
	else {
		str1.Format(L"https://www.youtube.com/results?search_query=%s", str1);
	}
	ShellExecute(NULL, L"open", str1, L"", L"", SW_SHOW);
}
