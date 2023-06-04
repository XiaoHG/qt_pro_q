
#ifndef PLUGIN2ACTIVATOR_H
#define PLUGIN2ACTIVATOR_H


#include <QObject>
#include "ctkPluginActivator.h"
#include "plugin2service.h"

class Plugin2;
class Plugin2Activator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PLUGIN2_IID)
    Q_INTERFACES(ctkPluginActivator)

public:
    explicit Plugin2Activator(QObject *parent = nullptr);
    virtual void start(ctkPluginContext* context);
    virtual void stop(ctkPluginContext* context);

signals:

private:
    Plugin2 *m_lugin2 = nullptr;
};

#endif // PLUGIN2ACTIVATOR_H
