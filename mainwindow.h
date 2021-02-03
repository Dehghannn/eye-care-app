#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reminder.h"
#include <QAction>
#include <QContextMenuEvent>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QLocale>
#include <QFont>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void changeEvent(QEvent *event) override;

  /// @brief create and set a Tray Icon with actions
  void initIconTray();
  void show_tray_icon();

private slots:
  void on_saveButton_clicked();
  void on_startButton_clicked();

  void on_stopButton_clicked();
  void tray_doubleClicked(QSystemTrayIcon::ActivationReason reason);
  /// @brief toggle between mainwindow show and hide
  void show_hide();

public slots:
  /// @brief triggered by reminder each interval minutes
  void timeLimit_reached();

private:
  Ui::MainWindow *ui;
  Reminder *reminder;
  QMessageBox *m_messg;
  QSystemTrayIcon *m_tray_icon;
};
#endif // MAINWINDOW_H
