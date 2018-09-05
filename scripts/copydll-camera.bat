@echo off

if not exist $(OutDir)Qt5MultimediaWidgetsd.dll (
    copy $(QTDIR)\bin\Qt5MultimediaWidgetsd.dll $(OutDir)Qt5MultimediaWidgetsd.dll
    echo copy Qt5MultimediaWidgetsd.dll done
) else (
    echo Qt5MultimediaWidgetsd.dll is already exist!
)

if not exist $(OutDir)Qt5Multimediad.dll (
    copy $(QTDIR)\bin\Qt5Multimediad.dll $(OutDir)Qt5Multimediad.dll
    echo copy Qt5Multimediad.dll done
) else (
    echo Qt5Multimediad.dll is already exist!
)

if not exist $(OutDir)Qt5Networkd.dll (
    copy $(QTDIR)\bin\Qt5Networkd.dll $(OutDir)Qt5Networkd.dll
    echo copy Qt5Networkd.dll done
) else (
    echo Qt5Networkd.dll is already exist!
)

if not exist $(OutDir)Qt5OpenGLd.dll (
    copy $(QTDIR)\bin\Qt5OpenGLd.dll $(OutDir)Qt5OpenGLd.dll
    echo copy Qt5OpenGLd.dll done
) else (
    echo Qt5OpenGLd.dll is already exist!
)

if not exist $(OutDir)Qt5Widgetsd.dll (
    copy $(QTDIR)\bin\Qt5Widgetsd.dll $(OutDir)Qt5Widgetsd.dll
    echo copy Qt5Widgetsd.dll done
) else (
    echo Qt5Widgetsd.dll is already exist!
)

if not exist $(OutDir)Qt5Guid.dll (
    copy $(QTDIR)\bin\Qt5Guid.dll $(OutDir)Qt5Guid.dll
    echo copy Qt5Guid.dll done
) else (
    echo Qt5Guid.dll is already exist!
)

if not exist $(OutDir)Qt5Cored.dll (
    copy $(QTDIR)\bin\Qt5Cored.dll $(OutDir)Qt5Cored.dll
    echo copy Qt5Cored.dll done
) else (
    echo Qt5Cored.dll is already exist!
)

%release%
@echo off

if not exist $(OutDir)Qt5MultimediaWidgets.dll (
    copy $(QTDIR)\bin\Qt5MultimediaWidgets.dll $(OutDir)Qt5MultimediaWidgets.dll
    echo copy Qt5MultimediaWidgets.dll done
) else (
    echo Qt5MultimediaWidgets.dll is already exist!
)

if not exist $(OutDir)Qt5Multimedia.dll (
    copy $(QTDIR)\bin\Qt5multimedia.dll $(OutDir)Qt5Multimedia.dll
    echo copy Qt5Multimedia.dll done
) else (
    echo Qt5Multimedia.dll is already exist!
)

if not exist $(OutDir)Qt5Network.dll (
    copy $(QTDIR)\bin\Qt5Network.dll $(OutDir)Qt5Network.dll
    echo copy Qt5Network.dll done
) else (
    echo Qt5Network.dll is already exist!
)

if not exist $(OutDir)Qt5OpenGL.dll (
    copy $(QTDIR)\bin\Qt5OpenGL.dll $(OutDir)Qt5OpenGL.dll
    echo copy Qt5OpenGL.dll done
) else (
    echo Qt5OpenGL.dll is already exist!
)

if not exist $(OutDir)Qt5Widgets.dll (
    copy $(QTDIR)\bin\Qt5Widgets.dll $(OutDir)Qt5Widgets.dll
    echo copy Qt5Widgets.dll done
) else (
    echo Qt5Widgets.dll is already exist!
)

if not exist $(OutDir)Qt5Gui.dll (
    copy $(QTDIR)\bin\Qt5Gui.dll $(OutDir)Qt5Gui.dll
    echo copy Qt5Gui.dll done
) else (
    echo Qt5Gui.dll is already exist!
)

if not exist $(OutDir)Qt5Core.dll (
    copy $(QTDIR)\bin\Qt5Core.dll $(OutDir)Qt5Core.dll
    echo copy Qt5Core.dll done
) else (
    echo Qt5Core.dll is already exist!
)