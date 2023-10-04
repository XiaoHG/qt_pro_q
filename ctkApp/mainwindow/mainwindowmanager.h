#ifndef MAINWINDOWMANAGER_H
#define MAINWINDOWMANAGER_H

#include <QObject>
#include "./src/d3drendercontrol.h"

class MainWindow;
class MainWindowManager : public QObject
{
    friend class MainWindow;
    Q_OBJECT
public:
    explicit MainWindowManager(QObject *parent = nullptr);

signals:


private:
    D3DRenderControl *m_d3DRenderControl = nullptr;
};

#endif // MAINWINDOWMANAGER_H
