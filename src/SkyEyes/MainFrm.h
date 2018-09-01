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

// MainFrm.h : CMainFrame 类的接口

//

#pragma once
#pragma comment( lib, "vfw32.lib" )  
#pragma comment( lib, "comctl32.lib" )  

#include "OutputWnd.h"
#include "opencv2\core\core.hpp"
#include "afxwin.h"
#include "afxcmn.h"
#include "stdlib.h"
#include <vector>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "afxdialogex.h"
#include "calib.h"
#include "StereoMatch.h"
#include "PointCloudAnalyzer.h"
#include "string.h"
#include "cvaux.h"
#include "cxcore.h"
#include "highgui.h"
#include "cv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "CvvImage.h"
#include "calib.h"
#include <math.h>
#define CalibWnd 541301
#define MatchWnd 541302
#define RangeWnd 541303

//using namespace std;
using namespace cv;
static Point moupoint = 0;
static Point moupoint2 = 0;//这个用来给两点距离的测量做缓存
class CMainFrame : public CFrameWndEx
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	COutputWnd        m_wndOutput;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnViewOutputWindow();
	afx_msg void OnUpdateViewOutputWindow(CCmdUI* pCmdUI);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	DECLARE_MESSAGE_MAP()
	
	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
public:
	/*===============================用户自定义数据类型============================*/
	   // 匹配算法枚举
	typedef enum { STEREO_BM, STEREO_SGBM, STEREO_VAR} STEREO_METHOD;
	   // 帧处理算法枚举
	typedef enum { SHOW_ORIGINAL_FRAME, SHOW_EDGE_IMAGE, SHOW_EQUAL_HISTOGRAM, SHOW_CONVERT_COLOR } FRAME_PROCESS_METHOD;
	   // 测距模式枚举
	typedef enum { GetDepth, GetLength } RANGING_MODEL;
	   // 相机标定设置结构体
	struct OptionCameraCalib
	{
		int				numberBoards;		   //棋盘检测次数
		int				flagStereoCalib;	   //双目定标标志符
		int				numberFrameSkip;	   //角点检测的帧间间隔数
		double   		squareSize;			   //棋盘方块大小
		cv::Size		cornerSize;			   //棋盘角点数
		double          alpha;                 //双目校正缩放系数
		calib::RECTIFYMETHOD	rectifyMethod; //选择的双目校正算法
	};
private:
	// OpenCV成员
	cv::Mat m_lfImage;                          // 用于左视图的显示
	cv::Mat m_riImage;                          // 用于右视图的显示
	cv::Mat m_disparity;                        // 用于视差图的显示
    cv::Mat OriginalDisparity;                  // 原始差数据        (使用:本类:OnBngivedisp();OnBnCompdisp())
	cv::Mat ProcessedImageL, ProcessedImageR;   // 处理过后的左右视图(使用:本类:OnBngivedisp() OnBnCompdisp())
	cv::Mat DisparityMap;                       // 视差图            (使用;本类:OnBngivedisp();OnBnCompdisp();OnBnMouseon())
	cv::Mat DisparityMap2;                      // 视差图副本,用于在测量两点距离的时候进行叠绘            (使用;本类:)
	cv::Mat pointCloud;                         // 三维点云          (使用:本类:OnBnMouseon();OnBnCompdisp())
	cv::Mat TargetImageL, TargetImageR;         // 全局变量: 待测目标图像      (使用:本类:OnBngivedisp(); RefreshDispMap())
	cv::Mat depth;                              // 全局变量: 以图像世界二维坐标为索引的深度信息 (使用:本类:
	// 简单数据成员
	CString WorkPath;                           // 工作路径
	UINT m_nID_RAD;                             // 色彩空间变换方法
	int m_ProcMethod;                           // 帧处理算法
	int m_nCamCount;                            // 摄像头数目
	int m_lfCamID;                              // 左镜头ID
	int m_riCamID;                              // 右镜头ID
	int m_nImageWidth;                          // 相机分辨率:宽
	int m_nImageHeight;                         // 相机分辨率:高
	int m_nImageChannels;                       // 相机通道数
	double m_ObjectDistance;                    // 目标距离
	bool BOUGUET=true;                          // 是否使用BOUGUET标定算法?  true=BOUGUET; false=Hartley
	bool BM=true;                               // 是否使用BM匹配算法?       true=BM;      false=SGBM    
	bool VAR;                                   // 是否使用VAR求解器?        true=使用;    false=不使用
	bool CalibDefaultParamEnable = false;       // 是否启用 标定->默认参数
	bool CalibDeleteParamEnable = false;        // 是否启用 标定->清除参数        
	bool CalibFromImage = false;                // 是否启用 标定->从图片标定
	bool CalibFromCamera = false;               // 是否启用 标定->从相机标定
	bool CalibFromFile = false;                 // 是否启用 标定->从文件标定
	bool StopCalibFromCamera = false;           // 是否启用 标定->停止从镜头标定
	bool MatchDefaultParamEnable = false;       // 是否启用 匹配->默认参数
	bool MatchDeleteParamEnable = false;        // 是否启用 匹配->清除参数
	bool MatchBngivedispEnable = false;         // 是否启用 匹配->生成视差图
	bool MatchDeepRebuildEnable = false;        // 是否启用 匹配->深度重建
	bool DoRefreshDisparityMapEnable = false;   // 是否启用 匹配->刷新视差图
	bool RangeEnable = false;                   // 是否启用 测距相关功能
	bool FileSelected = false;                  // 是否选择了匹配所需的文件
	bool IsSecondPoint = true;                 // 是不是第二个点
	STEREO_METHOD stereoMethod;		        // 选择的立体匹配算法
	RANGING_MODEL rangingModel;
	// 对象成员
	VideoCapture lfCam;                         //左镜头对象
	VideoCapture riCam;                         //右镜头对象
	calib m_stereoCalibrator;                   //
	StereoMatch m_stereoMatcher;
	calib::CornerDatas cornerDatas;
	calib::StereoParams stereoParams;
	calib::RemapMatrixs remapMatrixs;
	CMainFrame::OptionCameraCalib optCalib;
	
