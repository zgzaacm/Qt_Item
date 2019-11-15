#ifndef SEARCHFUNCTION_H
#define SEARCHFUNCTION_H


/**************************
File Name: SearchFunction.h
Content: Search something in data
Date: 2019/11/13
**************************/
#include <string>
#include <vector>
#include <QString>
/**************************
File Name: SearchFunction.h
Content: Search something in data
Date: 2019/11/13
**************************/
#include "roadinfo.h"
#include "roadstorage.h"
#include "roadinfo.h"
#include "roadstorage.h"
using namespace std;
#pragma once
extern RoadStorage Old_Data;
extern RoadStorage New_Data;
class SearchFunction
{
protected:

    vector<RoadInfo> Result;
public:
    int KeyWordType;
    SearchFunction(int KeyWordType);
    SearchFunction(void);
    virtual ~SearchFunction(void);
    /* 虚函数需要对Result进行操作 */
    virtual void SearchFunction_Search(QString Waiting) = 0;
    virtual int SearchFunction_Search(unsigned int LinkId) = 0;
    void SearchFunction_GetResult(vector<RoadInfo>& Res);
};


#endif // SEARCHFUNCTION_H
