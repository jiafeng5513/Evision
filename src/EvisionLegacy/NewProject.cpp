// NewProject.cpp : 实现文件
//

#include "stdafx.h"
#include "EvisionLegacy.h"
#include "NewProject.h"
#include "afxdialogex.h"
#include "Resource.h"


// CNewProject 对话框
/*
用来获取新建工程的工程名用的对话框
*/

IMPLEMENT_DYNAMIC(CNewProject, CDialogEx)

CNewProject::CNewProject(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewProject::IDD, pParent)
	, ProjectName(_T(""))
{

}

CNewProject::~CNewProject()
{
}

void CNewProject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ProjectName, ProjectName);
}


BEGIN_MESSAGE_MAP(CNewProject, CDialogEx)
END_MESSAGE_MAP()


// CNewProject 消息处理程序
