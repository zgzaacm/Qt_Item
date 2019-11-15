#include "getdata.h"
#include "ui_getdata.h"
#include <QCheckBox>
#include "successwidget.h"
#include "countsort.h"
GetData::GetData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetData)
{
    ui->setupUi(this);
    Flag = false;
    ui->LineName->setEnabled(false);
    connect(ui->CheckBoxName,&QCheckBox::stateChanged,[=](int n){
        if(n == 2){
            ui->LineName->setEnabled(true);
        }
        else{
            ui->LineName->setEnabled(false);
        }
    });
    connect(ui->BtnSure,&QPushButton::clicked,[=](){
        CountSort c;
        c.SortFunction_Sort();
        QString StrLinkId = ui->LineLinkID->text();
        QString StrNumber = ui->LineClass->text();
        QString StrBranch = ui->LineBranch->text();
        QString StrName = ui->LineName->text();
        RoadInfo Now(true,StrBranch.toShort(),StrNumber.toShort(),StrLinkId.toInt(),StrName);
        New_Data.RoadStorage_PushBack(Now);
        SuccessWidget * W = new SuccessWidget;
        W->show();
    });

}
void GetData::Clear()
{
    ui->LineName->clear();
    ui->LineClass->clear();
    ui->LineBranch->clear();
    ui->LineLinkID->clear();
}

GetData::~GetData()
{
    delete ui;
}
