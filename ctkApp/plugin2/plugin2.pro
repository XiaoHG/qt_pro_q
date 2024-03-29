QT = core gui
TARGET = plugin2
TEMPLATE = lib
CONFIG += c++17 cmdline
DESTDIR = $$PWD/../exec/plugins

include($$PWD/../../third_party/ctk/install/ctk.pri)
include($$PWD/../ctk_common/ctk_common.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    plugin2.cpp \
    plugin2activator.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    plugin2.h \
    plugin2activator.h \
    plugin2service.h

RESOURCES += \
    resource.qrc
