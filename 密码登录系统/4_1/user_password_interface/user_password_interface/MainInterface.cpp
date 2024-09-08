// MainInterface.cpp: 实现文件
//

#include "pch.h"
#include "user_password_interface.h"
#include "afxdialogex.h"
#include "MainInterface.h"



// MainInterface 对话框

IMPLEMENT_DYNAMIC(MainInterface, CDialogEx)

MainInterface::MainInterface(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

MainInterface::~MainInterface()
{
}

void MainInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainInterface, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MainInterface::OnBnClickedButton1)
END_MESSAGE_MAP()


// MainInterface 消息处理程序


void MainInterface::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cwind1.DoModal();
}
