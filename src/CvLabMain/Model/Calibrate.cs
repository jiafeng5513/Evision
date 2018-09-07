using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CvLabMain.Model
{
    class Calibrate : INotifyPropertyChanged
    {
        private int _rows;
        private int _columns;
        private int _numOfImages;
        private int _sizeOfSquare;

        public Calibrate()
        {
            this.Rows = 6;
            this.Columns = 9;
            this._numOfImages = 20;
            this._sizeOfSquare = 25;
        }

        public int Rows
        {
            get { return _rows; }
            set
            {
                _rows = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Rows"));
                }
            }
        }

        public int Columns
        {
            get { return _columns; }
            set
            {
                _columns = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Columns"));
                }
            }
        }

        public int NumOfImages
        {
            get { return _numOfImages; }
            set
            {
                _numOfImages = value;
                if (this.PropertyChanged!= null)
                {
                    this.PropertyChanged.Invoke(this,new PropertyChangedEventArgs("NumOfImages"));
                }
            }
        }

        public int SizeOfSquare
        {
            get { return _sizeOfSquare; }
            set
            {
                _sizeOfSquare = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("SizeOfSquare"));
                }
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
