
#include "mainwindow.h"
#include "ctkException.h"
#include "ctkPlugin.h"
#include "ctkPluginContext.h"
#include "ui_mainwindow.h"
#include "ctkPluginException.h"
#include "ctkPluginFrameworkLauncher.h"
#include "service/event/ctkEventAdmin.h"
#include <QDebug>
#include <QCoreApplication>
#include <QUrl>
#include <QDir>
#include "../plugin1/plugin1service.h"
#include "../plugin2/plugin2service.h"
#include "ctkeventcommon.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ctkPluginInit();
    ctkPluginStart();
}

MainWindow::~MainWindow()
{
    delete ui;
    ctkPluginFrameworkLauncher::stop();
}

void MainWindow::postCtkEvent(const ctkEvent &event)
{
    ctkPluginContext* context = m_ctkFramework->getPluginContext();
    ctkServiceReference ref = context->getServiceReference<ctkEventAdmin>();
    if (ref) {
        ctkEventAdmin* eventAdmin = context->getService<ctkEventAdmin>(ref);
        eventAdmin->sendEvent(event);
    }
}

void MainWindow::ctkPluginInit()
{
    // 获取插件所在位置
    // 在插件的搜索路径列表中添加一条路径
    ctkPluginFrameworkLauncher::addSearchPath("E:/ctk/install/lib/ctk-0.1/plugins");
    // 设置并启动 CTK 插件框架
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");


    //插件加载
    m_ctkFramework = m_ctkFrameworkFactory.getFramework();
    try{
        m_ctkFramework->init();
        m_ctkFramework->start();
        qDebug() << Q_FUNC_INFO << ", CTK plugin m_ctkFramework start ... ";
    }catch(const ctkPluginException &e){
        qDebug() << Q_FUNC_INFO << ", CTK plugin m_ctkFramework init err: " << e.what();
        return;
    }

    QDir pluginDir = QApplication::applicationDirPath();
    pluginDir.cd("plugins");
    foreach (auto fileInfo, pluginDir.entryInfoList()) {
        if(fileInfo.suffix() != "dll") continue;
        QString pluginPath = pluginDir.absoluteFilePath(fileInfo.fileName());
        try{
            QSharedPointer<ctkPlugin> plugin = m_ctkFramework->getPluginContext()->installPlugin(QUrl::fromLocalFile(pluginPath));
            if(plugin){
                qDebug() << Q_FUNC_INFO << ", " + pluginPath << ": install success! " << "version = " << plugin->getVersion();
            }
        }catch(const ctkPluginException &e){
            qDebug() << Q_FUNC_INFO << ", " + pluginPath << ": install error! " << "error msg: " << e.what();
            return;
        }catch(...){
            qDebug() << Q_FUNC_INFO << ", " + pluginPath << ": install failed! " << "error msg: unknown error";
            return;
        }
    }
}

void MainWindow::ctkPluginStart()
{
    QList<QSharedPointer<ctkPlugin>> plugins = m_ctkFramework->getPluginContext()->getPlugins();
    for(int i = 0; i < plugins.count(); i++){
        QSharedPointer<ctkPlugin> plugin = plugins.at(i);
        qDebug () << Q_FUNC_INFO << ", getSymbolicName = " << plugin->getSymbolicName();
        try{
            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << Q_FUNC_INFO << ", " + plugin->getSymbolicName() << ": start success! " << "version = " << plugin->getVersion();
        }catch(const ctkPluginException &e){
            qDebug() << Q_FUNC_INFO << ", " + plugin->getSymbolicName() << ": start failed! " << "error msg = " << e.what();
            return;
        }catch(...){
            qDebug() << Q_FUNC_INFO << ", " + plugin->getSymbolicName() << ": start failed! " << "error msg = unknown error";
            return;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    //测试， 发布一个stk广播
    ctkDictionary props;
    props["title"] = "mainwindow msg";
    props["content"] = "this is a mainwindow test msg";
    props["author"] = "mainwindow";
    qDebug() << "Publisher sends a message, properties:" << props;
    ctkEvent event(CTK_E_MAINWINDOW_TOPIC, props);
    postCtkEvent(event);


    //插件接口直接调用
    ctkPluginContext* context = m_ctkFramework->getPluginContext();

    ctkServiceReference plugin1Ref = context->getServiceReference<Plugin1Service>();
    Plugin1Service* plugin1 = nullptr;
    if(plugin1Ref)
        plugin1 = context->getService<Plugin1Service>(plugin1Ref);
    if(plugin1)
        plugin1->exec();

    ctkServiceReference plugin2Ref = context->getServiceReference<Plugin2Service>();
    Plugin2Service* plugin2 = nullptr;
    if(plugin2Ref)
        plugin2 = context->getService<Plugin2Service>(plugin2Ref);
    if(plugin2)
        plugin2->exec();
}

