using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Runtime.InteropServices.ComTypes;
using AForge.Video.DirectShow;
using CCWin.Win32;
using Emgu;
namespace CvLabSandbox.Model
{
    /// <summary>
    /// 描述摄像机的性能,每种相机都有可能具备多种性能模式,对应不同的分辨率和帧率
    /// </summary>
    class CaptureCapability : INotifyPropertyChanged
    {
        private int _averageFrameRate;
        private Size _frameSize;
        private int _bitCount;
        private int _maximumFrameRate;
        private string _describe;

        public CaptureCapability(VideoCapabilities Capabilities)
        {
            _averageFrameRate = Capabilities.AverageFrameRate;
            _frameSize = Capabilities.FrameSize;
            _bitCount = Capabilities.BitCount;
            _maximumFrameRate = Capabilities.MaximumFrameRate;
            Describe = _frameSize.Width + "×"+_frameSize.Height+"  "+ _averageFrameRate+" "+_maximumFrameRate+" "+_bitCount;
        }

        public string Describe
        {
            get => _describe;
            set
            {
                _describe = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("Describe"));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }



    /// <summary>
    /// 描述一个相机设备
    /// 相机设备由ID,名称,绰号,性能类来标识
    /// 
    /// 对于用户来说,ID+名称即可唯一标识一台设备
    /// 对于系统来说,绰号可以唯一标识一台设备并以特定的性能来启动对应的设备
    /// </summary>
    class DeviceItem : INotifyPropertyChanged
    {
        private int _index;
        private string _name;
        private string _monikerstring;

        private List<CaptureCapability> _VideoCapabilities;

        public DeviceItem(int index, string name, string monikerstring)
        {
            Index = index;
            Name = index.ToString() + "--" + (name);
            Monikerstring = monikerstring;
            VideoCapabilities=new List<CaptureCapability>();
            VideoCaptureDevice capture = new VideoCaptureDevice(monikerstring);
            for (int i = 0; i < capture.VideoCapabilities.Length; i++)
            {
                VideoCapabilities.Add(new CaptureCapability(capture.VideoCapabilities[i]));
            }
        }
        public int Index
        {
            get { return _index; }
            set
            {
                _index = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Index"));
            }
        }
        public string Name
        {
            get { return _name; }
            set
            {
                _name = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Name"));
            }
        }
        public string Monikerstring
        {
            get { return _monikerstring; }
            set
            {
                _monikerstring = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Monikerstring"));
            }
        }

        public List<CaptureCapability> VideoCapabilities
        {
            get => _VideoCapabilities;
            set
            {
                _VideoCapabilities = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("VideoCapabilities"));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }


    /// <summary>
    /// 描述电脑上能查询到的所有的摄像机设备,用两个列表分表提供给左右两个摄像机
    /// </summary>
    class CameraDevice : INotifyPropertyChanged
    {
        private List<DeviceItem> _DeviceList_L;
        private List<DeviceItem> _DeviceList_R;


        public CameraDevice(List<DeviceItem> DeviceList)
        {
            DeviceList_L = new List<DeviceItem>();
            DeviceList_R = new List<DeviceItem>();

            for (int i = 0; i < DeviceList.Count; i++)
            {
                DeviceList_L.Add(DeviceList[i]);
                DeviceList_R.Add(DeviceList[i]);
               

            }
        }

        public void CameraDeviceRefresh(List<DeviceItem> DeviceList)
        {
            DeviceList_L.Clear();
            DeviceList_R.Clear();
            for (int i = 0; i < DeviceList.Count; i++)
            {
                DeviceList_L.Add(DeviceList[i]);
                DeviceList_R.Add(DeviceList[i]);
            }
        }
        public List<DeviceItem> DeviceList_L
        {
            get { return _DeviceList_L; }
            set
            {
                _DeviceList_L = value;
                if (PropertyChanged != null)
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("DeviceList_L"));
            }
        }
        public List<DeviceItem> DeviceList_R
        {
            get { return _DeviceList_R; }
            set
            {
                _DeviceList_R = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("DeviceList_R"));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
