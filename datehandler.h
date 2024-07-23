#ifndef DATEHANDLER_H
#define DATEHANDLER_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDate>

class DateHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentDate READ currentDate NOTIFY dateChanged)

public:
    explicit DateHandler(QObject *parent = nullptr);

    QString currentDate() const;

signals:
    void dateChanged();

private slots:
    void updateDate();

private:
    QString m_currentDate;
    QTimer m_timer;
};

#endif // DATEHANDLER_H
