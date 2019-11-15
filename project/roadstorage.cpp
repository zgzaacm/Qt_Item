#include "roadstorage.h"
#include <fstream>
#include <QDebug>
#include <QTextCodec>
RoadStorage::RoadStorage(void)
{
    Size = 0;
    DataMemory.clear();
}

void RoadStorage::RoadStorage_Set(QString Path)
{
    this->DataMemory.clear();
    this->Size = 0;
    /* 读取文件 并把所有数据存入DataStream中 */


    vector<unsigned char> DataStream;
    ifstream FileIn(Path.toStdString(),std::ifstream::in|std::ifstream::binary);
    unsigned char Now;
    while(!FileIn.eof())
    {
        /* 每读一个字节 就存入DataStream中 */
        FileIn.read((char *)(&Now), sizeof(Now));
        DataStream.push_back(Now);
    }
    FileIn.close();

    /* 将数据一块一块传入roadinfo的构造函数进行初始化 */
    unsigned long long Num = DataStream.size()-1, Index=0;
    /* 当前读取数据的下标小于总长度时
     * 继续构造roadinfo类
     * 并加入DataMemory中
     */
    while(Index < Num)
    {
        /* 传入文件数据以及当前数据读取的指针来初始化 */
        RoadInfo RoadNow;
        RoadNow.RoadInfo_Set(DataStream,Index);
        DataMemory.push_back(RoadNow);
    }

    this->Size = DataMemory.size();
}

void RoadStorage::RoadStorage_GetRoadInfo(QString& S,int Index)
{
    this->DataMemory[Index].RoadInfo_Disp(S);
}

int RoadStorage::RoadStorage_GetSize(void)
{
    return DataMemory.size();
}

RoadInfo& RoadStorage::operator[](int Index)
{
    return this->DataMemory[Index];
}

vector<RoadInfo>::iterator RoadStorage::RoadStorage_GetBegin()
{
    return this->DataMemory.begin();
}
void RoadStorage::RoadStorage_PushBack(RoadInfo Now)
{
    this->Size++;
    this->DataMemory.push_back(Now);
}

RoadStorage& RoadStorage::operator=(const RoadStorage& Other)
{
    this->DataMemory = Other.DataMemory;
    this->Size = Other.Size;
}

RoadStorage::~RoadStorage(void)
{
    DataMemory.clear();
}
