// Qt includes
#include <QApplication>
#include <QDebug>

// CTKPluginFramework includes
#include "ctkPluginException.h"
#include "ctkPluginContext.h"
#include "ctkPluginFrameworkLauncher.h"

//mainwindow plugin
#include "../mainwindow/mainwindowservice.h"

QSharedPointer<ctkPlugin> installPlugin(const QString &path, ctkPluginContext* context)
{
    QSharedPointer<ctkPlugin> installPluginPtr = nullptr;
    qInfo() << "[Install Plugin] " << path;
    try {
        QUrl location = QUrl::fromLocalFile(QFileInfo(path).absoluteFilePath());
        installPluginPtr = context->installPlugin(location);
    } catch(const ctkPluginException &e) {
        qCritical() << QString("Failed to install plugin") << e.what();
        return nullptr;
    }

    qInfo() << "Install Plugin Success!";
    return installPluginPtr;
}

bool startPlugin(QSharedPointer<ctkPlugin> plugin)
{
    try {
        plugin->start(ctkPlugin::START_TRANSIENT);
    } catch(const ctkPluginException &e) {
        qCritical() << QString("Failed to start plugin") << e.what();
        return false;
    }

    return true;
}

bool loadPlugins(const QString& pluginName)
{
    QString pluginsPath = QCoreApplication::applicationDirPath() + "/plugins/";
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();

    // Install plugins
    QString installPath = pluginsPath + pluginName;
    QSharedPointer<ctkPlugin> installPluginPtr = installPlugin(installPath, context);
    if (installPluginPtr == nullptr)
        return false;

    // Start plugins
    if (!startPlugin(installPluginPtr))
        return false;
    return true;
}

void initCtkPluginFramework()
{
    // 获取插件所在位置
    // 在插件的搜索路径列表中添加一条路径
    QString pluginsPath = QApplication::applicationDirPath() + "/plugins/";
    ctkPluginFrameworkLauncher::addSearchPath(pluginsPath);
    // 设置并启动 CTK 插件框架
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");


    loadPlugins("mainwindow.dll");
    //    loadPlugins(SPLASHWINDOW_DLL);
    //    loadPlugins(PRINTER_DLL);
    //    loadPlugins(AUTOUPDATER_DLL);
    //    loadPlugins(ACCLOUD_DLL);
    //    loadPlugins(GAREPORT_DLL);

    // mainWindow
    ctkPluginContext *context = ctkPluginFrameworkLauncher::getPluginContext();
    ctkServiceReference ref = context->getServiceReference<MainWindowService>();
    if (ref) {
        MainWindowService* mainWindow = context->getService<MainWindowService>(ref);
        if (mainWindow != nullptr) {
            mainWindow->exec();
        }
    } else {
        qFatal("No Main Window found.");
    }
}

int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#    if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#    endif
#endif

    QApplication app(argc, argv);
    initCtkPluginFramework();

    return app.exec();
}



