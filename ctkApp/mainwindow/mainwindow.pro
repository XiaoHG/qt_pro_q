QT       += core gui qml quick widgets
QT += 3dcore 3drender 3dinput 3dextras 3dquick 3dquickextras 3danimation
Qt += 3dquickscene2d

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TEMPLATE = lib

DESTDIR = $$PWD/../exec/plugins

include($$PWD/../../third_party/ctk/install/ctk.pri)
include($$PWD/../ctk_common/ctk_common.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mainwindow.cpp \
    mainwindowactivator.cpp \
    mainwindowmanager.cpp \
    mainwindowservice.cpp \
    src/d3drendercontrol.cpp

HEADERS += \
    mainwindow.h \
    mainwindowactivator.h \
    mainwindowmanager.h \
    mainwindowservice.h \
    src/d3drendercontrol.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
