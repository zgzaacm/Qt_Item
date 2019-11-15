#include "Update.h"
#include "BinarySearch.h"
#include <vector>
#include <fstream>
#include <QDebug>
using namespace std;
void Update::Update_Replace()
{
    vector<unsigned char> Res;
    int i = 0;
    int j = 0;
    /* 先打开需要写进去的文件 */
    ofstream FileOut(S.toStdString(), std::ios::out | std::ios::binary);
    /* 获取排序后的每一个数据并将其进行转换后写入文件 */
    for (i = 0; i < New_Data.RoadStorage_GetSize(); i++)
    {
        Res.clear();
        /* 参数传回了转换后的二进制流 */
        New_Data[i].RoadInfo_Convert(Res);
        for (j = 0; j < Res.size(); j++)
        {
            /* 将二进制数据按顺序写入文件 */
            FileOut.write((char *)(&Res[j]), sizeof(Res[j]));
//            qDebug() << Res[j];
        }
    }
    /* 关闭文件 */
    FileOut.close();

}
void Update::Update_Append(RoadInfo& RoadAdd)
{
    New_Data.RoadStorage_PushBack(RoadAdd);
}

bool Update::Update_Delete(unsigned int LinkId)
{
    int Position = 0;
    SearchFunction* p;
    p = new BinarySearch(1);
    Position = p->SearchFunction_Search(LinkId);
    if (Position == -1)return false;
    New_Data.DataMemory.erase(New_Data.DataMemory.begin()+Position);
    return true;
}
bool Update::Update_Modify(const RoadInfo& RoadModify, unsigned int LinkId)
{
    int Position = 0;
    SearchFunction* p;
    p = new BinarySearch(1);
    Position = p->SearchFunction_Search(LinkId);
    if (Position == -1)return false;
    New_Data[Position] = RoadModify;
    return true;
}
