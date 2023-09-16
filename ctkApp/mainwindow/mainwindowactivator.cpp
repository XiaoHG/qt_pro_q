
#include "mainwindowactivator.h"
#include "mainwindow.h"
#include <QDebug>

MainWindowActivator::MainWindowActivator(QObject *parent)
    : QObject{parent}
{

}

void MainWindowActivator::start(ctkPluginContext *context)
{
    qDebug() << "qin --- MainWindowActivator::start";

    m_mainWindowPlugin.reset(new MainWindow(context));

    ctkDictionary dic;
    context->registerService<MainWindowService>(m_mainWindowPlugin.get(), dic);
}

void MainWindowActivator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)
    qDebug() << "my plugin stop";
}

