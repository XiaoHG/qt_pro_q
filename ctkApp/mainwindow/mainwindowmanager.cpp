#include "mainwindowmanager.h"

MainWindowManager::MainWindowManager(QObject *parent)
    : QObject{parent}
{
    m_d3DRenderControl = new D3DRenderControl(this);
}
