
// MyTestDlg.h: 헤더 파일
//

#pragma once
class CTab1;    // 달력
class CTab2;    // 일정
class CTab3;	// 메모
class CTab4;	// 스톱 워치
class CTab5;	// 검색
class Setting;	// 메모, 데이터파일 관리
// CMyTestDlg 대화 상자
class CMyTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CMyTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTab1 *pDlg1;
	CTab2 *pDlg2;
	CTab3 *pDlg3;
	CTab4 *pDlg4;
	CTab5 *pDlg5;
	Setting *set;
	CTabCtrl m_tab;
	void UpdateOpa();
	CSliderCtrl *m_slider;
	CString day;
	CString time;
	static UINT TimeThread(LPVOID _mothod);
	int m_nOpa;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);  // 탭 선택
	afx_msg void OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult);   // 슬라이더
};
