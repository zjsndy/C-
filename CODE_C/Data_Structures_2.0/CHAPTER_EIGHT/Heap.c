#include "statement.h"

//重建堆
void sift(RecordType r[],int k,int m)
{
    int i, j;
    KeyType x;
    RecordType t;
    t = r[k];         //假设r[k...m]是以r[k]为根的完全二叉树,且分别以r[2k]和r[2k+1]为根的左、右子树为大根堆
    x = r[k].key;     //调整r[k],使整个序列r[k...m]满足堆的性质
    i = k;
    j = 2 * i;
    int finished = FALSE;
    while(j<=m&&!finished)
    {
        if(j+1<=m&&r[j].key<r[j+1].key)    //若存在右子树,且右子树根的关键字大,则沿右分支"筛选"
            j = j + 1;

        if(x>=r[j].key)           //筛选完毕
            finished = TRUE;
        else
        {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
    }
    r[i] = t;          //将r[k]填入到恰当的位置
}

//建初堆,n为数组的长度
void crt_heap(RecordType r[],int n)
{
    for (int i = n / 2; i >= 1;i--)
        sift(r, i, n);
}

//堆排序算法
void HeapSort(RecordType r[],int n)
{
    crt_heap(r, n);
    RecordType b;
    for (int i = n; i >= 2;i--)
    {
        b = r[1];
        r[1] = r[i];
        r[i] = b;
        sift(r, 1, i - 1);           //进行调整,使r[1...i-1]成堆
    }
}

