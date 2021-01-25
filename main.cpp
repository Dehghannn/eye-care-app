#include "mainwindow.h"

#include <QApplication>
#include <QFont>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont(":/fonts/Ubuntu-R.ttf");
//    QFontDatabase fontDB;
//    fontDB.addApplicationFont(":/fonts/Ubuntu-R.ttf");
//    QStringList fontFamily = fontDB.families();
//    QStringList fontStyles = fontDB.styles(fontFamily.first());
//    QList<int> fontPointSizes = fontDB.smoothSizes(fontFamily.first(), fontStyles.first());
//    qDebug() << fontFamily << fontStyles <<  fontPointSizes;
//    QFont mainFont(fontDB.font(fontFamily.first(), fontStyles.first(), 24));
//    qDebug() << mainFont.pixelSize() << mainFont.pointSize();
    if (fontId != -1)
    {
    QFont font("MyFont");
    a.setFont(font);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
