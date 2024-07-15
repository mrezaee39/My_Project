#include "MyClass.h"

MyClass::MyClass(QObject *parent) : QObject(parent), m_message("Hello from MyClass!") {}

QString MyClass::message() const {
    return m_message;
}

void MyClass::setMessage(const QString &message) {
    if (m_message != message) {
        m_message = message;
        emit messageChanged();
    }
}

int MyClass::onButtonClicked(int i) {
   qDebug() << i++;
   return i++;
    }
