#include "statement.h"

//一趟快速排序算法
int QKPass(RecordType r[],int low,int high)
{
    RecordType x;
    x = r[low];

    while(low<high)
    {
        while(low<high&&r[high].key>=x.key)
            high--;
        
        if(low<high)
        {
            r[low] = r[high];
            low++;
        }

        while (low<high&&r[low].key<x.key)
        {
            low++;
        }

        if(low<high)
        {
            r[high] = r[low];
            high--;
        }
    }

    r[low] = x;
    return low;
}

//完整的快速排序
void QKSort(RecordType r[],int low,int high)
{
    int pos;
    if(low<high)
    {
        pos = QKPass(r, low, high);
        QKSort(r, low, pos - 1);
        QKSort(r, pos + 1, high);
    }
}