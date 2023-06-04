
#ifndef PLUGIN1ACTIVATOR_H
#define PLUGIN1ACTIVATOR_H


#include <QObject>
#include "ctkPluginActivator.h"
#include "plugin1service.h"

class Plugin1;
class Plugin1Activator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PLUGIN1_IID)
    Q_INTERFACES(ctkPluginActivator)

public:
    explicit Plugin1Activator(QObject *parent = nullptr);
    virtual void start(ctkPluginContext* context);
    virtual void stop(ctkPluginContext* context);

signals:

private:
    Plugin1 *m_lugin1 = nullptr;
};

#endif // PLUGIN1ACTIVATOR_H
