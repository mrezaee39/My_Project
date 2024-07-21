#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyClass.h"
#include "Uhr.h"
#include "Date.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MyClass myclass;
    Uhr uhr;
    Date date(21,7,2024);


    QQmlApplicationEngine engine;

    qmlRegisterType<MyClass>("com.example", 1, 0, "MyClass");
    qmlRegisterType<Uhr>("com.example", 1, 0, "Uhr");
    qmlRegisterType<Date>("com.example", 1, 0, "Date");


    engine.rootContext()->setContextProperty("myclass", &myclass);
    engine.rootContext()->setContextProperty("uhr", &uhr);
    engine.rootContext()->setContextProperty("date", &date);



    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}