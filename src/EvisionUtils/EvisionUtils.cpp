#include "EvisionUtils.h"
#include <sstream>
#include <QFileInfo>

EvisionUtils::EvisionUtils()
{
}


EvisionUtils::~EvisionUtils()
{
}
/*
 * 获取当前路径
 */
std::string EvisionUtils::getCurrentPath()
{
	std::ostringstream ss;
	ss << _pgmptr;
	std::string abspath = ss.str();
	int last_slash_pos = abspath.rfind("\\");
	std::string path = abspath.substr(0, last_slash_pos);
	return path;
}
/*
 * 路径整理
 */
std::string EvisionUtils::pathPurify(std::string& src)
{
	QString str1 = QString::fromStdString(src);
	QString str2 = str1.replace(QRegExp("\\\\"), "/");
	QFileInfo* fileinfo = new QFileInfo(str2);
	if (fileinfo->exists())
	{
		return fileinfo->absoluteFilePath().toStdString();
	}
	return str2.toStdString();
}

std::string EvisionUtils::getDataPath()
{
	return EvisionUtils::pathPurify(EvisionUtils::getCurrentPath() + "\\..\\..\\..\\data");
}

/*
 * cv::Mat转换为QImage
 */
QImage EvisionUtils::cvMat2QImage(const cv::Mat& mat)
{
	cv::Mat mat_8;
	switch (mat.channels())
	{
	case 1:
		mat.convertTo(mat_8, CV_8UC1);
		break;
	case 2:
		mat.convertTo(mat_8, CV_8UC2);
		break;
	case 3:
		mat.convertTo(mat_8, CV_8UC3);
		break;
	case 4:
		mat.convertTo(mat_8, CV_8UC4);
		break;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if (mat_8.type() == CV_8UC1)
	{
		QImage image(mat_8.cols, mat_8.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = mat_8.data;
		for (int row = 0; row < mat_8.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat_8.cols);
			pSrc += mat_8.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if (mat_8.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat_8.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat_8.cols, mat_8.rows, mat_8.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat_8.type() == CV_8UC4)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat_8.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat_8.cols, mat_8.rows, mat_8.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return getDefaultImage();
	}
}

/*
 * QImage转换为cv::Mat
 */
cv::Mat EvisionUtils::QImage2cvMat(QImage image)
{
	cv::Mat mat;
	//qDebug() << image.format();
	switch (image.format())
	{
	case QImage::Format_ARGB32:
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32_Premultiplied:
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
		break;
	case QImage::Format_RGB888:
		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
		cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
		break;
	case QImage::Format_Indexed8:
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	return mat;
}

/*
* 灰度图转彩虹图
*/

cv::Mat EvisionUtils::gray2rainbowcolor(cv::Mat& img) {
	cv::Mat img_color = cv::Mat::zeros(img.rows, img.cols, CV_8UC3);
#define IMG_B(img,y,x) img.at<cv::Vec3b>(y,x)[0]
#define IMG_G(img,y,x) img.at<cv::Vec3b>(y,x)[1]
#define IMG_R(img,y,x) img.at<cv::Vec3b>(y,x)[2]
	uchar tmp2 = 0;
	//转为彩虹图的具体算法，主要思路是把灰度图对
	//应的0～255的数值分别转换成彩虹色：红、橙、黄、绿、青、蓝。
	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			tmp2 = img.at<uchar>(y, x);
			if (tmp2 == 0)
				continue;
			if (tmp2 <= 51)
			{
				IMG_B(img_color, y, x) = 255;
				IMG_G(img_color, y, x) = tmp2 * 5;
				IMG_R(img_color, y, x) = 0;
			}
			else if (tmp2 <= 102)
			{
				tmp2 -= 51;
				IMG_B(img_color, y, x) = 255 - tmp2 * 5;
				IMG_G(img_color, y, x) = 255;
				IMG_R(img_color, y, x) = 0;
			}
			else if (tmp2 <= 153)
			{
				tmp2 -= 102;
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = 255;
				IMG_R(img_color, y, x) = tmp2 * 5;
			}
			else if (tmp2 <= 204)
			{
				tmp2 -= 153;
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = 255 - uchar(128.0 * tmp2 / 51.0 + 0.5);
				IMG_R(img_color, y, x) = 255;
			}
			else
			{
				tmp2 -= 204;
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = 127 - uchar(127.0 * tmp2 / 51.0 + 0.5);
				IMG_R(img_color, y, x) = 255;
			}
		}
	}
	return img_color;
}
/*
 * 创建并返回idle image
 */
QImage EvisionUtils::getDefaultImage()
{
	//图片上的字符串，例如 HELLO
	QString imageText = "Evision";
	QFont font;
	
	font.setPixelSize(13);//设置显示字体的大小


	QFontMetrics fm(font);
	int charWidth = fm.width(imageText);
	charWidth = fm.boundingRect(imageText).width();
	
	QSize size(charWidth + 8, 15);//指定图片大小为字体的大小
	//QSize size(1920, 1080);//指定图片大小为字体的大小


	//以ARGB32格式构造一个QImage
	QImage image(size, QImage::Format_ARGB32);
	//填充图片背景,120/250为透明度
	image.fill(qRgba(255, 255, 255, 0));


	//为这个QImage构造一个QPainter
	QPainter painter(&image);
	//设置画刷的组合模式CompositionMode_SourceOut这个模式为目标图像在上。
	//改变组合模式和上面的填充方式可以画出透明的图片。
	painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);


	//改变画笔和字体
	QPen pen = painter.pen();
	pen.setColor(QColor(0, 141, 239));


	painter.setPen(pen);
	painter.setFont(font);


	//将Hello写在Image的中心
	painter.drawText(image.rect(), Qt::AlignCenter, imageText);
	return image;
}

