
#include "plugin2activator.h"
#include "plugin2.h"
#include <QDebug>

Plugin2Activator::Plugin2Activator(QObject *parent)
    : QObject{parent}
{
}

void Plugin2Activator::start(ctkPluginContext *context)
{
    qDebug() << Q_FUNC_INFO;
    m_lugin2 = new Plugin2(context);
    ctkDictionary dic;
    context->registerService<Plugin2Service>(m_lugin2, dic);
}

void Plugin2Activator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)
    qDebug() << Q_FUNC_INFO;
    if( m_lugin2 != nullptr ){
        m_lugin2->deleteLater();
    }
}

