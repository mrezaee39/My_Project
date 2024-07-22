#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "MyClass.h"
#include "Uhr.h"
#include "Date.h"

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = nullptr);
    void initialize();

private:
    QQmlApplicationEngine engine;
    MyClass myclass;
    Uhr uhr;
    Date date;
};

#endif // MAINWINDOW_H
