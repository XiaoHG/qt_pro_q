
#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include <thread>
#include <iostream>
#include <QMap>

void threah_1()
{
    std::cout << "start thread_1" << std::endl;


    std::cout << "stop thread_1" << std::endl;
    return;
}

struct Data
{
    Data() {}
};

struct Ctrl
{
    Ctrl() {}
};

QMap<int, QPair<QSharedPointer<Data>, QSharedPointer<Ctrl>>>;


class A
{

public:
    void operator()()
    {
        std::cout << "A Thread start" << std::endl;

        std::cout << "A Thread end" << std::endl;

        return;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    A aa;

    std::thread t(threah_1);
    std::thread ta(aa);
    t.join();
    ta.join();

    std::cout << "main thread stop" << std::endl;

//    MainWindow w;
//    w.show();
    return a.exec();
}
