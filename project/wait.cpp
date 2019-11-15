#include "wait.h"
#include "ui_wait.h"

Wait::Wait(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wait)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&QWidget::close);
}

Wait::~Wait()
{
    delete ui;
}
