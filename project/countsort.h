#ifndef COUNTSORT_H
#define COUNTSORT_H

#pragma once
#include "SortFunction.h"
class CountSort :
    public SortFunction
{
    RoadInfo CountSort_GetMax(void);
    RoadInfo CountSort_GetMin(void);
public:
    void SortFunction_Sort(void);
};


#endif // COUNTSORT_H
