/**************************
File Name: MergeSort.cpp
Content: merge sort
Date: 2019/11/13
**************************/
#include "MergeSort.h"
#include <algorithm>
/* 将a开头的长为Length的数组和b开头长为Right的数组合并。n为数组长度，用于最后一组 */
void MergeSort::MergeSort_Merge(RoadStorage& Data, int Low, int Mid, int High)
{
    int i = Low;
    int j = Mid + 1;
    int k = 0;
    vector<RoadInfo> pTemp;
    while (i <= Mid && j <= High)
    {
        /* 根据两个数据的大小决定将哪个数据存放到临时数组中 */
        if (Reverse)
        {
            Data[i] < Data[j] ? (pTemp.push_back(Data[i++])) : (pTemp.push_back(Data[j++]));
        }
        else
        {
            !(Data[i] < Data[j]) ? (pTemp.push_back(Data[i++])) : (pTemp.push_back(Data[j++]));
        }
    }
    /* 将剩下的数据存入临时的数组中 */
    while (i <= Mid)
    {
        pTemp.push_back(Data[i++]);
    }
    while (j <= High)
    {
        pTemp.push_back(Data[j++]);
    }
    /* 分治排序后的数据传入原数据中 */
    copy(pTemp.begin(), pTemp.end(), New_Data.RoadStorage_GetBegin() + Low);
}

MergeSort::MergeSort(int Ord) :SortFunction(Ord) {}

void MergeSort::SortFunction_Sort(void)
{
    int n = New_Data.RoadStorage_GetSize();
    int length;
    for (length = 1; length < n; length *= 2)
    {
        int i;
        for (i = 0; i + 2 * length - 1 <= n - 1; i += 2 * length)
            MergeSort_Merge(New_Data, i, i + length - 1, i + 2 * length - 1);
        if (i + length <= n - 1)
            MergeSort_Merge(New_Data, i, i + length - 1, n - 1);
    }
}
