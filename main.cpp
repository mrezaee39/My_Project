#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.initialize();

    return app.exec();
}
