#ifndef GETDATA_H
#define GETDATA_H

#include <QWidget>
#include "roadstorage.h"
#include "roadinfo.h"
extern RoadStorage Old_Data;
extern RoadStorage New_Data;

namespace Ui {
class GetData;
}

class GetData : public QWidget
{
    Q_OBJECT

public:
    explicit GetData(QWidget *parent = nullptr);
    ~GetData();
    bool Flag;
    void Clear(void);

private:
    Ui::GetData *ui;
};

#endif // GETDATA_H
