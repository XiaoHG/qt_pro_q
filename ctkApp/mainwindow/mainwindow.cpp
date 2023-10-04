#include "mainwindow.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>

// CTKPluginFramework includes
#include "ctkPluginContext.h"
#include "ctkPluginFrameworkLauncher.h"
#include "service/event/ctkEventAdmin.h"

MainWindow::MainWindow(ctkPluginContext *context)
    : m_context(context)
{

    m_view.registerAspect(new Qt3DAnimation::QAnimationAspect());

    m_view.setSource(QUrl("qrc:/qml/main.qml"));
    m_view.resize(800, 600);
    m_view.show();

    //init & get qml root context.
    m_qmlRootContext = m_view.engine()->qmlEngine()->rootContext();

    initObj();
    initQml();
}

MainWindow::~MainWindow()
{

}

void MainWindow::exec()
{
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::quit()
{
    ctkPluginFrameworkLauncher::stop();
}

void MainWindow::initObj()
{
    m_mainWindowManager = new MainWindowManager(this);
}

void MainWindow::initQml()
{
    //register --- 1
    qmlRegisterType<MainWindowManager>("MainWindowManager", 1, 0, "MainWindowManager");


    //register --- 2
    m_qmlRootContext->setContextProperty("mainWindow", this);
    m_qmlRootContext->setContextProperty("mainWindowManager", m_mainWindowManager);
    m_qmlRootContext->setContextProperty("d3DRenderControl", m_mainWindowManager->m_d3DRenderControl);
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

