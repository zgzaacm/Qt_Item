#ifndef ORDERSEARCH_H
#define ORDERSEARCH_H
#pragma once
#include "SearchFunction.h"
class OrderSearch :
    public SearchFunction
{
public:
    OrderSearch(int ord);
    void SearchFunction_Search(QString Waiting) ;
    int SearchFunction_Search(unsigned int LinkId) ;
};

#endif // ORDERSEARCH_H
