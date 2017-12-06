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

// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "SkyEyes.h"
#include "SkyEyesView.h"
#include "MainFrm.h"
#include "NewProject.h"
//#include "CameraDS.h"
#include "DirectShowHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_VIEW_OUTPUTWND, &CMainFrame::OnViewOutputWindow)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OUTPUTWND, &CMainFrame::OnUpdateViewOutputWindow)
	ON_WM_SETTINGCHANGE()
	ON_COMMAND(IDC_BN_DefaultCamCalibParam, &CMainFrame::OnBnDefaultcamcalibparam)
	ON_COMMAND(IDC_BNDETECTAG, &CMainFrame::OnBndetectag)
	ON_COMMAND(IDC_BN_StereoDefParam, &CMainFrame::OnBnStereodefparam)
	ON_COMMAND(IDC_BNGIVEDISP, &CMainFrame::OnBngivedisp)
	ON_COMMAND(IDC_BN_CompDisp, &CMainFrame::OnBnCompdisp)
	ON_COMMAND(IDC_RAD_BM, &CMainFrame::OnRadBm)
	ON_COMMAND(IDC_RAD_SGBM, &CMainFrame::OnRadSgbm)
	ON_COMMAND(IDC_BN_MOUSEON, &CMainFrame::OnBnMouseon)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDC_RAD_BOUGUET, &CMainFrame::OnRadBouguet)
	ON_UPDATE_COMMAND_UI(IDC_RAD_BOUGUET, &CMainFrame::OnUpdateRadBouguet)
	ON_COMMAND(IDC_RAD_HARTLEY, &CMainFrame::OnRadHartley)
	ON_UPDATE_COMMAND_UI(IDC_RAD_HARTLEY, &CMainFrame::OnUpdateRadHartley)
	ON_UPDATE_COMMAND_UI(IDC_RAD_BM, &CMainFrame::OnUpdateRadBm)
	ON_UPDATE_COMMAND_UI(IDC_RAD_SGBM, &CMainFrame::OnUpdateRadSgbm)
	ON_COMMAND(ID_NewProject, &CMainFrame::OnNewproject)
	ON_COMMAND(ID_OpenProject, &CMainFrame::OnOpenproject)
	ON_COMMAND(ID_OpenPath, &CMainFrame::OnOpenpath)
	ON_COMMAND(ID_HelpDoc, &CMainFrame::OnHelpdoc)
	ON_UPDATE_COMMAND_UI(IDC_BN_DefaultCamCalibParam, &CMainFrame::OnUpdateBnDefaultcamcalibparam)
	ON_UPDATE_COMMAND_UI(IDC_BN_DeleteCamCalibParam, &CMainFrame::OnUpdateBnDeletecamcalibparam)
	ON_UPDATE_COMMAND_UI(IDC_BNDETECTAG, &CMainFrame::OnUpdateBndetectag)
	ON_UPDATE_COMMAND_UI(IDC_BN_StereoDefParam, &CMainFrame::OnUpdateBnStereodefparam)
	ON_UPDATE_COMMAND_UI(IDC_BN_StereoDeleteParam, &CMainFrame::OnUpdateBnStereodeleteparam)
	ON_UPDATE_COMMAND_UI(IDC_BNGIVEDISP, &CMainFrame::OnUpdateBngivedisp)
	ON_UPDATE_COMMAND_UI(IDC_BN_CompDisp, &CMainFrame::OnUpdateBnCompdisp)
	ON_UPDATE_COMMAND_UI(IDC_BN_MOUSEON, &CMainFrame::OnUpdateBnMouseon)
	ON_COMMAND(ID_CloseProject, &CMainFrame::OnCloseproject)
	ON_WM_PAINT()
	ON_MESSAGE(WM_USER_Initializable, &CMainFrame::OnUserInitializable)
	ON_COMMAND(ID_RefreshCam, &CMainFrame::OnRefreshcam)
	ON_MESSAGE(WM_USER_ChangeDPI, &CMainFrame::OnUserChangeDPI)
	ON_COMMAND(IDC_BN1RunCam, &CMainFrame::OnBn1runcam)
	ON_MESSAGE(WM_USER_CPara4ChangeCameraL, &CMainFrame::OnUserCPara4ChangeCameraL)
	ON_MESSAGE(WM_USER_CPara4ChangeCameraR, &CMainFrame::OnUserCPara4ChangeCameraR)
	ON_MESSAGE(WM_USER_ChangeFrameProcMethod, &CMainFrame::OnUserChangeFrameProcMethod)
	ON_WM_TIMER()
	ON_COMMAND(IDC_BN2StopCam, &CMainFrame::OnBn2stopcam)
	ON_COMMAND(ID_TESTCALIB, &CMainFrame::OnTestcalib)
	ON_COMMAND(ID_STOPCALIB, &CMainFrame::OnStopcalib)
	ON_COMMAND(ID_Photograph, &CMainFrame::OnPhotograph)
	ON_COMMAND(ID_CalibFromYML, &CMainFrame::OnCalibfromyml)
	ON_UPDATE_COMMAND_UI(ID_TESTCALIB, &CMainFrame::OnUpdateTestcalib)
	ON_UPDATE_COMMAND_UI(ID_CalibFromYML, &CMainFrame::OnUpdateCalibfromyml)
	ON_UPDATE_COMMAND_UI(ID_STOPCALIB, &CMainFrame::OnUpdateStopcalib)
	ON_COMMAND(IDC_BN_DeleteCamCalibParam, &CMainFrame::OnBnDeletecamcalibparam)
	ON_COMMAND(IDC_BN_StereoDeleteParam, &CMainFrame::OnBnStereodeleteparam)
	ON_COMMAND(ID_CHECK2, &CMainFrame::OnCheck2)
	ON_UPDATE_COMMAND_UI(ID_CHECK2, &CMainFrame::OnUpdateCheck2)
	ON_MESSAGE(WM_USER_RefreshDisparityMap, &CMainFrame::OnRefreshDisparityMap)
	ON_COMMAND(ID_DoRefreshDisparityMap, &CMainFrame::OnDorefreshdisparitymap)
	ON_UPDATE_COMMAND_UI(ID_DoRefreshDisparityMap, &CMainFrame::OnUpdateDorefreshdisparitymap)
	ON_COMMAND(ID_CHK_GetDepth, &CMainFrame::OnChkGetdepth)
	ON_UPDATE_COMMAND_UI(ID_CHK_GetDepth, &CMainFrame::OnUpdateChkGetdepth)
	ON_COMMAND(ID_CHK_GetLength, &CMainFrame::OnChkGetlength)
	ON_UPDATE_COMMAND_UI(ID_CHK_GetLength, &CMainFrame::OnUpdateChkGetlength)
	ON_MESSAGE(WM_USER_XYZAnalyse, &CMainFrame::OnXYZAnalyse)
END_MESSAGE_MAP()

// CMainFrame 构造/析构WM_USER_XYZAnalyse

CMainFrame::CMainFrame()
: m_ProcMethod(0)
, m_nImageWidth(0)
, m_nImageHeight(0)
, BOUGUET(false)
, BM(false)
, m_nCamCount(0)
, m_lfCamID(0)
, m_riCamID(0)
, VAR(false)
{
	// TODO:  在此添加成员初始化代码
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_OFF_2007_BLACK);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	m_wndRibbonBar.Create(this);
	m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);

	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);
	//EnableLoadDockState(FALSE);//禁止程序记忆界面状态
	// 创建停靠窗口
	if (!CreateDockingWindows())
	{
		TRACE0("未能创建停靠窗口\n");
		return -1;
	}

	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndOutput);
	m_wndOutput.SetControlBarStyle(~AFX_CBRS_CLOSE);//禁止用户关闭输出窗口
	//m_wndOutput.SetControlBarStyle(AFX_CBRS_RESIZE);//禁止用户对输出窗口执行拆分命令
	// 基于持久值设置视觉管理器和样式
	OnApplicationLook(theApp.m_nAppLook);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return TRUE;
}

BOOL CMainFrame::CreateDockingWindows()
{
	BOOL bNameValid;
	// 创建输出窗口
	CString strOutputWnd;
	bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
	ASSERT(bNameValid);
	if (!m_wndOutput.Create(strOutputWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		TRACE0("未能创建输出窗口\n");
		return FALSE; // 未能创建
	}

	SetDockingWindowIcons(theApp.m_bHiColorIcons);
	return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
	HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(TRUE);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
	}

	m_wndOutput.UpdateFonts();
	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}

void CMainFrame::OnViewOutputWindow()
{
	// 显示或激活窗格，具体取决于当前状态。
	// 只能通过窗格帧上的 [x] 按钮关闭窗格。
	m_wndOutput.ShowPane(TRUE, FALSE, TRUE);
	m_wndOutput.SetFocus();
}

void CMainFrame::OnUpdateViewOutputWindow(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CFrameWndEx::OnSettingChange(uFlags, lpszSection);
	m_wndOutput.UpdateFonts();
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWndEx::OnPaint()
	//OnPaint();
	UpdateWindow();				// 更新windows窗口，如果无这步调用，图片显示还会出现问题
	if (!m_lfImage.empty() || m_riImage.empty() || !m_disparity.empty())
	{
		F_ShowImage(m_lfImage, m_lfImage, IDC_PicLfCam);		// 重绘图片函数
		F_ShowImage(m_riImage, m_riImage, IDC_PicRiCam);		// 重绘图片函数
		F_ShowImage(m_disparity, m_disparity, IDC_PicSynImg);	// 重绘图片函数
	}
	/*注意:由于程序中对绘图区域的初始化需要执行"新建工程"或者"打开工程",所以界面刚刚加载完的时候,并不会调用这个IF语句块,
	所以图区域并不是黑色的.*/
}

/*======================================================================================*/
/*                        以下是一组响应自定义消息的监听器                              */
/*======================================================================================*/

//响应自定义消息,该消息从SkyEyes.cpp(APP类)中发出,收到此消息,即可进行初始化操作
afx_msg LRESULT CMainFrame::OnUserInitializable(WPARAM wParam, LPARAM lParam)
{
	//收到此消息表明界面已经完成加载,可以进行用户定义的初始化操作了
	//1.初始化图像显示控件和相关变量
	CRect rect;
	this->GetActiveView()->GetDlgItem(IDC_PicLfCam)->GetClientRect(&rect);
	m_lfImage = Mat::zeros(rect.Height(), rect.Width(), CV_8UC3);
	this->GetActiveView()->GetDlgItem(IDC_PicRiCam)->GetClientRect(&rect);
	m_riImage = Mat::zeros(rect.Height(), rect.Width(), CV_8UC3);
	this->GetActiveView()->GetDlgItem(IDC_PicSynImg)->GetClientRect(&rect);
	m_disparity = Mat::zeros(rect.Height(), rect.Width(), CV_8UC3);
	Invalidate();//刷新窗口
	UpdateWindow();
	//2.获取摄像头数目和代号
	RefalshCamera();
	//3.填写帧处理方法 显示原始画面;Canny边缘检测;直方图均衡;色彩空间变换;
	CPara4::getInstance()->m_CP4MethodList.SetCurSel(0);
	return 0;
}

