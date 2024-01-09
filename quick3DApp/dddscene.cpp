#include "dddscene.h"
#include "dddutils.h"

#include <QtQml/QQmlEngine>
#include <Qt3DRender/QRenderSettings>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DInput/QInputSettings>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QPlaneMesh>

DDDScene::DDDScene(QObject *parent)
    : QObject{parent}
    , m_rootEntity(new DDDRootEntity())
    , m_renderSettings(nullptr)
    , m_renderer(nullptr)
{
    m_dddUtils = new DDDUtils(this);
}

DDDRootEntity *DDDScene::rootEntity()
{
    return m_rootEntity;
}

void DDDScene::setRootEntity(DDDRootEntity *newRootEntity)
{
    if (m_rootEntity == newRootEntity)
        return;
    m_rootEntity = newRootEntity;
    emit rootEntityChanged();
}
