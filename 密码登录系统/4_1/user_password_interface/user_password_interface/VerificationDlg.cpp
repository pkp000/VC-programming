// VerificationDlg.cpp: 实现文件
//

#include "pch.h"
#include "user_password_interface.h"
#include "afxdialogex.h"
#include "VerificationDlg.h"


// VerificationDlg 对话框

IMPLEMENT_DYNAMIC(VerificationDlg, CDialogEx)

VerificationDlg::VerificationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

VerificationDlg::~VerificationDlg()
{
}

void VerificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(VerificationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &VerificationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// VerificationDlg 消息处理程序


void VerificationDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	// CDialogEx::OnOK();
	Cwind4.DoModal();
}