//接收到更改DPI的消息,本消息由CPara1/4发出,由本类捕获,分类并处理
afx_msg LRESULT CMainFrame::OnUserChangeDPI(WPARAM wParam, LPARAM lParam)
{
	int index =0;
	//判断消息来源,做对称操作
	if (wParam == 1){
		index = CPara1::getInstance()->m_CP1Resolution.GetCurSel();//从1取值
		CPara4::getInstance()->m_CP4Resolution.SetCurSel(index);//给4赋值
	}
	if (wParam == 4){
		index = CPara4::getInstance()->m_CP4Resolution.GetCurSel();//从4取值
		CPara1::getInstance()->m_CP1Resolution.SetCurSel(index);//给1赋值
	}
	switch (index)
	{
	case 0:
		m_nImageWidth = 640;
		m_nImageHeight = 480;
		break;
	case 1:
		m_nImageWidth = 352;
		m_nImageHeight = 288;
		break;
	case 2:
		m_nImageWidth = 320;
		m_nImageHeight = 240;
		break;
	default:
		m_nImageWidth = 352;
		m_nImageHeight = 288;
	}
	m_nImageChannels = 3;
	return 0;
}

//接收到更改帧处理方法的消息,本消息由CPara4发出,由本类捕获并处理
afx_msg LRESULT CMainFrame::OnUserChangeFrameProcMethod(WPARAM wParam, LPARAM lParam)
{
	m_ProcMethod = CPara4::getInstance()->m_CP4MethodList.GetCurSel();
	return 0;
}

//接收到更改左摄像头的消息,本消息由CPara1/4发出,由本类捕获,分类并处理
afx_msg LRESULT CMainFrame::OnUserCPara4ChangeCameraL(WPARAM wParam, LPARAM lParam)
{
	// 确定左右摄像头对应的设备序号（对应下拉菜单选择项的序号）
	//判断消息来源,做对称操作
	if (wParam == 1){
		m_lfCamID = CPara1::getInstance()->m_CP1CamList_L.GetCurSel();//从1取值
		CPara4::getInstance()->m_CP4CamList_L.SetCurSel(m_lfCamID);//给4赋值
	}
	if (wParam == 4){
		m_lfCamID = CPara4::getInstance()->m_CP4CamList_L.GetCurSel();//从4取值
		CPara1::getInstance()->m_CP1CamList_L.SetCurSel(m_lfCamID);//给1赋值
	}
	return 0;
}

//接收到更改右摄像头的消息,本消息由CPara1/4发出,由本类捕获,分类并处理
afx_msg LRESULT CMainFrame::OnUserCPara4ChangeCameraR(WPARAM wParam, LPARAM lParam)
{
	//判断消息来源,做对称操作
	if (wParam == 1){
		m_riCamID = CPara1::getInstance()->m_CP1CamList_R.GetCurSel();//从1取值
		CPara4::getInstance()->m_CP4CamList_R.SetCurSel(m_riCamID);//给4赋值
	}
	if (wParam == 4){
		m_riCamID = CPara4::getInstance()->m_CP4CamList_R.GetCurSel();//从4取值
		CPara1::getInstance()->m_CP1CamList_R.SetCurSel(m_riCamID);//给1赋值
	}
	return 0;
}

//接收到刷新视差图的消息,本消息由CPara2发出,由本类捕获,分类并处理
afx_msg LRESULT CMainFrame::OnRefreshDisparityMap(WPARAM wParam, LPARAM lParam)
{
	if (FileSelected == true){
		DoRefreshDisparityMapEnable = true;//只有选择完文件才能启用刷新功能
		if (stereoMethod == STEREO_VAR){   //如果使用的是VAR算法,可以进行实时刷新而不需要手动点击
			RefreshDisparityMap();
		}
		
	}
	return 0;
}



/*======================================================================================*/
/*                                以下是本类的工具方法定义                              */
/*======================================================================================*/

// 刷新摄像头
void CMainFrame::RefalshCamera()
{
	DirectShowHelper dsHelper;
	std::vector<std::wstring> devices;
	dsHelper.enumerateDevices(CLSID_VideoInputDeviceCategory, devices);

	m_nCamCount = devices.size();
	if (m_nCamCount < 1)
	{
		AfxMessageBox(_T("未检测到摄像头!相关功能将无法使用!"));
		//return -1;
	}

	// 在组合框CamList中添加摄像头名称的字符串
	//char camera_name[1024];
	//char istr[1024];
	//CString camstr;
	CPara1::getInstance()->m_CP1CamList_R.EnableWindow(TRUE);
	CPara1::getInstance()->m_CP1CamList_L.ResetContent();
	CPara1::getInstance()->m_CP1CamList_R.ResetContent();
	CPara4::getInstance()->m_CP4CamList_R.EnableWindow(TRUE);
	CPara4::getInstance()->m_CP4CamList_L.ResetContent();
	CPara4::getInstance()->m_CP4CamList_R.ResetContent();
	for (int i = 0; i < m_nCamCount; i++)
	{
		//int retval = CCameraDS::CameraName(i, camera_name, sizeof(camera_name));

		//sprintf_s(istr, "#%d ", i);
		//strcat_s(istr, camera_name);
		//camstr = istr;
		if (devices[i].empty()==false)
		{
			CPara1::getInstance()->m_CP1CamList_L.AddString(CString(devices[i].c_str()));
			CPara1::getInstance()->m_CP1CamList_R.AddString(CString(devices[i].c_str()));
			CPara4::getInstance()->m_CP4CamList_L.AddString(CString(devices[i].c_str()));
			CPara4::getInstance()->m_CP4CamList_R.AddString(CString(devices[i].c_str()));
		}
		else
			AfxMessageBox(_T("不能获取摄像头的名称"));
	}
	//camstr.ReleaseBuffer();
	if (m_nCamCount <= 1)
	{
		CPara1::getInstance()->m_CP1CamList_R.EnableWindow(FALSE);
		CPara4::getInstance()->m_CP4CamList_R.EnableWindow(FALSE);
	}
		
}



// 这个函数现在已经不用了....已经没有调用点了
void CMainFrame::FixDisp(Mat_<float> & disp, int numofdisp)
{
	/*
	Mat_<float> disp1;
	float lastPixel = 10;
	int minDisparity = 23;
	//	disp.at<float>(0,144) = lastPixel;
	for (int i = 0; i < disp.rows; i++)
	{
		for (int j = numofdisp; j < disp.cols; j++)
		{
			if (disp(i, j) <= minDisparity) disp(i, j) = lastPixel;
			else lastPixel = disp(i, j);
		}
	}
	int an = 4;
	copyMakeBorder(disp, disp1, an, an, an, an, BORDER_REPLICATE);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(an * 2 + 1, an * 2 + 1));
	morphologyEx(disp1, disp1, CV_MOP_OPEN, element);
	morphologyEx(disp1, disp1, CV_MOP_CLOSE, element);
	disp = disp1(Range(an, disp.rows - an), Range(an, disp.cols - an)).clone();
	*/
}

// 显示摄像头实时画面
void CMainFrame::DoShowOrigFrame()
{
	// 对图像数据清零
	m_lfImage = Scalar(0);
	F_ShowImage(m_lfImage, m_lfImage, IDC_PicLfCam);

	m_riImage = Scalar(0);
	F_ShowImage(m_riImage, m_riImage, IDC_PicRiCam);

	CPara4::getInstance()->m_CP4MethodList.SetCurSel(0);
	m_ProcMethod = SHOW_ORIGINAL_FRAME;
	SetTimer(1, 50, NULL);	// 50ms 定时显示
}

// 定时器响应主要用于没有双目定标或双目匹配操作时的其它显示和处理操作
void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (lfCam.isOpened())
	{
		Mat lfFrame;
		lfCam >> lfFrame;

		if (m_ProcMethod != SHOW_ORIGINAL_FRAME)
		{
			DoFrameProc(lfFrame, lfFrame);
		}

		F_ShowImage(lfFrame, m_lfImage, IDC_PicLfCam);
	}
	if (riCam.isOpened())
	{
		Mat riFrame;
		riCam >> riFrame;

		if (m_ProcMethod != SHOW_ORIGINAL_FRAME)
		{
			DoFrameProc(riFrame, riFrame);
		}

		F_ShowImage(riFrame, m_riImage, IDC_PicRiCam);
	}
	CFrameWndEx::OnTimer(nIDEvent);
}

// 执行帧处理
void CMainFrame::DoFrameProc(Mat& src, Mat& dst)
{
	try
	{
		switch (m_ProcMethod)
		{
		case SHOW_EDGE_IMAGE:
		{
								F_EdgeDetectCanny(src, dst);
		}
			break;
		case SHOW_EQUAL_HISTOGRAM:
		{
									 vector<Mat> rgb;
									 // 分解各个分量
									 split(src, rgb);
									 // 对各个分量依次进行直方图均衡
									 for (int i = 0; i<3; i++)
									 {
										 equalizeHist(rgb[i], rgb[i]);
									 }
									 // 合并各分量
									 merge(rgb, dst);
		}
			break;
		case SHOW_CONVERT_COLOR:
		{
								   m_nID_RAD = CPara4::getInstance()->GetCheckedRadioButton(IDC_RAD_ToHSV, IDC_RAD_ToXYZ);
								   int type =
									   m_nID_RAD == IDC_RAD_ToHSV ? CV_BGR2HSV :
									   m_nID_RAD == IDC_RAD_ToHLS ? CV_BGR2HLS :
									   m_nID_RAD == IDC_RAD_ToLab ? CV_BGR2Lab :
									   m_nID_RAD == IDC_RAD_ToLuv ? CV_BGR2Luv :
									   m_nID_RAD == IDC_RAD_ToYCrCb ? CV_BGR2YCrCb :
									   CV_BGR2XYZ;
								   cvtColor(src, dst, type);
		}
			break;
		}
	}
	catch (cv::Exception& e)
	{
		char err[2048];
		sprintf_s(err, "发生错误: %s", e.what());
		CString errInfo;
		errInfo = err;
		AfxMessageBox(errInfo);
	}
	catch (...)
	{
		AfxMessageBox(_T("发生未知错误！"));
	}

	return;
}

// Canny边缘检测
void CMainFrame::F_EdgeDetectCanny(Mat& src, Mat& des)
{
	Mat gray, edge, edge8u;

	edge = cv::Mat(src.size(), CV_16S);

	// 将源图像转为灰度图像
	if (src.channels() == 1)
		src.copyTo(gray);
	else
		cvtColor(src, gray, CV_RGB2GRAY);

	// 边缘检测
	Sobel(gray, edge, CV_16S, 0, 1);
	edge.convertTo(edge8u, CV_8U);

	// 将边缘检测图像转至输出图像格式
	if (des.channels() == 1)
		edge8u.copyTo(des);
	else
		cvtColor(edge8u, des, CV_GRAY2BGR);
}

