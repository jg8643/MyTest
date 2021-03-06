#pragma once


// CTab2 대화 상자
class Setting;
class CMyTestDlg;
class CTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrl;
	CMyTestDlg *pmytestdlg;
	Setting *set;
	int count;  // 리스트 컨트롤 개수
	virtual BOOL OnInitDialog();
	void UpdateList();   // 리스트 컨트롤 업데이트
	afx_msg void OnBnClickedButton1();   // 추가
	afx_msg void OnBnClickedButton2();   // 삭제
};
