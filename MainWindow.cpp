#include "MainWindow.h"
#include <QQmlContext>
#include <QDebug>

MainWindow::MainWindow(QObject *parent) : QObject(parent) {
    qmlRegisterType<MyClass>("com.example", 1, 0, "MyClass");
    qmlRegisterType<Uhr>("com.example", 1, 0, "Uhr");
    qmlRegisterType<Date>("com.example", 1, 0, "Date");

    engine.rootContext()->setContextProperty("myclass", &myclass);
    engine.rootContext()->setContextProperty("uhr", &uhr);
    engine.rootContext()->setContextProperty("date", &date);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    if (engine.rootObjects().isEmpty()) {
        qCritical() << "Error: No root objects loaded from QML.";
        exit(-1);
    }
}

void MainWindow::initialize() {
   
}
