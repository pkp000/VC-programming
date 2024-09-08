
// user_password_interfaceDlg.h: 头文件
//

#pragma once
#include"BackSystemDlg.h"
#include"RegistrationDlg.h"
#include"VerificationDlg.h"
#include"MainInterface.h"

// CuserpasswordinterfaceDlg 对话框
class CuserpasswordinterfaceDlg : public CDialogEx
{
// 构造
public:
	CuserpasswordinterfaceDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER_PASSWORD_INTERFACE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();


private:

	RegistrationDlg Cwind2;
	VerificationDlg Cwind3;
	MainInterface CwindMain;


public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
