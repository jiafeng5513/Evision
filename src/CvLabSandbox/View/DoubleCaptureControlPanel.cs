using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CvLabSandbox.Model;
using CvLabSandbox.Presenter;
using WeifenLuo.WinFormsUI.Docking;

namespace CvLabSandbox.View
{
    public partial class DoubleCaptureControlPanel : DockContent
    {
        private DoubleCapturePresenter _presenter;
        public DoubleCaptureControlPanel()
        {
            InitializeComponent();
        }

        internal DoubleCapturePresenter Presenter
        {
            get => _presenter;
            set
            {
                _presenter = value;
                textBox_NumOfColumns.DataBindings.Add("Text", _presenter._ChessBoard, "BoardColumns", false,
                    DataSourceUpdateMode.OnPropertyChanged);
                textBox_NumOfRows.DataBindings.Add("Text", _presenter._ChessBoard, "BoardRows", false,
                    DataSourceUpdateMode.OnPropertyChanged);
                textBox_NumOfImage.DataBindings.Add("Text", _presenter._ChessBoard, "NImages", false,
                    DataSourceUpdateMode.OnPropertyChanged);
                textBox_SquareSize.DataBindings.Add("Text", _presenter._ChessBoard, "SquareWidth", false,
                    DataSourceUpdateMode.OnPropertyChanged);
                
                comboBox_LCam.DataBindings.Add("DataSource", _presenter.m_cameraDevice, "DeviceList_L",
                    false,
                    DataSourceUpdateMode.OnPropertyChanged);
                comboBox_LCam.DisplayMember = "Name";
                comboBox_RCam.DataBindings.Add("DataSource", _presenter.m_cameraDevice, "DeviceList_R",
                    false,
                    DataSourceUpdateMode.OnPropertyChanged);
                comboBox_RCam.DisplayMember = "Name";

                textBox_ImgSavePath.DataBindings.Add("Text", _presenter._Photograph, "PathToSaveImgs", 
                    false,DataSourceUpdateMode.OnPropertyChanged);

                comboBox_LCam.SelectedIndexChanged += ComboBox_LCam_SelectedIndexChanged;
                comboBox_RCam.SelectedIndexChanged += ComboBox_RCam_SelectedIndexChanged;

                button_Power.Click += _presenter.CameraSwitch;
                button_RefreshCamera.Click += _presenter.CameraRefresh;
                button_releaseCamera.Click += _presenter.CameraRelease;
                button_DefaultCalibParam.Click += _presenter.DefaultParams;
                button_Calib.Click += _presenter.Calibrate;
                button_3DReconstruction.Click += _presenter.Reconstruction;
                button_ListDevices.Click += _presenter.ListDevice;
                button_Browser.Click += _presenter.BrowserPathToSaveImgs;
                button_shot.Click += _presenter.TakePhotos;
            }
        }        
        
        //左摄像头选项发生变化,CaptureCapability换绑,实现联动
        private void ComboBox_LCam_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox_lCapability.DataBindings.Clear();
            comboBox_lCapability.DataBindings.Add("DataSource", _presenter.m_cameraDevice.DeviceList_L[comboBox_LCam.SelectedIndex], "VideoCapabilities",
                false, DataSourceUpdateMode.OnPropertyChanged);
            comboBox_lCapability.DisplayMember = "Describe";
        }

        //右摄像头发生变化,CaptureCapability换绑,实现联动
        private void ComboBox_RCam_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox_rCapability.DataBindings.Clear();
            comboBox_rCapability.DataBindings.Add("DataSource", _presenter.m_cameraDevice.DeviceList_R[comboBox_RCam.SelectedIndex], "VideoCapabilities",
                false, DataSourceUpdateMode.OnPropertyChanged);
            comboBox_rCapability.DisplayMember = "Describe";
        }

        private void DoubleCaptureControlPanel_Load(object sender, EventArgs e)
        {

        }
    }
}