// 确认摄像机定标的相关选项
bool CMainFrame::DoParseOptionsOfCameraCalib(OptionCameraCalib& opt)
{
	//1.读入标定盘参数设定
	CString temp;
	(CPara1::getInstance()->GetDlgItem(IDC_BoardWidth)->GetWindowText(temp));//角点-X
	if (atoi(temp) <= 0){
		return false;
	}
	opt.cornerSize.width = atoi(temp);
	(CPara1::getInstance()->GetDlgItem(IDC_BoardHeight)->GetWindowText(temp));//角点-Y
	if (atoi(temp) <= 0){
		return false;
	}
	opt.cornerSize.height = atoi(temp);
	(CPara1::getInstance()->GetDlgItem(IDC_SquareSize)->GetWindowText(temp));//方格尺寸
	if (atoi(temp) <= 0){
		return false;
	}
	opt.squareSize = atof(temp);
	(CPara1::getInstance()->GetDlgItem(IDC_nBoards)->GetWindowText(temp));   //迭代次数
	if (atoi(temp) <= 0){
		return false;
	}
	opt.numberBoards = atoi(temp);

	//2.读入标志位设定
	UINT nCheckIDs[5] = { IDC_CHK_FPP, IDC_CHK_UIG, IDC_CHK_FAR, IDC_CHK_SFL, IDC_CHK_FI };
	int nFlagDefs2[5] = { CV_CALIB_FIX_PRINCIPAL_POINT, CV_CALIB_USE_INTRINSIC_GUESS,
		CV_CALIB_FIX_ASPECT_RATIO, CV_CALIB_SAME_FOCAL_LENGTH, CV_CALIB_FIX_INTRINSIC };
	for (int i = 0; i<5; i++)
	{
		if (((CButton*)CPara1::getInstance()->GetDlgItem(nCheckIDs[i]))->GetCheck())
			opt.flagStereoCalib |= nFlagDefs2[i];
	}

	//3.角点检测的帧间间隔数(从相机标定时此值为30)
	opt.numberFrameSkip = 30;

	//4.确认左右视图的来源（摄像头 or 本地图片）
	//opt.readLocalImage = LocalPicture;
	//if (opt.readLocalImage)		// 若从本地图片读入，则跳帧数减少为 5 帧
		//opt.numberFrameSkip = 5;

	//5.确认棋盘角点坐标数据的获取方式是现场计算还是从YML文件中读取
	//opt.loadConerDatas = ReadYML;

	//6.确定双目校正缩放系数
	(CPara1::getInstance()->GetDlgItem(IDC_Alpha)->GetWindowText(temp));   //Alpha
	opt.alpha = atof(temp);
	if (opt.alpha < 0 || opt.alpha > 1)//如果alpha越界使用-1为默认值
		opt.alpha = -1;

	//7.确认双目校正算法
	opt.rectifyMethod = (BOUGUET == true ? calib::RECTIFY_BOUGUET : calib::RECTIFY_HARTLEY);

	return true;
}

// 给匹配求解器设置启动参数
void CMainFrame::SetSolver(int imgChannels)
{
	//给相应的求解器设置启动参数,同时检查参数的正确性
	CString temp;
	switch (stereoMethod)
	{
	case STEREO_BM:
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_preFiltCap))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->preFilterCap = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_SADWinSiz))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->SADWindowSize = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->minDisparity = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->numberOfDisparities = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_textThres))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->textureThreshold = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_uniqRatio))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->uniquenessRatio = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckWinSiz))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->speckleWindowSize = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckRange))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->speckleRange = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_disp12MaxDiff))->GetWindowText(temp);
		m_stereoMatcher.m_BM.state->disp12MaxDiff = atoi(temp);

		//	m_stereoMatcher.m_BM.state->preFilterSize=41;
		break;
	case STEREO_SGBM:
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_preFiltCap))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.preFilterCap = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_SADWinSiz))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.SADWindowSize = atoi(temp);
		m_stereoMatcher.m_SGBM.P1 = 48 * imgChannels * atoi(temp) * atoi(temp);//48??????!!!!!!?!?!?!?!!?!??
		m_stereoMatcher.m_SGBM.P2 = 48 * imgChannels * atoi(temp) * atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.minDisparity = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.numberOfDisparities = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_uniqRatio))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.uniquenessRatio = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckWinSiz))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.speckleWindowSize = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckRange))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.speckleRange = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_disp12MaxDiff))->GetWindowText(temp);
		m_stereoMatcher.m_SGBM.disp12MaxDiff = atoi(temp);
		m_stereoMatcher.m_SGBM.fullDP = true;
		break;
	case STEREO_VAR:
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.minDisp = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.maxDisp = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Levels))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.levels = atoi(temp);// 如果设置USE_AUTO_PARAMS,算法将会自动设置该值
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PyrScale))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.pyrScale = atof(temp);// 如果设置USE_AUTO_PARAMS,算法将会自动设置该值
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PolyN))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.poly_n = atoi(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PolySigma))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.poly_sigma = atof(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Fi))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.fi = atof(temp);
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Lambda))->GetWindowText(temp);
		m_stereoMatcher.m_VAR.lambda = atof(temp);//如果设置PENALIZATION_CHARBONNIER or PENALIZATION_PERONA_MALIK,将会忽略该参数
		break;
	default:
		break;
	}
}

// 视差图刷新的执行函数
void CMainFrame::RefreshDisparityMap()
{
	int imgChannels = TargetImageL.channels();
	SetSolver(imgChannels);//识别所采用的匹配算法并对求解器进行初始化
	bool MatchSucceed = false;
	switch (stereoMethod)//求解视差
	{
	case STEREO_BM://使用BM求解器
		MatchSucceed = m_stereoMatcher.bmMatch(TargetImageL, TargetImageR, OriginalDisparity, ProcessedImageL, ProcessedImageR);
		break;
	case STEREO_SGBM://使用SGBM求解器
		MatchSucceed = m_stereoMatcher.sgbmMatch(TargetImageL, TargetImageR, OriginalDisparity, ProcessedImageL, ProcessedImageR);
		break;
	case STEREO_VAR://使用VAR求解器
		MatchSucceed = m_stereoMatcher.varMatch(TargetImageL, TargetImageR, OriginalDisparity, ProcessedImageL, ProcessedImageR);
		break;
	default:
		return;
	}
	if (MatchSucceed == false)//求解失败
	{
		return;
	}
	for (int j = 0; j < ProcessedImageL.rows; j += 32)//画平行线
	{
		line(ProcessedImageL, cvPoint(0, j), cvPoint(ProcessedImageL.cols, j), CV_RGB(0, 255, 0));
		line(ProcessedImageR, cvPoint(0, j), cvPoint(ProcessedImageR.cols, j), CV_RGB(0, 255, 0));
	}
	m_stereoMatcher.getDisparityImage(OriginalDisparity, DisparityMap, true);//得到伪彩
	//图像显示
	F_ShowImage(ProcessedImageL, m_lfImage, IDC_PicLfCam);
	F_ShowImage(ProcessedImageR, m_riImage, IDC_PicRiCam);
	F_ShowImage(DisparityMap, m_disparity, IDC_PicSynImg);
	MatchDeepRebuildEnable = true;      // 启用匹配->深度重建
	DoRefreshDisparityMapEnable = false;//刷新完,禁用刷新按钮
}


/*----------------------------------------------
* 功能 : 向输出窗口的指定标签页输出指定文本信息,
*-----------------------------------------------
* 函数 : CMainFrame::PutMessage
* 访问 : public
* 返回 : void
*
* 参数 : wndID  			[in]	输出位置
* 参数 : message			[in]	输出内容
*/
void CMainFrame::PutMessage(int wndID, LPCTSTR message)
{
	//LPCTSTR,使用_T(String)强制转换得到
	switch (wndID)
	{
	case CalibWnd:
		m_wndOutput.m_wndOutputCalib.AddString(message);
		break;
	case MatchWnd:
		m_wndOutput.m_wndOutputMatch.AddString(message);
		break;
	case RangeWnd:
		m_wndOutput.m_wndOutputRange.AddString(message);
		break;
	default:
		m_wndOutput.m_wndOutputCalib.AddString(_T("输出定向有误,以下显示预输出信息:\n"));
		m_wndOutput.m_wndOutputCalib.AddString(message);
		break;
	}
}

/*---------------------------------------------
* 功能 : 弹出打开文件对话框，选择单个或多个文件
*----------------------------------------------
* 函数 : CMainFrame::DoSelectFiles
* 访问 : private
* 返回 : selectedFiles	选择的文件的路径序列
*
* 参数 : lpszDefExt			[in]	文件默认格式
* 参数 : dwFlags			[in]	对话框选项
* 参数 : lpszFilter			[in]	文件格式过滤条件
* 参数 : lpstrTitle			[in]	对话框标题
* 参数 : lpstrInitialDir	[in]	对话框的初始路径
*/
vector<CStringA> CMainFrame::DoSelectFiles(LPCTSTR lpszDefExt, DWORD dwFlags, LPCTSTR lpszFilter, LPCTSTR lpstrTitle, LPCTSTR lpstrInitialDir)
{
	vector<CStringA> selectedFiles;
	POSITION filePosition;
	DWORD MAXFILE = 4000;
	TCHAR* pc = new TCHAR[MAXFILE];

	CFileDialog dlg(TRUE, lpszDefExt, NULL, dwFlags, lpszFilter, NULL);

	dlg.m_ofn.nMaxFile = MAXFILE;
	dlg.m_ofn.lpstrFile = pc;
	dlg.m_ofn.lpstrFile[0] = NULL;
	dlg.m_ofn.lpstrTitle = lpstrTitle;
	dlg.m_ofn.lpstrInitialDir = lpstrInitialDir;

	if (dlg.DoModal() == IDOK)
	{
		filePosition = dlg.GetStartPosition();
		while (filePosition != NULL)
		{
			CStringA path;
			path = dlg.GetNextPathName(filePosition);
			selectedFiles.push_back(path);
		}
	}

	delete[]pc;
	return selectedFiles;
}

