#pragma once
#include "afxdialogex.h"
#include"BackSystemDlg.h"


// MainInterface 对话框

class MainInterface : public CDialogEx
{
	DECLARE_DYNAMIC(MainInterface)

public:
	MainInterface(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MainInterface();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

private:
	BackSystemDlg Cwind1;
};
