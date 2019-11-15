#ifndef HILLSORT_H
#define HILLSORT_H

/**************************
File Name: HillSort.h
Content: hill sport
Date: 2019/11/13
**************************/

#include "SortFunction.h"
class HillSort :
    public SortFunction
{
public:
    HillSort(int Ord = 1);
    /*************************/
    #ifdef Hill
    Function : void SortFunction_Sort(void);
    Content: sort
    Parameter : none
    Return : none
    Date : 2019 / 11 / 13
    Description : use Hill sort
    #endif
    /*************************/
    void SortFunction_Sort(void);
};

#endif // HILLSORT_H
