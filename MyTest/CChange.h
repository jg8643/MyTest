#pragma once


// CChange 대화 상자
class Setting;
class CMyTestDlg;
class CTab2;
class CChange : public CDialogEx
{
	DECLARE_DYNAMIC(CChange)

public:
	CChange(CString str,CWnd* pParent = nullptr);  
	CChange(CWnd* pParent = nullptr);     // 표준 생성자입니다.
	virtual ~CChange();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	CString date;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMyTestDlg *pmytestdlg;
	Setting *set;
	CEdit *pEdit1;
	CEdit *pEdit2;
	CTab2 *pDlg2;
	afx_msg void OnBnClickedOk();
};
