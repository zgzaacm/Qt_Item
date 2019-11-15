#ifndef ROADINFO_H
#define ROADINFO_H
#include <vector>
#include <string>
#include <QString>
using namespace std;

class RoadInfo
{
private:
    unsigned short RecordSize;
    bool Flag;
    unsigned short Branch;
    unsigned short Number;

public:
    unsigned Linkid;
    QString pName;
    RoadInfo(void);
    RoadInfo( bool Flags, unsigned short
    Branchs, unsigned short Numbers, unsigned Linkids, QString pNames);
    void RoadInfo_Convert(vector<unsigned char>& Res);
    ~RoadInfo(void);
    void RoadInfo_Set(vector<unsigned char>& Data, unsigned long long& Index);
    void RoadInfo_Disp(QString& StringShow);
    bool operator<(const RoadInfo& Other);
    bool operator==(unsigned LinkId);
    bool operator>(const RoadInfo& Other);
    friend class OrderSearch;
    friend class Update;
};

#endif // ROADINFO_H
