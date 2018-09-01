// Para2.cpp : 实现文件
//

#include "stdafx.h"
#include "EvisionLegacy.h"
#include "Para2.h"
#include "afxdialogex.h"


// CPara2 对话框 匹配参数控件

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
	, v_nMinDisp(-64)
	, v_nMaxDisp(16)
	, v_nSADWinSiz(5)
	, v_nUniqRatio(0)
	, v_nSpeckRange(0)
	, v_nTextThres(0)
	, v_nSpeckWinSiz(0)
	, v_nPreFiltCap(1)
	, v_nDisp12MaxDiff(0)
	, v_nLevels(1)
	, v_nPyrScale(0.1f)
	, v_nPolyN(1)
	, v_nPolySigma(0)
	, v_nFi(0)
	, v_nLambda(0)
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
	DDX_Control(pDX, IDC_SLIDER_Levels, s_nLevels);
	DDX_Control(pDX, IDC_SLIDER_PyrScale, s_nPyrScale);
	DDX_Control(pDX, IDC_SLIDER_PolyN, s_nPolyn);
	DDX_Control(pDX, IDC_SLIDER_PolySigma, s_nPolySigma);
	DDX_Control(pDX, IDC_SLIDER_Fi, s_nFi);
	DDX_Control(pDX, IDC_SLIDER_Lambda, s_nLambda);
	DDX_Text(pDX, IDC_EDIT_minDisp, v_nMinDisp);
	DDX_Text(pDX, IDC_EDIT_maxDisp, v_nMaxDisp);
	DDX_Text(pDX, IDC_EDIT_SADWinSiz, v_nSADWinSiz);
	DDX_Text(pDX, IDC_EDIT_uniqRatio, v_nUniqRatio);
	DDX_Text(pDX, IDC_EDIT_speckRange, v_nSpeckRange);
	DDX_Text(pDX, IDC_EDIT_textThres, v_nTextThres);
	DDX_Text(pDX, IDC_EDIT_speckWinSiz, v_nSpeckWinSiz);
	DDX_Text(pDX, IDC_EDIT_preFiltCap, v_nPreFiltCap);
	DDX_Text(pDX, IDC_EDIT_disp12MaxDiff, v_nDisp12MaxDiff);
	DDX_Text(pDX, IDC_EDIT_Levels, v_nLevels);
	DDX_Text(pDX, IDC_EDIT_PyrScale, v_nPyrScale);
	DDX_Text(pDX, IDC_EDIT_PolyN, v_nPolyN);
	DDX_Text(pDX, IDC_EDIT_PolySigma, v_nPolySigma);
	DDX_Text(pDX, IDC_EDIT_Fi, v_nFi);
	DDX_Text(pDX, IDC_EDIT_Lambda, v_nLambda);
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
//	ON_EN_CHANGE(IDC_EDIT_Levels, &CPara2::OnEnChangeEditLevels)
ON_EN_CHANGE(IDC_EDIT_Levels, &CPara2::OnChangeEditLevels)
ON_EN_CHANGE(IDC_EDIT_Fi, &CPara2::OnChangeEditFi)
ON_EN_CHANGE(IDC_EDIT_Lambda, &CPara2::OnChangeEditLambda)
ON_EN_CHANGE(IDC_EDIT_PolyN, &CPara2::OnChangeEditPolyn)
ON_EN_CHANGE(IDC_EDIT_PolySigma, &CPara2::OnChangeEditPolysigma)
ON_EN_CHANGE(IDC_EDIT_PyrScale, &CPara2::OnChangeEditPyrscale)
END_MESSAGE_MAP()

//滑动条更新事件处理
void CPara2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	v_nMinDisp       = s_nMinDisp.GetPos();//取得当前位置值 
	v_nUniqRatio     = s_nUniqRatio.GetPos();
	v_nSpeckWinSiz   = s_nSpeckWinSiz.GetPos();
	v_nMaxDisp       = s_nMaxDisp.GetPos()*16;
	v_nSpeckRange    = s_nSpeckRange.GetPos();
	v_nPreFiltCap    = s_nPreFiltCap.GetPos();
	v_nSADWinSiz     = s_nSADWinSiz.GetPos()*2+1;
	v_nTextThres     = s_nTextThres.GetPos();
	v_nDisp12MaxDiff = s_nDisp12MaxDiff.GetPos();

	v_nLevels        =s_nLevels.GetPos();
	v_nPyrScale      = s_nPyrScale.GetPos()/10.0f;
	v_nPolyN         = s_nPolyn.GetPos() * 2 + 1;
	v_nPolySigma     = s_nPolySigma.GetPos() / 10.0f;
	v_nFi            = s_nFi.GetPos() / 10.0f;
	v_nLambda        = s_nLambda.GetPos() / 100.00f;
	

	if (UpdateData(false))
	{
		// 发出消息,提醒主类,此时应该更新视差图
		AfxGetMainWnd()->SendMessage(WM_USER_RefreshDisparityMap, 0, 0);
	}
	
	//回调
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


