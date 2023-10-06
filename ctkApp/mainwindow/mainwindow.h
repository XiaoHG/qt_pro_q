#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ctkPluginContext.h"
#include "mainwindowservice.h"
#include "mainwindowmanager.h"
#include "QQmlApplicationEngine"
#include <QObject>

#include <QQuickView>
#include <QQmlContext>

class MainWindow : public QObject, public MainWindowService
{
    Q_OBJECT

    //接口、插件、服务的关系
    //1个接口类(MainWindowPluginServer)由1个类(MainWindow)实现，输出1个服务(MainWindowPluginServer)和1个插件(MainWindow)。


    //此宏与Q_DECLARE_INTERFACE宏配合使用。
    //Q_DECLARE_INTERFACE：声明一个接口类,
    //Q_INTERFACES：当一个类继承这个接口类， 表明需要实现这个接口类
    Q_INTERFACES(MainWindowService)//表明实现, 告诉Qt插件系统实现插件服务的实现类, 调用时候就调用这个实现类的具体实现

public:
    explicit MainWindow(ctkPluginContext *context = nullptr);
    ~MainWindow();
    virtual void exec();
    Q_INVOKABLE void quit();
    void postCtkEvent(const QString &topic, const ctkDictionary &message);

private:
    void initObj();
    void initQml();

signals:

private:
    ctkPluginContext *m_context;

private:
    QQuickView m_view;
    QQmlContext *m_qmlRootContext = nullptr;

private:
    MainWindowManager *m_mainWindowManager = nullptr;
};

#endif // MAINWINDOW_H
