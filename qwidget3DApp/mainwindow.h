
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVBoxLayout>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QTransform>
#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/QForwardRenderer>
#include <QScreen>
#include <Qt3DAnimation>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QSphereMesh>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void init3DSence();
    void addGeoMesh(Qt3DCore::QEntity *rootEntity, Qt3DRender::QGeometryRenderer *geometry, QVector3D pos);

private:
    Ui::MainWindow *ui;

private:
    Qt3DExtras::Qt3DWindow* m_view = nullptr;
};

#endif // MAINWINDOW_H
