#include "readfile.h"
#include "ui_readfile.h"
#include <QFileDialog>

ReadFile::ReadFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadFile)
{
    ui->setupUi(this);
}

void ReadFile::ShowAll()
{
    ui->listWidget->clear();
    Old_Data.RoadStorage_Set(S);
    QString S;
    for(int i = 0; i < Old_Data.RoadStorage_GetSize(); i++)
    {
        Old_Data.RoadStorage_GetRoadInfo(S, i);
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(S);
        ui->listWidget->addItem(item);
    }
    New_Data = Old_Data;
}

ReadFile::~ReadFile()
{
    delete ui;
}
