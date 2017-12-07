#pragma once
#include "afxwin.h"


// CPara4 对话框

class CPara4 : public CDialogEx
{
	DECLARE_DYNAMIC(CPara4)

public:
	static CPara4* getInstance();//取得实例
	
	virtual ~CPara4();

// 对话框数据
	enum { IDD = IDD_PARA4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CPara4(CWnd* pParent = NULL);   // 标准构造函数
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_CP4CamList_L;
	CComboBox m_CP4CamList_R;
	CComboBox m_CP4Resolution;
	CComboBox m_CP4MethodList;

	afx_msg void OnSelchangeCp4resolution();
	
	afx_msg void OnCbnSelchangeCbn2methodlist();
	afx_msg void OnCbnSelchangeCp4camlistL();
	afx_msg void OnCbnSelchangeCp4camlistR();
};
static CPara4* CP4_instance;//单件模式