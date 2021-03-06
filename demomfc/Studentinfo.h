#pragma once


// Studentinfo 对话框

class Studentinfo : public CDialogEx
{
	DECLARE_DYNAMIC(Studentinfo)

public:
	Studentinfo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Studentinfo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Stuinfo };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void refresh();
	CListCtrl m_list;
	BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
