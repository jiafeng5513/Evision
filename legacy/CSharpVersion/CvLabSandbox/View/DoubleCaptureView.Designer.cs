namespace CvLabSandbox.View
{
    partial class DoubleCaptureView
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.imageBoxR = new Emgu.CV.UI.ImageBox();
            this.imageBoxL = new Emgu.CV.UI.ImageBox();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.imageBoxR)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imageBoxL)).BeginInit();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.imageBoxR, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.imageBoxL, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(974, 369);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // imageBoxR
            // 
            this.imageBoxR.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.imageBoxR.Dock = System.Windows.Forms.DockStyle.Fill;
            this.imageBoxR.Location = new System.Drawing.Point(490, 3);
            this.imageBoxR.Name = "imageBoxR";
            this.imageBoxR.Size = new System.Drawing.Size(481, 363);
            this.imageBoxR.TabIndex = 4;
            this.imageBoxR.TabStop = false;
            // 
            // imageBoxL
            // 
            this.imageBoxL.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.imageBoxL.Dock = System.Windows.Forms.DockStyle.Fill;
            this.imageBoxL.Location = new System.Drawing.Point(3, 3);
            this.imageBoxL.Name = "imageBoxL";
            this.imageBoxL.Size = new System.Drawing.Size(481, 363);
            this.imageBoxL.TabIndex = 3;
            this.imageBoxL.TabStop = false;
            // 
            // DoubleCaptureView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(974, 369);
            this.Controls.Add(this.tableLayoutPanel1);
            this.HideOnClose = true;
            this.Name = "DoubleCaptureView";
            this.ShowHint = WeifenLuo.WinFormsUI.Docking.DockState.Document;
            this.TabText = "DoubleCaptureView";
            this.Text = "DoubleCaptureView";
            this.tableLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.imageBoxR)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imageBoxL)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private Emgu.CV.UI.ImageBox imageBoxR;
        private Emgu.CV.UI.ImageBox imageBoxL;
    }
}