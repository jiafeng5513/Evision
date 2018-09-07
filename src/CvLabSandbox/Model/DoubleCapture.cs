using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Emgu.CV;

namespace CvLabSandbox.Model
{
    /// <summary>
    /// 双镜头画面的Model
    /// </summary>
    class DoubleCapture : INotifyPropertyChanged
    {
        private Mat _imgL;
        private Mat _imgR;

        public DoubleCapture()
        {
            ImgL = new Mat();
            ImgR = new Mat();
        }

        public Mat ImgL
        {
            get => _imgL;
            set
            {
                _imgL = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("ImgL"));
            }
        }

        public Mat ImgR
        {
            get => _imgR;
            set
            {
                _imgR = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("ImgR"));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
