公用
=======
	int SADWindowSize=51; SAD窗口大小，容许范围是[5,255]，一般应该在 5x5 至 21x21 之间，参数必须是奇数
	int numberOfDisparities=144;视差窗口，即最大视差值与最小视差值之差, 窗口大小必须是 16 的整数倍，int 型
	float scale=1.0;

bm
=======

PreFilterCap(31);
BlockSize(SADWindowSize > 0 ? SADWindowSize : 9);
MinDisparity(0);
NumDisparities(numberOfDisparities);
TextureThreshold(10);
UniquenessRatio(15);
SpeckleWindowSize(100);
SpeckleRange(32);
Disp12MaxDiff(1);

sgbm
=======
PreFilterCap(63);
            int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
BlockSize(sgbmWinSize);
P1(8 * cn*sgbmWinSize*sgbmWinSize);
P2(32 * cn*sgbmWinSize*sgbmWinSize);
MinDisparity(0);
NumDisparities(numberOfDisparities);
UniquenessRatio(10);
SpeckleWindowSize(100);
SpeckleRange(32);
Disp12MaxDiff(1);

	if (alg == STEREO_HH)
		sgbm->setMode(cv::StereoSGBM::MODE_HH);
	else if (alg == STEREO_SGBM)
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM);
	else if (alg == STEREO_3WAY)
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM_3WAY);

参数解释
=======
1. `preFilterCap` 前置滤波的像素截断值。该算法首先计算每个像素的x偏导数，并以[-preFilterCap，preFilterCap]区间裁剪其值，并将结果值传递给Birchfield-Tomasi像素代价函数。
2. `blockSize` 匹配块的大小,必须是>=1的奇数,取值范围通常在[3,11]中
3. `minDisparity` 最小视差值。通常是零，但有时滤波算法可能会移动图像，因此需要相应地调整该参数。
4. `numDisparities` 视差窗口，即最大视差值与最小视差值之差, 窗口大小必须是 16 的整数倍，int 型
5. `TextureThreshold`低纹理区域的判断阈值。如果当前SAD窗口内所有邻居像素点的x导数绝对值之和小于指定阈值，则该窗口对应的像素点的视差值为 0
6. `uniquenessRatio` 视差唯一性百分比，视差窗口范围内最低代价是次低代价的(1 + uniquenessRatio/100)倍时，最低代价对应的视差值才是该像素点的视差，否则该像素点的视差为0.该参数不能为负值，一般5-15左右的值比较合适
7. `SpeckleWindowSize` 检查视差连通区域变化度的窗口大小, 值为 0 时取消 speckle 检查,常用范围是50-200
8. `speckleRange` 每个连通区域内的最大视差变化，当视差变化大于阈值时，该区域内的视差清零。如果进行散斑滤波，将参数设置为正值，则将隐式地乘以16。通常取值1或2(16或32).
9. `disp12MaxDiff` 左视差图（直接计算得出）和右视差图（通过cvValidateDisparity计算得出）之间的最大容许差异。超过该阈值的视差值将被清零。该参数为-1时不执行左右视差检查,为1时执行检查。


API原文
====
@param minDisparity Minimum possible disparity value. Normally, it is zero but sometimes rectification algorithms can shift images, so this parameter needs to be adjusted accordingly.
 @param numDisparities Maximum disparity minus minimum disparity. The value is always greater than zero. In the current implementation, this parameter must be divisible by 16.
 @param blockSize Matched block size. It must be an odd number \>=1 . Normally, it should be somewhere in the 3..11 range.
 @param P1 The first parameter controlling the disparity smoothness. See below.
 @param P2 The second parameter controlling the disparity smoothness. The larger the values are, the smoother the disparity is. P1 is the penalty on the disparity change by plus or minus 1 between neighbor pixels. P2 is the penalty on the disparity change by more than 1 between neighbor pixels. The algorithm requires P2 \> P1 . See stereo_match.cpp sample where some reasonably good P1 and P2 values are shown (like 8\*number_of_image_channels\*SADWindowSize\*SADWindowSize and 32\*number_of_image_channels\*SADWindowSize\*SADWindowSize , respectively).
 @param disp12MaxDiff Maximum allowed difference (in integer pixel units) in the left-right disparity check. Set it to a non-positive value to disable the check.
 @param preFilterCap Truncation value for the prefiltered image pixels. The algorithm first computes x-derivative at each pixel and clips its value by [-preFilterCap, preFilterCap] interval. The result values are passed to the Birchfield-Tomasi pixel cost function.
 @param uniquenessRatio Margin in percentage by which the best (minimum) computed cost function value should "win" the second best value to consider the found match correct. Normally, a value within the 5-15 range is good enough.
 @param speckleWindowSize Maximum size of smooth disparity regions to consider their noise speckles and invalidate. Set it to 0 to disable speckle filtering. Otherwise, set it somewhere in the 50-200 range.
 @param speckleRange Maximum disparity variation within each connected component. If you do speckle filtering, set the parameter to a positive value, it will be implicitly multiplied by 16. Normally, 1 or 2 is good enough.
 @param mode Set it to StereoSGBM::MODE_HH to run the full-scale two-pass dynamic programming algorithm. It will consume O(W\*H\*numDisparities) bytes, which is large for 640x480 stereo and huge for HD-size pictures. By default, it is set to false .
 The first constructor initializes StereoSGBM with all the default parameters. So, you only have to set StereoSGBM::numDisparities at minimum. The second constructor enables you to set each parameter to a custom value.