/*---------------------------------------------
* 功能 : 显示图像
*		 将要绘制的图像 src 复制到 des，然后绘制到控件号为 ID 的 Picture 控件
*----------------------------------------------
* 函数 : CMainFrame::F_ShowImage
* 访问 : private
* 返回 : void
*
* 参数 : src	[in]	待显示图像
* 参数 : des	[in]	窗口图像
* 参数 : ID		[in]	图像窗口控件ID
*/
void CMainFrame::F_ShowImage(Mat& src, Mat& des, UINT ID)
{
	if (src.empty())
	{
		return;
	}
	// 计算将图片缩放到 Image 区域所需的比例因子
	double wRatio = des.cols / (double)src.cols;
	double hRatio = des.rows / (double)src.rows;
	double srcWH = src.cols / (double)src.rows;
	double desWH = des.cols / (double)des.rows;
	double scale = srcWH > desWH ? wRatio : hRatio;

	// 缩放后图片的宽和高
	int nw = (int)(src.cols * scale);
	int nh = (int)(src.rows * scale);

	// 为了将缩放后的图片存入 des 的正中部位，需计算图片在 des 左上角的期望坐标值
	int tlx = (int)((des.cols - nw) / 2);
	int tly = (int)((des.rows - nh) / 2);

	// 设置 des 的 ROI 区域，用来存入图片 img
	Mat desRoi = des(Rect(tlx, tly, nw, nh));

	// 如果src是单通道图像，则转换为三通道图像
	if (src.channels() == 1)
	{
		Mat src_c;
		cvtColor(src, src_c, CV_GRAY2BGR);
		// 对图片 src_t 进行缩放，并存入到 des 中
		resize(src_c, desRoi, desRoi.size());
	}
	else
	{
		// 对图片 src 进行缩放，并存入到 des 中
		resize(src, desRoi, desRoi.size());//===================================
	}

	CDC* pDC = this->GetActiveView()->GetDlgItem(ID)->GetDC();		// 获得显示控件的 DC
	HDC hDC = pDC->GetSafeHdc();				// 获取 HDC(设备句柄) 来进行绘图操作
	CRect rect;
	this->GetActiveView()->GetDlgItem(ID)->GetClientRect(&rect);	// 获取控件尺寸位置
	CvvImage cimg;
	IplImage cpy = des;
	cimg.CopyOf(&cpy);						// 复制图片
	cimg.DrawToHDC(hDC, &rect);				// 将图片绘制到显示控件的指定区域内
	ReleaseDC(pDC);
}

/*=====================以下的一组监听器负责更新Ribbon界面上的控件状态====================*/
/*                                     标志位说明:                                       
  bool CalibDefaultParamEnable     = false;      // 是否启用标定->默认参数             
  bool CalibDeleteParamEnable      = false;      // 是否启用标定->清除参数             
  bool CalibFromImage              = false;      // 是否启用 标定->从图片标定          
  bool CalibFromCamera             = false;      // 是否启用 标定->从相机标定          
  bool CalibFromFile               = false;      // 是否启用 标定->从文件标定          
  bool StopCalibFromCamera         = false;      // 是否启用 标定->停止从镜头标定      
  bool MatchDefaultParamEnable     = false;      // 是否启用匹配->默认参数             
  bool MatchDeleteParamEnable      = false;      // 是否启用匹配->清除参数             
  bool MatchBngivedispEnable       = false;      // 是否启用匹配->生成视差图           
  bool MatchDeepRebuildEnable      = false;      // 是否启用匹配->深度重建             
  bool RangeEnable                 = false;      // 是否启用测距相关功能               
  bool DoRefreshDisparityMapEnable = false;      // 是否启用 匹配->刷新视差图          
  */
/*=======================================================================================*/
//ribbon->标定->默认参数
void CMainFrame::OnUpdateBnDefaultcamcalibparam(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(CalibDefaultParamEnable);
}

//ribbon->标定->清空参数
void CMainFrame::OnUpdateBnDeletecamcalibparam(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(CalibDeleteParamEnable);
}

//ribbon->标定->从图片标定
void CMainFrame::OnUpdateBndetectag(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(CalibFromImage);
}

//ribbon->标定->从镜头标定
void CMainFrame::OnUpdateTestcalib(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(CalibFromCamera);
}

//ribbon->标定->从文件标定
void CMainFrame::OnUpdateCalibfromyml(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(CalibFromFile);
}

//ribbon->标定->停止从镜头标定
void CMainFrame::OnUpdateStopcalib(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(StopCalibFromCamera);
}

//ribbon->匹配->默认参数
void CMainFrame::OnUpdateBnStereodefparam(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(MatchDefaultParamEnable);
}

//ribbon->匹配->清除参数
void CMainFrame::OnUpdateBnStereodeleteparam(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(MatchDeleteParamEnable);
}

//ribbon->匹配->生成视差图
void CMainFrame::OnUpdateBngivedisp(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(MatchBngivedispEnable);
}

//ribbon->匹配->刷新
void CMainFrame::OnUpdateDorefreshdisparitymap(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(DoRefreshDisparityMapEnable);
}

//ribbon->匹配->深度重建
void CMainFrame::OnUpdateBnCompdisp(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(MatchDeepRebuildEnable);
}

//ribbon->测距->鼠标定点
void CMainFrame::OnUpdateBnMouseon(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(RangeEnable);
}

/*======================================================================================*/
/*                          以下为Home按键的内部菜单项的事件处理                        */
/*======================================================================================*/
//Home键->新工程
void CMainFrame::OnNewproject()
{
	// TODO:  在此添加命令处理程序代码
	//1.弹出命名对话框,给工程命名
	CNewProject NPDialog;
	if (NPDialog.DoModal()){//模态对话框结束
		CString proName = NPDialog.ProjectName;//把输入的东西取出来
		if (proName.IsEmpty())//判断是否得到了有效的工程名
		{
			AfxMessageBox("无效的工程名!");
			return;//本函数结束
		}
		else//工程名有效
		{

			char szPath[MAX_PATH];     //存放选择的目录路径 
			CString AbsPath;
			ZeroMemory(szPath, sizeof(szPath));
			BROWSEINFO bi;
			bi.hwndOwner = m_hWnd;
			bi.pidlRoot = NULL;
			bi.pszDisplayName = szPath;
			CString temp;
			temp.Format(_T("%s%s%s"), "请选择新工程:'", NPDialog.ProjectName, "'的目录：");
			bi.lpszTitle = _T(temp);
			bi.ulFlags = 0;
			bi.lpfn = NULL;
			bi.lParam = 0;
			bi.iImage = 0;
			LPITEMIDLIST lp = SHBrowseForFolder(&bi);//弹出选择目录对话框
			if (lp && SHGetPathFromIDList(lp, szPath))//目录有效,建立目录结构,对全局变量进行赋值
			{
				AbsPath.Format("%s%s", szPath, proName);//在所选目录下面连接上以工程名命名的文件夹作为本工程的根目录 
				CString CalibPicturePath;
				CString RangePicturePath;
				CString DataPath;
				CalibPicturePath.Format(_T("%s\\%s"), AbsPath, _T("标定图片"));
				RangePicturePath.Format(_T("%s\\%s"), AbsPath, _T("拍照"));
				DataPath.Format(_T("%s\\%s"), AbsPath, _T("DATA"));
				//开始建立工程目录
				if (!PathIsDirectory(AbsPath))//指定目录不存在
				{
					if (CreateDirectory(AbsPath, NULL) &&         /*根目录*/
						CreateDirectory(CalibPicturePath, NULL) &&/*保存标定图片*/
						CreateDirectory(RangePicturePath, NULL) &&/*保存测距图片*/
						CreateDirectory(DataPath, NULL)           /*保存数据文件*/
						)//创建并判断是否创建成功
					{
						//创建成功,对工作目录全局变量进行赋值
						WorkPath = AbsPath;
						CalibDefaultParamEnable = true;      // 启用标定->默认参数
						CalibDeleteParamEnable = true;      // 启用标定->清除参数
						CalibFromImage = true;              // 启用 标定->从图片标定
						CalibFromCamera = true;             // 启用 标定->从相机标定
						CalibFromFile = true;               // 启用 标定->从文件标定
						PutMessage(CalibWnd, _T("工程目录载入成功!\n已经完成初始化!\n"));
					}
					else//创建失败
					{
						AfxMessageBox(_T("创建失败!"));
						return;
					}
				}
			}
			else
			{
				AfxMessageBox("无效的工程目录!");
				return; //本函数结束
			}

		}

	}

}

//Home键->打开工程
void CMainFrame::OnOpenproject()
{
	// TODO:  在此添加命令处理程序代码
	//1.打开文件选择器
	//2.找到工程目录
	//3.加载所需要的文件
	//4.提示信息
	char szPath[MAX_PATH];     //存放选择的目录路径 
	CString AbsPath;
	ZeroMemory(szPath, sizeof(szPath));
	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	CString temp;
	temp.Format(_T("%s"), "请选择工程目录：");
	bi.lpszTitle = _T(temp);
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);//弹出选择目录对话框
	if (lp && SHGetPathFromIDList(lp, szPath))//目录有效
	{
		AbsPath.Format("%s", szPath);//父目录,工程名,应该在父目录下面建立一个名叫工程名的新文件夹
		if (!PathIsDirectory(AbsPath))//指定目录不存在
		{
			AfxMessageBox(_T("所选目录不存在或不可访问!"));
			return;
		}
		else//所选择的目录有效
		{
			WorkPath = AbsPath;//工作目录赋值
			CalibDefaultParamEnable = true;      // 启用标定->默认参数
			CalibDeleteParamEnable = true;      // 启用标定->清除参数
			CalibFromImage = true;              // 启用 标定->从图片标定
			CalibFromCamera = true;             // 启用 标定->从相机标定
			CalibFromFile = true;               // 启用 标定->从文件标定
			PutMessage(CalibWnd, _T("工程目录载入成功!\n已经完成初始化!\n"));
		}
	}
	else
	{
		AfxMessageBox("无效的工程目录!");
		return; //本函数结束
	}

}

//Home键->打开工程目录
void CMainFrame::OnOpenpath()
{
	// TODO:  在此添加命令处理程序代码
	ShellExecute(NULL, NULL, WorkPath, NULL, NULL, SW_SHOW);
}

//Home->关闭工程
void CMainFrame::OnCloseproject()
{
	// TODO:  在此添加命令处理程序代码
	//禁用所有的功能
	CalibDefaultParamEnable = false;      // 禁用标定->默认参数
	CalibDeleteParamEnable = false;       // 禁用标定->清除参数
	CalibFromImage = false;               // 禁用标定->从图片标定
	CalibFromCamera = false;              // 禁用标定->从相机标定
	CalibFromFile = false;                // 禁用标定->从文件标定
	MatchDefaultParamEnable = false;      // 禁用匹配->默认参数
	MatchDeleteParamEnable = false;       // 禁用匹配->清除参数
	MatchBngivedispEnable = false;        // 禁用匹配->生成视差图
	MatchDeepRebuildEnable = false;       // 禁用匹配->深度重建
	RangeEnable = false;                  // 禁用测距相关功能        
	StopCalibFromCamera = false;          // 禁用 标定->停止从镜头标定                     
	DoRefreshDisparityMapEnable = false;  // 禁用 匹配->刷新视差图
}

//Home键->帮助文档
void CMainFrame::OnHelpdoc()
{
	// TODO:  在此添加命令处理程序代码
	//1.用RTF写帮助文档
	//2.按这个打开
}

/*======================================================================================*/
/*                         以下是Ribbon按键的事件处理程序                               */
/*======================================================================================*/
//Ribbon->标定->BOUGUET(复选框)
void CMainFrame::OnRadBouguet()
{
	// TODO:  在此添加命令处理程序代码
	BOUGUET = !BOUGUET;
}
void CMainFrame::OnUpdateRadBouguet(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(BOUGUET);
}

//Ribbon->标定->HEARTLY(复选框)
void CMainFrame::OnRadHartley()
{
	// TODO:  在此添加命令处理程序代码
	BOUGUET = !BOUGUET;
}
void CMainFrame::OnUpdateRadHartley(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(!BOUGUET);
}

