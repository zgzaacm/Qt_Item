#ifndef READFILE_H
#define READFILE_H

#include <QWidget>
#include <string>
#include "roadstorage.h"
using namespace std;

extern QString S;
extern RoadStorage Old_Data;
extern RoadStorage New_Data;

namespace Ui {
class ReadFile;
}

class ReadFile : public QWidget
{
    Q_OBJECT

public:
    explicit ReadFile(QWidget *parent = nullptr);
    ~ReadFile();
    void ShowAll();

private:
    Ui::ReadFile *ui;
};

#endif // READFILE_H
