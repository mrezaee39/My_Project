#include "MyClass.h"

MyClass::MyClass(QObject *parent) : QObject(parent), m_message("Hello from MyClass!") {
    
/**
 * @brief Binds the UDP socket to all available network interfaces on port 12345.
 * @param address QHostAddress::Any to bind to all available network interfaces.
 * @param port Port number 12345 to listen for incoming UDP datagrams.
 * @return true if the socket is successfully bound; otherwise false.
 */

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 12345);

    connect(udpSocket, &QUdpSocket::readyRead, this, &MyClass::handleReadyRead);

}

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


void MyClass::handleReadyRead() {
        while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        qDebug() << "Received message:" << datagram;
    }
}
