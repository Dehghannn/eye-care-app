#ifndef REMINDER_H
#define REMINDER_H

#include <QDebug>
#include <QObject>
#include <QTimer>
/// @brief Reminder Class implements methods needed to notify the user every few
///  minutes
class Reminder : public QObject {
  Q_OBJECT
public:
  explicit Reminder(QObject *parent = nullptr);

  int interval() const;
  void setInterval(int interval);
  void stop();
  void start();
public slots:

  void timerTimeOut();

signals:
  void timeOut();

private:
  QTimer m_timer;
  int m_interval;
};

#endif // REMINDER_H
