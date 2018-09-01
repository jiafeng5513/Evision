// Para1.cpp : 实现文件
//

#include "stdafx.h"
#include "EvisionLegacy.h"
#include "Para1.h"
#include "afxdialogex.h"


// CPara1 对话框 标定控件面板

IMPLEMENT_DYNAMIC(CPara1, CDialog)
CPara1* CPara1::getInstance(){//取得实例
	if (CP1_instance==0)
	{
		CP1_instance = new CPara1();
	}
	return CP1_instance;
}
CPara1::CPara1(CWnd* pParent /*=NULL*/)
	: CDialog(CPara1::IDD, pParent)
{

}

CPara1::~CPara1()
{
}

void CPara1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CP1CamList_L, m_CP1CamList_L);
	DDX_Control(pDX, IDC_CP1CamList_R, m_CP1CamList_R);
	DDX_Control(pDX, IDC_CP1Resolution, m_CP1Resolution);
}


BEGIN_MESSAGE_MAP(CPara1, CDialog)
	ON_EN_CHANGE(IDC_BoardWidth, &CPara1::OnChangeBoardwidth)
	ON_EN_CHANGE(IDC_BoardHeight, &CPara1::OnChangeBoardheight)
	ON_EN_CHANGE(IDC_SquareSize, &CPara1::OnChangeSquaresize)
	ON_CBN_SELCHANGE(IDC_CP1CamList_L, &CPara1::OnCbnSelchangeCp1camlistL)
	ON_CBN_SELCHANGE(IDC_CP1CamList_R, &CPara1::OnCbnSelchangeCp1camlistR)
	ON_CBN_SELCHANGE(IDC_CP1Resolution, &CPara1::OnCbnSelchangeCp1resolution)
END_MESSAGE_MAP()


// CPara1 消息处理程序


void CPara1::OnChangeBoardwidth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	//原程序中并没有给出实现.天使微积分注
}


void CPara1::OnChangeBoardheight()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	//原程序中并没有给出实现.天使微积分注
}


void CPara1::OnChangeSquaresize()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	//原程序中并没有给出实现.天使微积分注
}



//左摄像头下拉列表
void CPara1::OnCbnSelchangeCp1camlistL()
{
	// TODO:  在此添加控件通知处理程序代码
	//左摄像头被修改,发出自定义消息,通知主程序框架处理该事件
	//主程序框架收到这个消息的时候,应该使用单件模式,使用本类的静态指针访问下拉列表框得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_CPara4ChangeCameraL, 1, 0);
}

//右摄像头下拉列表
void CPara1::OnCbnSelchangeCp1camlistR()
{
	// TODO:  在此添加控件通知处理程序代码
	//右摄像头被修改,发出自定义消息,通知主程序框架处理该事件
	//主程序框架收到这个消息的时候,应该使用单件模式,使用本类的静态指针访问下拉列表框得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_CPara4ChangeCameraR, 1, 0);
}

//分辨率下拉列表
void CPara1::OnCbnSelchangeCp1resolution()
{
	// TODO:  在此添加控件通知处理程序代码
	//分辨率被更改,应该发出自定义消息,通知主程序处理该事件
	//在处理改的时候,应该使用单件模式,使用CPara1/4的静态指针访问下拉列表框,得到索引号
	AfxGetMainWnd()->SendMessage(WM_USER_ChangeDPI, 1, 0);
}
