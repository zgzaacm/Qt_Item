#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(920,505);

    setWindowTitle("电子地图信息管理系统");

    for(int i = 0; i < 4; i++) Used[i] = 0;

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/timg.jpg")));
    setPalette(pal);

    ui->BtnRead->setIcon(QIcon(":/new/prefix1/read.png"));
    ui->BtnSort->setIcon(QIcon(":/new/prefix1/sort.png"));
    ui->BtnSearch->setIcon(QIcon(":/new/prefix1/serch.png"));
    ui->BtnRenew->setIcon(QIcon(":/new/prefix1/renew.png"));

    ui->ReadWidget->hide();
    ui->SortWidget->hide();
    ui->SearchWidget->hide();
    ui->RenewWidge->hide();

    connect(ui->BtnRead,&QPushButton::clicked,[=]()
    {
        Used[0] = 1;
        Used[1] = 0;
        ui->RenewWidge->hide();
        ui->LabelWelcome->hide();
        ui->SortWidget->hide();
        ui->SearchWidget->hide();
        S = QFileDialog::getOpenFileName(this,"文件读取","C:\\Users\\Dell\\Desktop","*.dat");
        ui->ReadWidget->show();
        ui->ReadWidget->ShowAll();
    });

    connect(ui->BtnSort,&QPushButton::clicked,[=](){
        if(!Used[0]){
            MyWarning * Warn = new MyWarning;
            Warn->show();

        }else{
            ui->RenewWidge->hide();
            ui->SortWidget->SortChoose_DeleteAll();
            ui->LabelWelcome->hide();
            ui->ReadWidget->hide();
            ui->SearchWidget->hide();
            ui->SortWidget->show();
            Used[1] = 1;
            Used[0] = 1;
        }
    });

    connect(ui->BtnSearch,&QPushButton::clicked,[=](){
        if(!Used[0]){
            MyWarning * Warn = new MyWarning;
            Warn->show();
        }else{
            ui->RenewWidge->hide();
            ui->LabelWelcome->hide();
            ui->ReadWidget->hide();
            ui->SortWidget->hide();
            ui->SearchWidget->show();
        }
    });

    connect(ui->BtnRenew,&QPushButton::clicked,[=](){
        if(!Used[0]){
            MyWarning * Warn = new MyWarning;
            Warn->show();
        }else{
            ui->SearchWidget->hide();
            ui->LabelWelcome->hide();
            ui->ReadWidget->hide();
            ui->SortWidget->hide();
            ui->RenewWidge->show();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
