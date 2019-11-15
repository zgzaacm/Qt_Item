#include "QuickSort.h"
#include <QDebug>

int QuickSort::QuickSort_Partition(RoadStorage& arr, int low, int high)
{
    RoadInfo tmp= arr[low];
    while(low<high)
    {
         while(low<high && arr[high].Linkid >= tmp.Linkid) high--;
         arr[low]=arr[high];
         while(low<high && arr[low].Linkid <= tmp.Linkid)  low++;
         arr[high]=arr[low];
    }
    arr[low]=tmp;
    return low;
}
void QuickSort::SortFunction_QuickSort(RoadStorage& arr, int low, int high)
{
    if(low<high)
    {
        int mid = (high-low)/2+low;
        if (arr[high] < arr[mid])SortFunction_Swap(arr, mid, high);
        if (arr[low] < arr[mid])SortFunction_Swap(arr, mid, low);
        if (arr[low] > arr[high])SortFunction_Swap(arr, high, low);
        int bound=QuickSort_Partition(arr,low,high);
        SortFunction_QuickSort(arr,low,bound-1);
        SortFunction_QuickSort(arr,bound+1,high);
    }
}


void QuickSort::SortFunction_Sort(void)
{
    SortFunction_QuickSort(New_Data, 0, New_Data.RoadStorage_GetSize()-1);
}
