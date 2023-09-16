
#ifndef MAINWINDOWSERVICE_H
#define MAINWINDOWSERVICE_H


#include <QObject>


class MainWindowService
{
public:
    MainWindowService();
    virtual void exec() = 0;
};

Q_DECLARE_INTERFACE(MainWindowService, "interface_mainwindow")

#endif // MAINWINDOWSERVICE_H
