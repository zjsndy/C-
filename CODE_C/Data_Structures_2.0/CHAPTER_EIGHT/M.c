#include "statement.h"

//相邻两个有序子序列的合并成算法
void Merge(RecordType r1[],int low,int mid,int high,RecordType r2[])
{
    //已知r1[low...mid]和r1[mid+1...high]分别按关键字有序排列,将它们合并成一个有序序列，存放在r[low...high]
    int i = low;
    int j = mid + 1;
    int k = low;
    while((i<=mid)&&(j<=high))
    {
        if(r1[i].key<=r1[j].key)
        {
            r2[k] = r1[i];
            i++;
        }
        else
        {
            r2[k] = r1[j];
            j++;
        }
        k++;
    }

    while (i<=mid)
    {
        r2[k] = r1[i];
        k++;
        i++;
    }

    while(j<=high)
    {
        r2[k] = r1[j];
        j++;
        k++;
    }
}

//2-路归并排序的递归算法
void MSort(RecordType r1[],int low,int high,RecordType r3[])
{
    //r1[low...high]排序后放在r3[low...high]中,r2[low...high]为辅助空间
    RecordType *r2;
    int mid;
    r2 = (RecordType *)malloc(sizeof(RecordType) * (high - low + 1));
    if(low==high)
        r3[low] = r1[low];
    else
    {
        mid = (low + high) / 2;
        MSort(r1, low, mid, r2);
        MSort(r1, mid + 1, high, r2);
        Merge(r2, low, mid, high, r3);
    }
    //free(r2);
}

//2-路归并排序的初始调用过程
void MergeSort(RecordType r[],int n)
{
    MSort(r, 1, n, r);
}