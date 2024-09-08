#pragma once
#include "afxdialogex.h"

extern CString userName0;
extern CString password0;
extern CString* p;
// BackSystemDlg 对话框

class BackSystemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BackSystemDlg)

public:
	BackSystemDlg(CWnd* pParent = nullptr)afx_msg; void OnBnClickedOk();
	;   // 标准构造函数
	virtual ~BackSystemDlg();
	BOOL m_bCanExit;


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Back };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	
	
	// 自定义的声明
private:
	CString str1;
	CString str2;
};
