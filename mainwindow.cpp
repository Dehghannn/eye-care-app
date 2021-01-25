#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    reminder = new Reminder;
    connect(reminder, &Reminder::timeOut, this,
            &MainWindow::on_timeLimit_reached);
    m_messg = new QMessageBox;
    m_messg->setWindowFlag(Qt::WindowType::Tool);
    m_messg->setWindowFlag(Qt::WindowType::WindowStaysOnTopHint);
    m_messg->setText("Look far for at least 20 seconds to protect your eyes.");
    m_messg->addButton(QMessageBox::Ok);
    m_messg->setIcon(QMessageBox::Warning);
    m_messg->setWindowTitle("Watch Out!");
    initIconTray();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::changeEvent(QEvent *event) {
    QMainWindow::changeEvent(event);
    /// handling minimize to system tray event
    if (event->type() == QEvent::WindowStateChange) {
        if (isMinimized()) {
            show_tray_icon();
            /// 100 ms delay for hiding window
            QTimer::singleShot(100, this, &MainWindow::hide);
        }
    }
}

void MainWindow::on_saveButton_clicked() {
    reminder->setInterval(
                ui->intervalSpinBox->value() *
                60000); ///< @todo change 10000 to 60000 after development
}

void MainWindow::on_timeLimit_reached() { m_messg->exec(); }

void MainWindow::on_startButton_clicked() {
    reminder->start();
    ui->statusLabel->setText("EyeCare is On");
}

void MainWindow::on_stopButton_clicked() {
    reminder->stop();
    ui->statusLabel->setText("EyeCare is Off");
}
void MainWindow::show_tray_icon() { m_tray_icon->show(); }

void MainWindow::initIconTray() {
    m_tray_icon = new QSystemTrayIcon(QIcon(":/etc/icon.png"), this);

    connect(m_tray_icon, &QSystemTrayIcon::activated, this,
            &MainWindow::on_tray_doubleClicked);

    QAction *quit_action = new QAction("Exit", m_tray_icon);
    connect(quit_action, &QAction::triggered, this, &MainWindow::close);

    QAction *show_action = new QAction("Show", m_tray_icon);
    connect(show_action, &QAction::triggered, this, &MainWindow::on_show_hide);

    QMenu *tray_icon_menu = new QMenu;
    tray_icon_menu->addAction(show_action);
    tray_icon_menu->addAction(quit_action);

    m_tray_icon->setContextMenu(tray_icon_menu);
}

void MainWindow::on_tray_doubleClicked(
        QSystemTrayIcon::ActivationReason reason) {
    if (reason) {
        if (reason != QSystemTrayIcon::DoubleClick)
            return;
    }

    on_show_hide();
}

void MainWindow::on_show_hide() {
    if (isVisible()) {
        hide();
    } else {
        m_tray_icon->hide();
        setWindowState(Qt::WindowState::WindowActive);
        showNormal();
        setFocus();

    }
}
