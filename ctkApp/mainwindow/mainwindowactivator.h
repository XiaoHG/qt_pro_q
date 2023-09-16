
#ifndef MAINWINDOWACTIVATOR_H
#define MAINWINDOWACTIVATOR_H

#include <QObject>
#include "ctkPluginActivator.h"
#include "ctkPluginContext.h"

class MainWindow;
class MainWindowActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "MainWindow")
    Q_INTERFACES(ctkPluginActivator)

public:
    explicit MainWindowActivator(QObject *parent = nullptr);
    void start(ctkPluginContext *context);
    void stop(ctkPluginContext *context);

signals:

private:
    QSharedPointer<MainWindow> m_mainWindowPlugin;

};

#endif // MAINWINDOWACTIVATOR_H