//Ribbon->标定->默认参数(按键)
void CMainFrame::OnBnDefaultcamcalibparam()
{
	// TODO:  在此添加命令处理程序代码
	//1.单选框初始化
	//LocalPicture = true; //从本地读取图片
	//ReadYML = false;     //从本地读取角点坐标数据
	BOUGUET = true;      //使用BOUGUET检测算法

	//2.变量对应的界面参数初始化
	CPara1::getInstance()->GetDlgItem(IDC_BoardWidth)->SetWindowText("9");
	CPara1::getInstance()->GetDlgItem(IDC_BoardHeight)->SetWindowText("6");
	CPara1::getInstance()->GetDlgItem(IDC_nBoards)->SetWindowText("20");
	CPara1::getInstance()->GetDlgItem(IDC_SquareSize)->SetWindowText("25");
	CPara1::getInstance()->GetDlgItem(IDC_Alpha)->SetWindowText("-1");
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_FPP)))->SetCheck(true);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_UIG)))->SetCheck(true);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_FAR)))->SetCheck(true);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_SFL)))->SetCheck(true);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_FI)))->SetCheck(false);
	return;
}

//Ribbon->标定->清除参数(按键)
void CMainFrame::OnBnDeletecamcalibparam()
{
	// TODO:  在此添加命令处理程序代码
	CPara1::getInstance()->GetDlgItem(IDC_BoardWidth)->SetWindowText("");
	CPara1::getInstance()->GetDlgItem(IDC_BoardHeight)->SetWindowText("");
	CPara1::getInstance()->GetDlgItem(IDC_nBoards)->SetWindowText("");
	CPara1::getInstance()->GetDlgItem(IDC_SquareSize)->SetWindowText("");
	CPara1::getInstance()->GetDlgItem(IDC_Alpha)->SetWindowText("");
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_FPP)))->SetCheck(false);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_UIG)))->SetCheck(false);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_FAR)))->SetCheck(false);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_SFL)))->SetCheck(false);
	((CButton *)(CPara1::getInstance()->GetDlgItem(IDC_CHK_FI)))->SetCheck(false);
}

//Ribbon->标定/采样->启动摄像头(按键)
void CMainFrame::OnBn1runcam()
{
	// TODO:  在此添加命令处理程序代码
	if (m_nImageWidth * m_nImageHeight * m_nImageChannels == 0)
	{
		AfxMessageBox(_T("请选择摄像头画面的分辨率！"));
		return;
	}
	if (m_nCamCount > 0)
	{
		//打开第一个摄像头
		//if( ! lfCam.OpenCamera(m_riCamID, false, m_nImageWidth, m_nImageHeight) ) //不弹出属性选择窗口，用代码制定图像宽和高
		if (!lfCam.open(m_lfCamID))
		{
			AfxMessageBox(_T("打开左摄像头失败."));
			return;
		}
		lfCam.set(CV_CAP_PROP_FRAME_WIDTH, m_nImageWidth);
		lfCam.set(CV_CAP_PROP_FRAME_HEIGHT, m_nImageHeight);
	}
	if (m_nCamCount > 1)
	{
		if (m_lfCamID == m_riCamID)
		{
			AfxMessageBox(_T("左右摄像头的设备序号不能相同！"));
			return;
		}
		//打开第二个摄像头
		//if( ! riCam.OpenCamera(m_lfCamID, false, m_nImageWidth, m_nImageHeight) ) 
		if (!riCam.open(m_riCamID))
		{
			AfxMessageBox(_T("打开右摄像头失败."));
			return;
		}
		riCam.set(CV_CAP_PROP_FRAME_WIDTH, m_nImageWidth);
		riCam.set(CV_CAP_PROP_FRAME_HEIGHT, m_nImageHeight);
	}
	/*
	// 使部分按钮生效
	GetDlgItem(IDC_BN2StopCam)->EnableWindow(TRUE);
	
	GetDlgItem(IDC_BN_CompDisp)->EnableWindow(TRUE);
	// 使部分按钮失效
	GetDlgItem(IDC_BN1RunCam)->EnableWindow(FALSE);
	GetDlgItem(IDC_CBN1CamList_L)->EnableWindow(FALSE);
	GetDlgItem(IDC_CBN1CamList_R)->EnableWindow(FALSE);
	GetDlgItem(IDC_CBN_Resolution)->EnableWindow(FALSE);
	*/


	// 启动摄像头后显示实时画面
	DoShowOrigFrame();
}

//Ribbon->标定/采样->关闭相机(按键)
void CMainFrame::OnBn2stopcam()
{
	// TODO:  在此添加命令处理程序代码
	if (lfCam.isOpened())
	{
		//GetDlgItem(IDC_BN2StopCam)->EnableWindow(FALSE);
		KillTimer(1);

		// 对图像数据清零
		m_lfImage = Scalar(0);
		F_ShowImage(m_lfImage, m_lfImage, IDC_PicLfCam);
		lfCam.release();
		if (riCam.isOpened())
		{
			m_riImage = Scalar(0);
			F_ShowImage(m_riImage, m_riImage, IDC_PicRiCam);
			riCam.release();
		}

		// 使启动摄像头按钮和摄像头选择列表生效
		/*
		GetDlgItem(IDC_BN1RunCam)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBN1CamList_L)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBN1CamList_R)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBN_Resolution)->EnableWindow(TRUE);
		GetDlgItem(IDC_BN_CompDisp)->EnableWindow(FALSE);
		*/
	}
	return;
}

//Ribbon->标定/采样->刷新相机(按键)
void CMainFrame::OnRefreshcam()
{
	// TODO:  在此添加命令处理程序代码
	RefalshCamera();
}

//Ribbon->标定->从图片标定(按键)
void CMainFrame::OnBndetectag()
{
	// TODO:  在此添加命令处理程序代码
	/*进行初始化*/
	int nFoundBoard = 0, nFrame = 0, nSucceedBoard = 0;
	vector<CStringA> img0Files, img1Files;
	const char* img0_file = NULL, *img1_file = NULL;
	cv::Mat frame0, frame1, img0, img1;
	cv::Size imageSize;
	UpdateData(TRUE);
	
	try
	{
		if (DoParseOptionsOfCameraCalib(optCalib) == false){//对界面上的参数进行检查,并传递到镜头标定参数结构体中	
			AfxMessageBox(_T("您没有设置合理的标定参数!"));
			return;
		};
		optCalib.numberFrameSkip = 5;//跳帧数改成5
	
		img0Files = DoSelectFiles(
				_T("*.bmp"),
				OFN_ENABLESIZING | OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY,
				_T("image files (*.bmp; *.png; *.jpg) |*.bmp; *.png; *.jpg; *.jpeg| All Files (*.*) |*.*||"),
				_T("选择左视图文件"),
				WorkPath);
		img1Files = DoSelectFiles(
				_T("*.bmp"),
				OFN_ENABLESIZING | OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY,
				_T("image files (*.bmp; *.png; *.jpg) |*.bmp; *.png; *.jpg; *.jpeg| All Files (*.*) |*.*||"),
				_T("选择右视图文件"),
				WorkPath);

		if (img0Files.empty())	// 判断是否获得图片
		{
			LPCTSTR errMsg = _T("没有选择到有效的图像文件，请重新选择!");
			throw errMsg;
		}

		img0_file = img0Files[0];
		img0 = cvLoadImage(img0_file);
		if (img0.rows>1000)
		{
			cv::resize(img0, img0, Size(img0.cols / 6, img0.rows / 6));
		}
		imageSize = img0.size();

		optCalib.numberBoards = MIN(optCalib.numberBoards, MIN(img0Files.size(), img1Files.size()));
			
		m_stereoCalibrator.initCornerData(optCalib.numberBoards, imageSize, optCalib.cornerSize, optCalib.squareSize, cornerDatas);

		// 开始检测角点
		while (nFoundBoard < optCalib.numberBoards)
		{
			// 载入图像
			img0_file = img0Files[nFoundBoard];
			frame0 = cvLoadImage(img0_file);
			// 复制图像
			img0 = frame0.clone();
			if (img0.rows>1000)
			{
				cv::resize(img0, img0, Size(img0.cols / 6, img0.rows / 6));
			}
					
			img1_file = img1Files[nFoundBoard];
			frame1 = cvLoadImage(img1_file);
			img1 = frame1.clone();
			if (img1.rows>1000)
			{
				cv::resize(img1, img1, Size(img1.cols / 6, img1.rows / 6));
			}
				
			if (img0.rows>1000)//
			{
				cv::resize(img0, img0, Size(img0.cols / 6, img0.rows / 6));
				cv::resize(img1, img1, Size(img1.cols / 6, img1.rows / 6));
			}
			// 检测角点
			if (m_stereoCalibrator.detectCorners(img0, img1, cornerDatas, nFoundBoard))//如果检测成功
			{				 
				nSucceedBoard++;
				nFrame = 0;
				if (nFoundBoard > 0 && nFrame < 5)
				{
					//使图像反色，表明同时找到完整的棋盘角点
					bitwise_not(img0, img0);
					bitwise_not(img1, img1);
				}
			}
			else//如果检测失败
			{
				PutMessage(CalibWnd, _T("此图片检测失败!\n"));
			}
			nFoundBoard++;//不管成功失败,这幅图都过去了
			// 显示检测到的角点
			F_ShowImage(img0, m_lfImage, IDC_PicLfCam);
			F_ShowImage(img1, m_riImage, IDC_PicRiCam);
		} // --End "while(nFoundBoard < optCalib.numberBoards) "

		if (nSucceedBoard < 4)
		{
			PutMessage(CalibWnd, _T("检测成功的棋盘图像数小于4个，标定失败!\n请重新进行标定操作.\n"));
				return;
		}
		else if (nFoundBoard != optCalib.numberBoards)
		{
			optCalib.numberBoards = nFoundBoard;
			m_stereoCalibrator.resizeCornerData(optCalib.numberBoards, cornerDatas);
		}
		cornerDatas.nImages = nSucceedBoard;//更新棋盘图像数量
		// 保存角点坐标数据
		CString FileTemp;
		FileTemp.Format(_T("%s\\%s"), WorkPath, _T("\\DATA\\CornerData.yml"));
		const char* cornerFile = FileTemp.GetBuffer(FileTemp.GetLength());
		m_stereoCalibrator.saveCornerData(cornerFile, cornerDatas);
		PutMessage(CalibWnd, _T("棋盘角点检测结束.\n"));
		// 已获取角点坐标数据
		
	}
	catch (LPCTSTR errMsg)
	{
		AfxMessageBox(errMsg);
		return;
	}
	catch (cv::Exception& e)
	{
		char err[2048];
		sprintf_s(err, "发生错误: %s", e.what());
		CString errInfo;
		errInfo = err;
		//AfxMessageBox(_T(errInfo));
		PutMessage(CalibWnd, _T(errInfo));
		return;
	}
	catch (...)
	{
		//AfxMessageBox(_T("发生未知错误！"));
		PutMessage(CalibWnd, _T("发生未知错误！"));
		return;
	}
	
	//stereoParams.flags = optCalib.flagStereoCalib;
	stereoParams.flags = 0;
	stereoParams.alpha = optCalib.alpha;
	m_stereoCalibrator.calibrateStereoCamera(cornerDatas, stereoParams, FALSE);

	// 计算标定误差
	double avgErr = 0;
	int x = m_stereoCalibrator.getStereoCalibrateError(cornerDatas, stereoParams, avgErr);
	char info[50];
	sprintf_s(info, "标定误差 = %7.4g", avgErr);
	CString ss;
	ss = info;
	PutMessage(CalibWnd, ss);//输出标定误差

	optCalib.rectifyMethod = (BOUGUET == true ? calib::RECTIFY_BOUGUET : calib::RECTIFY_HARTLEY);//识别所选择的匹配算法

	// 执行双目校正
	m_stereoCalibrator.rectifyStereoCamera(cornerDatas, stereoParams, remapMatrixs, optCalib.rectifyMethod);
	//得到重投影矩阵和校正映射矩阵
	PutMessage(CalibWnd, _T("已完成双目校正.\n"));
	// 保存摄像头定标参数
	CString CalibParasFile;
	CalibParasFile.Format(_T("%s\\%s"), WorkPath, _T("\\DATA\\calib_paras.xml"));
	const char* calibparasfile = CalibParasFile.GetBuffer(CalibParasFile.GetLength());
	m_stereoCalibrator.saveCalibrationDatas(calibparasfile, optCalib.rectifyMethod, cornerDatas, stereoParams, remapMatrixs);
	PutMessage(CalibWnd, _T("已保存定标参数文件:\n"));
	if (avgErr > 5.0){
		AfxMessageBox(_T("标定误差过大!强烈建议您检查标定来源的合理性并进行调整和重试,如果您继续执行操作,将会降低结果的置信度!"));
	}
	MatchDefaultParamEnable = true;      // 启用匹配->默认参数
	MatchDeleteParamEnable = true;      // 启用匹配->清除参数
	MatchBngivedispEnable = true;      // 启用匹配->生成视差图
}

