
#ifndef PLUGIN1_H
#define PLUGIN1_H


#include <QObject>
#include "ctkPluginContext.h"
#include "plugin1service.h"
#include "service/event/ctkEventHandler.h"
#include "service/event/ctkEvent.h"

class Plugin1 : public QObject, public Plugin1Service, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(Plugin1Service ctkEventHandler)

public:
    explicit Plugin1(ctkPluginContext *context = nullptr, QObject *parent = nullptr);
    virtual void exec();
    virtual void handleEvent(const ctkEvent& event);
    void initCtkEvent();
    void postCtkEvent(const ctkEvent &event);

signals:

private:
    ctkPluginContext *m_ctkContext = nullptr;
};

#endif // PLUGIN1_H
