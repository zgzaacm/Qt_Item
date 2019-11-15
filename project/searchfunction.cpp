/**************************
File Name: SearchFunction.cpp
Content: Search something in data
Date: 2019/11/13
**************************/
#include "SearchFunction.h"
#include <vector>

SearchFunction::~SearchFunction(){

}
SearchFunction::SearchFunction(int KeyType)
{
    KeyWordType = KeyType;
}

SearchFunction::SearchFunction(void)
{
    KeyWordType = 0;
}

void SearchFunction::SearchFunction_GetResult(vector<RoadInfo>& Res)
{
    Res = Result;
}
