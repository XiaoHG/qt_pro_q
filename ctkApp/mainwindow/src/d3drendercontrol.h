#ifndef D3DRENDERCONTROL_H
#define D3DRENDERCONTROL_H

#include <QObject>
#include <QSharedPointer>

class D3DRenderData: public QObject
{
    Q_OBJECT

public:
    explicit D3DRenderData(QObject *parent = nullptr);
    ~D3DRenderData();
};

class D3DRenderControl : public QObject
{
    Q_OBJECT
public:
    explicit D3DRenderControl(QObject *parent = nullptr);

signals:


private:
    QSharedPointer<D3DRenderData> m_d3DRenderData;
};

#endif // D3DRENDERCONTROL_H
