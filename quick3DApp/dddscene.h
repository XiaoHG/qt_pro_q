#ifndef DDDSCENE_H
#define DDDSCENE_H

#include <QObject>
#include <Qt3DCore/QEntity>

#include "dddrootentity.h"

namespace Qt3DCore {
    class QTransform;
    class QComponent;
}

namespace Qt3DRender {
    class QPickEvent;
    class QObjectPicker;
    class QRenderSettings;
    class QMaterial;
    class QGeometryRenderer;
    class QCamera;
    class QCameraLens;
    class QSceneExporter;
}

namespace Qt3DExtras {
    class QPhongAlphaMaterial;
    class QForwardRenderer;
}

class DDDUtils;
class DDDScene : public QObject
{
    Q_OBJECT
    Q_PROPERTY(DDDRootEntity *rootEntity READ rootEntity WRITE setRootEntity NOTIFY rootEntityChanged FINAL)

public:
    explicit DDDScene(QObject *parent = nullptr);

    DDDRootEntity *rootEntity();
    void setRootEntity(DDDRootEntity *newRootEntity);

signals:
    void rootEntityChanged();

private:
    DDDRootEntity *m_rootEntity = nullptr;
    Qt3DRender::QRenderSettings *m_renderSettings = nullptr;
    Qt3DExtras::QForwardRenderer *m_renderer = nullptr;

private:
    DDDUtils *m_dddUtils = nullptr;

};

#endif // DDDSCENE_H
