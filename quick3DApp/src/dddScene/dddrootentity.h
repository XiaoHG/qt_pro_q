#ifndef DDDROOTENTITY_H
#define DDDROOTENTITY_H

#include <QObject>
#include <Qt3DCore/QEntity>

class DDDRootEntity : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit DDDRootEntity(Qt3DCore::QNode *parent = nullptr);

private:
    void createRootEntity();

signals:

};

#endif // DDDROOTENTITY_H
