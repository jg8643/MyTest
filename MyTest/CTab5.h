#pragma once


// CTab5 대화 상자

class CTab5 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab5)

public:
	CTab5(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab5();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CEdit* pEdit;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();  // 검색
};
