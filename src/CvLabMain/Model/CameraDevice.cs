using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
/// <summary>
/// 硬件信息
/// </summary>
namespace CvLabMain.Model
{
    class DeviceItem : INotifyPropertyChanged
    {
        private int _index;
        private string _name;
        private string _monikerstring;
        public DeviceItem(int index, string name, string monikerstring)
        {
            Index = index;
            Name = index.ToString() + "--" + (name);
            Monikerstring = monikerstring;
        }
        public int Index {
            get { return _index; }
            set
            {
                _index = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Index"));
            }
        }
        public string Name {
            get { return _name; }
            set
            {
                _name = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Name"));
            }
        }
        public string Monikerstring {
            get { return _monikerstring; }
            set
            {
                _monikerstring = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Monikerstring"));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }

    class CameraDevice: INotifyPropertyChanged
    {
        private Dictionary<int,DeviceItem> _DeviceList_L;
        private Dictionary<int,DeviceItem> _DeviceList_R;

        public CameraDevice(List<DeviceItem> DeviceList)
        {
            DeviceList_L = new Dictionary<int, DeviceItem>();
            DeviceList_R = new Dictionary<int, DeviceItem>();
            for (int i = 0; i < DeviceList.Count; i++)
            {
                DeviceList_L.Add(DeviceList[i].Index, DeviceList[i]);
                DeviceList_R.Add(DeviceList[i].Index, DeviceList[i]);
            }
        }

        public void CameraDeviceRefresh(List<DeviceItem> DeviceList)
        {
            DeviceList_L.Clear();
            DeviceList_R.Clear();
            for (int i = 0; i < DeviceList.Count; i++)
            {
                DeviceList_L.Add(DeviceList[i].Index, DeviceList[i]);
                DeviceList_R.Add(DeviceList[i].Index, DeviceList[i]);
            }
        }
        public Dictionary<int, DeviceItem> DeviceList_L
        {
            get { return _DeviceList_L; }
            set
            {
                _DeviceList_L = value;
                if (PropertyChanged != null)
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("DeviceList_L"));
            }
        }
        public Dictionary<int, DeviceItem> DeviceList_R
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
