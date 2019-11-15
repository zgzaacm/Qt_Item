#ifndef UPDATE_H
#define UPDATE_H

#pragma once
#include <string>
#include "roadinfo.h"
#include "roadstorage.h"
#include "SearchFunction.h"
#include "ordersearch.h"

extern QString S;
using namespace std;
class Update
{
public:
    void Update_Replace();
    void Update_Append(RoadInfo& RoadAdd);
    bool Update_Delete(unsigned int LinkId);
    bool Update_Modify(const RoadInfo& RoadModify, unsigned int LinkId);
};


#endif // UPDATE_H
