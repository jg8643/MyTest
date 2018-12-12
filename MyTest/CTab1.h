#pragma once


// CTab1 대화 상자
class Setting;
class CMyTestDlg;
class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMonthCalCtrl *calendar;
	CFont font;
	afx_msg void OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	CMyTestDlg *pmytestdlg;
	Setting *set;
	afx_msg void OnMcnSelectMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
};
