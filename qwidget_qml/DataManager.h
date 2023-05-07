
#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QDebug>

class DataManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    DataManager(QObject *parent = 0);
    Q_INVOKABLE void printer();

    QString name() const;
    void setName(const QString &newName);

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // DATAMANAGER_H