private:
	/*===================================本类的工具方法==================================*/
	// 清除立体匹配的参数
	void DoClearParamsOfStereoMatch();
	// 文件选择器对话框
	vector<CStringA> DoSelectFiles(LPCTSTR lpszDefExt, DWORD dwFlags, LPCTSTR lpszFilter, LPCTSTR lpstrTitle, LPCTSTR lpstrInitialDir);
	// 处理图片的显示
	void F_ShowImage(Mat& src, Mat& des, UINT ID);
	// 向输出窗口的指定位置输出指定文本信息,
	void PutMessage(int wndID, LPCTSTR message);
	// 保存图片之前的调整操作,唯一一个调用点已经被注释
	void FixDisp(Mat_<float> & disp, int numofdisp);
	// 鼠标定点函数
	static void On_Mouse(int event, int x, int y, int flags, void *);
	// 刷新摄像头
	void RefalshCamera();
	// 显示摄像头实时画面
	void DoShowOrigFrame();
	// 执行帧处理
	void DoFrameProc(Mat& src, Mat& dst);
	// Canny边缘检测
	void F_EdgeDetectCanny(Mat& src, Mat& des);
	// 确认摄像机定标的相关选项
	bool DoParseOptionsOfCameraCalib(OptionCameraCalib& opt);
	// 视差图刷新的执行函数
	void RefreshDisparityMap();
	// 给匹配求解器设置启动参数
	void SetSolver(int imgChannels);
public:
	/*================================自定义消息的回调函数===============================*/
	afx_msg LRESULT OnUserInitializable(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserChangeDPI(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserChangeFrameProcMethod(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserCPara4ChangeCameraL(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserCPara4ChangeCameraR(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserChangedpi(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRefreshDisparityMap(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnXYZAnalyse(WPARAM wParam, LPARAM lParam);
	/*===============================以下是界面事件处理程序==============================*/
	afx_msg void OnBnDefaultcamcalibparam();
	afx_msg void OnBndetectag();
	afx_msg void OnBn2stereocalib();
	afx_msg void OnBnStereodefparam();
	afx_msg void OnBngivedisp();
	afx_msg void OnBnCompdisp();
	afx_msg void OnRadBm();
	afx_msg void OnRadSgbm();
	afx_msg void OnBnMouseon();
	afx_msg void OnUpdateRadCalibfromimg(CCmdUI *pCmdUI);
	afx_msg void OnRadCalibfromimg();
	afx_msg void OnRadBouguet();
	afx_msg void OnUpdateRadBouguet(CCmdUI *pCmdUI);
	afx_msg void OnRadHartley();
	afx_msg void OnUpdateRadHartley(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRadBm(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRadSgbm(CCmdUI *pCmdUI);
	afx_msg void OnNewproject();
	afx_msg void OnOpenproject();
	afx_msg void OnOpenpath();
	afx_msg void OnHelpdoc();
	afx_msg void OnUpdateBnDefaultcamcalibparam(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBnDeletecamcalibparam(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBndetectag(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBn2stereocalib(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBnStereodefparam(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBnStereodeleteparam(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBngivedisp(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBnCompdisp(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBnMouseon(CCmdUI *pCmdUI);
	afx_msg void OnCloseproject();
	afx_msg void OnPaint();
	afx_msg void OnRefreshcam();
	afx_msg void OnBn1runcam();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBn2stopcam();
	afx_msg void OnTestcalib();
	afx_msg void OnStopcalib();
	afx_msg void OnChkCalculate();
	afx_msg void OnPhotograph();
	afx_msg void OnCalibfromyml();
	afx_msg void OnUpdateTestcalib(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCalibfromyml(CCmdUI *pCmdUI);
	afx_msg void OnUpdateStopcalib(CCmdUI *pCmdUI);
	afx_msg void OnBnDeletecamcalibparam();
	afx_msg void OnBnStereodeleteparam();
	afx_msg void OnCheck2();
	afx_msg void OnUpdateCheck2(CCmdUI *pCmdUI);
	afx_msg void OnChkGc();
	afx_msg void OnUpdateChkGc(CCmdUI *pCmdUI);
	afx_msg void OnDorefreshdisparitymap();
	afx_msg void OnUpdateDorefreshdisparitymap(CCmdUI *pCmdUI);
	afx_msg void OnChkGetdepth();
	afx_msg void OnUpdateChkGetdepth(CCmdUI *pCmdUI);
	afx_msg void OnChkGetlength();
	afx_msg void OnUpdateChkGetlength(CCmdUI *pCmdUI);
};

