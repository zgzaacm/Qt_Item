#include "mainwindow.h"
#include <QApplication>
#include "roadstorage.h"
#include <QTextCodec>
#include <QString>
RoadStorage Old_Data;
RoadStorage New_Data;
QString S;

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
