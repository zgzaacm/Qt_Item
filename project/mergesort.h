#ifndef MERGESORT_H
#define MERGESORT_H

/**************************
File Name: MergeSort.h
Content: merge sort
Date: 2019/11/13
**************************/
#include "SortFunction.h"

class MergeSort :
    public SortFunction
{
    void MergeSort_Merge(RoadStorage& Data, int Low, int Mid, int High);
public:
    MergeSort(int Ord = 1);
    /*************************/
    #ifdef merge
    Function : void SortFunction_Sort(void);
    Content: sort
    Parameter : none
    Return : none
    Date : 2019 / 11 / 13
    Description : use merge sort
    #endif
    /*************************/
void SortFunction_Sort(void);
};


#endif // MERGESORT_H
