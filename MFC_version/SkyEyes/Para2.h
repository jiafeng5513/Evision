 #pragma once
#include "afxcmn.h"


// CPara2 对话框

class CPara2 : public CDialog
{
	DECLARE_DYNAMIC(CPara2)

public:
	static CPara2* getInstance();//取得实例
	virtual ~CPara2();

// 对话框数据
	enum { IDD = IDD_PARA2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CPara2(CWnd* pParent = NULL);   // 标准构造函数
	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl s_nMinDisp;
	CSliderCtrl s_nUniqRatio;
	CSliderCtrl s_nSpeckWinSiz;
	CSliderCtrl s_nMaxDisp;
	CSliderCtrl s_nSpeckRange;
	CSliderCtrl s_nPreFiltCap;
	CSliderCtrl s_nSADWinSiz;
	CSliderCtrl s_nTextThres;
	CSliderCtrl s_nDisp12MaxDiff;
	CSliderCtrl s_nLevels;
	CSliderCtrl s_nPyrScale;
	CSliderCtrl s_nPolyn;
	CSliderCtrl s_nPolySigma;
	CSliderCtrl s_nFi;
	CSliderCtrl s_nLambda;
	int v_nMinDisp; //最小可能的差异值。通常，它是零，但有时校正算法可以转移图像，所以这个参数需要调整。
	int v_nMaxDisp; //最大差距减去最小差距。价值总是大于零。在目前的实现中，此参数必须能被16整除。
	int v_nSADWinSiz;//匹配块大小。它必须是大于等于1的奇数。通常情况下，它应该在3到11之间
	/*Margin in percentage by which the best (minimum) computed cost function value should “win” the second best value to consider the found match correct. 
	通常的最佳值在[5,15]*/
	int v_nUniqRatio; //唯一比
	int v_nSpeckRange;//散斑比
	int v_nTextThres;
	
	int v_nSpeckWinSiz;/*考虑到噪声斑点和无效的光滑的视差地区最大尺寸。设置为0禁用散斑滤波。否则，它设置在50-200范围介于。*/
	/*预滤波图像的截断像素值. 该算法先对每个像素计算X-衍射值,并把这些值限制在[-preFilterCap, preFilterCap]之间
	. 再将结果传送给 Birchfield-Tomasi像素计数函数*/
	int v_nPreFiltCap;//预滤波图像的截断像素值

	int v_nDisp12MaxDiff;//在左右视差检查中允许的最大差值（整数像素单位）。将它设置为非正值，将会禁用该检查。

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	// 给滚动条按照对应变量设置位置
	void SetSlider();
	afx_msg void OnChangeEditMindisp();
	afx_msg void OnChangeEditDisp12maxdiff();
	afx_msg void OnChangeEditMaxdisp();
	afx_msg void OnChangeEditPrefiltcap();
	afx_msg void OnChangeEditSadwinsiz();
	afx_msg void OnChangeEditSpeckrange();
	afx_msg void OnChangeEditSpeckwinsiz();
	afx_msg void OnChangeEditTextthres();
	afx_msg void OnChangeEditUniqratio();
//	afx_msg void OnInitMenu(CMenu* pMenu);
	virtual BOOL OnInitDialog();
	
	// 层次数
	int v_nLevels;
	// 缩放比例
	float v_nPyrScale;
	int v_nPolyN;
	// 高斯标准差
	float v_nPolySigma;
	// 平滑度
	float v_nFi;
	// 边缘平滑
	float v_nLambda;
//	afx_msg void OnEnChangeEditLevels();
	afx_msg void OnChangeEditLevels();
	afx_msg void OnChangeEditFi();
	afx_msg void OnChangeEditLambda();
	afx_msg void OnChangeEditPolyn();
	afx_msg void OnChangeEditPolysigma();
	afx_msg void OnChangeEditPyrscale();
};
static CPara2* CP2_instance;//单件模式