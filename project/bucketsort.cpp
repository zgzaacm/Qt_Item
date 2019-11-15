#include "bucketsort.h"


void BucketSort::SortFunction_Sort(void)
{
    int length = New_Data.RoadStorage_GetSize();
    int index = 0;
    const int bucket_num = 600;
    RoadStorage buckets[bucket_num];
    RoadInfo max = New_Data[0];
    for (int i = 1; i < length; i++)
        if (max < New_Data[i])
            max = New_Data[i];


    max.Linkid = max.Linkid + 1;
    float domain = (float)max.Linkid / bucket_num;

    for (int i = 0; i < length; ++i)
        buckets[int(floor((float)New_Data[i].Linkid / domain))].RoadStorage_PushBack(New_Data[i]);

    for (int i = 0; i < bucket_num; i++)
    {
        /* 设置增量 */
        int Gap = 0;
        /* 数据的长度 */
        int DataLength = buckets[i].RoadStorage_GetSize();
        int k = 0;
        int j = 0;
        RoadInfo temp;
        /* 设置增量每次都是Gap/2 */
        for(Gap = DataLength/2 ; Gap > 0 ; Gap /= 2)
        {
            /* 将要插入的数据放入temp中 */
            for(k = Gap ; k < DataLength ; k++)
            {
                /* 需要插入的数据 */
                temp = buckets[i][k];
                j = k - Gap;
                /* temp若比前面位置上的数字小，前面数就要后移 */
                while(j >= 0 && (Reverse?(temp < buckets[i][j]):!(temp < buckets[i][j])))
                {
                    /* 后移 */
                    buckets[i][j + Gap] = buckets[i][j];
                    /* 找到前面一个位置上的数 */
                    j = j - Gap;
                }
                /* temp插入这个位置 */
                buckets[i][j + Gap] = temp;
            }
        }
    }

    for (int i = 0; i < bucket_num; ++i)
        for (int j = 0; j < buckets[i].RoadStorage_GetSize(); j++)
            New_Data[index++] = buckets[i][j];


}
