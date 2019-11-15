#ifndef RENEWWIDGET_H
#define RENEWWIDGET_H

#include <QWidget>
#include "update.h"
namespace Ui {
class RenewWidget;
}

class RenewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RenewWidget(QWidget *parent = nullptr);
    ~RenewWidget();

private:
    Ui::RenewWidget *ui;
};

#endif // RENEWWIDGET_H
