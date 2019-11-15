#include "binarysearch.h"


BinarySearch::BinarySearch(int ord):SearchFunction (ord){}

int BinarySearch::SearchFunction_Search(unsigned int LinkId)
{
    Result.clear();
    /* 初始化左右的值为边界值 */
    int Left = 0;
    int Right = New_Data.RoadStorage_GetSize() - 1;
    int Middle = 0;

    /* 循环查找直到左右边界重合且查找标志为false */
    while(Left <= Right)
    {
        Middle = (Left + Right) / 2;
        if(New_Data[Middle] == LinkId){
            Result.push_back(New_Data[Middle]);
            return Middle;
        }
        if(New_Data[Middle].Linkid < LinkId)
            Left = Middle + 1;
        else
            Right = Middle - 1;
    }
    return -1;
}

void BinarySearch::SearchFunction_Search(QString Waiting)
{
}

