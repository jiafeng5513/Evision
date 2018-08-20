%用于拷貝dll到輸出目錄的腳本,其中使用了VS宏,在生成前事件中起作用%

%debug%

@echo off
echo copy dlls from the opencv version :
$(SolutionDir)..\package\opencv\build\x64\vc15\bin\opencv_version.exe

if not exist $(OutDir)opencv_world341d.dll (
    copy $(SolutionDir)..\package\opencv\build\x64\vc15\bin\opencv_world341d.dll $(OutDir)opencv_world341d.dll
    echo copy opencv_world34d1.dll done
)else (
    echo opencv_world341d.dll is already exist!
)

if not exist $(OutDir)opencv_ffmpeg341_64.dll (
    copy $(SolutionDir)..\package\opencv\build\x64\vc15\bin\opencv_ffmpeg341_64.dll $(OutDir)opencv_ffmpeg341_64.dll
    echo copy opencv_ffmpeg341_64.dll done
)else (
    echo opencv_ffmpeg341_64.dll is already exist!
)


%release%
@echo off
echo copy dlls from the opencv version :
$(SolutionDir)..\package\opencv\build\x64\vc15\bin\opencv_version.exe

if not exist $(OutDir)opencv_world341.dll (
    copy $(SolutionDir)..\package\opencv\build\x64\vc15\bin\opencv_world341d.dll $(OutDir)opencv_world341.dll
    echo copy opencv_world341.dll done
)else (
    echo opencv_world341.dll is already exist!
)

if not exist $(OutDir)opencv_ffmpeg341_64.dll (
    copy $(SolutionDir)..\package\opencv\build\x64\vc15\bin\opencv_ffmpeg341_64.dll $(OutDir)opencv_ffmpeg341_64.dll
    echo copy opencv_ffmpeg341_64.dll done
)else (
    echo opencv_ffmpeg341_64.dll is already exist!
)