// 给滚动条按照对应变量设置位置
void CPara2::SetSlider()
{
	s_nMinDisp.SetPos(v_nMinDisp);
	s_nUniqRatio.SetPos(v_nUniqRatio);
	s_nSpeckWinSiz.SetPos(v_nSpeckWinSiz);
	s_nMaxDisp.SetPos(v_nMaxDisp/16);
	s_nSpeckRange.SetPos(v_nSpeckRange);
	s_nPreFiltCap.SetPos(v_nPreFiltCap);
	s_nSADWinSiz.SetPos((v_nSADWinSiz-1)/2);
	s_nTextThres.SetPos(v_nTextThres);
	s_nDisp12MaxDiff.SetPos(v_nDisp12MaxDiff);

	s_nLevels.SetPos(v_nLevels);
	s_nPyrScale.SetPos(int(v_nPyrScale*10));
	s_nPolyn.SetPos((v_nPolyN-1)/2);
	s_nPolySigma.SetPos(int(v_nPolySigma*10));
	s_nFi.SetPos(int(v_nFi*10));
	s_nLambda.SetPos(int(v_nLambda*100));


}
//初始化事件处理
BOOL CPara2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//初始化滑动条的滑动范围
	s_nMinDisp.SetRange(-64, 16);     //步长是1
	s_nMaxDisp.SetRange(1, 16);     //步长是16,本来的范围是[16-256]
	s_nSADWinSiz.SetRange(2, 25);     //步长是2,本来的范围是[5,21]
	s_nTextThres.SetRange(0, 50);     //步长是1
	s_nDisp12MaxDiff.SetRange(-1, 5);//步长是1
	s_nPreFiltCap.SetRange(1, 100);    //步长是1
	s_nUniqRatio.SetRange(0, 50);     //步长是1
	s_nSpeckRange.SetRange(0, 64);    //步长是1
	s_nSpeckWinSiz.SetRange(0, 200);  //步长是1

	s_nLevels.SetRange(1, 10);     //一到十,正常
	s_nPyrScale.SetRange(1, 10);   //本来的范围是(0.1,1)
	s_nPolyn.SetRange(1, 30);       //本来的范围是 奇数,2n+1,n∈[1,7]
	s_nPolySigma.SetRange(0, 1000); //本来的范围是[0,10]
	s_nFi.SetRange(0, 900);        //本来的范围是[0,30]
	s_nLambda.SetRange(0, 100);    //本来的范围是[0,1]
	
	s_nLevels.SetPos(1);
	s_nPyrScale.SetPos(1);
	s_nPolyn.SetPos(1);
	s_nPolySigma.SetPos(0);
	s_nFi.SetPos(0);
	s_nLambda.SetPos(0);

	s_nMinDisp.SetPos(-64);
	s_nMaxDisp.SetPos(1);
	s_nSADWinSiz.SetPos(2);
	s_nTextThres.SetPos(0);
	s_nDisp12MaxDiff.SetPos(0);
	s_nPreFiltCap.SetPos(1);
	s_nUniqRatio.SetPos(0);
	s_nSpeckRange.SetPos(0);
	s_nSpeckWinSiz.SetPos(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
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
	s_nMaxDisp.SetPos(v_nMaxDisp/16);
}

void CPara2::OnChangeEditPrefiltcap()
{
	UpdateData(TRUE);
	s_nPreFiltCap.SetPos(v_nPreFiltCap);
}

void CPara2::OnChangeEditSadwinsiz()
{
	UpdateData(TRUE);
	s_nSADWinSiz.SetPos((v_nSADWinSiz-1)/2);
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

void CPara2::OnChangeEditLevels()
{
	UpdateData(TRUE);
	s_nLevels.SetPos(v_nLevels);
}

void CPara2::OnChangeEditFi()
{
	UpdateData(TRUE);
	s_nFi.SetPos(int(v_nFi * 10));
}

void CPara2::OnChangeEditLambda()
{
	UpdateData(TRUE);
	s_nLambda.SetPos(int(v_nLambda * 100));
}

void CPara2::OnChangeEditPolyn()
{
	UpdateData(TRUE);
	s_nPolyn.SetPos((v_nPolyN - 1) / 2);
}

void CPara2::OnChangeEditPolysigma()
{
	UpdateData(TRUE);
	s_nPolySigma.SetPos(int(v_nPolySigma * 10));
}

void CPara2::OnChangeEditPyrscale()
{
	UpdateData(TRUE);
	s_nPyrScale.SetPos(int(v_nPyrScale * 10));
}
