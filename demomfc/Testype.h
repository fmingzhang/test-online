#pragma once


// Testype 对话框

class Testype : public CDialogEx
{
	DECLARE_DYNAMIC(Testype)

public:
	Testype(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Testype();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_select_paper };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedok();
	CComboBox m_combox;
	virtual BOOL OnInitDialog();
	int m_id;
};
