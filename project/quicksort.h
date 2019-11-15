#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortFunction.h"
class QuickSort :
    public SortFunction
{
public:
    static int QuickSort_Partition(RoadStorage& arr, int low, int high);
    static void SortFunction_QuickSort(RoadStorage& Data,int low, int high);
    void SortFunction_Sort(void);
};


#endif // QUICKSORT_H
