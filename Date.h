#ifndef DATE_H
#define DATE_H

#include <QObject>
#include <QString>
#include <QDebug>

class Date : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString dateString READ toString NOTIFY dateChanged)

public:
    Date(QObject *parent = nullptr);  // Default constructor
    Date(int day, int month, int year, QObject *parent = nullptr);  // Parameterized constructor

    // Setters
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Utility function
    QString toString() const;

signals:
    void dateChanged();

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif // DATE_H
