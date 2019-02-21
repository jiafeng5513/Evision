#include "StereoMatcherView.h"
#include <direct.h>

StereoMatcherView::StereoMatcherView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

StereoMatcherView::~StereoMatcherView()
{
}

bool StereoMatcherView::LoadPtsPairs(std::vector<cv::Point2f>& ptsL, std::vector<cv::Point2f>& ptsR,
	std::string& filename)
{
	std::ifstream is(filename.c_str());
	if (!is)
	{
		std::cerr << filename << " unable to read" << std::endl;
		return false;
	}

	cv::Point2f buf;
	int cnt;
	is >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		is >> buf.x >> buf.y;
		ptsL.push_back(buf);
		is >> buf.x >> buf.y;
		ptsR.push_back(buf);
	}
	is.close();
	return true;

}

void StereoMatcherView::SavePtsPairs(std::vector<cv::Point2f>& ptsL, std::vector<cv::Point2f>& ptsR,
	std::string& filename)
{
	std::ofstream os(filename.c_str());
	std::vector<cv::Point2f>::iterator iterL = ptsL.begin(),
		iterR = ptsR.begin();
	os << ptsL.size() << std::endl;

	for (; iterL != ptsL.end(); iterL++, iterR++)
	{
		os << iterL->x << '\t' << iterL->y << "\t\t"
			<< iterR->x << '\t' << iterR->y << std::endl;
	}
	os.close();
}

void StereoMatcherView::StereoTo3D(std::vector<cv::Point2f> ptsL, std::vector<cv::Point2f> ptsR,
	std::vector<cv::Point3f>& pts3D, float focalLenInPixel, float baselineInMM, cv::Mat img, cv::Point3f& center3D,
	cv::Vec3f& size3D)
{
	std::vector<cv::Point2f>::iterator iterL = ptsL.begin(),
		iterR = ptsR.begin();

	float xl, xr, ylr;
	float imgH = float(img.rows), imgW = float(img.cols);
	cv::Point3f pt3D;
	float minX = 1e9, maxX = -1e9;
	float minY = 1e9, maxY = -1e9;
	float minZ = 1e9, maxZ = -1e9;

	cv::Mat imgShow = img.clone();
	char str[100];
	int ptCnt = ptsL.size(), showPtNum = 30, cnt = 0;
	int showIntv = max(ptCnt / showPtNum, 1);
	for (; iterL != ptsL.end(); iterL++, iterR++)
	{
		xl = iterL->x;
		xr = iterR->x; // need not add baseline
		ylr = (iterL->y + iterR->y) / 2;

		//if (yl-yr>5 || yr-yl>5) // may be wrong correspondence, discard. But vector can't be changed during iteration
		//{}

		pt3D.z = -focalLenInPixel * baselineInMM / (xl - xr); // xl should be larger than xr, if xl is shot by the left camera
		pt3D.y = -(-ylr + imgH / 2) * pt3D.z / focalLenInPixel;
		pt3D.x = (imgW / 2 - xl) * pt3D.z / focalLenInPixel;

		minX = min(minX, pt3D.x); maxX = max(maxX, pt3D.x);
		minY = min(minY, pt3D.y); maxY = max(maxY, pt3D.y);
		minZ = min(minZ, pt3D.z); maxZ = max(maxZ, pt3D.z);
		pts3D.push_back(pt3D);

		if ((cnt++) % showIntv == 0)
		{
			cv::Scalar color = CV_RGB(rand() & 64, rand() & 64, rand() & 64);
			sprintf_s(str, 100, "%.0f,%.0f,%.0f", pt3D.x, pt3D.y, pt3D.z);
			putText(imgShow, str, cv::Point(xl - 13, ylr - 3), cv::FONT_HERSHEY_SIMPLEX, .3, color);
			circle(imgShow, *iterL, 2, color, 3);
		}

	}

	imshow("back project", imgShow);
	cv::waitKey();

	center3D.x = (minX + maxX) / 2;
	center3D.y = (minY + maxY) / 2;
	center3D.z = (minZ + maxZ) / 2;
	size3D[0] = maxX - minX;
	size3D[1] = maxY - minY;
	size3D[2] = maxZ - minZ;
}

