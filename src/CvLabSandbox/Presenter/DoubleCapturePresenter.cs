using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using AForge.Video.DirectShow;
using CCWin.SkinControl;
using CvLabSandbox.Model;
using CvLabSandbox.Properties;
using CvLabSandbox.utils;
using CvLabSandbox.View;
using Emgu.CV;
using Emgu.CV.CvEnum;
using Emgu.CV.Structure;
using Emgu.CV.Util;

namespace CvLabSandbox.Presenter
{
    class DoubleCapturePresenter
    {

        private int _nPoints;			  // 棋盘角点总数
        //private Size _boardSize;		  // 棋盘尺寸
        //private int _nImages;			  // 棋盘图像数
        private int _nPointsPerImage;	  // 每幅棋盘的角点数
        private Size _imageSize;	      // 图像分辨率
        private List<MCvPoint3D32f[]> _objectPoints;	      // 棋盘角点世界坐标序列
        private List<PointF[]> _imagePointsL;	      // 左视图的棋盘角点像素坐标序列
        private List<PointF[]> _imagePointsR;	      // 右视图的棋盘角点像素坐标序列                                     
        private Matrix<float> _mx1;	              // 左视图 X 方向像素映射矩阵
        private Matrix<float> _my1;	              // 左视图 Y 方向像素映射矩阵
        private Matrix<float> _mx2;	              // 右视图 X 方向像素映射矩阵
        private Matrix<float> _my2;	              // 右视图 Y 方向像素映射矩阵
        private Matrix<double> _q;		          // 用于计算三维点云的 Q 矩阵
        private Matrix<double> _r1;
        private Matrix<double> _r2;
        private Matrix<double> _p1;
        private Matrix<double> _p2;
        private Rectangle _roi1;	              // 左视图有效区域的矩形
        private Rectangle _roi2;	              // 右视图有效区域的矩形
        private CalibType _calibType;          // 标定种类
        private MCvTermCriteria _termCriteria;       // 终止准则
        private Matrix<double> _foundamentalMatrix; // 基础矩阵
        private Matrix<double> _essentialMatrix;    // 本征矩阵
        private ExtrinsicCameraParameters _extrParamsS;        // 立体摄像机外部参数
        private IntrinsicCameraParameters _intrParamL;         // 左摄像机内参
        private IntrinsicCameraParameters _intrParamR;         // 右摄像机内参
        private ExtrinsicCameraParameters[] _extrParamsL;        // 左摄像机外参
        private ExtrinsicCameraParameters[] _extrParamsR;        // 右摄像机外参

        private VideoCaptureDevice _captureDeviceL = null;
        private VideoCaptureDevice _captureDeviceR = null;
        private bool _captureInProgress;
        private bool _captureBinded = false;
        private DoubleCaptureControlPanel _controlPane;
        private DoubleCaptureView _viewPanel;
        private List<DeviceItem> _deviceList;
        private Mat _frameL;
        private Mat _frameR;

        public CameraDevice m_cameraDevice { get; set; }
        public Model.ChessBoard _ChessBoard { get; set; }
        public Model.DoubleCapture _DoubleCapture { get; set; }
        //public string _ImgSavePath { get; set; }
        public Photograph _Photograph { get; set;}

