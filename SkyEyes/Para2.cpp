// Para2.cpp : 实现文件
//

#include "stdafx.h"
#include "SkyEyes.h"
#include "Para2.h"
#include "afxdialogex.h"


// CPara2 对话框

IMPLEMENT_DYNAMIC(CPara2, CDialog)
CPara2* CPara2::getInstance(){//取得实例
	if (CP2_instance == 0)
	{
		CP2_instance = new CPara2();
	}
	return CP2_instance;
}
CPara2::CPara2(CWnd* pParent /*=NULL*/)
	: CDialog(CPara2::IDD, pParent)
	, v_nMinDisp(0)
	, v_nMaxDisp(0)
	, v_nSADWinSiz(0)
	, v_nUniqRatio(0)
	, v_nSpeckRange(0)
	, v_nTextThres(0)
	, v_nSpeckWinSiz(0)
	, v_nPreFiltCap(0)
	, v_nDisp12MaxDiff(0)
{
	
}

CPara2::~CPara2()
{
}

void CPara2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_minDisp, s_nMinDisp);
	DDX_Control(pDX, IDC_SLIDER_uniqRatio, s_nUniqRatio);
	DDX_Control(pDX, IDC_SLIDER_speckWinSiz, s_nSpeckWinSiz);
	DDX_Control(pDX, IDC_SLIDER_maxDisp, s_nMaxDisp);
	DDX_Control(pDX, IDC_SLIDER_speckRange, s_nSpeckRange);
	DDX_Control(pDX, IDC_SLIDER_preFiltCap, s_nPreFiltCap);
	DDX_Control(pDX, IDC_SLIDER_SADWinSiz, s_nSADWinSiz);
	DDX_Control(pDX, IDC_SLIDER_textThres, s_nTextThres);
	DDX_Control(pDX, IDC_SLIDER_disp12MaxDiff, s_nDisp12MaxDiff);
	DDX_Text(pDX, IDC_EDIT_minDisp, v_nMinDisp);
	DDX_Text(pDX, IDC_EDIT_maxDisp, v_nMaxDisp);
	DDX_Text(pDX, IDC_EDIT_SADWinSiz, v_nSADWinSiz);
	DDX_Text(pDX, IDC_EDIT_uniqRatio, v_nUniqRatio);
	DDX_Text(pDX, IDC_EDIT_speckRange, v_nSpeckRange);
	DDX_Text(pDX, IDC_EDIT_textThres, v_nTextThres);
	DDX_Text(pDX, IDC_EDIT_speckWinSiz, v_nSpeckWinSiz);
	DDX_Text(pDX, IDC_EDIT_preFiltCap, v_nPreFiltCap);
	DDX_Text(pDX, IDC_EDIT_disp12MaxDiff, v_nDisp12MaxDiff);
}

BEGIN_MESSAGE_MAP(CPara2, CDialog)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT_minDisp, &CPara2::OnChangeEditMindisp)
	ON_EN_CHANGE(IDC_EDIT_disp12MaxDiff, &CPara2::OnChangeEditDisp12maxdiff)
	ON_EN_CHANGE(IDC_EDIT_maxDisp, &CPara2::OnChangeEditMaxdisp)
	ON_EN_CHANGE(IDC_EDIT_preFiltCap, &CPara2::OnChangeEditPrefiltcap)
	ON_EN_CHANGE(IDC_EDIT_SADWinSiz, &CPara2::OnChangeEditSadwinsiz)
	ON_EN_CHANGE(IDC_EDIT_speckRange, &CPara2::OnChangeEditSpeckrange)
	ON_EN_CHANGE(IDC_EDIT_speckWinSiz, &CPara2::OnChangeEditSpeckwinsiz)
	ON_EN_CHANGE(IDC_EDIT_textThres, &CPara2::OnChangeEditTextthres)
	ON_EN_CHANGE(IDC_EDIT_uniqRatio, &CPara2::OnChangeEditUniqratio)
END_MESSAGE_MAP()

//滑动条更新事件处理
void CPara2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	v_nMinDisp = s_nMinDisp.GetPos();//取得当前位置值 
	v_nUniqRatio = s_nUniqRatio.GetPos();
	v_nSpeckWinSiz = s_nSpeckWinSiz.GetPos();
	v_nMaxDisp = s_nMaxDisp.GetPos();
	v_nSpeckRange = s_nSpeckRange.GetPos();
	v_nPreFiltCap = s_nPreFiltCap.GetPos();
	v_nSADWinSiz = s_nSADWinSiz.GetPos();
	v_nTextThres = s_nTextThres.GetPos();
	v_nDisp12MaxDiff = s_nDisp12MaxDiff.GetPos();
	UpdateData(false);
	//回调
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


// 给滚动条按照对应变量设置位置
void CPara2::SetSlider()
{
	s_nMinDisp.SetPos(v_nMinDisp);
	s_nUniqRatio.SetPos(v_nUniqRatio);
	s_nSpeckWinSiz.SetPos(v_nSpeckWinSiz);
	s_nMaxDisp.SetPos(v_nMaxDisp);
	s_nSpeckRange.SetPos(v_nSpeckRange);
	s_nPreFiltCap.SetPos(v_nPreFiltCap);
	s_nSADWinSiz.SetPos(v_nSADWinSiz);
	s_nTextThres.SetPos(v_nTextThres);
	s_nDisp12MaxDiff.SetPos(v_nDisp12MaxDiff);
}


void CPara2::OnChangeEditMindisp()
{
	UpdateData(TRUE);
	s_nMinDisp.SetPos(v_nMinDisp);
}


void CPara2::OnChangeEditDisp12maxdiff()
{
	UpdateData(TRUE);
	s_nDisp12MaxDiff.SetPos(v_nDisp12MaxDiff);
}


void CPara2::OnChangeEditMaxdisp()
{
	UpdateData(TRUE);
	s_nMaxDisp.SetPos(v_nMaxDisp);
}


void CPara2::OnChangeEditPrefiltcap()
{
	UpdateData(TRUE);
	s_nPreFiltCap.SetPos(v_nPreFiltCap);
}


void CPara2::OnChangeEditSadwinsiz()
{
	UpdateData(TRUE);
	s_nSADWinSiz.SetPos(v_nSADWinSiz);
}


void CPara2::OnChangeEditSpeckrange()
{
	UpdateData(TRUE);
	s_nSpeckRange.SetPos(v_nSpeckRange);
}


void CPara2::OnChangeEditSpeckwinsiz()
{
	UpdateData(TRUE);
	s_nSpeckWinSiz.SetPos(v_nSpeckWinSiz);
}


void CPara2::OnChangeEditTextthres()
{
	UpdateData(TRUE);
	s_nTextThres.SetPos(v_nTextThres);
}


void CPara2::OnChangeEditUniqratio()
{
	UpdateData(TRUE);
	s_nUniqRatio.SetPos(v_nUniqRatio);
}

//初始化事件处理
BOOL CPara2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
//初始化滑动条的滑动范围
	s_nMinDisp.SetRange(-159, 159);
	s_nUniqRatio.SetRange(0, 30);
    s_nSpeckWinSiz.SetRange(0, 150);
	s_nMaxDisp.SetRange(0, 200);
	s_nSpeckRange.SetRange(0, 100);
	s_nPreFiltCap.SetRange(0, 100);
	s_nSADWinSiz.SetRange(0, 20);
	s_nTextThres.SetRange(0, 100);
	s_nDisp12MaxDiff.SetRange(0, 100);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
