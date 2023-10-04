
#include "mainwindowactivator.h"
#include "mainwindow.h"
#include <QDebug>

MainWindowActivator::MainWindowActivator(QObject *parent)
    : QObject{parent}
{

}

void MainWindowActivator::start(ctkPluginContext *context)
{
    m_mainWindowPlugin = new MainWindow(context);

    ctkDictionary dic;
    context->registerService<MainWindowService>(m_mainWindowPlugin, dic);
}

void MainWindowActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)
    if( m_mainWindowPlugin != nullptr )
        m_mainWindowPlugin->deleteLater();
    qDebug() << "my plugin stop";
}

