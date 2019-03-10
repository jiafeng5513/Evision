SLAM-simultaneous localization and mapping-并发建图与定位
=====
### 数据集
1. KITTI数据集:http://www.cvlibs.net/datasets/kitti/
2. http://vision.middlebury.edu/stereo/data/scenes2014/
### 参考
0. LIBVISO2(LibViso1)
网站:http://www.cvlibs.net/software/libviso/

1. DynSLAM
网站:https://siegedog.com/dynslam/
论文:BARSAN-IoanAndrei-RobustDenseMapping-ICRA-2018-CameraReady
代码:https://github.com/AndreiBarsan/DynSLAM

2. stereo-vision
代码:https://github.com/willSapgreen/stereo-vision
基于libviso2,libelas的qt程序,linux C++
作者：无语西
链接：https://zhuanlan.zhihu.com/p/38252296
来源：知乎
1、libelas：这个库的作用是用于计算视差图，通过输入校准好的双目图片，可以快速的计算出点和相机之间的距离。
2、libviso2：这个库提供了视觉里程计，在没有已知的pose时就需要用这个去计算。（11年的paper，用的好像不是现在流行的BA优化而是EKF，这部分我没仔细看不是非常了解，自己运行的时候画出来误差比较大，因为不存在闭环检测环节所以误差会一直累计。）3、stereomapper：这个就是画图用的代码，基于Qtgui，使用opengl绘图。maindialog.cpp 这个是程序的主窗口，QThread线程的运行逻辑都在这个文件里面，首先是读取标定文件和图片的时间戳，确认以上文件存在后，开始读取图片（线程1），检测到新图片后开始计算位姿（线程2），有位姿和他们对应的图片后进行三维重建（线程3）。readfromfilesthread.cpp 读取本地标定文件以及图片的线程，这个线程里面读取到标定参数后会进入读取图片的循环，以设定的速度读取本地的双目图片，并调用Stereoimage类里面的函数，将时间戳一样的图片复制进内存stereoimage.cpp 将图片按elas和viso2需要的格式保存进内存的类visualodometrythread.cpp 计算位姿的线程，在有图片保存进内存后会触发，读取当前的图片并调用viso2计算出位姿，里面有判定计算出来的位姿是否合格的程序（这里viso2就是一个视觉里程计，我这部分没有深入研究，具体请看viso2的Paper）stereothread.cpp 这个是建立三维地图的线程，在这个线程中，会接收到主线程递过来的图片以及对应的位姿，然后调用elas，计算出视差图，再将二维灰度图加上深度信息，成为三维的灰度图，最后是当前帧的三维图乘以位姿，得到在世界坐标系中的三维地图。view3d.cpp 画图的程序，使用opengl进行渲染，画出三维地图。

3. Google 单目深度获取
网站:https://ai.googleblog.com/2018/11/a-structured-approach-to-unsupervised.html
论文已投AAAI 2019:Depth Prediction Without the Sensors: Leveraging Structure for Unsupervised Learning from Monocular Videos
代码:https://github.com/tensorflow/models/tree/master/research/struct2depth






### 其他参考
作者：Hengkai Guo
链接：https://www.zhihu.com/question/66006923/answer/238601811
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

深度学习在SLAM上目前有不少文章了，简单列一下最近的工作：
CNN-SLAM[1]为今年CVPR的文章，是比较完整的pipeline，将LSD-SLAM里的深度估计和图像匹配都替换成基于CNN的方法，取得了更为robust的结果，并可以融合语义信息。见http://campar.in.tum.de/Chair/ProjectCNNSLAM。类似的工作还有[2]。

VINet[3]是今年AAAI的文章，利用CNN和RNN构建了一个VIO，即输入image和IMU信息，直接输出估计的pose。

[4]是Magic Leap放出来的文章，说是Deep SLAM，其实只是用CNN做了SLAM中提取特征点和匹配特征点的两个模块，在CPU上实时。

[5]是Google 今年CVPR的oral文章，利用CNN学习一个无监督的深度估计和pose估计网络，代码见tinghuiz/SfMLearner。

SfM-Net[6]利用监督学习也干了类似的工作。其他包括重定位[7][8]、语义地图[9]、回环检测等也有一些工作，这里不赘述。这些工作大部分都是针对单目来做的，因为单目尺度未知，正好需要CNN进行脑补。

个人觉得，基于CNN的方法由于局限于训练数据，目前除了回环和语义以外，其它方面在数据集或者受限场景以外尚未达到可用的效果。欢迎交流。

参考文献：
[1] Tateno K, Tombari F, Laina I, et al. CNN-SLAM: Real-time dense monocular SLAM with learned depth prediction[J]. arXiv preprint arXiv:1704.03489, 2017.[2] Li R, Wang S, Long Z, et al. UnDeepVO: Monocular Visual Odometry through Unsupervised Deep Learning[J]. arXiv preprint arXiv:1709.06841, 2017.
[3] Clark R, Wang S, Wen H, et al. VINet: Visual-Inertial Odometry as a Sequence-to-Sequence Learning Problem[C]//AAAI. 2017: 3995-4001.
[4] DeTone D, Malisiewicz T, Rabinovich A. Toward Geometric Deep SLAM[J]. arXiv preprint arXiv:1707.07410, 2017.
[5] Zhou T, Brown M, Snavely N, et al. Unsupervised learning of depth and ego-motion from video[J]. arXiv preprint arXiv:1704.07813, 2017.
[6] Vijayanarasimhan S, Ricco S, Schmid C, et al. SfM-Net: Learning of Structure and Motion from Video[J]. arXiv preprint arXiv:1704.07804, 2017.
[7] Wu J, Ma L, Hu X. Delving deeper into convolutional neural networks for camera relocalization[C]//Robotics and Automation (ICRA), 2017 IEEE International Conference on. IEEE, 2017: 5644-5651.
[8] Kendall A, Grimes M, Cipolla R. Posenet: A convolutional network for real-time 6-dof camera relocalization[C]//Proceedings of the IEEE international conference on computer vision. 2015: 2938-2946.
[9] Li X, Belaroussi R. Semi-Dense 3D Semantic Mapping from Monocular SLAM[J]. arXiv preprint arXiv:1611.04144, 2016.

深度学习SLAM——CNN-SLAM: Real-time dense monocular SLAM
https://zhuanlan.zhihu.com/p/35062953