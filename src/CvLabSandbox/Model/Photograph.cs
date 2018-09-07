using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CvLabSandbox.Model
{
    class Photograph : INotifyPropertyChanged
    {
        private string _pathToSaveImgs;

        public Photograph()
        {
            PathToSaveImgs = "";
        }

        public string PathToSaveImgs
        {
            get => _pathToSaveImgs;
            set
            {
                _pathToSaveImgs = value;
                PropertyChanged?.Invoke(this,new PropertyChangedEventArgs("PathToSaveImgs"));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
