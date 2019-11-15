#ifndef MYWARNING_H
#define MYWARNING_H

#include <QWidget>

namespace Ui {
class MyWarning;
}

class MyWarning : public QWidget
{
    Q_OBJECT

public:
    explicit MyWarning(QWidget *parent = nullptr);
    ~MyWarning();

private:
    Ui::MyWarning *ui;
};

#endif // MYWARNING_H
