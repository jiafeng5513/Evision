using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CCWin.SkinControl;
using CvLabSandbox.Presenter;
using Emgu.CV;
using Emgu.CV.UI;
using WeifenLuo.WinFormsUI.Docking;

namespace CvLabSandbox.View
{
    public partial class DoubleCaptureView : DockContent
    {
        private DoubleCapturePresenter _presenter;
        public DoubleCaptureView()
        {
            InitializeComponent();
            imageBoxL.SizeMode = PictureBoxSizeMode.Zoom;
            imageBoxR.SizeMode = PictureBoxSizeMode.Zoom;
        }

        internal DoubleCapturePresenter Presenter
        {
            get => _presenter;
            set
            {
                _presenter = value;
                imageBoxL.DataBindings.Add("Image", _presenter._DoubleCapture, "ImgL", true, DataSourceUpdateMode.OnPropertyChanged);
                imageBoxR.DataBindings.Add("Image", _presenter._DoubleCapture, "ImgR", true, DataSourceUpdateMode.OnPropertyChanged);
            }
        }
    }
}
