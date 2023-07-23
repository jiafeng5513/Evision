<div align=center><img width="100" height="100" src="./src/EvisionSandbox/resource/Evision.ico"/></div>

<div align=center>Evision 双目视觉系统</div>
<div align=center><a href="https://www.bilibili.com/video/av46024738">演示视频</a></div>
<div align=center></div>
<div align=center>如果您觉得有帮助,请为该项目点star.以便于及时收到最新更新.</div>

## 重要提示:Evision已支持vcpkg


Introduction:
=========

1. 双目系统的标定,畸变校正,视差,三维重建,距离测量等.<br>
2. 基于Yolo的实时目标检测.<br>
3. ELAS,ADCensus视差算法.<br>
4. 关于双目的中文资料重复度太高,希望各位后来者能够吸取前人精华,摒弃前人的糟粕,多多自行探索,不要抄来抄去.<br>
5. 关于程序的BUG,以及其他困惑,请使用issues,或联系邮件jiafeng5513@outlook.com.<br>
6. Evision使用cmake-vcpkg工具链进行编译,开发者使用Visual Studio 2019作为IDE.<br>
7. 轻量版正在开发,请查看作者的GitHUb仓库并搜索"EvisionLight",未来Evision会采用ImgUI作为界面,不再基于Qt,以提供更方便的安装体验,并提高运行效率.<br>

资助作者
========
<div align=center><img width="500" height="339" src="./doc/pay.png"/></div>


