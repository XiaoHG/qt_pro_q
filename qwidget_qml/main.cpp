
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{

    //虚拟键盘
    qputenv("QT_IM_MODULE", QByteArray("platforminputcontexts"));
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QQuickView *view = new QQuickView();
//    view->setSource(QUrl("qrc:/qml/test_page.qml"));
//    view->show();

    return a.exec();
}
