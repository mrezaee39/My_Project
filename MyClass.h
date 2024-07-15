#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>

class MyClass : public QObject 
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit MyClass(QObject *parent = nullptr);

    QString message() const;
    void setMessage(const QString &message);

signals:
    void messageChanged(); 

public slots:
    int onButtonClicked(int i);

    void handleReadyRead();

private:
    QString m_message;

    QUdpSocket *udpSocket;
};

#endif // MYCLASS_H