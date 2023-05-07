
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

    QScopedPointer<QQuickView> m_pQuickView;
    QScopedPointer<QQmlContext> m_pQuickContext;
    QScopedPointer<QQuickItem> m_pQuickItem;

    QScopedPointer<DataManager> m_pDataManager;
};

#endif // MAINWINDOW_H
