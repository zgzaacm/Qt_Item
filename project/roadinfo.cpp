#include "roadinfo.h"
#include <roadinfo.h>
#include <QDebug>
#include <QString>
RoadInfo::RoadInfo(void)
{
}
void RoadInfo::RoadInfo_Convert(vector<unsigned char>& Res)
{
    /* 每一次存储数据的时候都需要先清除缓存区 */

    unsigned char Temp = 0x00;
    QByteArray array = pName.toLocal8Bit();
    char *pTemp = array.data();
//    const char* pTemp = pName.toStdString().c_str();

    unsigned char Other;
    int i = 0;
    /* 存储记录的长度 */
    Other = ((RecordSize & 0xFF00) >> 8);
    Res.push_back(Other);
    Other = (RecordSize & 0x00FF);
    Res.push_back(Other);
    /* 存储linkid */
    Other = (Linkid & 0xFF000000) >> 24;
    Res.push_back(Other);
    Other = ((Linkid & 0x00FF0000) >> 16);
    Res.push_back(Other);
    Other = ((Linkid & 0x0000FF00) >> 8);
    Res.push_back(Other);
    Other = ((Linkid & 0x000000FF));
    Res.push_back(Other);

    /* 存储Reserved以及道路名称的长度 */
    for (i = 0; i < 5; i++)
    {
        Res.push_back(0x00);
    }
    /* 存储Flag */
    if (Flag)Temp |= 0x80;
    /* 存储岔路数 */
    Temp += (Branch << 4);
    /* 存储class番号 */
    Temp += Number;
    Res.push_back(Temp);

    int Len = RecordSize - 12, n = 0;

    /* 存储道路名称没有到达道路名称的最后面的时候 */
    while (*pTemp != '\0')
    {
        unsigned char No = *pTemp;
        Res.push_back(No);
        pTemp++;
        n++;
    }

    n = Len - n;
    while(n--)
    Res.push_back('\0');


}
void RoadInfo::RoadInfo_Set(vector<unsigned char>& Data, unsigned long long& Index)
{
    /* 读取记录大小 */
    this->RecordSize = Data[Index++];
    this->RecordSize <<= 8;
    this->RecordSize += Data[Index++];

    /* 获取名称大小 */
    int NameSize = this->RecordSize - 12;

    /* 读取linkID */
    this->Linkid = Data[Index++];
    for(int i = 0; i < 3; i++)
    {
        this->Linkid <<= 8;
        this->Linkid += Data[Index++];
    }

    /* 跳过道路名称长度 以及Resrved */
    Index += 5;

    /* 读取flag */
    this->Flag = (128 & Data[Index]) >> 7;

    /* 读取岔路数目*/
    this->Branch = (112 & Data[Index]) >> 4;

    /* 读取番号 */
    this->Number = (15 & Data[Index++]);

    /* 读取道路名称 */
    char *pN = new char[NameSize+1];
    for(int i = 0; i < NameSize; i++)
        pN[i] = Data[Index++];
    pN[NameSize] = '\0';
    pName = QString::fromLocal8Bit(pN);
    delete []pN;
}

RoadInfo::~RoadInfo(void)
{

}

void RoadInfo::RoadInfo_Disp(QString& StringShow)
{
    StringShow = "道路名称:" + pName + (Flag?" ":" 空     ")
                 +"LinkID：" + QString::number(this->Linkid )+ " "
                 +"岔路数：" + QString::number(this->Branch) + " "
                 +"Class番号：" + QString::number(this->Number) + "\n";

}

RoadInfo::RoadInfo( bool Flags, unsigned short
Branchs, unsigned short Numbers, unsigned Linkids, QString pNames)
{
    Flag = Flags;
    Branch = Branchs;
    Number = Numbers;
    Linkid = Linkids;
    pName = pNames;
    RecordSize = 12 + pName.length();
}

bool RoadInfo::operator<(const RoadInfo& Other)
{
    return this->Linkid < Other.Linkid;
}
bool RoadInfo::operator==(unsigned LinkId)
{
    return this->Linkid == LinkId;
}
bool RoadInfo::operator>(const RoadInfo &Other)
{
    return this->Linkid > Other.Linkid;
}