//Ribbon->标定->从相机标定(按键) 
void CMainFrame::OnTestcalib()
{
	// TODO:  在此添加命令处理程序代码
	//确认摄像机定标的相关选项
	StopCalibFromCamera = true;      // 启用 停止标定的按键
	KillTimer(1);
	if (DoParseOptionsOfCameraCalib(optCalib) == false){//对界面上的参数进行检查,并传递到镜头标定参数结构体中	
		AfxMessageBox(_T("您没有设置合理的标定参数!"));
		return;
	};
	// 本函数使用的临时变量
	int nFoundBoard = 0, nFrame = 0;
	cv::Mat frame0, frame1, img0, img1;
	cv::Size imageSize;
	try
	{
		// 初始化角点数据集
		lfCam >> img0;
		imageSize = img0.size();
		m_stereoCalibrator.initCornerData(optCalib.numberBoards, 
										  imageSize, 
									      optCalib.cornerSize, 
										  optCalib.squareSize,
										  cornerDatas);

		// 开始检测角点
		MSG msg;
		while (nFoundBoard < optCalib.numberBoards)//如果已经检测过的图像数目没有达到预设的迭代次数
		{
			// 用于响应中途退出标定的消息
			if (::PeekMessage(&msg, this->m_hWnd, 0, 0, PM_REMOVE)){
				if (msg.message == WM_QUIT){
					LPCTSTR errMsg = _T("手动退出双目标定!");
					throw errMsg;
				}
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}

			// 从摄像头载入图像
			lfCam >> frame0;
			riCam >> frame1;

			if (frame0.empty() || frame1.empty())
				break;

			// 复制图像
			img0 = frame0.clone();
			img1 = frame1.clone();
			// 检测角点
			if (m_stereoCalibrator.detectCorners(img0, img1, cornerDatas, nFoundBoard))//如果这一幅图角点检测成功
			{
				if (nFrame++ > optCalib.numberFrameSkip)//到达指定的帧间隔数目
				{
					//保存视图
					CString ImgName;
					ImgName.Format(_T("%s\\标定图片\\left%03d.jpg"), WorkPath, nFoundBoard);
					string imgnameL(ImgName.GetBuffer());
					imwrite(imgnameL, frame0);
					ImgName.Format(_T("%s\\标定图片\\right%03d.jpg"), WorkPath, nFoundBoard);
					string imgnameR(ImgName.GetBuffer());
					imwrite(imgnameR, frame1);
					ImgName.ReleaseBuffer();
					
					nFoundBoard++;
					nFrame = 0;
				}

				if (nFoundBoard > 0 && nFrame < 5)
				{
					//使图像反色，表明同时找到完整的棋盘角点
					bitwise_not(img0, img0);
					bitwise_not(img1, img1);
				}
			} // --End "if ( m_stereoCalibrator.detectCorners )"

			// 显示检测到的角点
			F_ShowImage(img0, m_lfImage, IDC_PicLfCam);
			F_ShowImage(img1, m_riImage, IDC_PicRiCam);
		} // --End "while(nFoundBoard < optCalib.numberBoards) "

		if (nFoundBoard < 4)
		{
			LPCTSTR errMsg = _T("检测成功的棋盘图像数小于4个，退出双目标定!");
			throw errMsg;
		}
		else if (nFoundBoard != optCalib.numberBoards)
		{
			optCalib.numberBoards = nFoundBoard;
			m_stereoCalibrator.resizeCornerData(optCalib.numberBoards, cornerDatas);
		}

		// 保存角点坐标数据
		CString CornerDataFile;
		CornerDataFile.Format(_T("%s\\%s"), WorkPath, _T("\\DATA\\CornerData.yml"));
		const char* cornerFile = CornerDataFile.GetBuffer(CornerDataFile.GetLength());
		m_stereoCalibrator.saveCornerData(cornerFile, cornerDatas);

		//AfxMessageBox(_T("棋盘角点检测结束"));
		PutMessage(CalibWnd, _T("棋盘角点检测结束\n"));//输出标定误差
		
	}
	catch (LPCTSTR errMsg)
	{
		AfxMessageBox(errMsg);
	}
	catch (cv::Exception& e)
	{
		char err[2048];
		sprintf_s(err, "发生错误: %s", e.what());
		CString errInfo(err);
		AfxMessageBox(errInfo);
	}
	catch (...)
	{
		AfxMessageBox(_T("发生未知错误！"));
	}
	// 已获取角点坐标数据

	// 传递标定参数
	//stereoParams.cameraParams1.flags = optCalib.flagCameraCalib;
	//stereoParams.cameraParams2.flags = optCalib.flagCameraCalib;
	stereoParams.flags = optCalib.flagStereoCalib;
	stereoParams.alpha = optCalib.alpha;
	//执行立体相机标定(最后一个参数代表不需要先进行单目标定)
	m_stereoCalibrator.calibrateStereoCamera(cornerDatas, stereoParams, false);

	// 计算标定误差
	double avgErr = 0;
	m_stereoCalibrator.getStereoCalibrateError(cornerDatas, stereoParams, avgErr);
	char info[50];
	sprintf_s(info, "标定误差 = %7.4g\n", avgErr);
	CString ss;
	ss = info;
	PutMessage(CalibWnd, ss);//输出标定误差
	//AfxMessageBox(ss);

	// 执行立体相机矫正
	m_stereoCalibrator.rectifyStereoCamera(cornerDatas, stereoParams, remapMatrixs, optCalib.rectifyMethod);
	//AfxMessageBox(_T("已完成双目校正"));
	PutMessage(CalibWnd, _T("已完成双目校正\n"));//输出标定误差

	// 保存摄像头定标参数	
	CString CalibParasFile;
	CalibParasFile.Format(_T("%s\\%s"), WorkPath, _T("\\DATA\\calib_paras.xml"));
	const char* calibparasfile = CalibParasFile.GetBuffer(CalibParasFile.GetLength());
	m_stereoCalibrator.saveCalibrationDatas(calibparasfile, optCalib.rectifyMethod, cornerDatas, stereoParams, remapMatrixs);
	//AfxMessageBox(_T("已保存定标参数"));
	PutMessage(CalibWnd, _T("已保存定标参数\n"));//输出标定误差
		
	MSG msg;
	while (true)// 显示标定效果
	{
		// MFC 窗口消息处理
		if (::PeekMessage(&msg, this->m_hWnd, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		// 载入图像
		lfCam >> frame0;
		riCam >> frame1;
		if (frame0.empty() || frame1.empty())
			break;
		// 复制图像
		img0 = frame0.clone();
		img1 = frame1.clone();
		// 校正图像
		UpdateData(FALSE);
		m_stereoCalibrator.remapImage(img0, img1, img0, img1, remapMatrixs);
		// 显示校正效果	
		// 画出等距的若干条横线，以比对 行对准 情况
		for (int j = 0; j < img0.rows; j += 32)
		{
			line(img0, cvPoint(0, j), cvPoint(img0.cols, j), CV_RGB(0, 255, 0));
			line(img1, cvPoint(0, j), cvPoint(img1.cols, j), CV_RGB(0, 255, 0));
		}
		F_ShowImage(img0, m_lfImage, IDC_PicLfCam);
		F_ShowImage(img1, m_riImage, IDC_PicRiCam);
	}
	

	// 禁用退出摄像机定标按钮

	//////////////////////////////////////////////////////////////////////////	
	if (lfCam.isOpened() || riCam.isOpened())
	{
		// 定标结束，恢复双目定标按钮
		// 恢复正常显示
		DoShowOrigFrame();
	}
	return;
	MatchDefaultParamEnable = true;      // 启用匹配->默认参数
	MatchDeleteParamEnable = true;      // 启用匹配->清除参数
	MatchBngivedispEnable = true;      // 启用匹配->生成视差图
}
 
//Ribbon->标定->从文件标定(按键)
void CMainFrame::OnCalibfromyml()
{
	// TODO:  在此添加命令处理程序代码
	if (!DoParseOptionsOfCameraCalib(optCalib)){// 导入相机标定的相关参数
		AfxMessageBox(_T("您没有设置合理的标定参数!"));
		return;
	}
		
	try
	{
		vector<CStringA> YmlFilePath;
		YmlFilePath = DoSelectFiles(
			_T("*.yml"),
			OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
			_T("yml files (*.yml) |*.yml| All Files (*.*) |*.*||"),
			_T("选择标定盘坐标文件"),
			WorkPath
			);
		/*_T("*.bmp"),
				OFN_ENABLESIZING | OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY,
				_T("image files (*.bmp; *.png; *.jpg) |*.bmp; *.png; *.jpg; *.jpeg| All Files (*.*) |*.*||"),
				_T("选择左视图文件"),*/
		if (YmlFilePath.empty())
		{
			AfxMessageBox(_T("没有选中有效的坐标文件!"));
			return;
		}
		const char* YMLFile = YmlFilePath[0];			// 获取yml文件路径
		// 从本地文件读入角点坐标数据YML
		if (m_stereoCalibrator.loadCornerData(YMLFile, cornerDatas))
		{
			//AfxMessageBox(_T("已读入坐标数据"));
			PutMessage(CalibWnd, _T("已读入坐标数据"));
		}
		else
		{
			LPCTSTR errMsg = _T("坐标数据读入失败！\n 请确认文件的正确性或执行棋盘角点检测。");
			throw errMsg;
		}
	}
	catch (LPCTSTR errMsg)
	{
		AfxMessageBox(errMsg);
		return;
	}
	catch (cv::Exception& e)
	{
		char err[2048];
		sprintf_s(err, "文件错误!以下是系统提供的错误信息: %s", e.what());
		CString errInfo(err);
		AfxMessageBox(errInfo);
		return;
	}
	catch (...)
	{
		AfxMessageBox(_T("发生未知错误！"));
		return;
	}
	// 已获取角点坐标数据

	// 进行摄像头标定

	//stereoParams.flags = optCalib.flagStereoCalib;
	stereoParams.flags = 0;
	stereoParams.alpha = optCalib.alpha;
	m_stereoCalibrator.calibrateStereoCamera(cornerDatas, stereoParams, FALSE);

	// 计算标定误差
	double avgErr = 0;
	m_stereoCalibrator.getStereoCalibrateError(cornerDatas, stereoParams, avgErr);
	char info[50];
	sprintf_s(info, "标定误差 = %7.4g\n", avgErr);
	CString ss;
	ss = info;
	PutMessage(CalibWnd, ss);
	//AfxMessageBox(ss);

	// 执行双目校正
	m_stereoCalibrator.rectifyStereoCamera(cornerDatas, stereoParams, remapMatrixs, optCalib.rectifyMethod);
	PutMessage(CalibWnd, _T("已完成双目校正\n"));
	//AfxMessageBox(_T("已完成双目校正"));

	// 保存定标参数
	CString CalibParasFile;
	CalibParasFile.Format(_T("%s\\%s"), WorkPath, _T("\\DATA\\calib_paras.xml"));
	const char* calibparasFile = CalibParasFile.GetBuffer(CalibParasFile.GetLength());
	m_stereoCalibrator.saveCalibrationDatas(calibparasFile, optCalib.rectifyMethod, cornerDatas, stereoParams, remapMatrixs);

	//AfxMessageBox(_T("已保存定标参数"));
	PutMessage(CalibWnd, _T("已保存定标参数\n"));
	MatchDefaultParamEnable = true;      // 启用匹配->默认参数
	MatchDeleteParamEnable = true;      // 启用匹配->清除参数
	MatchBngivedispEnable = true;      // 启用匹配->生成视差图
	return;
}

//Ribbon->标定->停止标定(按键)
void CMainFrame::OnStopcalib()
{
	// TODO:  在此添加命令处理程序代码
	::PostMessage(this->m_hWnd, WM_QUIT, 0, 0);
	StopCalibFromCamera = false;      // 禁用这个按键
}

//Ribbon->匹配->BM(复选框)
void CMainFrame::OnRadBm()
{
	// TODO:  在此添加命令处理程序代码
	stereoMethod = STEREO_BM;
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_minDisp)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_uniqRatio)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_speckWinSiz)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_maxDisp)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_speckRange)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_preFiltCap)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_SADWinSiz)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_textThres)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_disp12MaxDiff)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Levels)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PyrScale)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PolyN)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PolySigma)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Fi)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Lambda)->ShowWindow(SW_HIDE);
}
void CMainFrame::OnUpdateRadBm(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(stereoMethod==STEREO_BM);
}

