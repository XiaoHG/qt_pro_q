#include "dddrootentity.h"
#include "qplanemesh.h"

#include <QtQml/QQmlEngine>
#include <Qt3DRender/QRenderSettings>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DInput/QInputSettings>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QOrbitCameraController>

DDDRootEntity::DDDRootEntity(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity{parent}
{
    createRootEntity();
}

void DDDRootEntity::createRootEntity()
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    this->setObjectName(QStringLiteral("__internal root entity"));

    Qt3DRender::QCamera *camera = new Qt3DRender::QCamera();
    camera->setPosition(QVector3D(0, 5, 20));
    camera->setViewCenter(QVector3D(0, 0, 0));
    auto *cameraController = new Qt3DExtras::QOrbitCameraController(this);
    cameraController->setCamera(camera);

    Qt3DRender::QRenderSettings *m_renderSettings = new Qt3DRender::QRenderSettings();
    m_renderSettings->pickingSettings()->setPickMethod(Qt3DRender::QPickingSettings::TrianglePicking);
    m_renderSettings->pickingSettings()->setPickResultMode(Qt3DRender::QPickingSettings::AllPicks);
    m_renderSettings->setObjectName(QStringLiteral("__internal Scene frame graph"));
    Qt3DExtras::QForwardRenderer *m_renderer = new Qt3DExtras::QForwardRenderer();
    m_renderer->setClearColor(Qt::lightGray);
    m_renderer->setCamera(camera);
    m_renderSettings->setActiveFrameGraph(m_renderer);

    // Setting the FrameGraph to actual root entity to protect it from accidental removal
    this->addComponent(m_renderSettings);
    this->addComponent(new Qt3DInput::QInputSettings());


    { // plane
        auto *plane = new Qt3DCore::QEntity(this);
        auto *planeMesh = new Qt3DExtras::QPlaneMesh();
        auto *planeTransform = new Qt3DCore::QTransform();
        auto *planeMaterial = new Qt3DExtras::QPhongMaterial(this);
        planeMesh->setWidth(10); planeMesh->setHeight(10);
        planeTransform->setTranslation(QVector3D(0, 0, 0));
        planeMaterial->setDiffuse(QColor(150, 150, 150));

        plane->addComponent(planeMaterial);
        plane->addComponent(planeMesh);
        plane->addComponent(planeTransform);
    }
}
