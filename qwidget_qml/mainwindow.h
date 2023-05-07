
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QQuickWidget>
#include "DataManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void notifyChangedForQml();

private slots:
    void on_pushButton_clicked();
    void selectedChangedFromQml();

private:
    Ui::MainWindow *ui;

    QQuickView *m_pQuickView;
    QQmlContext *m_pQuickContext;
    QQuickItem *m_pQuickItem;

    QQuickWidget *m_pQuickWidget;
    DataManager *m_pDataManager;
};

#endif // MAINWINDOW_H
