
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ctkPluginFrameworkFactory.h"
#include "ctkPluginFramework.h"
#include "service/event/ctkEvent.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void postCtkEvent(const ctkEvent &event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ctkPluginFrameworkFactory m_ctkFrameworkFactory;
    QSharedPointer<ctkPluginFramework> m_ctkFramework;

private:
    void ctkPluginInit();
    void ctkPluginStart();
};

#endif // MAINWINDOW_H
