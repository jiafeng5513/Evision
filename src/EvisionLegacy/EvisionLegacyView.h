// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// EvisionLegacyView.h : CEvisionLegacyView 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "EvisionLegacyDoc.h"
#include "Para1.h"
#include "Para2.h"
#include "Para3.h"
#include "Para4.h"

class CEvisionLegacyView : public CFormView
{
protected: // 仅从序列化创建
	CEvisionLegacyView();
	DECLARE_DYNCREATE(CEvisionLegacyView)

public:
	enum{ IDD = IDD_SKYEYES_FORM };

// 特性
public:
	CEvisionLegacyDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CEvisionLegacyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	// TabControl的控制变量
	CTabCtrl m_tab;
    //外挂窗口的引用
	CPara1* m_para1;
	CPara2* m_para2;
	CPara3* m_para3;
	CPara4* m_para4;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnPaint();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // EvisionLegacyView.cpp 中的调试版本
inline CEvisionLegacyDoc* CEvisionLegacyView::GetDocument() const
   { return reinterpret_cast<CEvisionLegacyDoc*>(m_pDocument); }
#endif

