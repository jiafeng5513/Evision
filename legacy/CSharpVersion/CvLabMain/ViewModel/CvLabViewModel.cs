using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using CvLabMain.Model;
using Emgu.CV;
using Emgu.CV.CvEnum;
using Emgu.CV.Structure;
using Emgu.Util;
using AForge.Video.DirectShow;

namespace CvLabMain.ViewModel
{
    class CvLabViewModel
    {
        /// <summary>
        /// command
        /// </summary>
        public DelegateCommand SwitchCameraCommand { get; set; }
        public DelegateCommand RefreshCameraCommand { get; set; }
        public DelegateCommand ReleaseCameraCommand { get; set; }
        public DelegateCommand DefaultCalibParaCommand { get; set; }
        public DelegateCommand DoCalibrateCommand { get; set; }
        /// <summary>
        /// 数据model
        /// </summary>
        public Calibrate m_calibrate { get; set; }
        public CameraDevice m_cameraDevice { get; set; }

        /// <summary>
        /// 构造函数
        /// </summary>
        public CvLabViewModel()
        {
            SwitchCameraCommand = new DelegateCommand();
            SwitchCameraCommand.ExecuteCommand = new Action<object>(SwitchCameraAction);
            RefreshCameraCommand = new DelegateCommand();
            RefreshCameraCommand.ExecuteCommand = new Action<object>(RefreshCameraAction);
            ReleaseCameraCommand = new DelegateCommand();
            ReleaseCameraCommand.ExecuteCommand = new Action<object>(ReleaseCameraAction);
            DefaultCalibParaCommand = new DelegateCommand();
            DefaultCalibParaCommand.ExecuteCommand = new Action<object>(DefaultCalibParaActioon);
            DoCalibrateCommand = new DelegateCommand();
            DoCalibrateCommand.ExecuteCommand = new Action<object>(DoCalibrateAction);
            m_calibrate = new Calibrate();

            RefreshCamera();
            
        }
        /// <summary>
        /// 相机的开关
        /// </summary>
        /// <param name="obj"></param>
        private void SwitchCameraAction(object obj)
        {
            //MessageBox.Show("SwitchCameraAction");
            m_calibrate.Rows++;
            m_calibrate.Columns++;
            m_calibrate.NumOfImages++;
            m_calibrate.SizeOfSquare++;
        }

        void RefreshCamera()
        {
            FilterInfoCollection videoDevicesnew = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            List<DeviceItem> deviceList = new List<DeviceItem>();
            for (int i = 0; i < videoDevicesnew.Count; i++)
            {
                deviceList.Add(new DeviceItem(i, videoDevicesnew[i].Name, videoDevicesnew[i].MonikerString));
            }

            //if (m_cameraDevice!=null)
            //{
            //     m_cameraDevice.CameraDeviceRefresh(deviceList);//相机硬件设备列表
            //}
            //else
            //{
                m_cameraDevice=new CameraDevice(deviceList);
            //}
           
            //m_cameraDevice.DeviceList_L
        }
        /// <summary>
        /// 刷新相机
        /// </summary>
        /// <param name="obj"></param>
        private void RefreshCameraAction(object obj)
        {
            RefreshCamera();
            MessageBox.Show("相机数量更新:"+m_cameraDevice.DeviceList_L.Count);
        }
        /// <summary>
        /// 释放相机
        /// </summary>
        /// <param name="obj"></param>
        private void ReleaseCameraAction(object obj)
        {
            MessageBox.Show("ReleaseCameraAction");
        }
        /// <summary>
        /// 默认标定参数
        /// </summary>
        /// <param name="obj"></param>
        private void DefaultCalibParaActioon(object obj)
        {
            MessageBox.Show("DefaultCalibParaActioon");
        }
        /// <summary>
        /// 进行标定
        /// </summary>
        /// <param name="obj"></param>
        private void DoCalibrateAction(object obj)
        {
            MessageBox.Show("DoCalibrateAction");
        }
    }
}