        /// <summary>
        /// 构造函数
        /// </summary>
        public DoubleCapturePresenter()
        {
            _ChessBoard=new ChessBoard();
            _DoubleCapture=new DoubleCapture();
            _frameL = new Mat();
            _frameR = new Mat();
            _deviceList = new List<DeviceItem>();
            _Photograph=new Photograph();
            FilterInfoCollection videoDevicesnew = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            //List<DeviceItem> deviceList = new List<DeviceItem>();
            for (int i = 0; i < videoDevicesnew.Count; i++)
            {
                _deviceList.Add(new DeviceItem(i, videoDevicesnew[i].Name, videoDevicesnew[i].MonikerString));
            }
            m_cameraDevice = new CameraDevice(_deviceList);
        }
        /// <summary>
        /// 注入view
        /// </summary>
        /// <param name="controlPanel"></param>
        /// <param name="viewPanel"></param>
        public void InjectViews(ref DoubleCaptureControlPanel controlPanel,
                                ref DoubleCaptureView viewPanel )
        {
            _controlPane = controlPanel;
            _controlPane.Presenter = this;
            _viewPanel = viewPanel;
            _viewPanel.Presenter = this;
        }
        /// <summary>
        /// 初始化内部数据
        /// </summary>
        /// <param name="imgsize"></param>
        private void Initializer(Size imgsize)
        {
            _nPointsPerImage = _ChessBoard.BoardRows * _ChessBoard.BoardColumns; // 每幅棋盘的角点数
            _nPoints = _nPointsPerImage * _ChessBoard.NImages; // 棋盘角点总数
            _imageSize = imgsize; // 图像分辨率
            _objectPoints = new List<MCvPoint3D32f[]>(_ChessBoard.NImages); //棋盘角点的世界坐标值(三维)
            for (int i = 0; i < _ChessBoard.NImages; i++)
            {
                _objectPoints.Add(new MCvPoint3D32f[_nPointsPerImage]);
            }
            int currentImage;
            for (currentImage = 0; currentImage < _ChessBoard.NImages; currentImage++)
            {
                int currentRow;
                for (currentRow = 0; currentRow < _ChessBoard.BoardRows; currentRow++)
                {
                    int currentCol;
                    for (currentCol = 0; currentCol < _ChessBoard.BoardColumns; currentCol++)
                    {
                        int nPoint = currentRow * _ChessBoard.BoardColumns + currentCol;
                        _objectPoints[currentImage][nPoint].X = (float)currentCol * _ChessBoard.SquareWidth;
                        _objectPoints[currentImage][nPoint].Y = (float)currentRow * _ChessBoard.SquareWidth;
                        _objectPoints[currentImage][nPoint].Z = (float)0.0f;
                    }
                }
            }


            _imagePointsL = new List<PointF[]>(); // 左视图的棋盘角点像素坐标序列(二维)
            _imagePointsR = new List<PointF[]>(); // 右视图的棋盘角点像素坐标序列(二维)
            _q = new Matrix<double>(4, 4); // 用于计算三维点云的 Q 矩阵
            _roi1 = new Rectangle(); // 左视图有效区域的矩形
            _roi2 = new Rectangle(); // 右视图有效区域的矩形
            _r1 = new Matrix<double>(3, 3);
            _r2 = new Matrix<double>(3, 3);
            _p1 = new Matrix<double>(3, 4);
            _p2 = new Matrix<double>(3, 4);
            _mx1 = new Matrix<float>(_imageSize);
            _my1 = new Matrix<float>(_imageSize);
            _mx2 = new Matrix<float>(_imageSize);
            _my2 = new Matrix<float>(_imageSize);
            _extrParamsS = new ExtrinsicCameraParameters(); //立体摄像机外部参数
            _intrParamL = new IntrinsicCameraParameters(); //左摄像机内参
            _intrParamR = new IntrinsicCameraParameters(); //右摄像机内参
            _extrParamsL = new ExtrinsicCameraParameters[_ChessBoard.NImages];
            _extrParamsR = new ExtrinsicCameraParameters[_ChessBoard.NImages];
            _termCriteria = new MCvTermCriteria(30, 0.05); //终止准则
            _calibType = CalibType.FixK3;
            _DoubleCapture.ImgL = new Mat();
            _DoubleCapture.ImgR = new Mat();
        }

