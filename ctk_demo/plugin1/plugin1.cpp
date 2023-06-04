
#include "plugin1.h"
#include "ctkPluginContext.h"
#include "service/event/ctkEventAdmin.h"
#include "service/event/ctkEventConstants.h"
#include "ctkeventcommon.h"
#include <QDebug>

Plugin1::Plugin1(ctkPluginContext *context, QObject *parent)
    : QObject{parent}, m_ctkContext(context)
{
    ctkDictionary dic;
    dic.insert(ctkEventConstants::EVENT_TOPIC, CTK_E_MAINWINDOW_TOPIC);
    context->registerService<ctkEventHandler>(this, dic);
}

void Plugin1::exec()
{
    qDebug() << Q_FUNC_INFO;

    ctkDictionary props;
    props["title"] = "demoplugin send";
    props["content"] = "this is a test event";
    props["author"] = "demoplugin";
    qDebug() << "Publisher sends a message, properties:" << props;
    ctkEvent event("demoplugin", props);
    postCtkEvent(event);
}

void Plugin1::handleEvent(const ctkEvent& event)
{
    QString title = event.getProperty("title").toString();
    QString content = event.getProperty("content").toString();
    QString author = event.getProperty("author").toString();

    qDebug()<< Q_FUNC_INFO;
    qDebug()<<"====================================================";
    qDebug()<<"=== EventHandler received the message ===";
    qDebug()<<"topic: "<<event.getTopic();
    qDebug()<<"----------- properties -----------";
    qDebug()<<"title: "<<title;
    qDebug()<<"content: "<<content;
    qDebug()<<"author: "<<author;
}

void Plugin1::postCtkEvent(const ctkEvent &event)
{
    ctkServiceReference ref = m_ctkContext->getServiceReference<ctkEventAdmin>();
    if (ref) {
        ctkEventAdmin* eventAdmin = m_ctkContext->getService<ctkEventAdmin>(ref);
        eventAdmin->postEvent(event);
    }
}
