#include "ordersearch.h"
#include <QDebug>
void OrderSearch::SearchFunction_Search(QString pName)
{
    Result.clear();
    for(int i = 0; i < New_Data.RoadStorage_GetSize(); i++){
        if(New_Data[i].pName.toStdString().find(pName.toStdString()) != string::npos)
            Result.push_back(New_Data[i]);
    }
}

OrderSearch::OrderSearch(int ord):SearchFunction (ord){}

int OrderSearch::SearchFunction_Search(unsigned int LinkID)
{
    Result.clear();
    for(int i = 0;i < New_Data.RoadStorage_GetSize(); i++)
    {
        switch (this->KeyWordType) {
        case 1:{
            if(New_Data[i].Linkid == LinkID)
                Result.push_back(New_Data[i]);
            break;
        }
        case 3:{
            if(New_Data[i].Branch == LinkID)
                Result.push_back(New_Data[i]);
            break;
        }
        case 2:{
            if(New_Data[i].Number == LinkID)
                Result.push_back(New_Data[i]);
        }
        }
    }
    return 0;
}
