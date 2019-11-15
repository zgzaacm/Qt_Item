#ifndef BUCKETSORT_H
#define BUCKETSORT_H
#pragma once
#include "SortFunction.h"
#include <cmath>
#include "quicksort.h"
class BucketSort :
    public SortFunction
{
public:
    void SortFunction_Sort(void);
};

#endif // BUCKETSORT_H
