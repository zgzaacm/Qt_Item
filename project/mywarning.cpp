#include "mywarning.h"
#include "ui_mywarning.h"

MyWarning::MyWarning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWarning)
{
    ui->setupUi(this);
    this->setWindowTitle("提醒");
    this->setFixedSize(260,210);
    this->setWindowIcon(QIcon(":/timg (2).jpg"));
    connect(ui->Btn,&QPushButton::clicked,this,&QWidget::close);
}

MyWarning::~MyWarning()
{
    delete ui;
}
