
#ifndef PLUGIN2_H
#define PLUGIN2_H


#include <QObject>
#include "ctkPluginContext.h"
#include "plugin2service.h"
#include "service/event/ctkEventHandler.h"
#include "service/event/ctkEvent.h"

class Plugin2 : public QObject, public Plugin2Service, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(Plugin2Service ctkEventHandler)

public:
    explicit Plugin2(ctkPluginContext *context = nullptr, QObject *parent = nullptr);
    virtual void exec();
    virtual void handleEvent(const ctkEvent& event);
    void initCtkEvent();
    void postCtkEvent(const ctkEvent &event);

signals:

private:
    ctkPluginContext *m_ctkContext = nullptr;
};

#endif // PLUGIN2_H
