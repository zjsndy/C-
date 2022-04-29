#include "statement.h"

void Insert(RecordType a[])
{
    for (int i = 2; i <= N;i++)
    {
        a[0] = a[i];          //将待插入记录存放到监察哨a[0]
        int j = i - 1;
        while(a[0].key<a[j].key)    //寻找插入位置,从后往前
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = a[0];
    }
}