        /// <summary>
        /// 角点检测
        /// /// 输入一对图像,检测其中的角点,保存到角点数组中,并返回两幅做了标记的图片
        /// </summary>
        /// <param name="imageL">in 左视图图片</param>
        /// <param name="imageR">in 右视图图片</param>
        /// <param name="photoL">out 标记好的左视图</param>
        /// <param name="photoR">out 标记好的右视图</param>
        private void CornerDetection(Image<Gray, byte> imageL,
                                    Image<Gray, byte> imageR,
                                    out Image<Bgr, byte> photoL,
                                    out Image<Bgr, byte> photoR)
        {
            PointF[] cdL = new PointF[_nPointsPerImage];
            PointF[] cdR = new PointF[_nPointsPerImage];

            if (imageL == null || imageR == null)
            {
                MessageBox.Show("图片不成对或没有正确的图片!");
                photoL = null;
                photoR = null;
                return;
            }
            try
            {
                //以原图为底准备绘制
                Image<Bgr, byte> imageL2 = imageL.Convert<Bgr, byte>();
                Image<Bgr, byte> imageR2 = imageR.Convert<Bgr, byte>();

                List<PointF> temp = new List<PointF>();
                var cornerPoints = new VectorOfPoint();
                bool succeedL = CvInvoke.FindChessboardCorners(imageL, new Size(9, 6), cornerPoints, CalibCbType.Default);//cornerDatas.boardSize、
                cdL = TypeConverter.PointArray2PointFArray(cornerPoints.ToArray());
                bool succeedR = CvInvoke.FindChessboardCorners(imageR, new Size(9, 6), cornerPoints, CalibCbType.Default);//cornerDatas.boardSize
                cdR = TypeConverter.PointArray2PointFArray(cornerPoints.ToArray());

                _imagePointsL.Add(cdL);
                _imagePointsR.Add(cdR);
                if (succeedL && succeedR) //chess board found
                {
                    //亚像素求精
                    imageL.FindCornerSubPix(_imagePointsL.ToArray(), new Size(11, 11), new Size(-1, -1), new MCvTermCriteria(30, 0.05));
                    imageR.FindCornerSubPix(_imagePointsR.ToArray(), new Size(11, 11), new Size(-1, -1), new MCvTermCriteria(30, 0.05));
                    Bgr[] lineColourArray = new Bgr[cdL.Length];
                    //绘制角点折线图
                    Random r = new Random();
                    for (int i = 0; i < cdL.Length; i++)//取色
                    {
                        lineColourArray[i] = new Bgr(r.Next(0, 255), r.Next(0, 255), r.Next(0, 255));
                    }
                    //dram the results
                    imageL2.Draw(new CircleF(cdL[0], 3), new Bgr(Color.Yellow), 1);
                    imageR2.Draw(new CircleF(cdR[0], 3), new Bgr(Color.Yellow), 1);
                    for (int i = 1; i < cdL.Length; i++)
                    {
                        imageL2.Draw(new LineSegment2DF(cdL[i - 1], cdL[i]), lineColourArray[i], 2);
                        imageL2.Draw(new CircleF(cdL[i], 5), new Bgr(Color.Yellow), 2);
                        imageR2.Draw(new LineSegment2DF(cdR[i - 1], cdR[i]), lineColourArray[i], 2);
                        imageR2.Draw(new CircleF(cdR[i], 5), new Bgr(Color.Yellow), 2);
                    }
                    photoL = imageL2;
                    photoR = imageR2;
                    return;
                }
            }
            catch (System.TypeInitializationException)
            {
                MessageBox.Show("标定盘识别失败!");
                photoL = null;
                photoR = null;
                return;
            }
            photoL = null;
            photoR = null;
            return;
        }

        /// <summary>
        /// 立体相机标定方法
        /// </summary>
        private void DoCalibrate()
        {

            try
            {
                //左标定
                double x = CameraCalibration.CalibrateCamera(
                    _objectPoints.ToArray(),
                    _imagePointsL.ToArray(),
                    _imageSize,
                    _intrParamL, //内部参数
                    _calibType,
                    _termCriteria,
                    out _extrParamsL);

                //右标定
                double y = CameraCalibration.CalibrateCamera(
                    _objectPoints.ToArray(),
                    _imagePointsR.ToArray(),
                    _imageSize,
                    _intrParamR,
                    _calibType,
                    _termCriteria,
                    out _extrParamsR);

                //立体标定
                CameraCalibration.StereoCalibrate(
                    _objectPoints.ToArray(),
                    _imagePointsL.ToArray(),
                    _imagePointsR.ToArray(),
                    _intrParamL,         //左内部参数
                    _intrParamR,         //右内部参数
                    _imageSize,              //图像的大小
                    _calibType,              //标定种类
                    _termCriteria,           //终止准则
                    out _extrParamsS,       //立体相机外部参数
                    out _foundamentalMatrix, //基础矩阵
                    out _essentialMatrix);   //本征矩阵
            }
            catch (System.NullReferenceException e)
            {
                MessageBox.Show("在标定处产生异常" + e.Message);
                return;
            }
        }
        /// <summary>
        /// 摄像机矫正方法
        /// </summary>
        private void RectifyStereoCamera()
        {
            //参数初始化
            //执行双目校正
            CvInvoke.StereoRectify(
                _intrParamL.IntrinsicMatrix,//左摄像机矩阵
                _intrParamL.DistortionCoeffs,//左畸变矩阵
                _intrParamR.IntrinsicMatrix,//右摄像机矩阵
                _intrParamR.DistortionCoeffs,//右畸变矩阵
                _imageSize,                              //图片分辨率
                _extrParamsS.RotationVector,   //旋转矩阵
                _extrParamsS.TranslationVector,//平移矩阵
                _r1, _r2, _p1, _p2, _q,
                StereoRectifyType.Default,
                -1,
                _imageSize,
                ref _roi1, ref _roi2);
            //生成图像校正所需的像素映射矩阵
            //左
            //CvInvoke.InitUndistortRectifyMap(
            //    _intrParamL.IntrinsicMatrix,//左摄像机矩阵
            //    _intrParamL.DistortionCoeffs,//左畸变矩阵
            //    _r1,
            //    _intrParamL.IntrinsicMatrix,//new 摄像机矩阵?
            //    _imageSize, 
            //    DepthType.Default,
            //    _mx1, 
            //    _my1);
            ////右
            //CvInvoke.InitUndistortRectifyMap(
            //    _intrParamR.IntrinsicMatrix,//右摄像机矩阵
            //    _intrParamR.DistortionCoeffs,//右畸变矩阵
            //    _r2,
            //    _intrParamL.IntrinsicMatrix,//new 摄像机矩阵?
            //    _imageSize,
            //    DepthType.Default,
            //    _mx2, 
            //    _my2);
        }