void StereoMatcherView::GetPair(cv::Mat& imgL, cv::Mat& imgR, std::vector<cv::Point2f>& ptsL,
	std::vector<cv::Point2f>& ptsR)
{
	cv::Mat descriptorsL, descriptorsR;
	double tt = (double)cv::getTickCount();

	cv::Ptr<cv::Feature2D> detector = cv::xfeatures2d::SIFT::create();
	std::vector<cv::KeyPoint> keypointsL, keypointsR;
	detector->detect(imgL, keypointsL);
	detector->detect(imgR, keypointsR);

	//Ptr<DescriptorExtractor> de = DescriptorExtractor::create(DESCRIPTOR_TYPE);
	//SurfDescriptorExtractor de(4,2,true);
	detector->compute(imgL, keypointsL, descriptorsL);
	detector->compute(imgR, keypointsR, descriptorsR);

	tt = ((double)cv::getTickCount() - tt) / cv::getTickFrequency(); // 620*555 pic, about 2s for SURF, 120s for SIFT

	cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(MATCHER_TYPE);
	std::vector<std::vector<cv::DMatch>> matches;
	matcher->knnMatch(descriptorsL, descriptorsR, matches, 2); // L:query, R:train

	std::vector<cv::DMatch> passedMatches; // save for drawing
	cv::DMatch m1, m2;
	std::vector<cv::Point2f> ptsRtemp, ptsLtemp;
	for (int i = 0; i < matches.size(); i++)
	{
		m1 = matches[i][0];
		m2 = matches[i][1];
		if (m1.distance < MAXM_FILTER_TH * m2.distance)
		{
			ptsRtemp.push_back(keypointsR[m1.trainIdx].pt);
			ptsLtemp.push_back(keypointsL[i].pt);
			passedMatches.push_back(m1);
		}
	}

	cv::Mat HLR;
	HLR = findHomography(cv::Mat(ptsLtemp), cv::Mat(ptsRtemp), CV_RANSAC, 3);
	std::cout << "Homography:" << std::endl << HLR << std::endl;
	cv::Mat ptsLt;
	perspectiveTransform(cv::Mat(ptsLtemp), ptsLt, HLR);

	std::vector<char> matchesMask(passedMatches.size(), 0);
	int cnt = 0;
	for (int i1 = 0; i1 < ptsLtemp.size(); i1++)
	{
		cv::Point2f prjPtR = ptsLt.at<cv::Point2f>((int)i1, 0); // prjx = ptsLt.at<float>((int)i1,0), prjy = ptsLt.at<float>((int)i1,1);
		 // inlier
		if (abs(ptsRtemp[i1].x - prjPtR.x) < HOMO_FILTER_TH &&
			abs(ptsRtemp[i1].y - prjPtR.y) < 2) // restriction on y is more strict
		{
			std::vector<cv::Point2f>::iterator iter = ptsL.begin();
			for (; iter != ptsL.end(); iter++)
			{
				cv::Point2f diff = *iter - ptsLtemp[i1];
				float dist = abs(diff.x) + abs(diff.y);
				if (dist < NEAR_FILTER_TH) break;
			}
			if (iter != ptsL.end()) continue;

			ptsL.push_back(ptsLtemp[i1]);
			ptsR.push_back(ptsRtemp[i1]);
			cnt++;
			if (cnt % 1 == 0) matchesMask[i1] = 1; // don't want to draw to many matches
		}
	}

	cv::Mat outImg;
	drawMatches(imgL, keypointsL, imgR, keypointsR, passedMatches, outImg,
		cv::Scalar::all(-1), cv::Scalar::all(-1), matchesMask, cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	char title[50];
	sprintf_s(title, 50, "%.3f s, %d matches, %d passed", tt, matches.size(), cnt);
	imshow(title, outImg);
	cv::waitKey();
}

void StereoMatcherView::GetPairBM(cv::Mat& imgL, cv::Mat& imgR, std::vector<cv::Point2f>& ptsL,
	std::vector<cv::Point2f>& ptsR)
{
	cv::Mat_<float> disp;
	imshow("left image", imgL);

	int numOfDisp = 80; // number of disparity, must be divisible by 16// algorithm parameters that can be modified
	CalcDisparity(imgL, imgR, disp, numOfDisp);
	cv::Mat dispSave, dispS;
	normalize(disp, dispSave, 0, 1, cv::NORM_MINMAX);
	dispSave.convertTo(dispSave, CV_8U, 255);
	imwrite("disp.jpg", dispSave);

	int numOfEgdePt = 80, numOfFlatPt = 50;	// algorithm parameters that can be modified
	ChooseKeyPointsBM(disp, numOfDisp, numOfEgdePt, numOfFlatPt, ptsL, ptsR);
	cv::waitKey();
}

void StereoMatcherView::CalcDisparity(cv::Mat& imgL, cv::Mat& imgR, cv::Mat_<float>& disp, int nod)
{
	enum { STEREO_BM = 0, STEREO_SGBM = 1, STEREO_HH = 2 };
	int alg = STEREO_SGBM;

	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create();
	int cn = imgR.channels();

	sgbm->setBlockSize(3);
	sgbm->setNumDisparities(nod);
	sgbm->setPreFilterCap(63);
	sgbm->setP1(8 * cn*sgbm->getBlockSize()*sgbm->getBlockSize());
	sgbm->setP2(32 * cn*sgbm->getBlockSize()*sgbm->getBlockSize());
	sgbm->setMinDisparity(0);
	sgbm->setUniquenessRatio(10);
	sgbm->setSpeckleWindowSize(100);
	sgbm->setSpeckleRange(32);
	sgbm->setDisp12MaxDiff(1);
	sgbm->setMode(cv::StereoSGBM::MODE_HH);

	cv::Mat dispTemp, disp8;
	sgbm->compute(imgL, imgR, dispTemp);
	dispTemp.convertTo(disp, CV_32FC1, 1.0 / 16);
	disp.convertTo(disp8, CV_8U, 255.0 / nod);
	imshow("origin disparity", disp8);
	//waitKey();

	FixDisparity(disp, nod);
	disp.convertTo(disp8, CV_8U, 255.0 / nod);
	imshow("fixed disparity", disp8);
}
// used for doing delaunay trianglation with opencv function
bool StereoMatcherView::isGoodTri(cv::Vec3i& v, std::vector<cv::Vec3i>& tri)
{
	int a = v[0], b = v[1], c = v[2];
	v[0] = min(a, min(b, c));
	v[2] = max(a, max(b, c));
	v[1] = a + b + c - v[0] - v[2];
	if (v[0] == -1) return false;

	std::vector<cv::Vec3i>::iterator iter = tri.begin();
	for (; iter != tri.end(); iter++)
	{
		cv::Vec3i &check = *iter;
		if (check[0] == v[0] &&
			check[1] == v[1] &&
			check[2] == v[2])
		{
			break;
		}
	}
	if (iter == tri.end())
	{
		tri.push_back(v);
		return true;
	}
	return false;
}

void StereoMatcherView::ChooseKeyPointsBM(cv::Mat_<float>& disp, int nod, int noe, int nof,
	std::vector<cv::Point2f>& ptsL, std::vector<cv::Point2f>& ptsR)
{
	cv::Mat_<float>  dCopy, dx, dy, dEdge;
	dCopy = disp.colRange(cv::Range(nod, disp.cols)).clone();
	normalize(dCopy, dCopy, 0, 1, cv::NORM_MINMAX);

	imshow("disparity", dCopy);
	cv::Mat dShow(dCopy.size(), CV_32FC3);

	if (dCopy.channels() == 1)
		cvtColor(dCopy, dShow, CV_GRAY2RGB);//这个数据有问题 dshow

		//imshow("disparity", dShow);

	int sobelWinSz = 7;// algorithm parameters that can be modified
	Sobel(dCopy, dx, -1, 1, 0, sobelWinSz);
	Sobel(dCopy, dy, -1, 0, 1, sobelWinSz);
	magnitude(dx, dy, dEdge);
	normalize(dEdge, dEdge, 0, 10, cv::NORM_MINMAX);
	//imshow("edge of disparity", dEdge);
	//waitKey();

	int filterSz[] = { 50,30 };	// algorithm parameters that can be modified
	float slope[] = { 4,8 };	// algorithm parameters that can be modified
	int keepBorder = 5;	// algorithm parameters that can be modified
	int cnt = 0;
	double value;
	float minValue = .003;	// algorithm parameters that can be modified
	cv::Point2f selPt1, selPt2;
	cv::Mat_<float> dEdgeCopy1 = dEdge.clone();

	// find the strongest edges, assign 1 or 2 key points near it
	while (cnt < noe)
	{
		cv::Point loc;
		minMaxLoc(dEdgeCopy1, NULL, &value, NULL, &loc);
		if (value < minValue) break;

		float dx1 = dx(loc), dy1 = dy(loc);
		if (abs(dx1) >= abs(dy1))
		{
			selPt1.y = selPt2.y = loc.y;
			selPt1.x = loc.x - (dx1 > 0 ? slope[1] : slope[0]) + nod;
			selPt2.x = loc.x + (dx1 > 0 ? slope[0] : slope[1]) + nod;
			if (selPt1.x > keepBorder + nod)
			{
				ptsL.push_back(selPt1);
				ptsR.push_back(selPt1 - cv::Point2f(disp(selPt1), 0));
				circle(dShow, selPt1 - cv::Point2f(nod, 0), 2, CV_RGB(255, 0, 0), 2);
				cnt++;
			}
			if (selPt2.x < disp.cols - keepBorder)
			{
				ptsL.push_back(selPt2);
				ptsR.push_back(selPt2 - cv::Point2f(disp(selPt2), 0));
				circle(dShow, selPt2 - cv::Point2f(nod, 0), 2, CV_RGB(0, 255, 0), 2);
				cnt++;
			}

			imshow("disparity", dShow);
			//waitKey();

			int left = min(filterSz[1], loc.x),
				top = min(filterSz[0], loc.y),
				right = min(filterSz[1], dCopy.cols - loc.x - 1),
				bot = min(filterSz[0], dCopy.rows - loc.y - 1);
			cv::Mat sub = dEdgeCopy1(cv::Range(loc.y - top, loc.y + bot + 1), cv::Range(loc.x - left, loc.x + right + 1));
			sub.setTo(cv::Scalar(0));
			//imshow("processing disparity edge", dEdgeCopy1);
			//waitKey();
		}
		else
		{
			selPt1.x = selPt2.x = loc.x + nod;
			selPt1.y = loc.y - (dy1 > 0 ? slope[1] : slope[0]);
			selPt2.y = loc.y + (dy1 > 0 ? slope[0] : slope[1]);
			if (selPt1.y > keepBorder)
			{
				ptsL.push_back(selPt1);
				ptsR.push_back(selPt1 - cv::Point2f(disp(selPt1), 0));
				circle(dShow, selPt1 - cv::Point2f(nod, 0), 2, CV_RGB(255, 255, 0), 2);
				cnt++;
			}
			if (selPt2.y < disp.rows - keepBorder)
			{
				ptsL.push_back(selPt2);
				ptsR.push_back(selPt2 - cv::Point2f(disp(selPt2), 0));
				circle(dShow, selPt2 - cv::Point2f(nod, 0), 2, CV_RGB(0, 255, 255), 2);
				cnt++;
			}

			imshow("disparity", dShow);
			//waitKey();

			int left = min(filterSz[0], loc.x),
				top = min(filterSz[1], loc.y),
				right = min(filterSz[0], dCopy.cols - loc.x - 1),
				bot = min(filterSz[1], dCopy.rows - loc.y - 1);
			cv::Mat sub = dEdgeCopy1(cv::Range(loc.y - top, loc.y + bot + 1), cv::Range(loc.x - left, loc.x + right + 1));
			sub.setTo(cv::Scalar(0));
			//imshow("processing disparity edge", dEdgeCopy1);
			//waitKey();
		}

	}

	int filterSz0 = 6;// algorithm parameters that can be modified
	keepBorder = 3;// algorithm parameters that can be modified
	cnt = 0;
	cv::Mat_<float> dEdgeCopy2;// = dEdge.clone();
	GaussianBlur(dEdge, dEdgeCopy2, cv::Size(0, 0), 5);
	char str[10];

	// find the flat areas, assign 1 key point near it
	while (cnt < nof)
	{
		cv::Point loc;
		minMaxLoc(dEdgeCopy2, &value, NULL, &loc, NULL);
		if (value == 10) break;

		loc.x += nod;
		if (loc.x > keepBorder + nod && loc.y > keepBorder &&
			loc.x < disp.cols && loc.y < disp.rows)
		{
			ptsL.push_back(loc);
			ptsR.push_back(cv::Point2f(loc) - cv::Point2f(disp(loc), 0));
			circle(dShow, cv::Point2f(loc) - cv::Point2f(nod, 0), 2, CV_RGB(255, 0, 255), 2);
			cnt++;
			sprintf_s(str, 10, "%.1f", disp(loc));
			putText(dShow, str, cv::Point(loc.x - nod + 3, loc.y), cv::FONT_HERSHEY_SIMPLEX, .3, CV_RGB(255, 0, 255));
			imshow("disparity", dShow);
		}

		loc.x -= nod;
		int filterSz1 = (10 - value * 3)*filterSz0;
		int left = min(filterSz1, loc.x),
			top = min(filterSz1, loc.y),
			right = min(filterSz1, dCopy.cols - loc.x - 1),
			bot = min(filterSz1, dCopy.rows - loc.y - 1);
		cv::Mat sub = dEdgeCopy2(cv::Range(loc.y - top, loc.y + bot + 1), cv::Range(loc.x - left, loc.x + right + 1));
		sub.setTo(cv::Scalar(10));
		//imshow("processing disparity flat area", dEdgeCopy2);
	}
}
// roughly smooth the glitches on the disparity map
void StereoMatcherView::FixDisparity(cv::Mat_<float>& disp, int numberOfDisparities)
{
	cv::Mat_<float> disp1;
	float lastPixel = 10;
	float minDisparity = 23;// algorithm parameters that can be modified
	for (int i = 0; i < disp.rows; i++)
	{
		for (int j = numberOfDisparities; j < disp.cols; j++)
		{
			if (disp(i, j) <= minDisparity) disp(i, j) = lastPixel;
			else lastPixel = disp(i, j);
		}
	}
	int an = 4;	// algorithm parameters that can be modified
	copyMakeBorder(disp, disp1, an, an, an, an, cv::BORDER_REPLICATE);
	cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(an * 2 + 1, an * 2 + 1));
	morphologyEx(disp1, disp1, CV_MOP_OPEN, element);
	morphologyEx(disp1, disp1, CV_MOP_CLOSE, element);
	disp = disp1(cv::Range(an, disp.rows - an), cv::Range(an, disp.cols - an)).clone();
}