目录
=========
- [Introduction:](#introduction)
- [资助作者](#资助作者)
- [目录](#目录)
      - [1.Dependencies](#1dependencies)
      - [2.Directory_specification](#2directory_specification)
      - [3.build](#3build)
      - [4.Deprecated_Version](#4deprecated_version)
      - [5.双目设备](#5双目设备)
      - [6.参考文献](#6参考文献)
      - [7.未来计划](#7未来计划)

#### 1.路径说明
1. `data`文件夹存储测试用例.<br>
2. `doc`文件夹中存储的是文档和文档中所用的图片等资源,提供了本项目使用的一些算法相关的论文.<br>
3. `package`文件夹存储项目所需的依赖.<br>
4. `props`中存储的是属性表<br>
5. `scripts`文件夹存储编译脚本.<br>
6. `src`文件夹中存放代码文件.<br>
7. `legacy`文件夹中存放的是一些有一定保留价值的弃用模块.<br>
* `scripts`是作者开发期间使用的,对于使用者没有实际意义.<br>
* `package`中含有pthread的window版本,将会在未来改为使用CMake管理.<br>

#### 2.编译基础组件
1. 安装visual studio 2019 + 使用C++的桌面开发工作负载 + 英文语言包.([visual studio Installer](https://visualstudio.microsoft.com/zh-hans/vs/))<br>
2. 安装CMake 3.20.([Download CMake](https://cmake.org/download/))<br>
3. 安装vcpkg.([GitHub For vcpkg](https://github.com/Microsoft/vcpkg))<br>
4. `vcpkg install eigen:x64-windows`<br>
5. `vcpkg install opencv:x64-windows`<br>
6. `vcpkg install boost:x64-windows`<br>
7. `vcpkg install pcl:x64-windows`<br>
8. `vcpkg install qt5:x64-windows`<br>
9. `mkdir sln,cd sln`<br>
10. `cmake ..\src\ -DCMAKE_TOOLCHAIN_FILE="${vcpkg_root}/vcpkg/scripts/buildsystems/vcpkg.cmake" -G"Visual Studio 16" -DPointCloudViewer=ON`<br>
11. 使用visual studio打开Evision.sln.<br>
12. 右键_CMakeTargets/ALL_BUILD,生成.<br>
13. 右键EvisionSandBox,设为启动项目.<br>
14. 点击"本地Windows调试器",启动程序.<br>
* 如果vcpkg下载包的速度过慢,可以上代理(以PowerShell为例)`$env:HTTP_PROXY="http://127.0.0.1:1080"`

#### 3.编译目标检测和硬件加速模块
1. 必须具备支持CUDA的NVIDIA显卡.<br>
2. 安装CUDA 10.2.<br>
3. 基础组件编译并运行成功.
4. `cd sln, rm -r * `<br>
5. `cmake ..\src\ -DCMAKE_TOOLCHAIN_FILE="${vcpkg_root}/vcpkg/scripts/buildsystems/vcpkg.cmake" -G"Visual Studio 16" -DPointCloudViewer=ON -DObjectDetection`<br>
6. 使用visual studio打开Evision.sln.<br>
7. 右键_CMakeTargets/ALL_BUILD,生成.<br>
8. 右键EvisionSandBox,设为启动项目.<br>
9. 点击"本地Windows调试器",启动程序.<br>

#### 4.模块说明   
|      |模块名|功能|UI|输出目标|
|:----:|:----:|:----:|:----:|:----:|
| 1|EvisionADCensus           |ADCensus视差算法  | ×    |动态链接库|
| 2|EvisionElas               |Elas视差算法      | ×    |动态链接库|
| 3|EvisionPnP                |PnP              | ×    |动态链接库|
| 4|EvisionObjDetection       |目标检测UI        | √    |动态链接库|
| 5|EvisionObjDetectionEngine |目标检测算法      | ×   |动态链接库| 
| 6|EvisionMonocularCalib     |单目标定          | √    |动态链接库|
| 7|EvisionPolyTracker        |单目几何体追踪     | √    |动态链接库|
| 8|EvisionCalibrate          |双目标定          | √    |动态链接库|
| 9|EvisionDisparity          |视差(立体匹配)    |√   |动态链接库|
|10|EvisionTrace              |交互式测量        | √   |动态链接库|
|11|EvisionUndistortion       |畸变校正          | √   |动态链接库|  
|12|EvisionCamera             |单目和双目相机功能 | √    |动态链接库|   
|13|EvisionCloudViewer        |三维点云查看      | √    |动态链接库|
|14|EvisionParamBridge        |外部参数传递      | √   |动态链接库|  
|15|EvisionUtils              |通用工具类        | ×   |动态链接库|    
|16|EvisionSandbox            |主程序UI          | √    |可执行程序|


#### 5.Deprecated_Version
1. MFC版本.[演示视频](https://www.bilibili.com/video/av8862669).<br>
   基于[邹宇华老师的StereoVision](https://github.com/yuhuazou/StereoVision)编写.如有需要推荐访问邹宇华老师原版或者在本项目的Release中寻找,由于使用的依赖较为陈旧,强烈不建议继续使用或进行二次开发.<br>
2. CvLabMain和CvLabSandbox(C#版本)<br>
   * 用VS打开`src/CvLib.sln`,将会看到两个工程,该版本存在的目的是为了记录在C#平台上实现相似功能的方法,并没有实现Evision的全部功能,一般情况下不会更新,不推荐使用.<br>
    ![image](./doc/cvlib_sln.png)
   1. CvLabMain是用WPF框架写的.<br>
   2. CvLabSandbox是用WinFrom写的.<br>
   3. Docking风格MDI界面<br>
   4. 使用MVP设计模式,交互基于双向数据绑定<br>
   5. 运行时为`.NET 4.6.1`,依赖采用Nuget下载<br>
   6. packages:<br>
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

#### 8.未来计划
1. [参考](http://blog.csdn.net/hysteric314/article/details/51357318).<br>





编译opencv
cmake -DBUILD_opencv_world=TRUE -DBUILD_opencv_dnn=TRUE -DWITH_FFMPEG=TRUE -DWITH_GSTREAMER=FALSE -DCMAKE_INSTALL_PREFIX=<your install path>

devenv .\OpenCV.sln /Build "Debug|x64"  /Project "ALL_BUILD"
devenv .\OpenCV.sln /Build "Debug|x64"  /Project "INSTALL"
devenv .\OpenCV.sln /Build "Release|x64"  /Project "ALL_BUILD"
devenv .\OpenCV.sln /Build "Release|x64"  /Project "INSTALL"
