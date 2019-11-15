#ifndef SUCCESSWIDGET_H
#define SUCCESSWIDGET_H

#include <QWidget>
#include "wait.h"

namespace Ui {
class SuccessWidget;
}

class SuccessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SuccessWidget(QWidget *parent = nullptr);
    ~SuccessWidget();

private:
    Ui::SuccessWidget *ui;
};

#endif // SUCCESSWIDGET_H