        /// <summary>
        /// 图像矫正(矫正图像只是用来显示,以观察矫正效果,不参与任何实际的计算)
        /// </summary>
        /// <param name="originalImgL">输入图像1</param>
        /// <param name="originalImgR">输入图像2</param>
        /// <param name="imgLr">校正好的图像1</param>
        /// <param name="imgRr">校正好的图像2</param>
        private void RemapImage(Image<Bgr, byte> originalImgL, Image<Bgr, byte> originalImgR, out Image<Bgr, byte> imgLr, out Image<Bgr, byte> imgRr)
        {
            //临时变量用于保存矫正之后的图像
            Image<Gray, byte> grayimgLr = new Image<Gray, byte>(_imageSize);
            Image<Gray, byte> grayimgRr = new Image<Gray, byte>(_imageSize);
            //将原始图片转换成灰度图准备进行矫正
            Image<Gray, byte> t1 = originalImgL.Convert<Gray, Byte>();
            Image<Gray, byte> t2 = originalImgR.Convert<Gray, Byte>();
            //进行矫正
            if (t1 != null && t2 != null)
            {
                //校正图像
                CvInvoke.Remap(t1, grayimgLr, _mx1, _my1, Inter.Linear, BorderType.Constant, new MCvScalar(0, 0, 0));
                CvInvoke.Remap(t2, grayimgRr, _mx2, _my2, Inter.Linear, BorderType.Constant, new MCvScalar(0, 0, 0));
            }
            //图像格式转换准备输出
            imgLr = grayimgLr.Convert<Bgr, Byte>();
            imgRr = grayimgRr.Convert<Bgr, Byte>();
        }//end of remapImage

        /// <summary>
        /// 点云输出
        /// </summary>
        /// <param name="left">左图</param>
        /// <param name="right">右图</param>
        /// <param name="outputDisparityMap"></param>
        /// <param name="points">点云</param>
        private void Computer3DPointsFromStereoPair(IInputArray left, IInputArray right, Mat outputDisparityMap, Mat points)
        {
            Size size;
            using (InputArray ia = left.GetInputArray())
                size = ia.GetSize();

            using (StereoBM stereoSolver = new StereoBM())
            {
                stereoSolver.Compute(left, right, outputDisparityMap);

                float scale = Math.Max(size.Width, size.Height);

                //Construct a simple Q matrix, if you have a matrix from cvStereoRectify, you should use that instead
                using (Matrix<double> q = new Matrix<double>(
                    new double[,]
                    {
                        {1.0, 0.0, 0.0, -size.Width/2}, //shift the x origin to image center
                        {0.0, -1.0, 0.0, size.Height/2}, //shift the y origin to image center and flip it upside down
                        {0.0, 0.0, -1.0, 0.0}, //Multiply the z value by -1.0, 
                        {0.0, 0.0, 0.0, scale}
                    })) //scale the object's coordinate to within a [-0.5, 0.5] cube
                {
                    //注意此处的_q
                    CvInvoke.ReprojectImageTo3D(outputDisparityMap, points, _q, false, DepthType.Cv32F);

                }
                //points = PointCollection.ReprojectImageTo3D(outputDisparityMap, q);
            }
        }

