/*************************************************************
*  FileName:   DoubleList.c
*  Date:       2022-03-08 15:29:13
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_ONE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DoubleList;

void InitDList(DoubleList *DL)
{
    *DL = (DoubleList)malloc(sizeof(DNode));
    (*DL)->next = *DL;
    (*DL)->prior = *DL;
}

void CreateDList(DoubleList DL)
{
    DNode *rear, *s;
    rear = DL;
    int x;
    int Num;
    printf("你要创建多少位:");
    scanf("%d", &x);
    for (int i = 0; i < x;i++)
    {
        scanf("%d", &Num);
        s = (DNode *)malloc(sizeof(DNode));
        s->data = Num;
        s->prior = rear;
        s->next = DL;
        rear->next = s;
        DL->prior = s;
        rear = s;
    }
} 

int GetLen(DoubleList DL)
{
    DNode *p;
    p = DL->next;
    int len = 0;
    while(p!=DL)
    {
        len++;
        p = p->next;
    }
    return len;
}


int DlinkIns(DoubleList DL,int i,ElemType e)
{
    DNode *s, *p;
    int len = GetLen(DL);
    if(i<0||i>len)
    {
        printf("插入位置不合法\n");
        return 0;
    }

    p = DL;
    for(int j = 0; j < i;j++)
    {
        p = p->next;
    }

    s = (DNode *)malloc(sizeof(DNode));
    if(s)
    {
        s->data = e;
        s->prior = p->prior;
        p->prior ->next=s;
        s->next = p;
        p->prior = s;
    }
    return 1;
}

int DlinkDel(DoubleList L,int i,ElemType *e)
{
    DNode  *p;
    int len = GetLen(L);
    if(i<0||i>len)
    {
        printf("插入位置不合法\n");
        return 0;
    }

    p = L;
    for(int j = 0; j < i;j++)
    {
        p = p->next;
    }

    p->prior->next = p->next;
    p->next->prior = p->prior;
    *e = p->data;
    free(p);
    return 1;
}

int main ()
{
    DoubleList L;
    InitDList(&L);
    CreateDList(L);
    int e;
    DlinkDel(L, 2, &e);
    system("pause");
    return 0;
}