//Ribbon->匹配->SGBM(复选框)
void CMainFrame::OnRadSgbm()
{
	// TODO:  在此添加命令处理程序代码
	stereoMethod = STEREO_SGBM;
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_minDisp)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_uniqRatio)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_speckWinSiz)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_maxDisp)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_speckRange)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_preFiltCap)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_SADWinSiz)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_textThres)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_disp12MaxDiff)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Levels)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PyrScale)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PolyN)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PolySigma)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Fi)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Lambda)->ShowWindow(SW_HIDE);
}
void CMainFrame::OnUpdateRadSgbm(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(stereoMethod == STEREO_SGBM);
}

//Ribbon->匹配->VAR(复选框)
void CMainFrame::OnCheck2()
{
	stereoMethod = STEREO_VAR;
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_minDisp)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_uniqRatio)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_speckWinSiz)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_maxDisp)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_speckRange)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_preFiltCap)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_SADWinSiz)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_textThres)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_disp12MaxDiff)->ShowWindow(SW_HIDE);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Levels)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PyrScale)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PolyN)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_PolySigma)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Fi)->ShowWindow(SW_NORMAL);
	CPara2::getInstance()->GetDlgItem(IDC_SLIDER_Lambda)->ShowWindow(SW_NORMAL);
}
void CMainFrame::OnUpdateCheck2(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(stereoMethod == STEREO_VAR);
}

//Ribbon->匹配->默认参数(按键)
void CMainFrame::OnBnStereodefparam()
{
	// TODO:  在此添加命令处理程序代码
	switch (stereoMethod)//求解视差
	{
	case STEREO_BM://使用BM求解器
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp)->SetWindowText("0");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp)->SetWindowText("144");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_SADWinSiz)->SetWindowText("51");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_textThres)->SetWindowText("10");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_disp12MaxDiff)->SetWindowText("1");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_preFiltCap)->SetWindowText("31");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_uniqRatio)->SetWindowText("25");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckRange)->SetWindowText("32");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckWinSiz)->SetWindowText("100");
		break;
	case STEREO_SGBM://使用SGBM求解器
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp)->SetWindowText("0");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp)->SetWindowText("144");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_SADWinSiz)->SetWindowText("25");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_textThres)->SetWindowText("10");//这个以前不是这个值
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_disp12MaxDiff)->SetWindowText("1");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_preFiltCap)->SetWindowText("63");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_uniqRatio)->SetWindowText("20");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckRange)->SetWindowText("32");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckWinSiz)->SetWindowText("100");
		break;
	case STEREO_VAR://使用VAR求解器
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp)->SetWindowText("-64");
		CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp)->SetWindowText("64");
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Levels))->SetWindowText("1");
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PyrScale))->SetWindowText("01");
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PolyN))->SetWindowText("5");
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PolySigma))->SetWindowText("52.6");
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Fi))->SetWindowText("90");
		(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Lambda))->SetWindowText("0.82");
		break;
	default:
		break;
	}
}

//Ribbon->匹配->清除参数(按键)
void CMainFrame::OnBnStereodeleteparam()
{
	// TODO:  在此添加命令处理程序代码
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_minDisp)->SetWindowText("-64");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_maxDisp)->SetWindowText("16");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_SADWinSiz)->SetWindowText("5");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_textThres)->SetWindowText("0");//这个以前不是这个值
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_disp12MaxDiff)->SetWindowText("0");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_preFiltCap)->SetWindowText("0");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_uniqRatio)->SetWindowText("0");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckRange)->SetWindowText("0");
	CPara2::getInstance()->GetDlgItem(IDC_EDIT_speckWinSiz)->SetWindowText("0");
	(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Levels))->SetWindowText("1");
	(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PyrScale))->SetWindowText("0.1");
	(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PolyN))->SetWindowText("1");
	(CPara2::getInstance()->GetDlgItem(IDC_EDIT_PolySigma))->SetWindowText("0");
	(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Fi))->SetWindowText("0");
	(CPara2::getInstance()->GetDlgItem(IDC_EDIT_Lambda))->SetWindowText("0");
}

//Ribbon->匹配->选择文件(按键)
void CMainFrame::OnBngivedisp()
{
	// TODO:  在此添加命令处理程序代码
	CStringA xmlPath;			// 定标结果数据文件
	vector<CStringA> xmlFiles;
	vector<CStringA> imgFiles1; //左右视图文件路径序列
	vector<CStringA> imgFiles2;
	const char* img1_filename = NULL;
	const char* img2_filename = NULL;
	const char* xml_filename = NULL;
	
	LPCTSTR errMsg;
	try
	{
		// 选择左视图
		imgFiles1 = DoSelectFiles(
				_T("*.bmp"),
				OFN_ENABLESIZING | OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY,
				_T("image files (*.bmp; *.png; *.jpg) |*.bmp; *.png; *.jpg; *.jpeg| All Files (*.*) |*.*||"),
				_T("选择左视图图像"),
				WorkPath
				);
		// 选择右视图
		imgFiles2 = DoSelectFiles(
				_T("*.bmp"),
				OFN_ENABLESIZING | OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY,
				_T("image files (*.bmp; *.png; *.jpg) |*.bmp; *.png; *.jpg; *.jpeg| All Files (*.*) |*.*||"),
				_T("选择右视图图像"),
				WorkPath
				);
		if (imgFiles1.empty() || imgFiles2.empty())
		{
			errMsg = _T("没有选中有效的图像文件!");
			throw errMsg;
		}
		// 选择镜头参数文件
		xmlFiles = DoSelectFiles(
				_T("*.xml"),
				OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
				_T("XML/YML file (*.xml; *.yml) |*.xml; *.yml | All Files (*.*) |*.*||"),
				_T("选择摄像头定标参数文件"),
				WorkPath
				);
		if (xmlFiles.empty())
		{
			errMsg = _T("没有选中有效的摄像头定标参数文件!");
			throw errMsg;
		}// 读取图片
		img1_filename = imgFiles1[0];
		img2_filename = imgFiles2[0];
		TargetImageL = imread(img1_filename);
		TargetImageR = imread(img2_filename);

		if (TargetImageL.empty() || TargetImageR.empty()){
			AfxMessageBox(_T("图片文件错误!请重试."));
			return;
		}

			
		if (TargetImageL.rows>1000)
		{
			cv::resize(TargetImageL, TargetImageL, Size(TargetImageL.cols / 6, TargetImageL.rows / 6));
			cv::resize(TargetImageR, TargetImageR, Size(TargetImageL.cols / 6, TargetImageL.rows / 6));
		}
		// 获取xml文件路径
		xmlPath = xmlFiles[0];			
		xml_filename = xmlPath;
		// 读入摄像头定标参数
		switch (m_stereoMatcher.init(TargetImageL.cols, TargetImageL.rows, xml_filename))
		{
		case 0:
		case -99:
			errMsg = _T("读取摄像头定标参数文件失败，请重新选择!");
			throw errMsg;
		case -1:
			errMsg = _T("您选择的不是正确的标定参数文件或与所选择的图片来自不同的相机!");
			throw errMsg;
			break;
		}
	}
	catch (LPCTSTR ErrMsg)
	{
		AfxMessageBox(ErrMsg);
		return;
	}
	catch (cv::Exception& e)
	{
		char err[2048];
		sprintf_s(err, "发生错误: %s", e.what());
		CString errInfo;
		errInfo = err;
		AfxMessageBox(errInfo);
		return;
	}
	catch (...)
	{
		AfxMessageBox(_T("发生未知错误！"));
		return;
	}
	FileSelected = true;//已经选择完文件
	//直接执行一次刷新
	RefreshDisparityMap();
}

