
#ifndef PLUGIN2SERVICE_H
#define PLUGIN2SERVICE_H


#include <QObject>


class Plugin2Service
{
public:
    Plugin2Service(){};
    virtual void exec() = 0;
};

#define PLUGIN2_IID "interface_plugin2service"
Q_DECLARE_INTERFACE(Plugin2Service, PLUGIN2_IID)

#endif // PLUGIN2SERVICE_H
