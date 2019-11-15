#ifndef SEARCHUI_H
#define SEARCHUI_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QButtonGroup>
#include "binarysearch.h"
#include <QString>
#include "searchfunction.h"
#include "ordersearch.h"
namespace Ui {
class SearchUi;
}

class SearchUi : public QWidget
{
    Q_OBJECT

public:
    explicit SearchUi(QWidget *parent = nullptr);
    ~SearchUi();

private:
    SearchFunction * pSearch;
    int SearchWay;
    Ui::SearchUi *ui;
};

#endif // SEARCHUI_H
