#pragma once


// Sexam 对话框

class Sexam : public CDialogEx
{
	DECLARE_DYNAMIC(Sexam)

public:
	Sexam(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Sexam();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Exam };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	virtual BOOL OnInitDialog();
	void refresh(int);
	CListCtrl m_list;
	CComboBox m_combox;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
