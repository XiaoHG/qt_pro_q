#ifndef MAINWINDOWMANAGER_H
#define MAINWINDOWMANAGER_H

#include <QObject>

class MainWindowManager : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowManager(QObject *parent = nullptr);

signals:

};

#endif // MAINWINDOWMANAGER_H
