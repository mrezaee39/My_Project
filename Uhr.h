#ifndef UHR_H
#define UHR_H

#include <QObject>
#include <QTimer>
#include <QDateTime>

class Uhr : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString time READ time NOTIFY timeChanged)

public:
    explicit Uhr(QObject *parent = nullptr);
    ~Uhr();

    QString time() const;

signals:
    void timeChanged();

public slots:
    void updateTime();

private:
    QString m_time;
    QTimer *m_timer;
};

#endif // UHR_H
