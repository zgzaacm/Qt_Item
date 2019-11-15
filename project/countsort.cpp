#include "CountSort.h"
#include <QDebug>
RoadInfo CountSort::CountSort_GetMax(void)
{
    RoadInfo max = New_Data[0];
    for (int i = 1; i < New_Data.RoadStorage_GetSize(); i++)
    {
        if (New_Data[i] > max)   max = New_Data[i];
    }
    return max;
}

RoadInfo CountSort::CountSort_GetMin(void)
{

    RoadInfo min = New_Data[0];
    for (int i = 1; i < New_Data.RoadStorage_GetSize(); i++) {
        if (New_Data[i] < min)   min = New_Data[i];
    }
    return min;
}

void CountSort::SortFunction_Sort(void)
{
    RoadInfo Max = CountSort_GetMax(), Min = CountSort_GetMin();
    const int size = Max.Linkid - Min.Linkid + 1;
    int* count = new int[size];
    const int m = New_Data.RoadStorage_GetSize();
    for (int i = 0; i < size; i++) count[i] = 0;
    for (int i = 0; i < m; i++)
        count[New_Data[i].Linkid - Min.Linkid]++;
    for (int i = 1; i < size; i++)
        count[i] += count[i - 1];
    vector<RoadInfo> a;
    for(int i = 0; i < m ;i++)
        a.push_back(RoadInfo());
    for (int i = m-1; i >= 0; i--)
    {
        count[New_Data[i].Linkid - Min.Linkid]--;
        a[count[New_Data[i].Linkid - Min.Linkid]]= New_Data[i];
    }
    for (int i = 0; i < m; i++)
        New_Data[i] = a[i];
    delete []count;
}
