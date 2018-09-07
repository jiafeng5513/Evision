using System.Windows;
using CvLabMain.ViewModel;
using Emgu.CV;

namespace CvLabMain.View
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = new CvLabViewModel();
            LBox.Image = CvInvoke.Imread("F:\\cj.jpg");
            RBox.Image = CvInvoke.Imread("F:\\cj.jpg");
        }
    }
}
