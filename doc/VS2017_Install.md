VS2017安装指南
=====================

1. VS2017只能安装到Windows 7以及更新版本的64位系统上,需要不少于40GB的C盘空余空间.<br>
2. 下载安装引导程序.<br>
[Visual Studio Community 2017 官网下载地址](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=15)
> 额外说明: 
> 1. 该项目的开发者使用的是Visual Studio Enterprise 2017,但是在该项目的开发过程中并没有使用Enterprise版本的特有功能.<br>
> 2. Community版本虽然是免费使用的,但是必须尽快登录自己的Microsoft账号,否则在大概一个月之后,你的Visual Studio授权将会过期无法使用.所以如果您没有微软账号,借此机会注册一个.<br>
3. 执行安装引导程序,请注意以下图片中着重标记的模块是本项目所必须的,实际上也是大部分C++项目所必须的,其他选中但是没有标记的模块,是与.Net相关的,因为项目的开发者同时还做.NET程序,但是如果您对于.NET不感兴趣,完全可以不安装那些组件.虽然如此,但是有些被默认选中的.NET组件的安装是无法被取消的.<br>

4. 强烈建议将Visual Studio 安装到C盘.原因是即使你安装到别的分区,依然会有很大一部分组件必须安装到C盘,而这将会导致你的VS中的某些路径与其他人完全不同,这也许会引起一些不必要的麻烦.此外,如果您的C盘是固态磁盘驱动器,那么将会大幅度提高您的VS的打开和编译生成速度.<br>
使用C++的桌面开发<br>
![image](https://github.com/AngelaViVi/Evision/blob/master/doc/vs1.png)
Windows 10 SDK(10.0.17134.0)<br>
![image](https://github.com/AngelaViVi/Evision/blob/master/doc/vs2.png)
Windows 通用C运行时<br>
用于x86和x64的Visual C++ ATL<br>
用于x86和x64的Visual C++ MFC<br>
Visual C++核心功能<br>
VC++2017版本15.8 v14.15最新v141工具集<br>
Windows 通用CRT SDK<br>
对C++的Windows XP支持.<br>
![image](https://github.com/AngelaViVi/Evision/blob/master/doc/vs3.png)

5. 如果您以前使用过其他版本的VS,但是现在只想用最新版的,想彻底卸载掉旧版程序,推荐您使用微软官方的卸载工具:<br>
[旧版VS卸载工具](https://github.com/Microsoft/VisualStudioUninstaller/releases/download/v1.4/TotalUninstaller.zip)
以管理员权限执行其中的`Setup.ForcedUninstall.exe`,耐心等待程序运行完毕,即可干净的卸载旧版本的VS.注意,这个工具不能卸载VS2017.

6. 如果您想卸载VS2017,那么不用担心,只要在开始菜单中找到"Visual Studio Installer",运行他,就能看到卸载按钮,使用这个工具能够干净的卸载掉VS2017.