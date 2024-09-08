// RegistrationDlg.cpp: 实现文件
//

#include "pch.h"
#include "user_password_interface.h"
#include "afxdialogex.h"
#include "RegistrationDlg.h"


// RegistrationDlg 对话框

IMPLEMENT_DYNAMIC(RegistrationDlg, CDialogEx)

RegistrationDlg::RegistrationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

RegistrationDlg::~RegistrationDlg()
{
}

void RegistrationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RegistrationDlg, CDialogEx)
END_MESSAGE_MAP()


// RegistrationDlg 消息处理程序
