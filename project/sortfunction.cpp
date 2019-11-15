/**************************
File Name: SortFunction.cpp
Content: sort function
Date: 2019/11/13
**************************/
#include <iostream>
#include <vector>
#include "SortFunction.h"
using namespace std;
/* 需要操作的数据 */

SortFunction::SortFunction(void)
{
    Reverse = 1;
}

SortFunction::SortFunction(int Order)
{
    Reverse = Order;
}

void SortFunction::SortFunction_Swap(RoadStorage& Data,int First, int Second)
{
    RoadInfo temp;
    temp = Data[First];
    Data[First] = Data[Second];
    Data[Second] = temp;
}

bool SortFunction::SortFunction_Compare(int Left, int Right)
{
    return New_Data[Right] < New_Data[Left];
}
