
#ifndef PLUGIN1SERVICE_H
#define PLUGIN1SERVICE_H


#include <QObject>


class Plugin1Service
{
public:
    Plugin1Service(){};
    virtual void exec() = 0;
};

#define PLUGIN1_IID "interface_plugin1service"
Q_DECLARE_INTERFACE(Plugin1Service, PLUGIN1_IID)

#endif // PLUGIN1SERVICE_H
