#ifndef SORTFUNCTION_H
#define SORTFUNCTION_H
#include <vector>
using namespace std;
#include "roadstorage.h"
extern RoadStorage Old_Data;
extern RoadStorage New_Data;

class SortFunction
{
protected:
    int Reverse;
public:
    SortFunction(void);
    SortFunction(int Order);
    /*************************/
    #ifdef sort
    Function : void SortFunction_Sort(void)
    Content : sort data use different functions
    Parameter : none
    Return : none
    Date : 2019 / 11 / 13
    #endif
        /*************************/
    virtual void SortFunction_Sort(void) = 0;
    /*************************/
    #ifdef swap
    Function : void SortFunction_Swap(int First, int Second)
    Content : swap
    Parameter : int First, int Second
    Return : none
    Date : 2019 / 11 / 13
    Description : swap left and right
    #endif
    /*************************/
    static void SortFunction_Swap(RoadStorage& Data, int First, int Second);
    /*************************/
    #ifdef compare
    Function : bool SortFunction_Compare(int Left, int Right)
    Content : compare two data
    Parameter : int Left, int Right
    Return : right > left ? 0 : 1
    Date : 2019 / 11 / 13
    Description : compare two data
    #endif
    /*************************/
    bool SortFunction_Compare(int Left, int Right);
};
#endif // SORTFUNCTION_H
