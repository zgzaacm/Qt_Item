/**************************
File Name: BubbleSort.cpp
Content: Bubble sort
Date: 2019/11/13
**************************/
#include "bubblesort.h"
/* this function have some new things */
using namespace std;
BubbleSort::BubbleSort(int Ord):SortFunction(Ord) {}
void BubbleSort::SortFunction_Sort(void)
{
    int lastSwapPos = 0,lastSwapPosTemp = 0;
    for (int i = 0; i < New_Data.RoadStorage_GetSize()-1; i++)
    {
        lastSwapPos = lastSwapPosTemp;
        for (int j = New_Data.RoadStorage_GetSize()-1; j >lastSwapPos; j--)
        {
            if (New_Data[j - 1] > New_Data[j])
            {
                RoadInfo temp = New_Data[j - 1];
                New_Data[j - 1] = New_Data[j];
                New_Data[j] = temp;
                lastSwapPosTemp = j;
            }
        }
        if (lastSwapPos == lastSwapPosTemp)
            break;
    }
}
