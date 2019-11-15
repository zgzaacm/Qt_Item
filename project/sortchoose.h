#ifndef SORTCHOOSE_H
#define SORTCHOOSE_H
#include "quicksort.h"
#include "bubblesort.h"
#include "bucketsort.h"
#include "countsort.h"
#include "hillsort.h"
#include "mergesort.h"
#include "heapsort.h"
#include <QPushButton>
#include <QCheckBox>
#include <ctime>
#include <cstdlib>
#include "sortfunction.h"
#include <QWidget>
#include "wait.h"

namespace Ui {
class SortChoose;
}

class SortChoose : public QWidget
{
    Q_OBJECT

public:
    explicit SortChoose(QWidget *parent = nullptr);
    void SortChoose_DeleteAll();
    ~SortChoose();
    SortFunction* SortGet(int Index);


private:
    int Sort[8];
    Ui::SortChoose *ui;

friend class MainWindow;
};

#endif // SORTCHOOSE_H
