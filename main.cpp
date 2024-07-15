#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyClass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MyClass myclass;

    QQmlApplicationEngine engine;

    qmlRegisterType<MyClass>("com.example", 1, 0, "MyClass");

    engine.rootContext()->setContextProperty("myclass", &myclass);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}