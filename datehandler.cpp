#include "datehandler.h"

DateHandler::DateHandler(QObject *parent)
    : QObject(parent), m_currentDate(QDate::currentDate().toString())
{
    connect(&m_timer, &QTimer::timeout, this, &DateHandler::updateDate);
    m_timer.start(86400000); // Update every 24 hours
}

QString DateHandler::currentDate() const
{
    return m_currentDate;
}

void DateHandler::updateDate()
{
    QString newDate = QDate::currentDate().toString();
    if (newDate != m_currentDate) {
        m_currentDate = newDate;
        emit dateChanged();
    }
}
