#pragma once


// CTab4 대화 상자

static int m_sec = 1, sec = 0, min = 0;

class CTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab4)

public:
	CTab4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab4();
	CEdit *pEdit;
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();   // 시작
	afx_msg void OnBnClickedButton2();   // 정지
	afx_msg void OnBnClickedButton3();   // 초기화
	afx_msg void OnBnClickedButton4();   // 기록
	CListCtrl m_listctrl;
	int count;   // 리스트 컨트롤 목록 개수
};
