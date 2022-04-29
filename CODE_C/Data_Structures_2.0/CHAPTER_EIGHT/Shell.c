#include "statement.h"
int dlta[] = {5, 3, 1};

void ShellInsert(RecordType r[],int delta)
{
    int i, j;
    for ( i = 1 + delta; i <= N;i++)        //1+delta为第一个子序列的第二个元素的下标
        if(r[i].key<r[i-delta].key)
        {
            r[0] = r[i];         //备份r[i],不做监视哨
            //直接插入排序,寻找插入位置
            for ( j = i - delta; j > 0 && r[0].key < r[j].key;j-=delta)
                r[j + delta] = r[j];
            r[j + delta] = r[0];         //将待插入记录插入到已排序的序列中
        }
}

//delta为增量数组,n为delta[]的长度
void ShellSort(RecordType r[],int delta[],int n)
{
    for (int i = 0; i < n;i++)
        ShellInsert(r, delta[i]);
}

