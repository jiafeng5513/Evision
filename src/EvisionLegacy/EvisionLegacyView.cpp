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

// EvisionLegacyView.cpp : CEvisionLegacyView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EvisionLegacy.h"
#endif

#include "EvisionLegacyDoc.h"
#include "EvisionLegacyView.h"
#include "OutputWnd.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEvisionLegacyView

IMPLEMENT_DYNCREATE(CEvisionLegacyView, CFormView)

BEGIN_MESSAGE_MAP(CEvisionLegacyView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CEvisionLegacyView::OnTcnSelchangeTab)
//	ON_WM_PAINT()
//	ON_WM_CREATE()
END_MESSAGE_MAP()

// CEvisionLegacyView 构造/析构

CEvisionLegacyView::CEvisionLegacyView()
	: CFormView(CEvisionLegacyView::IDD)
{
	// TODO:  在此处添加构造代码
	m_para1 = CPara1::getInstance();
	m_para2 = CPara2::getInstance();
	m_para3 = CPara3::getInstance();
	m_para4 = CPara4::getInstance();
}

CEvisionLegacyView::~CEvisionLegacyView()
{
}

void CEvisionLegacyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BOOL CEvisionLegacyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CEvisionLegacyView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//下面对主窗口下面的TabControl进行设置
	//1.创建标签页
	m_tab.InsertItem(0, _T("标定"));      //添加选项卡 
	m_tab.InsertItem(1, _T("立体匹配"));  
	m_tab.InsertItem(2, _T("测距"));
	m_tab.InsertItem(3, _T("采样"));
	//2.子窗口绑定
	m_para1->Create(IDD_PARA1, GetDlgItem(IDC_TAB));
	m_para2->Create(IDD_PARA2, GetDlgItem(IDC_TAB));
	m_para3->Create(IDD_PARA3, GetDlgItem(IDC_TAB));
	m_para4->Create(IDD_PARA4, GetDlgItem(IDC_TAB));
	//3.调整大小
	CRect rs;                //获得IDC_TABTEST客户区大小
	m_tab.GetClientRect(&rs);//调整子对话框在父窗口中的位置 
    rs.top += 22;
	rs.bottom -= 2;
	rs.left += 1;
	rs.right -= 3;           //设置子对话框尺寸并移动到指定位置 
	m_para1->MoveWindow(&rs);
	m_para2->MoveWindow(&rs);
	m_para3->MoveWindow(&rs);
	m_para4->MoveWindow(&rs);
	//4.显示
	m_para1->ShowWindow(true);
	m_para2->ShowWindow(false);
	m_para3->ShowWindow(false);
	m_para4->ShowWindow(false);
	//5.默认选中
	m_tab.SetCurSel(0);
	//注意,此时,这三个子窗口其实是叠在一起的,所以需要使用监听程序来调整显示的是哪一个,以实现切换页的效果
}

void CEvisionLegacyView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEvisionLegacyView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CEvisionLegacyView 诊断

#ifdef _DEBUG
void CEvisionLegacyView::AssertValid() const
{
	CFormView::AssertValid();
}

void CEvisionLegacyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEvisionLegacyDoc* CEvisionLegacyView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEvisionLegacyDoc)));
	return (CEvisionLegacyDoc*)m_pDocument;
}
#endif //_DEBUG


// CEvisionLegacyView 消息处理程序


void CEvisionLegacyView::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	int CurSel = m_tab.GetCurSel();
	CString str;
	switch (CurSel)
	{
		case 0:
		    m_para1->ShowWindow(true);
		    m_para2->ShowWindow(false);
		    m_para3->ShowWindow(false);
	    	m_para4->ShowWindow(false);
			break;
		case 1:
		         m_para1->ShowWindow(false);
		         m_para2->ShowWindow(true);
				 m_para3->ShowWindow(false);
				 m_para4->ShowWindow(false);
			break;
		case 2:
		         m_para1->ShowWindow(false);
		         m_para2->ShowWindow(false);
				 m_para3->ShowWindow(true);
				 m_para4->ShowWindow(false);
			 break;
		case 3:
			m_para1->ShowWindow(false);
			m_para2->ShowWindow(false);
			m_para3->ShowWindow(false);
			m_para4->ShowWindow(true);
			break;
		default:
				;
    }

	*pResult = 0;
}