        /// <summary>
        /// 重建
        /// </summary>
        /// <param name="left"></param>
        /// <param name="right"></param>
        private void Reconstruction(Mat left, Mat right)
        {
            MCvPoint3D32f[] _points;
            Mat disparityMap = new Mat();

            Stopwatch watch = Stopwatch.StartNew();
            UMat leftGray = new UMat();
            UMat rightGray = new UMat();
            CvInvoke.CvtColor(left, leftGray, ColorConversion.Bgr2Gray);
            CvInvoke.CvtColor(right, rightGray, ColorConversion.Bgr2Gray);
            Mat points = new Mat();
            Computer3DPointsFromStereoPair(leftGray, rightGray, disparityMap, points);
            watch.Stop();
            long disparityComputationTime = watch.ElapsedMilliseconds;
            Mat temp = new Mat();
            CvInvoke.Resize(disparityMap, temp, new Size(1366, 768));
            CvInvoke.Imshow("视差图", temp);
            CvInvoke.WaitKey(0);
            Mat pointsArray = points.Reshape(points.NumberOfChannels, points.Rows * points.Cols);
            Mat colorArray = left.Reshape(left.NumberOfChannels, left.Rows * left.Cols);
            Mat colorArrayFloat = new Mat();
            colorArray.ConvertTo(colorArrayFloat, DepthType.Cv32F);
            WCloud cloud = new WCloud(pointsArray, colorArray);

            Emgu.CV.Viz3d v = new Emgu.CV.Viz3d("Simple stereo reconstruction");
            WText wtext = new WText("3d point cloud", new System.Drawing.Point(20, 20), 20, new MCvScalar(255, 255, 255));
            WCoordinateSystem wCoordinate = new WCoordinateSystem(1.0);
            
            v.ShowWidget("Coordinate", wCoordinate);
            v.ShowWidget("text", wtext);
            
            v.ShowWidget("cloud", cloud);
            v.Spin();
        }

        /// <summary>
        /// 列出摄像头列表
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void ListDevice(object sender, EventArgs e)
        {
            FilterInfoCollection videoDevicesnew = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            String tmp = "";
            foreach (FilterInfo o in videoDevicesnew)
            {
                tmp += o.MonikerString + o.Name + "\n";
            }

            MessageBox.Show("设备列表:" + tmp);
        }

        // 左视图更新
        private void VideoSource_NewFrameL(object sender, AForge.Video.NewFrameEventArgs eventArgs)
        {
            _DoubleCapture.ImgL = TypeConverter.Bitmap2Mat(eventArgs.Frame);
            GC.Collect();
        }

        // 右视图更新
        private void VideoSource_NewFrameR(object sender, AForge.Video.NewFrameEventArgs eventArgs)
        {
            _DoubleCapture.ImgR = TypeConverter.Bitmap2Mat(eventArgs.Frame);
            GC.Collect();
        }

