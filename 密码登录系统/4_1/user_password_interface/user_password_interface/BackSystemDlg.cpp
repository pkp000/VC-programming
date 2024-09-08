// BackSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "user_password_interface.h"
#include "afxdialogex.h"
#include "BackSystemDlg.h"

// BackSystemDlg 对话框

IMPLEMENT_DYNAMIC(BackSystemDlg, CDialogEx)

BackSystemDlg::BackSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Back, pParent)
	, m_bCanExit(FALSE)
{

}

BackSystemDlg::~BackSystemDlg()
{
}

void BackSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_new1, str1);
	DDX_Text(pDX, IDC_new2, str2);
}


BEGIN_MESSAGE_MAP(BackSystemDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BackSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &BackSystemDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// BackSystemDlg 消息处理程序

CString userName0 = "VC12345";
CString password0 = "123456";
CString* p = &password0;

void BackSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	if (strlen(str1) < 6 || strlen(str1) > 12)
	{
		MessageBox("The new password length does not meet the requirements. Please enter a password of 6 to 12 characters!");
	}
	
	else
	{
		if (strcmp(str1, str2)==0)
		{
			*p = str1;
			MessageBox("Password changed successfully!");
			str1 = "";
			str2 = "";

		}
		else
		{
			MessageBox("The two passwords are different!");
			str1 = "";
			str2 = "";
		}
	}

	UpdateData(FALSE);
}


void BackSystemDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
