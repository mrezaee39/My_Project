#include "Uhr.h"

Uhr::Uhr(QObject *parent) : QObject(parent), m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &Uhr::updateTime);
    m_timer->start(1000); // Update every second
}
Uhr::~Uhr() // Destructor implementation
{
    m_timer->stop();
    disconnect(m_timer, &QTimer::timeout, this, &Uhr::updateTime);
}

QString Uhr::time() const
{
    return m_time;
}

void Uhr::updateTime()
{
    m_time = QDateTime::currentDateTime().toString("hh:mm:ss");
    emit timeChanged();
}
