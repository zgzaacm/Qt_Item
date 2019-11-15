#include "heapsort.h"
#include "HeapSort.h"

void HeapSort::HeapSort_MaxHeapFixDown(RoadStorage& p, int i, int n)
{
    int j = 2 * i + 1;
    RoadInfo temp = p[i];
    while (j < n)
    {
        if (j + 1 < n && p[j] < p[j + 1])
            ++j;
        if (!(temp < p[j]))
            break;
        else {
            p[i] = p[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    p[i] = temp;
}

void HeapSort::SortFunction_Sort(void)
{
    int n = New_Data.RoadStorage_GetSize();
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapSort_MaxHeapFixDown(New_Data, i, n);
    for (int i = n - 1; i >= 1; i--)
    {
        SortFunction_Swap(New_Data, i, 0);
        HeapSort_MaxHeapFixDown(New_Data, 0, i);
    }
}
