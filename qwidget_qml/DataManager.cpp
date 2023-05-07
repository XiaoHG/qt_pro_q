
#include "DataManager.h"

DataManager::DataManager(QObject *parent)
    : QObject(parent)
{
    m_name = "qin";
}

void DataManager::printer()
{
    qDebug() << "qin --- DataManager::printer(), m_name = " + m_name;
    m_name += "x";
}

QString DataManager::name() const
{
    return m_name;
}

void DataManager::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
