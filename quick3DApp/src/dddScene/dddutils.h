#ifndef DDDUTILS_H
#define DDDUTILS_H

#include <QObject>

namespace Qt3DRender {
class QGeometryRenderer;
class QGeometry;
class QBuffer;
}

class DDDUtils : public QObject
{
    Q_OBJECT
public:
    explicit DDDUtils(QObject *parent = nullptr);
    static Qt3DRender::QGeometryRenderer *createWireframePlaneMesh(int lineCount);
    static void addPositionAttributeToGeometry(Qt3DRender::QGeometry *geometry,
                                               Qt3DRender::QBuffer *buffer,
                                               int count);
signals:
};

#endif // DDDUTILS_H
