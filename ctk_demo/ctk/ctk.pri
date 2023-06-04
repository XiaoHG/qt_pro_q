
INCLUDEPATH += $$PWD/include/ctk-0.1

CONFIG(debug, debug|release){
    LIBS += -L$$PWD/lib/ctk-0.1 -lCTKCore -lCTKPluginFramework -lCTKWidgets
} else {

}
