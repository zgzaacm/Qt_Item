#include "renewwidget.h"
#include "ui_renewwidget.h"
#include "countsort.h"
#include "successwidget.h"
RenewWidget::RenewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenewWidget)
{
    ui->setupUi(this);
    ui->DeleteWidget->hide();
    ui->ChangeWidget->hide();
    ui->NewWidget->hide();

    connect(ui->BtnDelete,&QPushButton::clicked,[=](){
        CountSort C;
        C.SortFunction_Sort();
        ui->LabelWelcome->hide();
        ui->ChangeWidget->hide();
        ui->LineDelete->clear();
        ui->NewWidget->hide();
        ui->DeleteWidget->show();
        ui->LabelFail->hide();
        ui->LabelSuccess->hide();
    });
    connect(ui->BtnForDelete,&QPushButton::clicked,[=](){
        Update U;
        ui->LabelFail->hide();
        ui->LabelSuccess->hide();
        QString str = ui->LineDelete->text();
        if(U.Update_Delete(str.toInt())){
            ui->LabelSuccess->show();
        }else{
            ui->LabelFail->show();
        }

    });
    connect(ui->BtnChange,&QPushButton::clicked,[=](){
        CountSort C;
        C.SortFunction_Sort();
        ui->LabelWelcome->hide();
        ui->DeleteWidget->hide();
        ui->lineEdit->clear();
        ui->NewWidget->Clear();
        ui->ChangeWidget->show();
        ui->NewWidget->show();
    });
    connect(ui->BtnChang,&QPushButton::clicked,[=](){

        Update U;
        QString str = ui->lineEdit->text();
        U.Update_Delete(str.toInt());
    });
    connect(ui->BtnAdd,&QPushButton::clicked,[=](){
        CountSort C;
        C.SortFunction_Sort();
        ui->LabelWelcome->hide();
        ui->DeleteWidget->hide();
        ui->ChangeWidget->hide();
        ui->NewWidget->Clear();
        ui->NewWidget->show();
    });
    connect(ui->BtnSource,&QPushButton::clicked,[=](){
        ui->LabelWelcome->hide();
        ui->DeleteWidget->hide();
        ui->ChangeWidget->hide();
        ui->NewWidget->hide();
        Update U;
        U.Update_Replace();
        SuccessWidget * W = new SuccessWidget;
        W->show();
    });
}

RenewWidget::~RenewWidget()
{
    delete ui;
}
