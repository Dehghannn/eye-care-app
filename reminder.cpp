#include "reminder.h"

Reminder::Reminder(QObject *parent) : QObject(parent) {
  m_timer.setSingleShot(false);
  m_timer.setTimerType(Qt::VeryCoarseTimer);
  connect(&m_timer, &QTimer::timeout, this, &Reminder::timerTimeOut);
  m_interval = 60000;
}

int Reminder::interval() const { return m_interval; }

void Reminder::setInterval(int interval) {
  m_interval = interval;
  m_timer.setInterval(m_interval);
}

void Reminder::stop() { m_timer.stop(); }

void Reminder::start() { m_timer.start(m_interval); }

void Reminder::timerTimeOut() { emit timeOut(); }
