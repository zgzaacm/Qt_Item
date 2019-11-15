#include "searchui.h"
#include "ui_searchui.h"
#include <QDebug>
#include "countsort.h"
SearchUi::SearchUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchUi)
{
    this->pSearch = new OrderSearch(1);
    this->SearchWay = 1;
    ui->setupUi(this);
    QButtonGroup * BtnGroup = new QButtonGroup(this);
    BtnGroup->addButton(ui->BtnName, 0);
    BtnGroup->addButton(ui->BtnLink, 1);
    BtnGroup->addButton(ui->BtnClass, 2);
    BtnGroup->addButton(ui->BtnBranch, 3);
    QButtonGroup * BtnGroup2 = new QButtonGroup(this);
    BtnGroup2->addButton(ui->BtnBinary, 0);
    BtnGroup2->addButton(ui->BtnHash, 1);
    void (QButtonGroup:: *pBtn)(int,bool) = &QButtonGroup::buttonToggled;
    connect(BtnGroup2, pBtn, [=](int n,bool y){
        if(!n){
            delete this->pSearch;
            this->pSearch = new BinarySearch(this->SearchWay);
        }
        else {
            delete this->pSearch;
            this->pSearch = new OrderSearch(this->SearchWay);
        }
    });

    connect(BtnGroup, pBtn, [=](int n,bool y){
        if(n == 1)
            ui->BtnBinary->setEnabled(true);
        else
            ui->BtnBinary->setEnabled(false);
        this->pSearch->KeyWordType = n;
        this->SearchWay = n;
    });

    connect(ui->BtnStart, &QPushButton::clicked, [=](){
        ui->ListWidget->clear();
        QString str = ui->LineEdit->text();
        CountSort c;
        c.SortFunction_Sort();

        if(this->SearchWay == 0){
            this->pSearch->SearchFunction_Search(str);
        }else{
            this->pSearch->SearchFunction_Search(unsigned(str.toInt()));
        }

        vector<RoadInfo> Result;
        this->pSearch->SearchFunction_GetResult(Result);

        if(!Result.size()){
            QListWidgetItem *item = new QListWidgetItem;
            item->setText("--------------------------------没找到------------------------------------");
            ui->ListWidget->addItem(item);
        }


        QString S;
        for(int i = 0; i < Result.size(); i++)
        {
            Result[i].RoadInfo_Disp(S);
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(S);
            ui->ListWidget->addItem(item);
        }

    });
    connect(ui->BtnClear,&QPushButton::clicked,[=](){
        ui->LineEdit->clear();
        ui->ListWidget->clear();
    });

}

SearchUi::~SearchUi()
{
    delete ui;
    delete this->pSearch;
}
