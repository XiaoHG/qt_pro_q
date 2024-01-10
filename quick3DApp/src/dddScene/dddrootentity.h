#ifndef DDDROOTENTITY_H
#define DDDROOTENTITY_H

#include <QObject>
#include <Qt3DCore/QEntity>

namespace Qt3DCore {
class QEntity;
class QTransform;
}

class DDDRootEntity : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit DDDRootEntity(Qt3DCore::QNode *parent = nullptr);

private:
    void init();
    void createHelperPlane();

signals:

private:
    Qt3DCore::QEntity *m_helperPlane = nullptr;
    Qt3DCore::QTransform *m_helperPlaneTransform = nullptr;

private:
    int m_gridSize;
};

#endif // DDDROOTENTITY_H
