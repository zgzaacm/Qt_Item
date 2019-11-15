#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "roadstorage.h"
#include <QPushButton>
#include <QListWidgetItem>
#include <QPalette>
#include <QPixmap>
#include <QBrush>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "sortfunction.h"
#include "mywarning.h"

extern QString S;
extern RoadStorage Old_Data;
extern RoadStorage New_Data;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool Used[4];
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
