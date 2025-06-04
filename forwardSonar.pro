QT       += core gui opengl multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BrigthnessScrollBar.cpp \
    CmdThread.cpp \
    ColorValueSetDlg.cpp \
    FanViewSettingDlg.cpp \
    dataacquisition.cpp \
    main.cpp \
    mainwindow.cpp \
    myopenglwidget.cpp \
    parsingfile.cpp \
    replayprogress.cpp

HEADERS += \
    BrigthnessScrollBar.h \
    CmdThread.h \
    ColorValueSetDlg.h \
    CommonDefs.h \
    FanViewSettingDlg.h \
    Packet.h \
    dataacquisition.h \
    mainwindow.h \
    myopenglwidget.h \
    parsingfile.h \
    replayprogress.h

FORMS += \
    ColorValueSetDlg.ui \
    FanViewSettingDlg.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

##包含路径
INCLUDEPATH += include

##库文件
LIBS += E:\develop\QTproject\forwardSonar\lib\libglew32.a
# LIBS += E:\develop\QTproject\forwardSonar\lib\libglew32.a

win32:LIBS += -lOpengl32\
-lglu32
unix:LIBS += -lglut -lGLU
