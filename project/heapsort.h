#ifndef HEAPSORT_H
#define HEAPSORT_H

#pragma once
#include "SortFunction.h"
class HeapSort :
    public SortFunction
{
    /*************************/
    #ifdef heap
    Function : void HeapSort_MaxHeapFixDown(RoadInfo* p, int i, int n)
    Content : make big heap
    Parameter : RoadInfo * p, int i, int n
    Return : none
    Date : 2019 / 11 / 13
    #endif
    /*************************/
    void HeapSort_MaxHeapFixDown(RoadStorage& p, int i, int n);
public:
    void SortFunction_Sort(void);
};

#endif // HEAPSORT_H
