#include "mainwindow.h"

#include <QApplication>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont(":/fonts/Vazir-Regular.ttf");
    if (fontId != -1)
    {
    QFont font("MyFont");
    a.setFont(font);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
