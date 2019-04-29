#-------------------------------------------------
#
# Project created by QtCreator 2019-04-20T12:30:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = embed_test
TEMPLATE = app
RC_FILE = cyx_logo.rc

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += D:/OpenCV/opencv/build/include \
            D:/OpenCV/opencv/build/include/opencv \
            D:/OpenCV/opencv/build/include/opence2 \
            D:/ffmpeg/dev/ffmpeg-4.1-win64-dev/include

LIBS += D:/OpenCV/opencv/build/x64/vc15/lib/*.lib \
        D:/ffmpeg/dev/ffmpeg-4.1-win64-dev/lib/*.lib

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        cyx_embed.cpp \
    cyx_util.cpp \
    cyx_support.cpp \
    cyx_event.cpp \
    cyx_base_window.cpp \
    cyx_manager.cpp \
    cyx_global.cpp \
    cyx_convert.cpp

HEADERS  += cyx_embed.h \
    cyx_util.h \
    cyx_support.h \
    cyx_event.h \
    cyx_base_window.h \
    cyx_manager.h \
    cyx_global.h \
    cyx_convert.h

FORMS    += \
    cyx_base_window.ui

RESOURCES += \
    cyx_resource.qrc

DISTFILES += \
    cyx_logo.rc
