
#include "plugin1activator.h"
#include "plugin1.h"
#include <QDebug>

Plugin1Activator::Plugin1Activator(QObject *parent)
    : QObject{parent}
{
}

void Plugin1Activator::start(ctkPluginContext *context)
{
    qDebug() << Q_FUNC_INFO;
    m_lugin1 = new Plugin1(context);
    ctkDictionary dic;
    context->registerService<Plugin1Service>(m_lugin1, dic);
}

void Plugin1Activator::stop(ctkPluginContext *context)
{
    Q_UNUSED(context)
    qDebug() << Q_FUNC_INFO;
    if( m_lugin1 != nullptr ){
        m_lugin1->deleteLater();
    }
}

