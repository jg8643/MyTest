#pragma once


// CTab3 대화 상자
class Setting;
class CMyTestDlg;
class CTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab3)

public:
	CTab3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CMyTestDlg *pmytestdlg;
	Setting *set;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();   // 자동 저장
};
