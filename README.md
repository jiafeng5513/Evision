<div align=center><img width="100" height="100" src="./src/EvisionSandbox/resource/Evision.ico"/></div>

<div align=center>Evision 双目视觉系统</div>
<div align=center><a href="https://www.bilibili.com/video/av46024738">演示视频</a></div>

Introduction:
=========

1. 双目系统的标定,畸变校正,视差,三维重建,距离测量等.<br>
2. 基于Yolo的实时目标检测.<br>
3. ELAS,ADCensus视差算法.<br>
4. 关于双目的中文资料重复度太高,希望各位后来者能够吸取前人精华,摒弃前人的糟粕,多多自行探索,不要抄来抄去<br>
5.  关于程序使用方面的问题,可以联系邮件jiafeng5513@outlook.com,有关课程设计和毕业论文(Windows程序开发,机器视觉,深度学习,图像处理)也可以联系作者<br>
6.  您可能会在目录中找到Visual Studio的解决方案文件`*.sln`,那是作者开发时使用的,未来的版本中将会移除,请不要视图打开或者修改自带的解决方案,推荐使用CMake进行build.<br>

目录
=========
- [Introduction:](#introduction)
- [目录](#%e7%9b%ae%e5%bd%95)
      - [1.Dependencies](#1dependencies)
      - [2.Installation_guide](#2installationguide)
      - [3.Directory_specification](#3directoryspecification)
      - [4.build](#4build)
      - [5.Deprecated_Version](#5deprecatedversion)
      - [6.双目设备](#6%e5%8f%8c%e7%9b%ae%e8%ae%be%e5%a4%87)
      - [7.参考文献](#7%e5%8f%82%e8%80%83%e6%96%87%e7%8c%ae)
      - [8.部分框图](#8%e9%83%a8%e5%88%86%e6%a1%86%e5%9b%be)
      - [9.未来计划](#9%e6%9c%aa%e6%9d%a5%e8%ae%a1%e5%88%92)

#### 1.Dependencies
1. Qt :5.12.0(Qt5.11.X以上版本均可)
2. OpenCV : 3.4.5(支持3.X.X版本,不支持2.X.X版本和4.X.X版本)
3. 可选依赖
   1. PCL 1.9.1(不使用PCL,将不能使用Evision3dViz和保存点云的功能)
   2. VTK 8.1.0 with QVTKWidget(不使用VTK,将不能使用Evision3dViz)
   3. CUDA 10.0(不使用CUDA,将无法使用目标检测模块)
   4. NVIDIA GTX 1060同级别或更高级,理论上也支持NVIDIA更老的显卡(如果没有NVIDIA显卡,将无法安装CUDA和CUDNN)

#### 2.Installation_guide
作者在windows平台上完成开发和测试,要在windows上使用本项目,您可能需要以下安装指南.如果您熟悉windows平台开发和Visual Studio的特性,您可不比理会这些安装指南,使用自己熟悉的方式和软件版本.<br>
1. [Qt安装指南](./doc/Qt_Install.md)<br>
2. [VS2017安装指南](./doc/VS2017_Install.md)<br>
3. [VS2017-Qt配置指南](./doc/qt_vs_config.md)<br>
4. [CUDA和GPU支持安装指南](./doc/cuda_install.md)<br>

#### 3.Directory_specification
1. `data`文件夹存储测试用例.<br>
2. `doc`文件夹中存储的是文档和文档中所用的图片等资源.<br>
3. `package`文件夹存储项目所需的依赖.<br>
4. `props`中存储的是属性表<br>
5. `scripts`文件夹存储编译脚本.<br>
6. `src`文件夹中存放代码文件.<br>
* `props`和`scripts`是作者开发期间使用的,对于使用者没有实际意义.<br>
* `package`中含有pthread的window版本,将会在未来改为使用CMake管理.<br>

#### 4.build
1. Evision目前由5个模块组成:
   1. Evision是Qt版的Evision主程序,生成目标是可执行程序.<br>
   2. Evision3dViz是点云模块,提供3维点云的观看和一些其他操作,依赖PCL和VTK.<br>
   3. EvisionADCensus是ADCensus视差算法模块.<br>
   4. EvisionElas是Elas视差算法模块.<br>
   5. EvisionObjDetection是目标检测模块,依赖CUDA.<br>
2. build方案:
   1. `./src/`目录下面含有的CMakeLists.txt,Evision基于CMake3.15编写,请使用版本大于等于3.13.X的CMake.<br>
   2. Evision是只能工作在64位下,另外如果您不是很熟悉CMake,推荐使用CMake GUI.
   3. 在CMake GUI中打开ObjectDetection和PointCloudViewer的开关,就会build目标检测和点云显示模块,并会询问相关的依赖路径.<br>
   4. Evision依赖Qt和OpenCV,请正确安装并设置环境变量;此外如果开启了ObjectDetection,需要安装CUDA(版本不低于10.0),如果开启了PointCloudViewer,需要安装PCL和VTK,注意虽然PCL自带了一个VTK,但是我们需要使用的QVTKWidget组件需要自行编译VTK才能获得.<br>
   5. CUDA_BLAS_LIBRARY<br>
      该变量询问cublas.lib的位置,例如`C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.0/lib/x64/cublas.lib`.<br>
   6. CUDA_RANDOM_LIBRARY<br>
       该变量询问curand.lib的位置,例如`C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.0/lib/x64/curand.lib`.<br>
   7. QT_INCLUDE_CORE_INNER<br>
    该变量询问形如`D:/Libraries/Qt/5.12.0/msvc2017_64/include/QtCore/5.12.0/QtCore`的路径.<br>
   8. Qt_INCLUDE_CORE_PRIVATE<br>
    该变量询问形如`D:/Libraries/Qt/5.12.0/msvc2017_64/include/QtCore/5.12.0/QtCore/private`的路径.<br>
   9. Qt_INCLUDE_Multimedia<br>
    该变量询问形如`D:/Libraries/Qt/5.12.0/msvc2017_64/include/QtMultimedia`的路径.<br>
   10. Qt_INCLUDE_MultimediaWidgets<br>
    该变量询问形如`D:/Libraries/Qt/5.12.0/msvc2017_64/include/QtMultimediaWidgets`的路径.<br>

   
#### 5.Deprecated_Version
1. MFC版本.[演示视频](https://www.bilibili.com/video/av8862669).<br>
   基于[邹宇华老师的StereoVision](https://github.com/yuhuazou/StereoVision)编写.如有需要推荐访问邹宇华老师原版或者在本项目的Release中寻找,由于使用的依赖较为陈旧,强烈不建议继续使用或进行二次开发.<br>
2. CvLabMain和CvLabSandbox(C#版本)<br>
   * 用VS2017打开`src/CvLib.sln`,你将会看到两个工程,该版本存在的目的是为了记录在C#平台上实现相似功能的方法,并没有实现Evision的全部功能,一般情况下不会更新,不推荐使用.<br>
    ![image](./doc/cvlib_sln.png)
   1. CvLabMain是用WPF框架写的.<br>
   2. CvLabSandbox是用WinFrom写的.<br>
   3. Docking风格MDI界面<br>
   4. 使用MVP设计模式,交互基于双向数据绑定<br>
   5. VS2017,请按照[Installation guide (环境安装指南)](#2.Installation_guide)进行安装.<br>
   6. 运行时为`.NET 4.6.1`,依赖采用Nuget下载<br>
   7. packages:<br>
       >1.AForge.2.2.5<br>
       >2.AForge.Video.2.2.5<br>
       >3.AForge.Video.DirectShow.2.2.5<br>
       >4.EMGU.CV.3.3.0.2824<br>
       >5.cskin.16.1.14.3<br>
       >6.WeifenLuo.WinFormsUI.Docking.2.1.0<br>
       >7.ZedGraph.5.1.5<br> 


#### 6.双目设备
1. 需要注意的是,视差效果,点云效果和精度和设备关系非常大,图片的分辨率越高,光照条件越好,畸变越小,一致性越好,最终效果也就越好.此外,两个相机的距离(基线长度)会影响系统的有效范围,一般来讲,基线越长的双目系统越容易获取远处目标的视差,延长基线能够一定程度上(因为有效距离和相机的焦段也有关)将系统的有效范围拉得更远,但同时,基线越长,盲区(距离相机过近的目标不会同时出现在两个视野中)也越大.
2. 推荐的双目系统:
   1. ZED/RealSense/MYNTEYE小觅相机.这是成熟(昂贵)的商业产品,出厂带有高精度的标定数据和功能强大的SDK,而且还带有IMU,IR主动光学等辅助设备,适合做SLAM,笔者认为购买这类相机是最节约时间成本的方法.<br>
   ![image](./doc/cameras.png)
   1. 双目开发板.淘宝上有很多这类产品,价格比ZED那类便宜很多,同时他们带的SDK也要更简陋,有些甚至只支持UVC协议没有SDK,但是他们至少能够控制两侧相机同时拍照,同时基线是固定的,能免去一些麻烦,需要注意的是,这种开发板大多数会输出一张左右视图拼在一起的图片<br>
   2. 两个工业相机组装.这种方案并不便宜,但是比较自由,可以自己调整基线和光轴指向.<br>
   ![image](./doc/device.png)<br>
   1. USB相机组装.这是最便宜的方案,只要买两个一样的USB相机,然后想办法把他们固定起来就可以了,但是便宜的USB相机画质比较有限,噪点比较多,而且无法控制两个相机同时拍照,再加上有效距离比较有限,会很大程度上限值效果,此外,由于两个相机固定的不稳定等原因可能出现移动,这会使标定失效,或者由于标定过程中的滑动直接导致标定失败.作者建议,在经济条件允许的情况下,尽量不要采用这种方案<br>

#### 7.参考文献
1. [相机标定+畸变矫正](https://blog.csdn.net/Loser__Wang/article/details/51811347)
2. [DarkNet](https://github.com/pjreddie/darknet)
3. [DarkNet_Windows](https://github.com/AlexeyAB/darknet)
4. [StdoutRedirector](https://github.com/dbzhang800/StdoutRedirector)
5. [ADCensus论文阅读笔记](https://wenku.baidu.com/view/3708e0554693daef5ff73d4d.html)
6. [ADCensus阅读笔记2](https://www.cnblogs.com/sinbad360/p/7842009.html)
7. [邹宇华CSDN](https://blog.csdn.net/chenyusiyuan/article/details/8131496)
8. [浅墨CSDN](https://blog.csdn.net/poem_qianmo/article/details/19809337)
9. Mei X, Sun X, Zhou M, et al. On building an accurate stereo matching system on graphics hardware[C]//2011 IEEE International Conference on Computer Vision Workshops (ICCV Workshops). IEEE, 2011: 467-474.
10. Geiger, Andreas, Martin Roser, and Raquel Urtasun. "Efficient large-scale stereo matching." Asian conference on computer vision. Springer, Berlin, Heidelberg, 2010.
11. Zhang K, Fang Y, Min D, et al. Cross-scale cost aggregation for stereo matching[C]//Proceedings of the IEEE Conference on Computer Vision and Pattern Recognition. 2014: 1590-1597.
12. Martull, Sarah, Martin Peris, and Kazuhiro Fukui. "Realistic CG stereo image dataset with ground truth disparity maps." ICPR workshop TrakMark2012. Vol. 111. No. 430. 2012.
13. Hirschmuller H. Stereo processing by semiglobal matching and mutual information[J]. IEEE Transactions on pattern analysis and machine intelligence, 2008, 30(2): 328-341.
14. [视差算法](./doc/立体匹配算法.md)
15. [warpped libelas with opencv and used pangolin as GUI](https://github.com/HeYijia/stereo_elas)

#### 8.部分框图
<div align=center><img src="./doc/flowchart.png"/></div>

#### 9.未来计划
1. [参考](http://blog.csdn.net/hysteric314/article/details/51357318).<br>
2. pthread改为跨平台依赖获取方式.<br>
3. 简化CMake过程中依赖路径的设置.<br>
4. 跨平台移植测试.<br>