#include "mainwindow.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "QtWidgets/qapplication.h"

// CTKPluginFramework includes
#include "ctkPluginContext.h"
#include "ctkPluginFrameworkLauncher.h"
#include "service/event/ctkEventAdmin.h"

MainWindow::MainWindow(ctkPluginContext *context)
    : m_context(context)
{
}

void MainWindow::exec()
{
    qDebug() << Q_FUNC_INFO;
    init();
}

void MainWindow::init()
{

    m_engine.load(QUrl(QStringLiteral("qrc:/qml/QApplicationWindow.qml")));
    QObject::connect(&m_engine, &QQmlEngine::quit, qApp, [](){
        ctkPluginFrameworkLauncher::stop();
        QApplication::quit();
    });

    initObj();
    initQml();
}

void MainWindow::initObj()
{
    m_rootContext = m_engine.rootContext();
    m_mainWindowManager = new MainWindowManager(this);
}

void MainWindow::initQml()
{
    qmlRegisterType<MainWindowManager>("MainWindowManager", 1, 0, "MainWindowManager");
    m_rootContext->setContextProperty("mainWindowManager", m_mainWindowManager);
}

void MainWindow::postCtkEvent(const QString &topic, const ctkDictionary &message)
{
    //获取事件服务接口
    ctkServiceReference ref;
    ctkEventAdmin* eventAdmin = nullptr;
    ref = m_context->getServiceReference<ctkEventAdmin>();

    if(ref)
    {
        eventAdmin = m_context->getService<ctkEventAdmin>(ref);
        m_context->ungetService(ref);
    }

    //发送事件
    if(eventAdmin){
        eventAdmin->postEvent(ctkEvent(topic, message));
    }
}

