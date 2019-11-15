#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#pragma once
#include "SearchFunction.h"
#include "roadinfo.h"
#include "roadstorage.h"
class BinarySearch :
    public SearchFunction
{
public:
    BinarySearch(int ord);
    void SearchFunction_Search(QString Waiting) ;
    int SearchFunction_Search(unsigned int LinkId) ;
};

#endif // BINARYSEARCH_H
