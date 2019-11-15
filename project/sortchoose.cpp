#include "sortchoose.h"
#include "ui_sortchoose.h"

SortChoose::SortChoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortChoose)
{
    ui->setupUi(this);
    connect(ui->BtnStart,&QPushButton::clicked,[=](){
        this->SortChoose_DeleteAll();
        SortFunction * GetSort;
        clock_t begin_time, end_clock;
        char SortChar[7][50] = {"HeapSort运行时间：", "CountSort运行时间：", "BucketSort运行时间：", "QuickSort运行时间：",
                                "HillSort运行时间：", "BubbleSort运行时间：", "MergeSort运行时间："};
        char NumberChar[20];
        for(int i = 0; i < 7 ;i++)
        {
            if(Sort[i]){

                begin_time = clock();

                New_Data.operator=(Old_Data);
                GetSort = SortGet(i);
                GetSort->SortFunction_Sort();
                end_clock = clock();

                double Num = static_cast<double>(end_clock - begin_time) / CLOCKS_PER_SEC;
                gcvt(Num, 10, NumberChar);
                strcat(SortChar[i], "  ");
                strcat(SortChar[i], NumberChar);
                strcat(SortChar[i], " s");

                QListWidgetItem *item = new QListWidgetItem;
                item->setText(SortChar[i]);
                ui->ListWidgetTime->addItem(item);

            }
        }

        QListWidgetItem *item = new QListWidgetItem;
        item->setText("-----------------------------------------------------\n排序结果：");
        ui->ListWidgetResult->addItem(item);

        QString S;
        for(int i = 0; i < New_Data.RoadStorage_GetSize(); i++)
        {
            New_Data.RoadStorage_GetRoadInfo(S, i);
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(S);
            ui->ListWidgetResult->addItem(item);
        }
    });

    for(int i = 0; i < 7;i++)
        Sort[i] = 0;

    connect(ui->CheckBoxHeapSort,&QCheckBox::stateChanged,[=](int n){
        if(n==2)
            Sort[0] = 1;
        else{
            Sort[0] = 0;
        }
    });
    connect(ui->CheckBoxCountSort,&QCheckBox::stateChanged,[=](int n){
        if(n==2)
            Sort[1] = 1;
        else{
            Sort[1] = 0;
        }
    });
    connect(ui->CheckBoxBucketSort,&QCheckBox::stateChanged,[=](int n){
        if(n==2)
            Sort[2] = 1;
        else{
            Sort[2] = 0;
        }
    });
    connect(ui->CheckBoxQuickSort,&QCheckBox::stateChanged,[=](int n){
        if(n==2)
            Sort[3] = 1;
        else{
            Sort[3] = 0;
        }
    });
    connect(ui->CheckBoxHillSort,&QCheckBox::stateChanged,[=](int n){
        if(n==2)
            Sort[4] = 1;
        else{
            Sort[4] = 0;
        }
    });
    connect(ui->CheckBoxBubbleSort,&QCheckBox::stateChanged,[=](int n){

        if(n==2){
            Wait * W = new Wait;
            W->show();
            Sort[5] = 1;
        }

        else {
            Sort[5] = 0;
        }
    });
    connect(ui->CheckBoxMergeSort,&QCheckBox::stateChanged,[=](int n){
        if(n==2)
            Sort[6] = 1;
        else{
            Sort[6] = 0;
        }
    });

    connect(ui->BtnClear,&QPushButton::clicked,[=](){
        for(int i = 0; i < 7; i++)
            Sort[i] = 0;
        SortChoose_DeleteAll();
        ui->CheckBoxHeapSort->setCheckState(Qt::Unchecked);
        ui->CheckBoxBubbleSort->setCheckState(Qt::Unchecked);
        ui->CheckBoxMergeSort->setCheckState(Qt::Unchecked);
        ui->CheckBoxBucketSort->setCheckState(Qt::Unchecked);
        ui->CheckBoxCountSort->setCheckState(Qt::Unchecked);
        ui->CheckBoxQuickSort->setCheckState(Qt::Unchecked);
        ui->CheckBoxHillSort->setCheckState(Qt::Unchecked);
    });
}
void SortChoose::SortChoose_DeleteAll()
{
    int counter =ui->ListWidgetTime->count();
    for(int index=0;index<counter;index++)
    {
        QListWidgetItem *item = ui->ListWidgetTime->takeItem(0);
            delete item;
    }
    int counter2 =ui->ListWidgetResult->count();
    for(int index=0;index<counter2;index++)
    {
        QListWidgetItem *item = ui->ListWidgetResult->takeItem(0);
            delete item;
    }
}

SortFunction* SortChoose::SortGet(int Index)
{
    switch (Index) {
    case 0:static HeapSort Heap;return &Heap;
    case 1:static CountSort Count;return &Count;
    case 2:static BucketSort Bucket;return &Bucket;
    case 3:static QuickSort Quick;return &Quick;
    case 4:static HillSort Hill;return &Hill;
    case 5:static BubbleSort Bubble;return &Bubble;
    case 6:static MergeSort Merge;return &Merge;
    }
}


SortChoose::~SortChoose()
{
    delete ui;
}
