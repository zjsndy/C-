/*************************************************************
*  FileName:   StaticList.c
*  Date:       2022-03-08 22:32:21
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_ONE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 

#define Maxsize 10
typedef int ElemType;

typedef struct{
    ElemType data;
    int cursor;
} Component, StaticList[Maxsize];

void Initalspace(StaticList space)
{
    for (int i = 0; i < Maxsize-1;i++)
    {
        space[i].cursor = i+1;
    }

    space[Maxsize - 1].cursor =0;
}

//为插入的数据申请空间
int Malloc(StaticList space)
{
    int i;
    i = space[0].cursor;

    if(space[0].cursor)
    {
        space[0].cursor = space[i].cursor;
        return i;
    }
    else
    {
        return 0;
    }
}

void Free(StaticList space,int k)
{
    space[k].cursor = space[0].cursor;
    space[0].cursor = k;
}

int InitList(StaticList space,int *Head)
{
    *Head = Malloc(space);
    if(!(*Head))
    {
        printf("内存满了\n");
        return -1;
    }

    space[*Head].cursor = 0;//头节点游标设为0
    return 0;
}

//置空
int ClearList(StaticList space,int Head)
{
    int p;
    if(!Head)
        return -1;
    p = space[Head].cursor;//p指向第一个结点

    while(p)
    {
        space[Head].cursor = space[p].cursor;
        Free(space, p);
        p = space[Head].cursor;
    }

    return 1;
}

void DestroyList(StaticList space,int *Head)
{
    ClearList(space,*Head);
    Free(space,*Head);
    *Head= 0;
}

int IsEmpty(StaticList space,int Head)
{
    if(Head&&!space[Head].cursor)
        return 1;
    else
        return 0;
}

int Getlen(StaticList space,int Head)
{
    int count;//计数器
    int p;
    if(!Head)
    {
        printf("不存在头节点\n");
        return 0;
    }

    count = 0;
    p = space[Head].cursor;
    while(p)
    {
        count++;
        p = space[p].cursor;
    }
    return count;
}

void GetElem(StaticList space,int Head,int i,ElemType *e)
{
    int count, p;
    if(!Head||i>Maxsize-2)
    {
        printf("位置不合法\n");
    }

    count = 0;
    p = space[Head].cursor;

    while(p)
    {
        count++;
        if(count==i)
        {
            *e = space[p].data;
            break;
        }
        p = space[p].cursor;
    }
}

int Locate(StaticList space,int Head,ElemType e)
{
    int k,count;

    count = 1;
    if(Head&&space[Head].cursor)
    {
        k = space[Head].cursor;

        while(k&&space[k].data!=e)
        {
            count++;
            k = space[k].cursor;
        }

        if(k)
            return count;
    }
    return 0;
}

//求前面的值
int Prior(StaticList space,int Head,ElemType cur,ElemType *pre)
{
    int p, q;

    if(Head)
    {
        p = space[Head].cursor;

        if(p&&space[p].data!=cur)
        {
            q = space[p].cursor;

            while(q&&space[q].data!=cur)
            {
                p = q;
                q = space[q].cursor;
            }

            if(q)
            {
                *pre = space[p].data;
                return 1;
            }
        }
    }
    return 0;
}

int NextElem(StaticList space,int Head,ElemType cur,ElemType *next)
{
    int p;

    if(Head)
    {
        p = space[Head].cursor;

        while(p&&space[p].data!=cur)
            p = space[p].cursor;
        if(p&&space[p].cursor)  
        {
            p = space[p].cursor;
            *next = space[p].data;
            return 1;
        }  
    }

    return 0;
}

int Insert(StaticList space,int Head,int i,ElemType e)
{
    int count, k, p;

    if(!Head)             //链表不存在
        return -1;
    if (i > 0 )
    {
            count = 0;
            k = Head;

            while(k&&count<i-1)
            {
                count++;
                k = space[k].cursor;
            }

            if(k)
            {
                p = Malloc(space);
                if(!p)
                    return -1;

                space[p].data = e;
                space[p].cursor = space[k].cursor;
                space[k].cursor = p;

                return 1;
            }
    }
    return 0;
}

int ListDelete(StaticList space,int Head,int i)
{
    int count, k, p;

    if(!Head)
        return 0;

    if(i>0)
    {
        count = 0;
        k = Head;

        while(k&&count<i-2)
        {
            count++;
            k = space[k].cursor;
        }

        if(k&&space[k].cursor)
        {
            p = space[k].cursor;
            space[k].cursor = space[p].cursor;
            Free(space, p);

            return 1;
        }
    }
    return -1;
}

int main()
{
    StaticList L;
    int H;
    Initalspace(L);
    InitList(L, &H);

    for (int i = 1; i <= 6;i++)
    {
        Insert(L,H,i,2*i);
    }

    int len = Getlen(L, H);

    //ClearList(L, H);
    //DestroyList(L, &H);
    ElemType e;
    GetElem(L, H, 2, &e);
    Prior(L, H, 6, &e);
    system("pause");
    return 0;
}