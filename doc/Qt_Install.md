Qt 安装指南
======

1. 下载Qt安装包和Visual Studio 2017的Qt 插件.<br>
> [Qt下载地址](http://download.qt.io/archive/qt/5.12/5.12.0/qt-opensource-windows-x86-5.12.0.exe)
> [VS2017的Qt插件下载地址](https://mirrors.tuna.tsinghua.edu.cn/qt/archive/vsaddin/qt-vsaddin-msvc2017-2.3.1.vsix)

2. 执行安装程序,注意第三张图片中所选择的组件.<br>
![image](https://github.com/AngelaViVi/Evision/blob/master/doc/qtinstall_1.png)
![image](https://github.com/AngelaViVi/Evision/blob/master/doc/qtinstall_2.png)
![image](https://github.com/AngelaViVi/Evision/blob/master/doc/qtinstall_3.png)
3. 等待安装完毕.<br>

4. 设置环境变量.<br>
在环境变量的系统变量/path中,添加Qt安装目录下的`...\Qt5.12.0\5.12.0\msvc2017_64\bin`目录,注意不要复制本文中的目录,要根据自己的实际情况填写.<br>

5. 如果此时您已经完成了VS2017的安装,那么请关闭VS2017,然后执行VS2017的Qt插件安装包即可.<br>