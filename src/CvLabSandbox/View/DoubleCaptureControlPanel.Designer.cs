namespace CvLabSandbox.View
{
    partial class DoubleCaptureControlPanel
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
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox_LCam = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.comboBox_RCam = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.comboBox_lCapability = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.comboBox_rCapability = new System.Windows.Forms.ComboBox();
            this.button_ListDevices = new System.Windows.Forms.Button();
            this.button_RefreshCamera = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_NumOfRows = new System.Windows.Forms.TextBox();
            this.NumOfColumns = new System.Windows.Forms.Label();
            this.textBox_NumOfColumns = new System.Windows.Forms.TextBox();
            this.NumOfImages = new System.Windows.Forms.Label();
            this.textBox_NumOfImage = new System.Windows.Forms.TextBox();
            this.SquareSize = new System.Windows.Forms.Label();
            this.textBox_SquareSize = new System.Windows.Forms.TextBox();
            this.button_DefaultCalibParam = new System.Windows.Forms.Button();
            this.button_Calib = new System.Windows.Forms.Button();
            this.button_3DReconstruction = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.radioButton_SaveLeftOnly = new System.Windows.Forms.RadioButton();
            this.button_Browser = new System.Windows.Forms.Button();
            this.radioButton_saveDoubleCapture = new System.Windows.Forms.RadioButton();
            this.button_shot = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox_ImgSavePath = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.button_Power = new System.Windows.Forms.Button();
            this.button_releaseCamera = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(4, 6);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(95, 15);
            this.label1.TabIndex = 8;
            this.label1.Text = "lCamera    ";
            // 
            // comboBox_LCam
            // 
            this.comboBox_LCam.Dock = System.Windows.Forms.DockStyle.Fill;
            this.comboBox_LCam.FormattingEnabled = true;
            this.comboBox_LCam.Location = new System.Drawing.Point(126, 4);
            this.comboBox_LCam.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.comboBox_LCam.Name = "comboBox_LCam";
            this.comboBox_LCam.Size = new System.Drawing.Size(279, 23);
            this.comboBox_LCam.TabIndex = 7;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(4, 62);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(95, 15);
            this.label2.TabIndex = 9;
            this.label2.Text = "rCamera    ";
            // 
            // comboBox_RCam
            // 
            this.comboBox_RCam.Dock = System.Windows.Forms.DockStyle.Fill;
            this.comboBox_RCam.FormattingEnabled = true;
            this.comboBox_RCam.Location = new System.Drawing.Point(126, 60);
            this.comboBox_RCam.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.comboBox_RCam.Name = "comboBox_RCam";
            this.comboBox_RCam.Size = new System.Drawing.Size(279, 23);
            this.comboBox_RCam.TabIndex = 10;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(4, 118);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(95, 15);
            this.label4.TabIndex = 16;
            this.label4.Text = "lCapability";
            // 
            // comboBox_lCapability
            // 
            this.comboBox_lCapability.Dock = System.Windows.Forms.DockStyle.Fill;
            this.comboBox_lCapability.FormattingEnabled = true;
            this.comboBox_lCapability.Location = new System.Drawing.Point(126, 116);
            this.comboBox_lCapability.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.comboBox_lCapability.Name = "comboBox_lCapability";
            this.comboBox_lCapability.Size = new System.Drawing.Size(279, 23);
            this.comboBox_lCapability.TabIndex = 15;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(4, 174);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(95, 15);
            this.label5.TabIndex = 17;
            this.label5.Text = "rCapability";
            // 
            // comboBox_rCapability
            // 
            this.comboBox_rCapability.Dock = System.Windows.Forms.DockStyle.Fill;
            this.comboBox_rCapability.FormattingEnabled = true;
            this.comboBox_rCapability.Location = new System.Drawing.Point(126, 172);
            this.comboBox_rCapability.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.comboBox_rCapability.Name = "comboBox_rCapability";
            this.comboBox_rCapability.Size = new System.Drawing.Size(279, 23);
            this.comboBox_rCapability.TabIndex = 18;
            // 
            // button_ListDevices
            // 
            this.button_ListDevices.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_ListDevices.Location = new System.Drawing.Point(4, 87);
            this.button_ListDevices.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_ListDevices.Name = "button_ListDevices";
            this.button_ListDevices.Size = new System.Drawing.Size(196, 75);
            this.button_ListDevices.TabIndex = 12;
            this.button_ListDevices.Text = "ListDevices";
            this.button_ListDevices.UseVisualStyleBackColor = true;
            // 
            // button_RefreshCamera
            // 
            this.button_RefreshCamera.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_RefreshCamera.Location = new System.Drawing.Point(207, 85);
            this.button_RefreshCamera.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_RefreshCamera.Name = "button_RefreshCamera";
            this.button_RefreshCamera.Size = new System.Drawing.Size(199, 79);
            this.button_RefreshCamera.TabIndex = 14;
            this.button_RefreshCamera.Text = "Refresh Camera";
            this.button_RefreshCamera.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(4, 286);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(111, 30);
            this.label3.TabIndex = 0;
            this.label3.Text = "Num of rows:   ";
            // 
            // textBox_NumOfRows
            // 
            this.textBox_NumOfRows.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox_NumOfRows.Location = new System.Drawing.Point(126, 284);
            this.textBox_NumOfRows.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox_NumOfRows.Name = "textBox_NumOfRows";
            this.textBox_NumOfRows.Size = new System.Drawing.Size(279, 25);
            this.textBox_NumOfRows.TabIndex = 1;
            // 
            // NumOfColumns
            // 
            this.NumOfColumns.AutoSize = true;
            this.NumOfColumns.Location = new System.Drawing.Point(4, 342);
            this.NumOfColumns.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.NumOfColumns.Name = "NumOfColumns";
            this.NumOfColumns.Size = new System.Drawing.Size(71, 30);
            this.NumOfColumns.TabIndex = 2;
            this.NumOfColumns.Text = "Num of Columns:";
            // 
            // textBox_NumOfColumns
            // 
            this.textBox_NumOfColumns.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox_NumOfColumns.Location = new System.Drawing.Point(126, 340);
            this.textBox_NumOfColumns.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox_NumOfColumns.Name = "textBox_NumOfColumns";
            this.textBox_NumOfColumns.Size = new System.Drawing.Size(279, 25);
            this.textBox_NumOfColumns.TabIndex = 3;
            // 
            // NumOfImages
            // 
            this.NumOfImages.AutoSize = true;
            this.NumOfImages.Location = new System.Drawing.Point(4, 398);
            this.NumOfImages.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.NumOfImages.Name = "NumOfImages";
            this.NumOfImages.Size = new System.Drawing.Size(71, 30);
            this.NumOfImages.TabIndex = 4;
            this.NumOfImages.Text = "Num of Images: ";
            // 
            // textBox_NumOfImage
            // 
            this.textBox_NumOfImage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox_NumOfImage.Location = new System.Drawing.Point(126, 396);
            this.textBox_NumOfImage.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox_NumOfImage.Name = "textBox_NumOfImage";
            this.textBox_NumOfImage.Size = new System.Drawing.Size(279, 25);
            this.textBox_NumOfImage.TabIndex = 5;
            // 
            // SquareSize
            // 
            this.SquareSize.AutoSize = true;
            this.SquareSize.Location = new System.Drawing.Point(4, 454);
            this.SquareSize.Margin = new System.Windows.Forms.Padding(4, 6, 4, 0);
            this.SquareSize.Name = "SquareSize";
            this.SquareSize.Padding = new System.Windows.Forms.Padding(0, 6, 0, 0);
            this.SquareSize.Size = new System.Drawing.Size(111, 36);
            this.SquareSize.TabIndex = 6;
            this.SquareSize.Text = "Square Size:   ";
            // 
            // textBox_SquareSize
            // 
            this.textBox_SquareSize.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox_SquareSize.Location = new System.Drawing.Point(126, 452);
            this.textBox_SquareSize.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox_SquareSize.Name = "textBox_SquareSize";
            this.textBox_SquareSize.Size = new System.Drawing.Size(279, 25);
            this.textBox_SquareSize.TabIndex = 7;
            // 
            // button_DefaultCalibParam
            // 
            this.button_DefaultCalibParam.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_DefaultCalibParam.Location = new System.Drawing.Point(4, 253);
            this.button_DefaultCalibParam.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_DefaultCalibParam.Name = "button_DefaultCalibParam";
            this.button_DefaultCalibParam.Size = new System.Drawing.Size(196, 75);
            this.button_DefaultCalibParam.TabIndex = 10;
            this.button_DefaultCalibParam.Text = "Default Params";
            this.button_DefaultCalibParam.UseVisualStyleBackColor = true;
            // 
            // button_Calib
            // 
            this.button_Calib.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_Calib.Location = new System.Drawing.Point(208, 253);
            this.button_Calib.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_Calib.Name = "button_Calib";
            this.button_Calib.Size = new System.Drawing.Size(197, 75);
            this.button_Calib.TabIndex = 9;
            this.button_Calib.Text = "Calibrate";
            this.button_Calib.UseVisualStyleBackColor = true;
            // 
            // button_3DReconstruction
            // 
            this.button_3DReconstruction.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_3DReconstruction.Location = new System.Drawing.Point(3, 334);
            this.button_3DReconstruction.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button_3DReconstruction.MinimumSize = new System.Drawing.Size(149, 0);
            this.button_3DReconstruction.Name = "button_3DReconstruction";
            this.button_3DReconstruction.Size = new System.Drawing.Size(198, 79);
            this.button_3DReconstruction.TabIndex = 2;
            this.button_3DReconstruction.Text = "3DReconstruction";
            this.button_3DReconstruction.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button1.Location = new System.Drawing.Point(207, 334);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.MinimumSize = new System.Drawing.Size(149, 0);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(199, 79);
            this.button1.TabIndex = 3;
            this.button1.Text = "Measure In Img";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // radioButton_SaveLeftOnly
            // 
            this.radioButton_SaveLeftOnly.AutoSize = true;
            this.radioButton_SaveLeftOnly.Dock = System.Windows.Forms.DockStyle.Fill;
            this.radioButton_SaveLeftOnly.Location = new System.Drawing.Point(4, 419);
            this.radioButton_SaveLeftOnly.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButton_SaveLeftOnly.Name = "radioButton_SaveLeftOnly";
            this.radioButton_SaveLeftOnly.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.radioButton_SaveLeftOnly.Size = new System.Drawing.Size(196, 77);
            this.radioButton_SaveLeftOnly.TabIndex = 3;
            this.radioButton_SaveLeftOnly.TabStop = true;
            this.radioButton_SaveLeftOnly.Text = "SaveLeftCaptureOnly";
            this.radioButton_SaveLeftOnly.UseVisualStyleBackColor = true;
            // 
            // button_Browser
            // 
            this.button_Browser.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_Browser.Location = new System.Drawing.Point(4, 170);
            this.button_Browser.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_Browser.Name = "button_Browser";
            this.button_Browser.Size = new System.Drawing.Size(196, 75);
            this.button_Browser.TabIndex = 2;
            this.button_Browser.Text = "browse";
            this.button_Browser.UseVisualStyleBackColor = true;
            // 
            // radioButton_saveDoubleCapture
            // 
            this.radioButton_saveDoubleCapture.AutoSize = true;
            this.radioButton_saveDoubleCapture.Dock = System.Windows.Forms.DockStyle.Fill;
            this.radioButton_saveDoubleCapture.Location = new System.Drawing.Point(208, 419);
            this.radioButton_saveDoubleCapture.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButton_saveDoubleCapture.Name = "radioButton_saveDoubleCapture";
            this.radioButton_saveDoubleCapture.Size = new System.Drawing.Size(197, 77);
            this.radioButton_saveDoubleCapture.TabIndex = 4;
            this.radioButton_saveDoubleCapture.TabStop = true;
            this.radioButton_saveDoubleCapture.Text = "SaveDoubleCapture  ";
            this.radioButton_saveDoubleCapture.UseVisualStyleBackColor = true;
            // 
            // button_shot
            // 
            this.button_shot.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_shot.Location = new System.Drawing.Point(208, 170);
            this.button_shot.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_shot.Name = "button_shot";
            this.button_shot.Size = new System.Drawing.Size(197, 75);
            this.button_shot.TabIndex = 5;
            this.button_shot.Text = "shot";
            this.button_shot.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(4, 234);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 10, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(63, 15);
            this.label6.TabIndex = 0;
            this.label6.Text = "SaveTo:";
            // 
            // textBox_ImgSavePath
            // 
            this.textBox_ImgSavePath.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox_ImgSavePath.Location = new System.Drawing.Point(126, 228);
            this.textBox_ImgSavePath.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox_ImgSavePath.Name = "textBox_ImgSavePath";
            this.textBox_ImgSavePath.Size = new System.Drawing.Size(279, 25);
            this.textBox_ImgSavePath.TabIndex = 1;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 70F));
            this.tableLayoutPanel2.Controls.Add(this.textBox_SquareSize, 1, 8);
            this.tableLayoutPanel2.Controls.Add(this.textBox_NumOfImage, 1, 7);
            this.tableLayoutPanel2.Controls.Add(this.SquareSize, 0, 8);
            this.tableLayoutPanel2.Controls.Add(this.textBox_NumOfColumns, 1, 6);
            this.tableLayoutPanel2.Controls.Add(this.NumOfImages, 0, 7);
            this.tableLayoutPanel2.Controls.Add(this.NumOfColumns, 0, 6);
            this.tableLayoutPanel2.Controls.Add(this.textBox_NumOfRows, 1, 5);
            this.tableLayoutPanel2.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.textBox_ImgSavePath, 1, 4);
            this.tableLayoutPanel2.Controls.Add(this.comboBox_LCam, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.label6, 0, 4);
            this.tableLayoutPanel2.Controls.Add(this.comboBox_rCapability, 1, 3);
            this.tableLayoutPanel2.Controls.Add(this.comboBox_RCam, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.label4, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.label5, 0, 3);
            this.tableLayoutPanel2.Controls.Add(this.comboBox_lCapability, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.label3, 0, 5);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel2.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 9;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.11F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 11.12F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(409, 505);
            this.tableLayoutPanel2.TabIndex = 19;
            // 
            // button_Power
            // 
            this.button_Power.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_Power.Location = new System.Drawing.Point(4, 4);
            this.button_Power.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_Power.Name = "button_Power";
            this.button_Power.Size = new System.Drawing.Size(196, 75);
            this.button_Power.TabIndex = 20;
            this.button_Power.Text = "Camera Switch";
            this.button_Power.UseVisualStyleBackColor = true;
            // 
            // button_releaseCamera
            // 
            this.button_releaseCamera.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button_releaseCamera.Location = new System.Drawing.Point(208, 4);
            this.button_releaseCamera.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button_releaseCamera.Name = "button_releaseCamera";
            this.button_releaseCamera.Size = new System.Drawing.Size(197, 75);
            this.button_releaseCamera.TabIndex = 21;
            this.button_releaseCamera.Text = "Release Camera";
            this.button_releaseCamera.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.button_Power, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.button_shot, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.radioButton_saveDoubleCapture, 1, 5);
            this.tableLayoutPanel1.Controls.Add(this.radioButton_SaveLeftOnly, 0, 5);
            this.tableLayoutPanel1.Controls.Add(this.button_releaseCamera, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.button_ListDevices, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.button1, 1, 4);
            this.tableLayoutPanel1.Controls.Add(this.button_Browser, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.button_3DReconstruction, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.button_RefreshCamera, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.button_DefaultCalibParam, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.button_Calib, 1, 3);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 6;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.67F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.67F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.67F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.67F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.67F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 16.65F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(409, 500);
            this.tableLayoutPanel1.TabIndex = 22;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.tableLayoutPanel2);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.tableLayoutPanel1);
            this.splitContainer1.Size = new System.Drawing.Size(409, 1010);
            this.splitContainer1.SplitterDistance = 505;
            this.splitContainer1.SplitterWidth = 5;
            this.splitContainer1.TabIndex = 24;
            // 
            // DoubleCaptureControlPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(409, 1010);
            this.Controls.Add(this.splitContainer1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.HideOnClose = true;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MaximizeBox = false;
            this.Name = "DoubleCaptureControlPanel";
            this.ShowHint = WeifenLuo.WinFormsUI.Docking.DockState.DockLeft;
            this.TabText = "DoubleCaptureControlPanel";
            this.Text = "DoubleCaptureControlPanel";
            this.Load += new System.EventHandler(this.DoubleCaptureControlPanel_Load);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button_ListDevices;
        private System.Windows.Forms.Button button_RefreshCamera;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_NumOfRows;
        private System.Windows.Forms.Label NumOfColumns;
        private System.Windows.Forms.TextBox textBox_NumOfColumns;
        private System.Windows.Forms.Label NumOfImages;
        private System.Windows.Forms.TextBox textBox_NumOfImage;
        private System.Windows.Forms.Label SquareSize;
        private System.Windows.Forms.TextBox textBox_SquareSize;
        private System.Windows.Forms.Button button_DefaultCalibParam;
        private System.Windows.Forms.Button button_Calib;
        private System.Windows.Forms.Button button_3DReconstruction;
        private System.Windows.Forms.Button button1;
        public System.Windows.Forms.ComboBox comboBox_LCam;
        public System.Windows.Forms.ComboBox comboBox_RCam;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        public System.Windows.Forms.ComboBox comboBox_lCapability;
        public System.Windows.Forms.ComboBox comboBox_rCapability;
        private System.Windows.Forms.Button button_Browser;
        public System.Windows.Forms.RadioButton radioButton_SaveLeftOnly;
        public System.Windows.Forms.RadioButton radioButton_saveDoubleCapture;
        private System.Windows.Forms.Button button_shot;
        private System.Windows.Forms.TextBox textBox_ImgSavePath;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Button button_Power;
        private System.Windows.Forms.Button button_releaseCamera;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.SplitContainer splitContainer1;
    }
}