void EvisionUtils::ShowImageOnUi(cv::Mat& img, QGraphicsScene* sense, QGraphicsView* view)
{
	sense->clear();
	sense->addPixmap(QPixmap::fromImage(cvMat2QImage(img)));
	view->setScene(sense);
	view->fitInView(sense->itemsBoundingRect(), Qt::KeepAspectRatio);
	view->centerOn(0, 0);
	view->show();
	view->update();
}

/*
 * 把双目标定得到的所有参数写入文件
 * 1.文件名							std::string filename
 * 2.相机矩阵1(相对焦距和主点坐标)	cv::Mat& cameraMatrix1
 * 3.畸变系数1						cv::Mat& distCoeffs1
 * 4.相机矩阵2						cv::Mat& cameraMatrix2
 * 5.畸变系数2						cv::Mat& distCoeffs2
 * 6.两个相机之间的旋转				cv::Mat& R
 * 7.两个相机之间的平移				cv::Mat& T
 * 8.本质矩阵						cv::Mat& E
 * 9.基本矩阵						cv::Mat& F
 * 10.图片尺寸						cv::Size& imageSize,
 * 11.旋转映射矩阵1                 cv::Mat& R1,
 * 12.投影映射矩阵1                 cv::Mat& P1,
 * 13.旋转映射矩阵2                 cv::Mat& R2,
 * 14.投影映射矩阵2                 cv::Mat& P2,
 * 15.三维映射矩阵                  cv::Mat& Q,
 * 16.矫正后的roi1                  cv::Rect& roi1,
 * 17.矫正后的roi2                  cv::Rect& roi2
 * 返回值:
 *	成功:true,失败和出错:false
 */
