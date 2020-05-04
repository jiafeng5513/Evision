#include <Utils.h>
#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

/*
输入:左视图和原始视差数据,相机标定数据文件
操作:标点,获得相机坐标系坐标,转换为世界坐标,
     按顺序标完4个点,计算长宽高
     询问是否修正
     修正完毕,生产PLY
     这道程序的任务就完成
输出:PLY网格文件
*/ 
/*
              Z
              |
              |
            V4 ---------- V5
            / |         /|
         V6/__|______V7/ |
           |  |        | |
           |  V0_ _ _ _|_|V1 _ _Y
           | /         |/
          V2----------V3
          /
         X
询问顺序是V4->V6->V7->V2
*/

//全局变量
int KeyPoints[4][2];
int KeyPointCount = 0;
cv::Mat imgToShow;
bool QuestionOver = false;
const std::string winname = "Semi-Automatic Ply Builder";
// 鼠标点击事件
static void onMouseDown(int event, int x, int y, int, void*)
{
    if (event == cv::EVENT_LBUTTONUP)
    {
        KeyPoints[KeyPointCount][0] = x;
        KeyPoints[KeyPointCount][1] = y;
        //绘图
        cv::circle(imgToShow, cv::Point2d(x,y), 4, cv::Scalar(0,255,0), -1, 8);
        KeyPointCount++;
        if (KeyPointCount >= 4) {
            QuestionOver = true;
            return;
        }
        std::cout << "请标下一个点" << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    std::string cameraParamFile = "";
    std::string leftImgFile = "";
    std::string RawDispFile = "";

    //step 1 :打开文件,读取Q矩阵,左图,原始视差数据
    cv::Mat Q, img, RawDisp;
    cv::FileStorage fStorage(cameraParamFile, cv::FileStorage::READ);
    fStorage["Q"] >> Q;
    fStorage.release();
    img = cv::imread(leftImgFile);
    cv::FileStorage fStorage(RawDispFile, cv::FileStorage::READ);
    fStorage["disp"] >> RawDisp;

    //step 2: 标点,获得四个图像坐标
    imgToShow = img.clone();
    cv::namedWindow(winname);
    std::cout << "|======================================================|" << std::endl;
    std::cout << "|                      Z                               |" << std::endl;
    std::cout << "|                      |                               |" << std::endl;
    std::cout << "|                      |                               |" << std::endl;
    std::cout << "|                    V4 ---------- V5                  |" << std::endl;
    std::cout << "|                    / |         /|                    |" << std::endl;
    std::cout << "|                 V6/__|______V7/ |                    |" << std::endl;
    std::cout << "|                   |  |        | |                    |" << std::endl;
    std::cout << "|                   |  V0_ _ _ _|_|V1 _ _Y             |" << std::endl;
    std::cout << "|                   | /         |/                     |" << std::endl;
    std::cout << "|                  V2----------V3                      |" << std::endl;
    std::cout << "|                  /                                   |" << std::endl;
    std::cout << "|                 X                                    |" << std::endl;
    std::cout << "|程序会依次询问V4->V6->V7->V2的位置,请用鼠标标出这些点!|" << std::endl;
    std::cout << "|======================================================|" << std::endl;
    std::cout << "请标V4" << std::endl;
    while (!QuestionOver)
    {
        cv::imshow(winname, imgToShow);
    }
    //step 3: 获取四个图像坐标对应的世界坐标
    cv::Point3f V4;
    getWorldCoordinate(RawDisp, Q, KeyPoints[0][0], KeyPoints[0][1], V4);
    cv::Point3f V6;
    getWorldCoordinate(RawDisp, Q, KeyPoints[1][0], KeyPoints[1][1], V6);
    cv::Point3f V7;
    getWorldCoordinate(RawDisp, Q, KeyPoints[2][0], KeyPoints[2][1], V7);
    cv::Point3f V2;
    getWorldCoordinate(RawDisp, Q, KeyPoints[3][0], KeyPoints[3][1], V2);
    //step 4: 计算长宽高
    float length = sqrt(pow(V4.x - V6.x,2) + pow(V4.y - V6.y, 2) + pow(V4.z - V6.z, 2));
    float width = sqrt(pow(V7.x - V6.x, 2) + pow(V7.y - V6.y, 2) + pow(V7.z - V6.z, 2));
    float height = sqrt(pow(V2.x - V6.x, 2) + pow(V2.y - V6.y, 2) + pow(V2.z - V6.z, 2));
    //step 5: 询问修正
    std::cout << "请确认尺寸:" << std::endl;
    std::cout << "length(V4-V6):" << length << std::endl;
    std::cout << "width(V7-V6):" << width << std::endl;
    std::cout << "height(V2-V6):" << height << std::endl;
    std::cout << "是否要修改? y for yes,n for no." << std::endl;
    char ans;
    std::cin >> ans;
    if (ans == 'y') {
        std::cout << "length(V4-V6) = " << length << ",修改为:"<< std::endl;
        std::cin >> length;
        std::cout << "width(V7-V6):" << width << ",修改为:" << std::endl;
        std::cin >> width;
        std::cout << "height(V2-V6):" << height << ",修改为:" << std::endl;
        std::cin >> height;
        std::cout<<"修正完毕!(l,w,h)=("<< length<<","<< width<<","<< height<<")" << std::endl;
    }
    //step 6: 输出ply
    std::vector<float> size;
    size.push_back(length);
    size.push_back(width);
    size.push_back(height);
    createCubePly(size, "E:/VisualStudio/Tracker/VideoTracker/Data/test_reg/cube_cpp.ply");
    std::cout << "ply创建完毕!" << length << std::endl;
    return 0;
}

//获取世界坐标
//如果获取失败,就返回false,获取成功返回true
bool getWorldCoordinate(cv::Mat& disparity, cv::Mat& Q, int ix, int iy, cv::Point3f & point)
{

	// Read out Q Values for faster access
	double Q03 = Q.at<double>(0, 3);
	double Q13 = Q.at<double>(1, 3);
	double Q23 = Q.at<double>(2, 3);
	double Q32 = Q.at<double>(3, 2);
	double Q33 = Q.at<double>(3, 3);


	// Read disparity
	float d = disparity.at<float>(iy, ix);

    if (d <= 0) { //Discard bad pixels
        return false; 
    } 

	// Transform 2D -> 3D and normalise to point
	double x = Q03 + ix;
	double y = Q13 + iy;
	double z = Q23;
	double w = (Q32 * d) + Q33;

    point.x = -x / w;
    point.y = -y / w;
    point.z = z / w;
    
    return true;
}
