#pragma once
#include "afxwin.h"


// CPara1 对话框

class CPara1 : public CDialog
{
	DECLARE_DYNAMIC(CPara1)

public:
	static CPara1* getInstance();//取得实例
	virtual ~CPara1();

// 对话框数据
	enum { IDD = IDD_PARA1 };

protected:
	CPara1(CWnd* pParent = NULL);   // 标准构造函数
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChangeBoardwidth();
	afx_msg void OnChangeBoardheight();
	afx_msg void OnChangeSquaresize();
	CComboBox m_CP1CamList_L;
	CComboBox m_CP1CamList_R;
	afx_msg void OnCbnSelchangeCp1camlistL();
	afx_msg void OnCbnSelchangeCp1camlistR();
	afx_msg void OnCbnSelchangeCp1resolution();
	CComboBox m_CP1Resolution;
};
static CPara1* CP1_instance;//单件模式