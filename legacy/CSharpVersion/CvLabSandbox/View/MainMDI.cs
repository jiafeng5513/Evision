using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CvLabSandbox.Presenter;
using WeifenLuo.WinFormsUI.Docking;

namespace CvLabSandbox.View
{
    public partial class MainMDI : Form
    {
        private int childFormNumber = 0;

        public MainMDI()
        {
            InitializeComponent();
        }

        private void ShowNewForm(object sender, EventArgs e)
        {
            Form childForm = new Form();
            childForm.MdiParent = this;
            childForm.Text = "窗口 " + childFormNumber++;
            childForm.Show();
        }

        private void OpenFile(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            openFileDialog.Filter = "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*";
            if (openFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = openFileDialog.FileName;
            }
        }

        private void SaveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            saveFileDialog.Filter = "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*";
            if (saveFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = saveFileDialog.FileName;
            }
        }

        private void ExitToolsStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CutToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void CopyToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void PasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void ToolBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStrip.Visible = toolBarToolStripMenuItem.Checked;
        }

        private void StatusBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            statusStrip.Visible = statusBarToolStripMenuItem.Checked;
        }

        private void CascadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }

        private void TileVerticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void TileHorizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void ArrangeIconsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.ArrangeIcons);
        }

        private void CloseAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form childForm in MdiChildren)
            {
                childForm.Close();
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            //MainForm mainForm=new MainForm();
            //mainForm.MdiParent = this;
            //mainForm.Show();
            DoubleCaptureView temDoubleCaptureView = new DoubleCaptureView();
            //temDoubleCaptureView.MdiParent = this;


            DoubleCaptureControlPanel _captureControlPanel = new DoubleCaptureControlPanel();
            //_captureControlPanel.MdiParent = this;


            DoubleCapturePresenter presenter = new DoubleCapturePresenter();
            presenter.InjectViews(ref _captureControlPanel, ref temDoubleCaptureView);


            //temDoubleCaptureView.Show();Show(this.dockPanel, DockState.DockLeft)
            temDoubleCaptureView.Show(this.MaindockPanel);
            _captureControlPanel.Show(this.MaindockPanel);
            LayoutMdi(MdiLayout.TileHorizontal);
        }
        /// <summary>
        /// 主界面加载
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MainMDI_Load(object sender, EventArgs e)
        {
            StartUpView startUpView = new StartUpView();
            
            startUpView.Show(this.MaindockPanel,DockState.Document);
        }
    }
}
