只使用双目视觉,不使用CUDA和目标检测时的build指南
====================
1. 打开Evision.sln<br>
2. 删除yolo_gpu项目.<br>
3. 在项目Evision的`附加依赖项`中,删除yolo_gpu.lib<br>
4. 在项目Evision的`延迟加载的DLL`中,删除yolo_gpu.dll<br>
5. 在项目Evision的Engine目录下,删除ObjectDetectionEngine.h和ObjectDetectionEngine.cpp<br>
6. 在项目Evision的Entity目录下,删除ObjectDetectionEntity.h和ObjectDetectionEntity.cpp<br>
7. 在项目Evision的View目录下,有ObjectDetectionView的类,从中删除相关的依赖<br>
8. 此时,与CUDA相关的代码已经删除完毕,整理项目,把由于刚刚删除代码导致的未定义类型和标识符的引用一并删除.<br>
9. 此时目标检测功能已经无法使用.<br>


### 如果您没有信心完成上述操作,可以使用不含没目标检测的一个release版本,但是这个版本可能也会缺少一些后续添加的功能.