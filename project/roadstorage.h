#ifndef ROADSTORAGE_H
#define ROADSTORAGE_H
#include <vector>
#include "roadinfo.h"
#include <string>
using namespace std;

class RoadStorage
{
private:
    vector<RoadInfo> DataMemory;
    int Size;
public:
    RoadStorage(void);
    ~RoadStorage(void);
    RoadStorage& operator=(const RoadStorage& Other);
    void RoadStorage_Set(QString Path);
    void RoadStorage_GetRoadInfo(QString& S,int Index);
    int RoadStorage_GetSize(void);
    RoadInfo& operator[](int Index);
    vector<RoadInfo>::iterator RoadStorage_GetBegin();
    void RoadStorage_PushBack(RoadInfo Now);
    friend class Update;
};

#endif // ROADSTORAGE_H
