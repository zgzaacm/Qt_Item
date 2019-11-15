#include "successwidget.h"
#include "ui_successwidget.h"

SuccessWidget::SuccessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuccessWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("提醒");
    connect(ui->Btn, &QPushButton::clicked, this, &QWidget::close);
}

SuccessWidget::~SuccessWidget()
{
    delete ui;
}