//Ribbon->匹配->刷新(按键)
void CMainFrame::OnDorefreshdisparitymap()
{
	// TODO:  在此添加命令处理程序代码
	RefreshDisparityMap();
}

//Ribbon->匹配->深度重建(按键)
void CMainFrame::OnBnCompdisp()
{
	CString FileTemp;
	FileTemp.Format(_T("%s\\%s"), WorkPath, _T("\\DATA\\pointcloud.xml"));
	const char* CloudsFile = FileTemp.GetBuffer(FileTemp.GetLength());
	// TODO:  在此添加命令处理程序代码
	m_stereoMatcher.getPointClouds(OriginalDisparity, pointCloud, CloudsFile);//生成三维点云并进行Y轴反转
	vector<PointCloudAnalyzer::ObjectInfo> objectInfos;
	PointCloudAnalyzer pointCloudAnalyzer;
	if (pointCloudAnalyzer.detectNearObject(DisparityMap, pointCloud, objectInfos)==0)
	{
		return;//上述函数失败,自行抛出异常信息,本函直接退出
	}
	pointCloudAnalyzer.showObjectInfo(objectInfos, ProcessedImageL);//在左视图上面叠加轮廓识别的框
	m_ObjectDistance = objectInfos[0].distance; 
	m_ObjectDistance = (int)(m_ObjectDistance * 10000) / 10000.;
	m_ObjectDistance = -16 * m_ObjectDistance;//这个16倍是精度的核心问题
	//向界面上写下距离数值
	CString DIS;
	DIS.Format("%f", m_ObjectDistance);
	CPara3::getInstance()->GetDlgItem(IDC_e7ObjDist)->SetWindowText(DIS);
	F_ShowImage(ProcessedImageL, m_lfImage, IDC_PicLfCam);
	F_ShowImage(ProcessedImageR, m_riImage, IDC_PicRiCam);
	F_ShowImage(DisparityMap, m_disparity, IDC_PicSynImg);
	RangeEnable = true;      // 启用测距相关功能
}

//Ribbon->测距->主点距离(复选框)
void CMainFrame::OnChkGetdepth()
{
	// TODO:  在此添加命令处理程序代码
	rangingModel = GetDepth;
}
void CMainFrame::OnUpdateChkGetdepth(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(rangingModel == GetDepth);
}

//Ribbon->测距->两点距离(复选框)
void CMainFrame::OnChkGetlength()
{
	rangingModel = GetLength;
}
void CMainFrame::OnUpdateChkGetlength(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(rangingModel == GetLength);
}



//Ribbon->采样->拍照(按键)
void CMainFrame::OnPhotograph()
{
	// TODO:  在此添加命令处理程序代码
	KillTimer(1);
	cv::Mat frame0, frame1, img0, img1;

	// 从摄像头载入图像
	lfCam >> frame0;
	riCam >> frame1;

	if (frame0.empty() && frame1.empty()){
		DoShowOrigFrame();//若都为空,没有必要继续,直接返回即可
		return;
	}
		
	//保存图片			
	CString ImgName;
	CString TIME;
	CTime tm;

	tm = CTime::GetCurrentTime();//获取系统时间 　
	TIME = tm.Format("%m%d%H%M%S");
	if (!frame0.empty()){
		ImgName.Format(_T("%s\\拍照\\%sL.jpg"), WorkPath, TIME);
		string imgnameL(ImgName.GetBuffer());
		imwrite(imgnameL, frame0);
	}
	
	if (!frame1.empty()){
		ImgName.Format(_T("%s\\拍照\\%sR.jpg"), WorkPath, TIME);
		string imgnameR(ImgName.GetBuffer());
		imwrite(imgnameR, frame1);
	}
	ImgName.ReleaseBuffer();
	TIME.ReleaseBuffer();
	//使图像反色
	if (!frame0.empty()){
		bitwise_not(frame0, frame0);
	}
	if (!frame1.empty()){
		bitwise_not(frame1, frame1);
	}
	
	//if (lfCam.isOpened() || riCam.isOpened())
	//{
		DoShowOrigFrame();
	//}
	return;
}



//Ribbon->测距->鼠标定点(按键)
void CMainFrame::OnBnMouseon()
{
	// 准备工作
	int flag;                              
	
	moupoint.x = 5;
	moupoint.y = 5;

	vector<cv::Mat> xyzSet;
	split(pointCloud, xyzSet);
	xyzSet[2].copyTo(depth);

	switch (rangingModel)//两种测距方法分开
	{
	case GetDepth:
		cv::namedWindow("鼠标点击测距-按ESC退出", 1);
		flag = 1;
		while (flag)
		{
			imshow("鼠标点击测距-按ESC退出", DisparityMap);
			cv::setMouseCallback("鼠标点击测距-按ESC退出", On_Mouse, 0);
			if (waitKey(100) == 27){//27是ESC按键的ASCNII码
				break;//break-while
			}	
		}
		destroyWindow("鼠标点击测距-按ESC退出");
		break;//break-case
	case GetLength:
		DisparityMap2 = DisparityMap.clone();//制作视差图副本
		cv::namedWindow("鼠标点击测距-按ESC退出", 1);
		while (true)
		{
			imshow("鼠标点击测距-按ESC退出", DisparityMap2);
			cv::setMouseCallback("鼠标点击测距-按ESC退出", On_Mouse, 0);
			if (waitKey(100) == 27){
				break;//break-while
			}
		}
		destroyWindow("鼠标点击测距-按ESC退出");
		break;//break-case

		//由于两点模式需要有一些绘制工作要做,所以为了提高效率,不能使用上面的循环方法
		//1 做一个视差图的副本,这个变量应该是全局变量
		//2 显示那个副本
		//3 这里只需要循环就行了
		//4 相应坐标分析的函数中,要这样做:
			//4-1 取第一个点,用视差图原件覆盖已经叠绘过的副本,在全局副本上面划线,每次点击,五个坐标都要输出
			//4-2 去第二个点,在全局副本上划线,并计算两点的距离,把这个距离输出到距离窗口
		break;
	default:
		break;
	}
	
	
}

// 鼠标定点函数 
void CMainFrame::On_Mouse(int event, int x, int y, int flags, void *)
{
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
	{
		moupoint.x = x;
		moupoint.y = y;
		AfxGetApp()->GetMainWnd()->SendMessage(WM_USER_XYZAnalyse, 0, 0);
	}
		break;
	case CV_EVENT_LBUTTONUP:
	{
							   
	}
		break;
	}
}

//接收到坐标分析消息,本消息由On_Mouse函数发出,发出此函数的时候,mousepoint已经获取
afx_msg LRESULT CMainFrame::OnXYZAnalyse(WPARAM wParam, LPARAM lParam)
{
	//准备临时变量
	CString DIS;
	Point3f WorldPoint;
	Point3f WorldPoint2;
	float distance;//用于存储两点之间的距离
	
	if (moupoint.x > 20)//大前提
	{
		m_ObjectDistance = depth.at<float>(moupoint);
		//	m_ObjectDistance=depth.ptr<float>(moupoint.x)[moupoint.y];
		m_ObjectDistance = -16 * m_ObjectDistance;
		if (m_ObjectDistance > 0)
		{
			//无论哪种模式,这五个点的坐标都要输出
			DIS.Format("%d", moupoint.x);
			CPara3::getInstance()->GetDlgItem(IDC_EDIT_ImageX)->SetWindowText(DIS);//图片坐标X
			DIS.Format("%d", moupoint.y);
			CPara3::getInstance()->GetDlgItem(IDC_EDIT_ImageY)->SetWindowText(DIS);//图片坐标Y
			WorldPoint = (pointCloud.at<Vec3f>(moupoint));//用像点坐标做索引,从点云中取得它对应的点的世界坐标
			DIS.Format("%.2f", 16 * WorldPoint.x);
			CPara3::getInstance()->GetDlgItem(IDC_EDIT_WorldX)->SetWindowText(DIS);//世界坐标X
			DIS.Format("%.2f", 16 * WorldPoint.y);
			CPara3::getInstance()->GetDlgItem(IDC_EDIT_WorldY)->SetWindowText(DIS);//世界坐标Y
			DIS.Format("%.2f", -16 * WorldPoint.z);
			CPara3::getInstance()->GetDlgItem(IDC_EDIT_WorldZ)->SetWindowText(DIS);//世界坐标Z
			//下面是两种方法的分别处理
			switch (rangingModel)
			{
			case GetDepth:
				DIS.Format("%.3f", m_ObjectDistance);
				CPara3::getInstance()->GetDlgItem(IDC_e7ObjDist)->SetWindowText(DIS);//目标距离(主点模式下,该值为Z坐标)
				break;
			case GetLength:
				//翻牌子
				//是不是第一个点-初值必须设置为true
				IsSecondPoint = !IsSecondPoint;

				if (IsSecondPoint == false){//如果是第一个点
					// 清空视差图缓存
					DisparityMap2 = DisparityMap.clone();//清掉视差图的缓存
					// 清空界面上的距离值
					CPara3::getInstance()->GetDlgItem(IDC_e7ObjDist)->SetWindowText(_T(""));//清空目标距离
					// 划线
					line(DisparityMap2, cvPoint(moupoint.x, 0), cvPoint(moupoint.x, DisparityMap2.rows), CV_RGB(255, 255, 255));//纵线
					line(DisparityMap2, cvPoint(0, moupoint.y), cvPoint(DisparityMap2.cols, moupoint.y), CV_RGB(255, 255, 255));//横线
					// 缓存这个点的图像空间坐标
					moupoint2.x = moupoint.x;
					moupoint2.y = moupoint.y;
				}
				else//如果是第二个点
				{
					//划线
					line(DisparityMap2, cvPoint(moupoint.x, 0), cvPoint(moupoint.x, DisparityMap2.rows), CV_RGB(255, 255, 255));//纵线
					line(DisparityMap2, cvPoint(0, moupoint.y), cvPoint(DisparityMap2.cols, moupoint.y), CV_RGB(255, 255, 255));//横线
					//交点连线
					line(DisparityMap2, cvPoint(moupoint2.x, moupoint2.y), cvPoint(moupoint.x, moupoint.y), CV_RGB(255, 255, 255));//两点连线
					//算出两个点的世界坐标
					WorldPoint = (pointCloud.at<Vec3f>(moupoint));
					WorldPoint2 = (pointCloud.at<Vec3f>(moupoint2));
					//计算距离
					distance = sqrt((256 * (WorldPoint.x - WorldPoint2.x)*(WorldPoint.x - WorldPoint2.x)) +
						(256 * (WorldPoint.y - WorldPoint2.y)*(WorldPoint.y - WorldPoint2.y)) +
						(256 * (WorldPoint.z - WorldPoint2.z)*(WorldPoint.z - WorldPoint2.z)));

					DIS.Format("%.3f", distance);
					CPara3::getInstance()->GetDlgItem(IDC_e7ObjDist)->SetWindowText(DIS);
					//end of if (IsSecondPoint == false)

					break;
			default:
				break;
				}//end of switch
			}//end of if (m_ObjectDistance>0)
		}//end of if (moupoint.x>20)//大前提
	}
	return 0;
}









