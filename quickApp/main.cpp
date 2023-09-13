#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QDebug>
#include <QtCore/QLoggingCategory>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("XiaoHG");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/QApplicationWindow.qml")));

    return app.exec();
}