        /// 开关摄像机
        public void CameraSwitch(object sender, EventArgs e)
        {
            if (_captureBinded == false) //如果没有绑定摄像头则绑定
            {
                try
                {
                    if (_deviceList.Count <= 0) //没有检测到设备
                    {
                        MessageBox.Show("没有检测到设备!");
                        return;
                    }

                    //只有一个设备或者两个设备选框中的选项相同,只打开一个镜头
                    if (_deviceList.Count == 1 || (_controlPane.comboBox_LCam.SelectedIndex == _controlPane.comboBox_RCam.SelectedIndex))
                    {
                        _captureDeviceL = new VideoCaptureDevice(_deviceList[0].Monikerstring);//连接摄像头。
                        _captureDeviceL.VideoResolution = _captureDeviceL.VideoCapabilities[_controlPane.comboBox_lCapability.SelectedIndex];
                        _captureDeviceL.NewFrame += VideoSource_NewFrameL;
                        _captureDeviceL.Start();
                    }
                    else //打开两个设备
                    {
                        _captureDeviceL = new VideoCaptureDevice(_deviceList[_controlPane.comboBox_LCam.SelectedIndex].Monikerstring);//连接摄像头。
                        _captureDeviceL.VideoResolution = _captureDeviceL.VideoCapabilities[_controlPane.comboBox_lCapability.SelectedIndex];
                        _captureDeviceL.NewFrame += VideoSource_NewFrameL;

                        _captureDeviceR = new VideoCaptureDevice(_deviceList[_controlPane.comboBox_RCam.SelectedIndex].Monikerstring);//连接摄像头。
                        _captureDeviceR.VideoResolution = _captureDeviceR.VideoCapabilities[_controlPane.comboBox_rCapability.SelectedIndex];
                        _captureDeviceR.NewFrame += VideoSource_NewFrameR;

                        _captureInProgress = true;
                        _captureDeviceL.Start();
                        _captureDeviceR.Start();
                    }

                    _captureBinded = true;
                }
                catch (NullReferenceException excpt)
                {
                    MessageBox.Show(excpt.Message);
                }
            }
            else //摄像头已经绑定
            {
                if (_captureInProgress)
                {
                    _captureDeviceL?.SignalToStop();
                    _captureDeviceR?.SignalToStop();
                }
                else
                {
                    _captureDeviceL?.Start();
                    _captureDeviceR?.Start();
                }
                _captureInProgress = !_captureInProgress;
            }
        }

        //释放摄像机准备重新绑定
        public void CameraRelease(object sender, EventArgs e)
        {
            if (_captureInProgress == false)
            {
                _captureBinded = false;
                _captureDeviceL = null;
                _captureDeviceR = null;
                _DoubleCapture.ImgL = null;
                _DoubleCapture.ImgR = null;
            }
            else
            {
                MessageBox.Show("please turn off the camera first!");
            }
        }

        //刷新摄像机
        public void CameraRefresh(object sender, EventArgs e)
        {
            //只有在摄像头都没有工作的情况下才能刷新
            //if (_captureDeviceR.IsRunning == false && _captureDeviceL.IsRunning == false)
            {
                FilterInfoCollection videoDevicesnew = new FilterInfoCollection(FilterCategory.VideoInputDevice);
                List<DeviceItem> deviceList = new List<DeviceItem>();
                for (int i = 0; i < videoDevicesnew.Count; i++)
                {
                    deviceList.Add(new DeviceItem(i, videoDevicesnew[i].Name, videoDevicesnew[i].MonikerString));
                }

                m_cameraDevice = new CameraDevice(deviceList);
            }
            //else
            //{
            //    MessageBox.Show("please turn off and release the Captures first!");
            //}
        }

        /// <summary>
        /// 默认标定参数
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void DefaultParams(object sender, EventArgs e)
        {
            _ChessBoard.BoardRows = 6;
            _ChessBoard.BoardColumns = 9;
            _ChessBoard.NImages = 20;
            _ChessBoard.SquareWidth = 25.0F;
        }

        /// <summary>
        /// 标定
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void Calibrate(object sender, EventArgs e)
        {
            OpenFileDialog FileDialog1 = new OpenFileDialog();
            OpenFileDialog FileDialog2 = new OpenFileDialog();
            FileDialog1.Filter = "所有文件|*.*";
            FileDialog2.Filter = "所有文件|*.*";
            FileDialog1.Multiselect = true;
            FileDialog2.Multiselect = true;
            FileDialog1.SupportMultiDottedExtensions = true;
            FileDialog2.SupportMultiDottedExtensions = true;
            FileDialog1.Title = "选择左视图文件序列";
            FileDialog2.Title = "选择右视图文件序列";
            //获取左右视图的文件路径序列
            String[] pathL = null, pathR = null;
            if (FileDialog1.ShowDialog() == DialogResult.OK)
            {
                pathL = FileDialog1.FileNames;
            }
            if (pathL == null)
            {
                MessageBox.Show("请选择有效文件!");
                return;
            }
            if (FileDialog2.ShowDialog() == DialogResult.OK)
            {
                pathR = FileDialog2.FileNames;
            }
            if (pathR == null)
            {
                MessageBox.Show("请选择有效文件!");
                return;
            }

            int numOfImg = Math.Min(_ChessBoard.NImages, Math.Min(pathL.Length, pathR.Length));
            Size pictureSize = new Image<Gray, byte>(pathR[0]).Size;
            Initializer(pictureSize);
            for (int i = 0; i < numOfImg; i++)
            {
                Image<Bgr, byte> photoL = new Image<Bgr, byte>(pictureSize);
                Image<Bgr, byte> photoR = new Image<Bgr, byte>(pictureSize);
                CornerDetection(new Image<Gray, byte>(pathL[i]),
                                new Image<Gray, byte>(pathL[i]), 
                                out photoL, out photoR);
                _DoubleCapture.ImgL = photoL.Mat;
                _DoubleCapture.ImgR = photoR.Mat;
                _viewPanel.Refresh();
            }
            MessageBox.Show("标定盘识别完成!");
            DoCalibrate();
            MessageBox.Show("标定完成!");
            RectifyStereoCamera();
            MessageBox.Show(_q[0, 0] + "," + _q[0, 1] + "," + _q[0, 2] + "," + _q[0, 3] + "\n" +
                            _q[1, 0] + "," + _q[1, 1] + "," + _q[1, 2] + "," + _q[1, 3] + "\n" +
                            _q[2, 0] + "," + _q[2, 1] + "," + _q[2, 2] + "," + _q[2, 3] + "\n" +
                            _q[3, 0] + "," + _q[3, 1] + "," + _q[3, 2] + "," + _q[3, 3] + "\n");
        }

