echo copy dlls from the opencv version :
$(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_version.exe

if not exist $(OutDir)opencv_calib3d2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_calib3d2413d.dll $(OutDir)opencv_calib3d2413d.dll
    echo copy opencv_calib3d2413d.dll done
) else (
    echo opencv_calib3d2413d.dll is already exist!
)

if not exist $(OutDir)opencv_contrib2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_contrib2413d.dll $(OutDir)opencv_contrib2413d.dll
    echo copy opencv_contrib2413d.dll done
) else (
    echo opencv_contrib2413d.dll is already exist!
)

if not exist $(OutDir)opencv_core2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_core2413d.dll $(OutDir)opencv_core2413d.dll
    echo copy opencv_core2413d.dll done
) else (
    echo opencv_core2413d.dll is already exist!
)

if not exist $(OutDir)opencv_features2d2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_features2d2413d.dll $(OutDir)opencv_features2d2413d.dll
    echo copy opencv_features2d2413d.dll done
) else (
    echo opencv_features2d2413d.dll is already exist!
)

if not exist $(OutDir)opencv_flann2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_flann2413d.dll $(OutDir)opencv_flann2413d.dll
    echo copy opencv_flann2413d.dll done
) else (
    echo opencv_flann2413d.dll is already exist!
)

if not exist $(OutDir)opencv_highgui2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_highgui2413d.dll $(OutDir)opencv_highgui2413d.dll
    echo copy opencv_highgui2413d.dll done
) else (
    echo opencv_highgui2413d.dll is already exist!
)

if not exist $(OutDir)opencv_imgproc2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_imgproc2413d.dll $(OutDir)opencv_imgproc2413d.dll
    echo copy opencv_imgproc2413d.dll done
) else (
    echo opencv_imgproc2413d.dll is already exist!
)

if not exist $(OutDir)opencv_legacy2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_legacy2413d.dll $(OutDir)opencv_legacy2413d.dll
    echo copy opencv_legacy2413d.dll done
) else (
    echo opencv_legacy2413d.dll is already exist!
)

if not exist $(OutDir)opencv_ml2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_ml2413d.dll $(OutDir)opencv_ml2413d.dll
    echo copy opencv_ml2413d.dll done
) else (
    echo opencv_ml2413d.dll is already exist!
)

if not exist $(OutDir)opencv_objdetect2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_objdetect2413d.dll $(OutDir)opencv_objdetect2413d.dll
    echo copy opencv_objdetect2413d.dll done
) else (
    echo opencv_objdetect2413d.dll is already exist!
)

if not exist $(OutDir)opencv_video2413d.dll (
    copy $(SolutionDir)..\package\opencv2.4.13\x86\vc14\bin\opencv_video2413d.dll $(OutDir)opencv_video2413d.dll
    echo copy opencv_video2413d.dll done
) else (
    echo opencv_video2413d.dll is already exist!
)