#include "MainWindow.h"
#include <QQmlContext>
#include <QDebug>

MainWindow::MainWindow(QObject *parent) : QObject(parent) {

    qDebug() << "MainWindow Constructor";


    engine.rootContext()->setContextProperty("myclass", &myclass);
    engine.rootContext()->setContextProperty("uhr", &uhr);
    engine.rootContext()->setContextProperty("dateHandler", &dateHandler);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));

    if (engine.rootObjects().isEmpty()) {
        qCritical() << "Error: No root objects loaded from QML.";
        exit(-1); //return -1;
    }
}

void MainWindow::initialize() {
   
}
