#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyClass.h"
#include "Uhr.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MyClass myclass;
    Uhr uhr;


    QQmlApplicationEngine engine;

    qmlRegisterType<MyClass>("com.example", 1, 0, "MyClass");
    qmlRegisterType<MyClass>("com.example", 1, 0, "Uhr");


    engine.rootContext()->setContextProperty("myclass", &myclass);
    engine.rootContext()->setContextProperty("uhr", &uhr);



    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}