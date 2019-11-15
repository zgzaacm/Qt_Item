#ifndef BUBBLESORT_H
#define BUBBLESORT_H

/**************************
File Name: BubbleSort.h
Content: Bubble sort
Date: 2019/11/13
**************************/
#pragma once
#include "sortfunction.h"
#include <iostream>
class BubbleSort :
    public SortFunction
{
public:
    BubbleSort(int Ord = 1);
    /*************************/
    #ifdef bubble
    Function : void SortFunction_Sort(void);
    Content : sort
    Parameter : none
    Return : none
    Date : 2019 / 11 / 13
    Description : use bubble sort
    #endif
    /*************************/
    void SortFunction_Sort(void);
};


#endif // BUBBLESORT_H
