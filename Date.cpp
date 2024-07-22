    #include "Date.h"

    Date::Date(QObject *parent) : QObject(parent), m_day(1), m_month(1), m_year(2000) {
         connect(this, &Date::dateChanged, this, &Date::toString);
    }

    Date::Date(int day, int month, int year, QObject *parent) : QObject(parent), m_day(day), m_month(month), m_year(year) {
        connect(this, &Date::dateChanged, this, &Date::toString);
    }

    void Date::setDay(int day) {
        if (m_day != day) {
            m_day = day;
            emit dateChanged();
        }
    }

    void Date::setMonth(int month) {
        if (m_month != month) {
            m_month = month;
            emit dateChanged();
        }
    }

    void Date::setYear(int year) {
        if (m_year != year) {
            m_year = year;
            emit dateChanged();
        }
    }

    int Date::getDay() const {
        return m_day;
    }

    int Date::getMonth() const {
        return m_month;
    }

    int Date::getYear() const {
        return m_year;
    }

    QString Date::toString() const {
        return QString("%1/%2/%3").arg(m_day).arg(m_month).arg(m_year);
    }
