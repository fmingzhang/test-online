// Sexam.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "Sexam.h"
#include "afxdialogex.h"
#include "Adocon.h"
# include "AddFix.h"
// Sexam 对话框

IMPLEMENT_DYNAMIC(Sexam, CDialogEx)

Sexam::Sexam(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Exam, pParent)
{

}

Sexam::~Sexam()
{
}

void Sexam::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
}


BEGIN_MESSAGE_MAP(Sexam, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &Sexam::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &Sexam::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Sexam::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Sexam::OnBnClickedButton4)
END_MESSAGE_MAP()


// Sexam 消息处理程序
void Sexam::refresh(int i)
{

	CRect rect;
	CString sql, test, name, dep, sno, sql_ans;
	CString cvt_c, cvt_d, cvt_ans, cvt_sco;
	Adocon con;
	_RecordsetPtr rec, rec_info;
	_variant_t vt, vt_name, vt_sno, vt_dep;
	_variant_t vt_ans, vt_sco, vt_c, vt_d;
	con.initadocon();

	sql.Format(_T("select count(*) as[c] from testquestion where subject_id = %d"),i);
		rec = con.record(sql);
	vt = rec->GetCollect("c");
	test = (LPCSTR)_bstr_t(vt);
	int num = _ttoi(test);
	//	sql.Format(_T("select * from testquestion where subject_id = %d"),i);
		//	sql="select * from testquestion,testanswer where subject_id = 3000";
		//	sql_ans.Format(_T("select * from testanswer where subject_id = %d"), i));
		sql_ans.Format(_T("select * from testquestion,testanswer where testquestion.question_id = testanswer.que_id and subject_id = %d"),i);
		rec_info = con.record(sql_ans);



	//AfxMessageBox(test);
	//

	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() |

		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("问题"), LVCFMT_CENTER, rect.Width() /7, 0);
	m_list.InsertColumn(1, _T("A"), LVCFMT_CENTER, rect.Width() / 7,1);
	m_list.InsertColumn(2, _T("B"), LVCFMT_CENTER, rect.Width() / 7,2);
	m_list.InsertColumn(3, _T("C"), LVCFMT_CENTER, rect.Width() / 7,3);
	m_list.InsertColumn(4, _T("D"), LVCFMT_CENTER, rect.Width() / 7,4);
	m_list.InsertColumn(5, _T("答案"), LVCFMT_CENTER, rect.Width() /7, 5);
	m_list.InsertColumn(6, _T("分数"), LVCFMT_CENTER, rect.Width() /7, 6);


	for (auto i = 0; i < num; i++)
	{
		//rec->MoveFirst();
		vt_sno = rec_info->GetCollect("question");
		vt_name = rec_info->GetCollect("ans_a");
		vt_dep = rec_info->GetCollect("ans_b");
		vt_c = rec_info->GetCollect("ans_c");
		vt_d = rec_info->GetCollect("ans_d");
		vt_ans = rec_info->GetCollect("ans");
		vt_sco = rec_info->GetCollect("score");

		sno = (LPCSTR)_bstr_t(vt_sno);
		name = (LPCSTR)_bstr_t(vt_name);
		dep = (LPCSTR)_bstr_t(vt_dep);
		cvt_c = (LPCSTR)_bstr_t(vt_c);
		cvt_d = (LPCSTR)_bstr_t(vt_d);
		cvt_ans = (LPCSTR)_bstr_t(vt_ans);
		cvt_sco = (LPCSTR)_bstr_t(vt_sco);



		m_list.InsertItem(i, sno);

		m_list.SetItemText(i, 1, name);
		m_list.SetItemText(i, 2, dep);
		m_list.SetItemText(i, 3, cvt_c);
		m_list.SetItemText(i, 4, cvt_d);
		m_list.SetItemText(i, 5, cvt_ans);
		m_list.SetItemText(i, 6, cvt_sco);


		rec_info->MoveNext();
	}

	con.exitcon();



}
int type;
void Sexam::OnBnClickedButton5()  //find
{
	// TODO: 在此添加控件通知处理程序代码

	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);

	CComboBox *box;
	
	box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	type = box->GetCurSel();
	if (type == 0)
	{
		refresh(3001);
	}
	else
	{
		refresh(3000);
	}

}


BOOL Sexam::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_combox.AddString(_T("数据库"));
	m_combox.AddString(_T("数据结构"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Sexam::OnBnClickedButton1()  //add
{
	// TODO: 在此添加控件通知处理程序代码
	AddFix add;
	if (type == 0)
	{
		add.subid = 3001;
	}
	else add.subid = 3000;
	add.DoModal();
	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);
	//m_list.dele
	if (type == 0)
	{
		refresh(3001);
	}
	else
	{
		refresh(3000);
	}

}


void Sexam::OnBnClickedButton3()  //fix
{
	// TODO: 在此添加控件通知处理程序代码
	int a;
	CString q_no;

	a = m_list.GetSelectionMark();
	q_no = m_list.GetItemText(a, 0);
	
	AddFix fix;
	fix.t = "fix";
	fix.num = q_no;
	//
	if(type==0)
	{
		fix.subid = 3001;
	}
	else fix.subid = 3000;
	fix.DoModal();

	m_list.DeleteAllItems();

	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);
	//m_list.dele
	if (type == 0)
	{
		refresh(3001);
	}
	else
	{
		refresh(3000);
	}
}


void Sexam::OnBnClickedButton4()  //del
{
	// TODO: 在此添加控件通知处理程序代码
	Adocon con;
	_RecordsetPtr record;
	CString sql, qno;
	int a;
	a = m_list.GetSelectionMark();
	qno = m_list.GetItemText(a, 0);

	sql.Format(_T("select * from testquestion,testanswer where testquestion.question_id=testanswer.que_id and question='%s'"), qno);
	con.initadocon();

	record = con.record(sql);
	record->Delete(adAffectCurrent);
	record->Update();
	con.exitcon();
	/*
	sql.Format(_T("delete from stuinfo where sno=%d"), s_no);
	con.initadocon();
	con.executesql(sql);
	con.exitcon();
	*/
	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);

	//m_list.dele
	if (type == 0)
	{
		refresh(3001);
	}
	else
	{
		refresh(3000);
	}
}
