#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit MyClass(QObject *parent = nullptr);

    QString message() const;
    void setMessage(const QString &message);

signals:
    void messageChanged();

private:
    QString m_message;
};

#endif // MYCLASS_H