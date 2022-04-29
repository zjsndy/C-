/*************************************************************
*  FileName:   Radix.c
*  Date:       2022-04-29 10:00:24
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_EIGHT
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 

#define RADIX 10
#define KEY_SIZE 6
#define LIST_SIZE 20
typedef int KeyType;

typedef struct{
    KeyType key;         //子关键字数组
    int next;              //静态链域
} RecordType;

typedef struct{
    RecordType r[LIST_SIZE + 1];          //r[0]为头节点
    int length;
    int keynum;
} SLinkList;

typedef int PVector[RADIX];

//取整数第i位数
int Order(int num,int i)
{
    while(i>0)
    {
        num /= 10;
        i--;
    }
    return num % 10;
}

//链式基数排序算法
void Distribute(RecordType r[],int i,PVector head,PVector tail)
{
    //记录数组r中记录已按低位关键字key[i+1],...,key[d]进行过"低位排序”
    //按第i位关键字key[i]建立RADIX个队列,同一个队列中记录的key[i]相同
    //head[j]和tail[j]分别指向各队列中第一个和最后一个记录(j=0,1,2,...,RADIX-1)head[j]=0表示相应队列位空队列
    int j;
    for (j = 0; j < RADIX;j++)
        head[j] = 0;                //将RADIX个队列初始化为空队列
    int p = r[0].next;               //p指向链表中第一个记录
    while(p!=0)
    {
        j = Order(r[p].key,i);
        if(head[j]==0)              //将p所指向的结点加入第j个队列中
            head[j] = p;
        else
            r[tail[j]].next = p;
        tail[j] = p;
        p = r[p].next;
    }
}

void Collect(RecordType r[],PVector head,PVector tail)
{
    int j = 0;
    while(head[j]==0)
        j++;

    r[0].next = head[j];
    int t = tail[j];
    while(j<RADIX-1)
    {
        j++;
        while((j<RADIX-1)&&(head[j]==0))
            j++;           //找下一个非空队列
        if(head[j]!=0)      //链接非空队列
        {
            r[t].next = head[j];
            t = tail[j];
        }
    }
    r[t].next = 0;           //t指向最后一个非空队列的最后一个结点
}

void RadixSort(RecordType r[],int n,int d)
{
    //n个记录存放在数组r中,d为关键字位数,执行本算法进行基数排序,链表中的记录将
    //按关键字从小到大的顺序相链接

    PVector head, tail;

    //构造静态链表
    for (int i = 0; i < n;i++)       
        r[i].next = i + 1;

    r[n].next = 0;

    for (int i = 0 ; i <d;i++)     //从最低位子关键字开始,进行d趟分配和收集
    {
        Distribute(r, i, head, tail);         //第i趟分配
        Collect(r, head, tail);          //第i趟收集
    }
}

int main ()
{
    int d[11] = {0, 278, 109, 63, 930, 589, 184, 505, 269, 8, 83};

    RecordType r[11];
    for (int i = 1; i <= 10;i++)
        r[i].key=d[i];

    RadixSort(r, 10, 3);
    int p = r[0].next;
    while(p!=0)
    {
        printf("%d  ", r[p].key);
        p = r[p].next;
    }

    system("pause");
    return 0;
}