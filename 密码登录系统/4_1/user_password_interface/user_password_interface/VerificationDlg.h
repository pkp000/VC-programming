#pragma once
#include "afxdialogex.h"
#include"BackSystemDlg.h"

// VerificationDlg 对话框

class VerificationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(VerificationDlg)

public:
	VerificationDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~VerificationDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	BackSystemDlg Cwind4;

public:
	afx_msg void OnBnClickedOk();
};
