#pragma once



// CPara3 对话框

class CPara3 : public CDialog
{
	DECLARE_DYNAMIC(CPara3)

public:
	static CPara3* getInstance();//取得实例
	virtual ~CPara3();

// 对话框数据
	enum { IDD = IDD_PARA3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CPara3(CWnd* pParent = NULL);   // 标准构造函数
	DECLARE_MESSAGE_MAP()
};
static CPara3* CP3_instance;//单件模式