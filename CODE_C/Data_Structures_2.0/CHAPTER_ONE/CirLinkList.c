/*************************************************************
*  FileName:   CirLinkList.c
*  Date:       2022-02-28 20:46:05
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_ONE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
} Node, *LinkList;


void InitCLinkList(LinkList *CL)
{
    *CL = (LinkList)malloc(sizeof(Node));
    (*CL)->next = *CL;
}

void CreateCLinkList(LinkList CL)
{
    Node *rear, *s;
    rear = CL;
    int x;
    int Num;
    printf("你要创建多少位:");
    scanf("%d", &x);
    for (int i = 0; i < x;i++)
    {
        scanf("%d", &Num);
        s = (Node *)malloc(sizeof(Node));
        s->data = Num;
        rear->next = s;
        rear = s;
    }
    rear->next = CL;

    //return rear;
}

void Destroy(LinkList *CL)
{
    //将循环链表变为单链表
    Node *p;
    p = (*CL)->next;
    (*CL)->next = NULL;
    *CL = p;
    while((*CL)!=NULL)
    {
        p = p->next;
        free(*CL);
        *CL = p;
    }
}

LinkList merge_1(LinkList LA,LinkList LB)
{
    Node *p, *q;
    p = LA;
    q = LB;

    while(p->next!=LA)
    {
        p = p->next;
    }
    while(q->next!=LB)
    {
        q = q->next;
    }

    p->next = LB->next;
    q->next = LA;

    Destroy(&LB);
    return LA;
}

LinkList merge_2(LinkList RA,LinkList RB)
{
    //用尾指针的循环链表
    Node *p;
    p = RA->next;
    RA->next = RB->next->next;
    free(RB->next);
    RB->next = p;
    return RB;
}

    int main()
    {
        LinkList L;
        InitCLinkList(&L);
        CreateCLinkList(L);
      

        //merge_2(L, M);
        //merge_1(L, M);
         Destroy(&L);
        system("pause");
        return 0;
}