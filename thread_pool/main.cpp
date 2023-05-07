
//#include "mainwindow.h"

//#include <QApplication>


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

#include "thread_pool.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void taskFunc(void* arg)
{
    int nNum = *(int*)arg;
    cout << "thread: " << std::this_thread::get_id() << ", number=" << nNum << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    // 设置线程池最小5个线程，最大10个线程
    ThreadPool pool(5, 10);
    int i;
    // 往任务队列中添加100个任务
    for (i = 0; i < 100; ++i)
    {
        int* pNum = new int(i + 100);
        pool.Add(taskFunc, (void*)pNum);
    }

    for (; i < 200; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int* pNum = new int(i + 100);
        pool.Add(taskFunc, (void*)pNum);
    }
    return 0;
}
