/**************************
File Name: HillSort.cpp
Content: hill sport
Date: 2019/11/13
**************************/
#include "HillSort.h"
/* 构造函数 */
HillSort::HillSort(int Ord) :SortFunction(Ord) {};
void HillSort::SortFunction_Sort(void)
{
    /* 设置增量 */
    int Gap = 0;
    /* 数据的长度 */
    int DataLength = New_Data.RoadStorage_GetSize();
    int k = 0;
    int j = 0;
    RoadInfo temp;
    /* 设置增量每次都是Gap/2 */
    for(Gap = DataLength/2 ; Gap > 0 ; Gap /= 2)
    {
        /* 将要插入的数据放入temp中 */
        for(k = Gap ; k < DataLength ; k++)
        {
            /* 需要插入的数据 */
            temp = New_Data[k];
            j = k - Gap;
            /* temp若比前面位置上的数字小，前面数就要后移 */
            while(j >= 0 && (Reverse?(temp < New_Data[j]):!(temp < New_Data[j])))
            {
                /* 后移 */
                New_Data[j + Gap] = New_Data[j];
                /* 找到前面一个位置上的数 */
                j = j - Gap;
            }
            /* temp插入这个位置 */
            New_Data[j + Gap] = temp;
        }
    }
}


