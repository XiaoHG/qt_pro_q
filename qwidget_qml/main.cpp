
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{

    //虚拟键盘
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