//选择左视图
void StereoMatcherView::onPush_SelectedLeftImg()
{
}
//选择右视图
void StereoMatcherView::onPush_SelectedRightImg()
{
}
//Link Start!!
void StereoMatcherView::onPush_LinkStart()
{
	/************************************************************************/
	/* load and resize images                                               */
	/************************************************************************/

	char* buffer;

	// Get the current working directory:   
	if ((buffer = _getcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	else
	{
		printf("%s \nLength: %d\n", buffer, strnlen(buffer, 1024));
		free(buffer);
	}

	//cout<<folder + groupname + filenameL<<endl;

	std::string str = "view1s.jpg";

	//FILE* fp;

	//fp = fopen(str.c_str(), "rb");//这块调试，似乎没东西。。。
	//if (!fp)
	//{
	//	return NULL;
	//}

	//Mat imgL = imread("D:\\Libraries\\OpenCV\\3.4.5\\source\\samples\\data\\aloeL.jpg"); 
	//Mat	imgR = imread("D:\\Libraries\\OpenCV\\3.4.5\\source\\samples\\data\\aloeR.jpg");

	cv::Mat imgL = cv::imread("F:\\im0.png");
	cv::Mat	imgR = cv::imread("F:\\im1.png");
	imshow("l", imgL);
	//waitKey(0);

	if (!(imgL.data) || !(imgR.data))
	{
		std::cerr << "can't load image!" << std::endl;
		exit(1);
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	float stdWidth = 800, resizeScale = 1;//stdWidth can change
	if (imgL.cols > stdWidth * 1.2)
	{
		resizeScale = stdWidth / imgL.cols;
		cv::Mat imgL1, imgR1;
		cv::resize(imgL, imgL1, cv::Size(), resizeScale, resizeScale);
		cv::resize(imgR, imgR1, cv::Size(), resizeScale, resizeScale);
		imgL = imgL1.clone();
		imgR = imgR1.clone();
	}

	/************************************************************************/
	/* decide which points in the left image should be chosen               */
	/* and calculate their corresponding points in the right image          */
	/************************************************************************/
	std::cout << "calculating feature points..." << std::endl;
	std::vector<cv::Point2f> ptsL, ptsR;
	std::vector<int> ptNum;
	if (g_algo == FEATURE_PT)
	{
		//if ( ! LoadPtsPairs(ptsL, ptsR, groupname+".pairs"))	{
		GetPair(imgL, imgR, ptsL, ptsR);
		//SavePtsPairs(ptsL, ptsR, groupname+".pairs");	}
	}
	else if (g_algo == DENSE)
		GetPairBM(imgL, imgR, ptsL, ptsR);

	/************************************************************************/
	/* calculate 3D coordinates                                             */
	/************************************************************************/
	std::vector<cv::Point3f> pts3D;
	float focalLenInPixel = 3740 * resizeScale,
		baselineInMM = 160;
	cv::Point3f center3D;
	cv::Vec3f size3D;
	float scale = .2; // scale the z coordinate so that it won't be too large spreaded
	//float imgHinMM = 400, // approximate real height of the scene in picture, useless
	//float MMperPixel = imgHinMM / imgL.rows;
	//float focalLenInMM = focalLenInPixel * MMperPixel;
	focalLenInPixel *= scale;

	std::cout << "calculating 3D coordinates..." << std::endl;
	StereoTo3D(ptsL, ptsR, pts3D,
		focalLenInPixel, baselineInMM,
		imgL, center3D, size3D);

	/************************************************************************/
	/* Delaunay triangulation                                               */
	/************************************************************************/
	std::cout << "doing triangulation..." << std::endl;
	int pairNum = ptsL.size();
	std::vector<cv::Vec3i> tri;


	return;
}
