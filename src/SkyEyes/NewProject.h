#pragma once


// CNewProject 对话框

class CNewProject : public CDialogEx
{
	DECLARE_DYNAMIC(CNewProject)

public:
	CNewProject(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewProject();

// 对话框数据
	enum { IDD = IDD_NewProject };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 用来保存工程名
	CString ProjectName;
};
