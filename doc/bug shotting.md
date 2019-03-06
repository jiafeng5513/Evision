
Z=fT/(xr-xl)
Z = baseline * f / (d + doffs)
视差图和原图的尺寸要一致,注意数据集中的图片尺寸
## 已知bug
1.  拍照功能的析构不完善
2.  整个程序缺乏错误处理
3.  VTK和PCL的dll不能自动复制

## coming
1. 把点云生成的那一段代码集成进来(正在进行)
2. 点用生成的材料最好是reprojectTo3D的结果
3. 锥形点云的问题:
   1. doffs=cx1-cx2
   2. 标定时把焦距,主点坐标,基线长度,doffs算出来,一起保存

## 进阶:
1. CMake
2. 录视频
3. 游戏的诞生视频
4. 监控器
5. 开淘宝店,自动发货

Q矩阵:
1   0   0   -cx
0   1   0   -cy
0   0   0   f
0   0   -1/Tx   (cx-cx')Tx


### 调试记录:
1. 从标定数据中拿出值,用视差图手算出来的点云是锥形的
2. 在Evision中直接导出xyz.txt文件,点云是锥形的
3. 根据1和2,推定标定数据和视差图中有问题,视差图看起来是没问题,准备用MatLab对比一下标定数据
4. Matlab的标定数据和Opencv的存在一些差距,不过,使用Matlab的标定数据+OpenCV的视差图,仍然是锥形点云
5. 从数据上看,Q矩阵是错误的Cx-C'x=0说明了一些问题.
6. 怀疑1:数据类型的混乱
7. 怀疑2:左右视图的问题
8. 测试一下匹配原始图片而不是矫正后的图片,使用另一套参数




想法:
1. Reconstuction3d中的匹配速度更快,效果也更好,或许是用了更好的参数
2. Evision和Reconstuction3d同时使用OpenCV自带的图片和自己拍的图片,视差图效果都很差
3. 同时使用scense2014数据集中的图片,Reconstuction3d的效果非常好,Evision很差
4. 同时使用scense2014数据集中的图片,Evision的速度差很多,在参数都全部一致,只有SADWindowSize=3/5这一个差别的情况下,视差图的区别依然特别大.
5. 总上,首先应该改进Evision的匹配参数范围,其次采用Reconstuction3d的匹配算法,最后优化流程,提高速度.

左视图 l 
缩放之后的左视图 left image
origin disparity
fixed disparity
disparity
back project
Delaunay: ...Triangles
3D reconstruction

左视图 
右视图 
原始视差图 origin disparity
修复视差图 fixed disparity
标点视差图 disparity
标点左视图 back project



1. 先对比代码
2. 用Legacy去匹配标准案例.
3. 等设备,排除标定的问题.

uniradio=25
prefiicap=31
SadWinSz=51
specwinsz=100
MinDisp=0
MaxDisp=144
specrange=32
maxdiffdisp12=1
textthread=10

现象描述:
1. 字典,SGBM,IMREAD_COLOR,CV_BGR2GRAY,不矫正,5,47,9,1,1,64,14,1,-,效果还可以
2. 字典,BM,IMREAD_GRAYSCALE,-,不矫正,参数25,31,51,100,0,144,32,1,10,全是黑的


使用黑白图像作为输入时,Evision和Legacy效果相似

是用彩色图片时,Legacy没问题,Evision视差图基本全是黑的

Evision使用彩色图片,放弃矫正,使用默认参数,有些中间结果是正确的,有些结果是空的,使用legacy参数,全是空的


感觉OpenCV2和3的匹配方法根本就不一样.


标定的准确度很差

应该做一个读取Matlab标定数据的功能



标定标志位

单目标定:

`CALIB_USE_INTRINSIC_GUESS`用户提供相机内参(相机矩阵和畸变系数)初值,由flag决定优化其中的哪些参数
`CALIB_FIX_PRINCIPAL_POINT` 不优化主点位置
`CALIB_FIX_ASPECT_RATIO` 固定宽高比,将fy视为自由参数进行优化,而fx由宽高比决定
`CALIB_ZERO_TANGENT_DIST` 切向畸变系数（p1，p2）设置为零并保持为零。
`CALIB_FIX_K1,...,CALIB_FIX_K6` 不优化相应的径向畸变系数
`CALIB_RATIONAL_MODEL` 使用理想模型,即使用8个畸变系数(启用k4,k5,k6),如果不设置该flag,则使用5个畸变系数
`CALIB_THIN_PRISM_MODEL` 使用薄棱镜模型,即使用12个畸变参数(启用s1,s2,s3,s4),如果不设置该flag,则使用5个畸变系数
`CALIB_FIX_S1_S2_S3_S4` 不优化薄棱镜畸变参数S1~S4
`CALIB_TILTED_MODEL` 使用倾斜传感器模型,即使用14个畸变系数(启用tauX,tauY)
`CALIB_FIX_TAUX_TAUY` 不优化tauX,tauY

立体标定:
`CALIB_FIX_INTRINSIC` 不优化相机矩阵和畸变系数,只计算RTEF
`CALIB_USE_INTRINSIC_GUESS` 用户提供相机内参(相机矩阵和畸变系数)初值,由flag决定优化其中的哪些参数
`CALIB_USE_EXTRINSIC_GUESS` 用户提供相机外参(R和T)的初值,由flag决定优化其中的哪些参数
`CALIB_FIX_PRINCIPAL_POINT` 不优化主点位置

`CALIB_FIX_FOCAL_LENGTH` Fix f(j)x and f(j)y .
`CALIB_FIX_ASPECT_RATIO` 固定宽高比,将fy视为自由参数进行优化,而fx由宽高比决定
`CALIB_SAME_FOCAL_LENGTH` Enforce f(0)x=f(1)x and f(0)y=f(1)y .
`CALIB_ZERO_TANGENT_DIST` 切向畸变系数（p1，p2）设置为零并保持为零。
`CALIB_FIX_K1,...,CALIB_FIX_K6` 不优化相应的径向畸变系数
`CALIB_USE_INTRINSIC_GUESS` 以提供的畸变系数为初值,否则以0为初值
`CALIB_RATIONAL_MODEL` 使用理想模型,即使用8个畸变系数(启用k4,k5,k6),如果不设置该flag,则使用5个畸变系数
`CALIB_THIN_PRISM_MODEL` 使用薄棱镜模型,即使用12个畸变参数(启用s1,s2,s3,s4),如果不设置该flag,则使用5个畸变系数
`CALIB_FIX_S1_S2_S3_S4` 不优化薄棱镜畸变参数S1~S4
`CALIB_TILTED_MODEL` 使用倾斜传感器模型,即使用14个畸变系数(启用tauX,tauY)
`CALIB_FIX_TAUX_TAUY` 不优化tauX,tauY

标定参数可选:
1. `CALIB_FIX_PRINCIPAL_POINT` 不优化主点位置
2. `CALIB_FIX_ASPECT_RATIO` 固定宽高比,将fy视为自由参数进行优化,而fx由宽高比决定
3. `CALIB_ZERO_TANGENT_DIST` 切向畸变系数（p1，p2）设置为零并保持为零。

其中1,2,3,4独立,5,6,8互斥,可以都不选,6-7级联,8-9级联

立体标定参数可选
`CALIB_FIX_INTRINSIC` [默认]不优化相机矩阵和畸变系数,只计算RTEF
`CALIB_SAME_FOCAL_LENGTH` 强制两侧相机的焦距相等



公用参数
`CALIB_FIX_K1,...,CALIB_FIX_K6` 不优化相应的径向畸变系数
`CALIB_RATIONAL_MODEL` 使用理想模型,即使用8个畸变系数(启用k4,k5,k6),如果不设置该flag,则使用5个畸变系数
`CALIB_THIN_PRISM_MODEL` 使用薄棱镜模型,即使用12个畸变参数(启用s1,s2,s3,s4),如果不设置该flag,则使用5个畸变系数
`CALIB_FIX_S1_S2_S3_S4` 不优化薄棱镜畸变参数S1~S4
`CALIB_TILTED_MODEL` 使用倾斜传感器模型,即使用14个畸变系数(启用tauX,tauY)
`CALIB_FIX_TAUX_TAUY` 不优化tauX,tauY





	bool CALIB_FIX_PRINCIPAL_POINT = false;	//不优化主点位置
	bool CALIB_FIX_ASPECT_RATIO = false;	//固定宽高比
	bool CALIB_ZERO_TANGENT_DIST = false;	//忽略切向畸变系数P1,P2
	bool CALIB_SAME_FOCAL_LENGTH = false;	//强制两侧相机的焦距相等
	bool CALIB_FIX_K1 = false;				//忽略径向畸变系数K1
	bool CALIB_FIX_K2 = false;				//忽略径向畸变系数K2
	bool CALIB_FIX_K3 = false;				//忽略径向畸变系数K3
	bool CALIB_FIX_K4 = false;				//忽略径向畸变系数K4
	bool CALIB_FIX_K5 = false;				//忽略径向畸变系数K5
	bool CALIB_FIX_K6 = false;				//忽略径向畸变系数K6
	bool CALIB_RATIONAL_MODEL = false;		//使用理想模型(8系数)
	bool CALIB_THIN_PRISM_MODEL = false;	//使用薄棱镜模型(12系数)
	bool CALIB_FIX_S1_S2_S3_S4 = false;		//不优化薄棱镜畸变系数S1-S4
	bool CALIB_TILTED_MODEL = false;		//使用倾斜传感器模型(14系数)
	bool CALIB_FIX_TAUX_TAUY = false;		//不优化倾斜传感器畸变系数(TauX,TauY)


void paramChanged_CALIB_FIX_PRINCIPAL_POINT();
void paramChanged_CALIB_FIX_ASPECT_RATIO();
void paramChanged_CALIB_ZERO_TANGENT_DIST();
void paramChanged_CALIB_SAME_FOCAL_LENGTH();
void paramChanged_CALIB_FIX_K1();
void paramChanged_CALIB_FIX_K2();
void paramChanged_CALIB_FIX_K3();
void paramChanged_CALIB_FIX_K4();
void paramChanged_CALIB_FIX_K5();
void paramChanged_CALIB_FIX_K6();
void paramChanged_CALIB_RATIONAL_MODEL();
void paramChanged_CALIB_THIN_PRISM_MODEL();
void paramChanged_CALIB_FIX_S1_S2_S3_S4();
void paramChanged_CALIB_TILTED_MODEL();
void paramChanged_CALIB_FIX_TAUX_TAUY();









CALIB_FIX_PRINCIPAL_POINT
CALIB_FIX_ASPECT_RATIO
CALIB_ZERO_TANGENT_DIST
CALIB_SAME_FOCAL_LENGTH
CALIB_FIX_K1
CALIB_FIX_K2
CALIB_FIX_K3
CALIB_FIX_K4
CALIB_FIX_K5
CALIB_FIX_K6
CALIB_RATIONAL_MODEL
CALIB_THIN_PRISM_MODEL
CALIB_FIX_S1_S2_S3_S4
CALIB_TILTED_MODEL
CALIB_FIX_TAUX_TAUY








onValueChanged_FIX_PRINCIPAL_POINT(bool)
onValueChanged_FIX_ASPECT_RATIO(bool)
onValueChanged_ZERO_TANGENT_DIST(bool)
onValueChanged_SAME_FOCAL_LENGTH(bool)
onValueChanged_FIX_K1(bool)
onValueChanged_FIX_K2(bool)
onValueChanged_FIX_K3(bool)
onValueChanged_FIX_K4(bool)
onValueChanged_FIX_K5(bool)
onValueChanged_FIX_K6(bool)
onValueChanged_RATIONAL_MODEL(bool)
onValueChanged_THIN_PRISM_MODEL(bool)
onValueChanged_FIX_S1_S2_S3_S4(bool)
onValueChanged_TILTED_MODEL(bool)
onValueChanged_FIX_TAUX_TAUY(bool)

