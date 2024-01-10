QT += qml quick gui
QT += qml quick widgets 3dcore 3drender 3dextras 3dinput 3dlogic 3dquick 3drender-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/dddScene/dddeditorsceneitem.cpp \
    src/dddScene/dddrootentity.cpp \
    src/dddScene/dddscene.cpp \
    src/dddScene/dddutils.cpp \
    src/main.cpp

HEADERS += \
    src/dddScene/dddeditorsceneitem.h \
    src/dddScene/dddrootentity.h \
    src/dddScene/dddscene.h \
    src/dddScene/dddutils.h

FORMS +=

INCLUDEPATH += $${PWD}/src

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
