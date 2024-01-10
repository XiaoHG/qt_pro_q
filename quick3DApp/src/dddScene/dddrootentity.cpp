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

#include "dddutils.h"

static const QColor helperPlaneColor("#585a5c");

DDDRootEntity::DDDRootEntity(Qt3DCore::QNode *parent)
    : Qt3DCore::QEntity{parent}
    , m_gridSize(3)
{
    init();
}

void DDDRootEntity::init()
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    this->setObjectName(QStringLiteral("__internal root entity"));

    Qt3DRender::QCamera *camera = new Qt3DRender::QCamera();
    camera->lens()->setPerspectiveProjection(45.0f, 50.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 5, 20));
    camera->setViewCenter(QVector3D(0, 0, 0));
    auto *cameraController = new Qt3DExtras::QOrbitCameraController(this);
    cameraController->setCamera(camera);
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(200.0f);

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


    createHelperPlane();
}

void DDDRootEntity::createHelperPlane()
{
    m_helperPlane = new Qt3DCore::QEntity();
    m_helperPlane->setObjectName(QStringLiteral("__internal helper plane"));

    // Helper plane origin must be at the meeting point of lines, hence the odd lineCount
    Qt3DRender::QGeometryRenderer *planeMesh = DDDUtils::createWireframePlaneMesh(51);

    Qt3DExtras::QPhongMaterial *helperPlaneMaterial = new Qt3DExtras::QPhongMaterial();
    helperPlaneMaterial->setAmbient(helperPlaneColor);
    helperPlaneMaterial->setDiffuse(QColor(Qt::black));
    helperPlaneMaterial->setSpecular(QColor(Qt::black));
    helperPlaneMaterial->setShininess(0);

    m_helperPlaneTransform = new Qt3DCore::QTransform();
    m_helperPlaneTransform->setScale3D(QVector3D(m_gridSize * 25.0f, m_gridSize * 25.0f, 1.0f));
    m_helperPlaneTransform->setRotation(
        m_helperPlaneTransform->fromAxisAndAngle(1.0f, 0.0f, 0.0f, 90.0f));
    m_helperPlane->addComponent(planeMesh);
    m_helperPlane->addComponent(helperPlaneMaterial);
    m_helperPlane->addComponent(m_helperPlaneTransform);
    m_helperPlane->setParent(this);
}