        /// <summary>
        /// 三维重建
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void Reconstruction(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = "E:\\VisualStudio\\CvLab\\ExampleData\\";
            openFileDialog.Filter = "所有文件|*.*";
            openFileDialog.RestoreDirectory = true;
            openFileDialog.FilterIndex = 1;
            string FileNameL = "", FileNameR = "";
            Mat _left = new Mat();
            Mat _right = new Mat();
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                FileNameL = openFileDialog.FileName;
                _left = CvInvoke.Imread(FileNameL, ImreadModes.Color);
                _DoubleCapture.ImgL = _left;
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    FileNameR = openFileDialog.FileName;
                    _right = CvInvoke.Imread(FileNameR, ImreadModes.Color);
                    _DoubleCapture.ImgL = _right;
                }
            }

            if (FileNameL == "" || FileNameR == "")
            {
                return;
            }
            Reconstruction(_left, _right);
        }

        /// <summary>
        /// 测量
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MeasureInImg(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 浏览保存图片的路径
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void BrowserPathToSaveImgs(object sender, EventArgs e)
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            dialog.Description = "请选择用来保存照片的文件夹";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                if (string.IsNullOrEmpty(dialog.SelectedPath))
                {
                    MessageBox.Show("请选择有效的文件路径!", "提示");
                }
                else
                {
                    _Photograph.PathToSaveImgs = dialog.SelectedPath;
                }
            }
        }

        /// <summary>
        /// 拍照
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void TakePhotos(object sender, EventArgs e)
        {
            if (_Photograph.PathToSaveImgs.IsNull())
            {
                //保存位置为空
                MessageBox.Show(Resources.DoubleCapturePresenter_TakePhotos_Please_set_up_the_path_to_save_the_imgs_);
            }
            else
            {
                if (_controlPane.radioButton_SaveLeftOnly.Checked == true)
                {
                    //只保存左视图
                    Mat lshot=_DoubleCapture.ImgL.Clone();
                    CvInvoke.Imwrite(_Photograph.PathToSaveImgs + DateTime.Now.ToFileTime() + ".jpg", lshot);
                    GC.Collect();
                }
                else if (_controlPane.radioButton_saveDoubleCapture.Checked == true)
                {
                    //保存双视图
                    Mat lshot = _DoubleCapture.ImgL.Clone();
                    Mat rshot = _DoubleCapture.ImgR.Clone();
                    string timeStamp = DateTime.Now.ToFileTime().ToString();
                    CvInvoke.Imwrite(_Photograph.PathToSaveImgs + "L-" + timeStamp + ".jpg", lshot);
                    CvInvoke.Imwrite(_Photograph.PathToSaveImgs + "R-" + timeStamp + ".jpg", rshot);
                    GC.Collect();
                }
                else
                {
                    //没有选择有效的保存模式
                    MessageBox.Show(
                        "please choose a save pattern by check one of the radio button on DoubleCaptureControlPanel!");
                }
            }
        }
    }
}
