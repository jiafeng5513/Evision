#### 0. 安装visual studio
1. 至微软官网下载[visual studio Installer](https://visualstudio.microsoft.com/zh-hans/vs/).
2. 执行visual studio Installer.
   * 工作负载`中勾选`使用C++的桌面开发`.<br>
   * 语言包中选择`中文`和`英语`,(注意必须安装英语,否则无法使用vcpkg).<br>
其他工作负载和组件按需选择,推荐不要修改安装路径.
3. 至github下载[vcpkg](https://github.com/Microsoft/vcpkg),按照说明安装.
4. 使用vcpkg安装如下依赖:
    * opencv.<br>
    * pcl.<br>
    * qt5.<br>
    * boost.<br>
    * eigen.<br>
    注意,如果下载缓慢,可以启用代理.由于windows平台的终端种类比较多,这里以PowerShell为例.首先启动代理(代理手段请自行解决),然后启动PowerShell,设置代理: 
    ```shell
    $env:HTTP_PROXY="http://127.0.0.1:1080"
    ```
    随后执行`vcpkg install ***`,注意代理的生效时间为单次会话,关闭会话后代理就会失效.
5. 至官网下载[CMake](https://cmake.org/download/)并安装.
6. 启动CMake-gui

#### 1. 安装vcpkg

#### 2. 安装依赖

#### 3.