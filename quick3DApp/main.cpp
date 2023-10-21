#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QDebug>
#include <QtCore/QLoggingCategory>
#include <QQmlApplicationEngine>


#include <Qt3DCore/Qt3DCore>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DExtras/Qt3DExtras>
#include <Qt3DExtras/QExtrudedTextMesh>

#include "dddscene.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("XiaoHG");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QGuiApplication app(argc, argv);

    DDDScene *dddScene = new DDDScene();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dddScene", dddScene);
    engine.load(QUrl(QStringLiteral("qrc:/qml/mian.qml")));

    return app.exec();
}