bool EvisionUtils::write_AllCameraParams(std::string& filename, cv::Mat& cameraMatrix1, cv::Mat& distCoeffs1,
	cv::Mat& cameraMatrix2, cv::Mat& distCoeffs2, cv::Mat& R, cv::Mat& T, cv::Size& imageSize,
	cv::Mat& R1, cv::Mat& P1, cv::Mat& R2, cv::Mat& P2, cv::Mat& Q, cv::Rect& roi1, cv::Rect& roi2)
{
	if (filename.empty() == true)
	{
		return false;
	}
	try
	{
		cv::FileStorage fs(filename, cv::FileStorage::WRITE);
		if (fs.isOpened())
		{
			fs << "cameraMatrix1" << cameraMatrix1;
			fs << "distCoeffs1" << distCoeffs1;
			fs << "cameraMatrix2" << cameraMatrix2;
			fs << "distCoeffs2" << distCoeffs2;
			fs << "R" << R;
			fs << "T" << T;
			fs << "imageSize" << imageSize;
			fs << "R1" << R1;
			fs << "P1" << P1;
			fs << "R2" << R2;
			fs << "P2" << P2;
			fs << "Q" << Q;
			fs << "roi1" << roi1;
			fs << "roi2" << roi2;
			fs.release();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}

bool EvisionUtils::write_MonocularCameraParams(std::string& filename, cv::Mat& cameraMatrix1, cv::Mat& distCoeffs1, cv::Size& imageSize)
{
	if (filename.empty() == true)
	{
		return false;
	}
	try
	{
		cv::FileStorage fs(filename, cv::FileStorage::WRITE);
		if (fs.isOpened())
		{
			fs << "cameraMatrix1" << cameraMatrix1;
			fs << "distCoeffs1" << distCoeffs1;
			fs << "imageSize" << imageSize;
			fs.release();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}


/*
 * 从文件中读取双目标定得到的参数
 * 1.文件名							std::string filename
 * 2.相机矩阵1(相对焦距和主点坐标)	cv::Mat* cameraMatrix1
 * 3.畸变系数1						cv::Mat* distCoeffs1
 * 4.相机矩阵2						cv::Mat* cameraMatrix2
 * 5.畸变系数2						cv::Mat* distCoeffs2
 * 6.两个相机之间的旋转				cv::Mat* R
 * 7.两个相机之间的平移				cv::Mat* T
 * 8.本质矩阵						cv::Mat* E
 * 9.基本矩阵						cv::Mat* F
 * 10.图片尺寸						cv::Size* imageSize,
 * 11.旋转映射矩阵1                 cv::Mat* R1,
 * 12.投影映射矩阵1                 cv::Mat* P1,
 * 13.旋转映射矩阵2                 cv::Mat* R2,
 * 14.投影映射矩阵2                 cv::Mat* P2,
 * 15.三维映射矩阵                  cv::Mat* Q,
 * 16.矫正后的roi1                  cv::Rect* roi1,
 * 17.矫正后的roi2                  cv::Rect* roi2
 * 返回值:
 *	成功:true,失败和出错:false
 */
bool EvisionUtils::read_AllCameraParams(std::string& filename, cv::Mat* cameraMatrix1, cv::Mat* distCoeffs1,
	cv::Mat* cameraMatrix2, cv::Mat* distCoeffs2, cv::Mat* R, cv::Mat* T, cv::Mat* E, cv::Mat* F, cv::Size* imageSize,
	cv::Mat* R1, cv::Mat* P1, cv::Mat* R2, cv::Mat* P2, cv::Mat* Q, cv::Rect* roi1, cv::Rect* roi2)
{
	if (filename.empty() == true)
	{
		return false;
	}
	try
	{
		cv::FileStorage fs(filename, cv::FileStorage::READ);
		if (fs.isOpened())
		{
			fs["cameraMatrix1"] >> *cameraMatrix1;
			fs["distCoeffs1"] >> *distCoeffs1;
			fs["cameraMatrix2"] >> *cameraMatrix2;
			fs["distCoeffs2"] >> *distCoeffs2;
			fs["R"] >> *R;
			fs["T"] >> *T;
			fs["E"] >> *E;
			fs["F"] >> *F;
			fs["imageSize"] >> *imageSize;
			fs["R1"] >> *R1;
			fs["P1"] >> *P1;
			fs["R2"] >> *R2;
			fs["P2"] >> *P2;
			fs["Q"] >> *Q;
			fs["roi1"] >> *roi1;
			fs["roi2"] >> *roi2;
			fs.release();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}
bool EvisionUtils::read_MonocularParams(std::string& filename, cv::Mat* cameraMatrix1, cv::Mat* distCoeffs1, cv::Size* imageSize)
{
	if (filename.empty() == true)
	{
		return false;
	}
	try
	{
		cv::FileStorage fs(filename, cv::FileStorage::READ);
		if (fs.isOpened())
		{
			fs["cameraMatrix1"] >> *cameraMatrix1;
			fs["distCoeffs1"] >> *distCoeffs1;
			fs["imageSize"] >> *imageSize;
			fs.release();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}
/*
 * 读取匹配所需的参数
 */
bool EvisionUtils::read_ParamsForStereoMatch(std::string& filename, cv::Mat* cameraMatrix1, cv::Mat* distCoeffs1,
	cv::Mat* cameraMatrix2, cv::Mat* distCoeffs2, cv::Mat* R1, cv::Mat* P1, cv::Mat* R2, cv::Mat* P2, cv::Mat* Q, cv::Rect* roi1,
	cv::Rect* roi2)
{
	if (filename.empty()==true)
	{
		return false;
	}
	try
	{
		cv::FileStorage fs(filename, cv::FileStorage::READ);
		if (fs.isOpened())
		{
			fs["cameraMatrix1"] >> *cameraMatrix1;
			fs["distCoeffs1"] >> *distCoeffs1;
			fs["cameraMatrix2"] >> *cameraMatrix2;
			fs["distCoeffs2"] >> *distCoeffs2;
			fs["R1"] >> *R1;
			fs["P1"] >> *P1;
			fs["R2"] >> *R2;
			fs["P2"] >> *P2;
			fs["Q"] >> *Q;
			fs["roi1"] >> *roi1;
			fs["roi2"] >> *roi2;
			fs.release();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}

bool EvisionUtils::read_ParamsForStereoRectify(std::string& filename, cv::Mat* cameraMatrix1, cv::Mat* distCoeffs1,
	cv::Mat* cameraMatrix2, cv::Mat* distCoeffs2, cv::Mat* R1, cv::Mat* P1, cv::Mat* R2, cv::Mat* P2, cv::Rect* roi1,
	cv::Rect* roi2)
{
	if (filename.empty() == true)
	{
		return false;
	}
	try
	{
		cv::FileStorage fs(filename, cv::FileStorage::READ);
		if (fs.isOpened())
		{
			fs["cameraMatrix1"] >> *cameraMatrix1;
			fs["distCoeffs1"] >> *distCoeffs1;
			fs["cameraMatrix2"] >> *cameraMatrix2;
			fs["distCoeffs2"] >> *distCoeffs2;
			fs["R1"] >> *R1;
			fs["P1"] >> *P1;
			fs["R2"] >> *R2;
			fs["P2"] >> *P2;
			fs["roi1"] >> *roi1;
			fs["roi2"] >> *roi2;
			fs.release();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}

void EvisionUtils::getGrayDisparity(const cv::Mat& disp, cv::Mat& grayDisp, bool stretch)
{
	cv::Size imgSize = disp.size();
	cv::Mat output(imgSize, CV_8UC3);
	float min, max;

	if (stretch)
	{
		min = (std::numeric_limits<float>::max());
		max = 0;
		for (size_t h = 0; h < imgSize.height; h++)
		{
			for (size_t w = 0; w < imgSize.width; w++)
			{
				float disparity = disp.at<float>(h, w);

				if (disparity < min && disparity >= 0)
					min = disparity;
				else if (disparity > max)
					max = disparity;
			}
		}
	}

	for (size_t h = 0; h < imgSize.height; h++)
	{
		for (size_t w = 0; w < imgSize.width; w++)
		{
			cv::Vec3b color;
			float disparity = disp.at<float>(h, w);

			if (disparity >= 0)
			{
				if (stretch)
					disparity = (255 / (max - min)) * (disparity - min);

				color[0] = (uchar)disparity;
				color[1] = (uchar)disparity;
				color[2] = (uchar)disparity;

			}
			else
			{
				color[0] = 0;
				color[1] = 0;
				color[2] = 0;
			}

			output.at<cv::Vec3b>(h, w) = color;
		}
	}

	grayDisp = output.clone();
}