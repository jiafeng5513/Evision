// Para4.cpp : 实现文件
//

#include "stdafx.h"
#include "SkyEyes.h"
#include "Para4.h"
#include "afxdialogex.h"
#include "MainFrm.h"

// CPara4 对话框 采样控件面板

IMPLEMENT_DYNAMIC(CPara4, CDialogEx)

CPara4* CPara4::getInstance(){//取得实例
	if (CP4_instance == 0)
	{
		CP4_instance = new CPara4();
	}
	return CP4_instance;
}

CPara4::CPara4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPara4::IDD, pParent)
{

}

CPara4::~CPara4()
{
}

void CPara4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CP4CamList_L, m_CP4CamList_L);
	DDX_Control(pDX, IDC_CP4CamList_R, m_CP4CamList_R);
	DDX_Control(pDX, IDC_CP4MethodList, m_CP4MethodList);
	DDX_Control(pDX, IDC_CP4Resolution, m_CP4Resolution);
}


BEGIN_MESSAGE_MAP(CPara4, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CP4Resolution, &CPara4::OnSelchangeCp4resolution)
	ON_CBN_SELCHANGE(IDC_CP4MethodList, &CPara4::OnCbnSelchangeCbn2methodlist)
	ON_CBN_SELCHANGE(IDC_CP4CamList_L, &CPara4::OnCbnSelchangeCp4camlistL)
	ON_CBN_SELCHANGE(IDC_CP4CamList_R, &CPara4::OnCbnSelchangeCp4camlistR)
END_MESSAGE_MAP()


// CPara4 消息处理程序


void CPara4::OnSelchangeCp4resolution()
{
	// TODO:  在此添加控件通知处理程序代码
	//分辨率被更改,应该发出自定义消息,通知主程序处理该事件
	//在处理改的时候,应该使用单件模式,使用CPara1/4的静态指针访问下拉列表框,得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_ChangeDPI, 4, 0);
}


void CPara4::OnCbnSelchangeCbn2methodlist()
{
	// TODO:  在此添加控件通知处理程序代码
	//帧处理方法被修改,发出自定义消息,通知主程序框架处理该事件
	//主程序框架收到这个消息的时候,应该使用单件模式,使用本类的静态指针访问下拉列表框得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_ChangeFrameProcMethod, 4, 0);
}


void CPara4::OnCbnSelchangeCp4camlistL()
{
	// TODO:  在此添加控件通知处理程序代码
	//左摄像头被修改,发出自定义消息,通知主程序框架处理该事件
	//主程序框架收到这个消息的时候,应该使用单件模式,使用本类的静态指针访问下拉列表框得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_CPara4ChangeCameraL, 4, 0);
}


void CPara4::OnCbnSelchangeCp4camlistR()
{
	// TODO:  在此添加控件通知处理程序代码
	//右摄像头被修改,发出自定义消息,通知主程序框架处理该事件
	//主程序框架收到这个消息的时候,应该使用单件模式,使用本类的静态指针访问下拉列表框得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_CPara4ChangeCameraR, 4, 0);
}
