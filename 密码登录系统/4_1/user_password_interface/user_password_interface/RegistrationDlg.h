﻿#pragma once
#include "afxdialogex.h"


// RegistrationDlg 对话框

class RegistrationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RegistrationDlg)

public:
	RegistrationDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RegistrationDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
