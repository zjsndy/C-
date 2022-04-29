/*************************************************************
*  FileName:   LinkList.c
*  Date:       2022-02-27 09:56:42
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_ONE
*  Description:单链表的操作
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateFromHead(LinkList L)
{
    Node* s;
    int total;
    int x;
    printf("你想创建几位\n");
    scanf("%d", &total);
    for (int i = 0; i < total;i++)
    {
        scanf("%d", &x);
        s = ( Node *)malloc(sizeof(Node));
        s->data =x;
        s->next = L->next;
        L->next = s;
    }
}

void CreateFromTail(LinkList L)
{
    Node *r, *s;
    r = L;
    int total;
    int x;
    printf("你想创建几位\n");
    scanf("%d", &total);
    for (int i = 0; i < total;i++)
    {
        scanf("%d", &x);
        s = ( Node *)malloc(sizeof(Node));
        s->data =x;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

Node *Get(LinkList L,int i)
{
    int j;
    Node *p;

    if(i<=0)
    {
        return NULL;
    }

    p = L;
    j = 0;

    while((p->next!=NULL)&&(j<i))
    {
        p = p->next;
        j++;
    }

    if(j==i)
    {
        return p;
    }
    else
    {
        return NULL;
    }

}

Node *Locate(LinkList L,ElemType key)
{
    Node *p;
    p = L->next;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

int ListLength(LinkList L)
{
    Node *p;
    p = L->next;
    int j = 0;

    while(p!=NULL)
    {
        p = p->next;
        j++;
    }

    return j;
}

void InsList(LinkList L,int i,ElemType e)
{
    Node *pre,*s;
    pre = L;
    int j = 0;

    while(pre!=NULL&&j<i-1)
    {
        pre = pre->next;
        j++;
    }

    if(j==i-1)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = e;
        s->next = pre->next;
        pre->next = s;
    }
    else
    {
        printf("插入位置不合理\n");
    }
}

void DelList(LinkList L,int i,ElemType *e)
{
    Node *pre, *r;
    int k=0;
    pre = L;

    while(pre->next!=NULL&&k<i-1)
    {
        pre = pre->next;
        k++;
    }

    if(k==i-1)
    {
        r = pre->next;
        pre->next = r->next;
        *e = r->data;
        free(r);
    }
    else
    {
        printf("删除位置不合理\n");
    }
}

void Destroy(LinkList *L)
{
    LinkList q, p = *L;
    while(p!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
}

LinkList MergeLinkList(LinkList LA,LinkList LB)
{
    Node *pa, *pb,*r;
    LinkList LC;

    pa = LA->next;
    pb = LB->next;
    LC = LA;
    r = LC;

    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data>pb->data)
        {
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
        else
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
    }

    if(pa)
    {
        r->next = pa;
    }
    else
    {
        r->next = pb;
    }

    Destroy(&LB);
    return LC;
}

void ReverseList(LinkList L)
{
    Node *p, *q;
    p = L->next;
    
    L->next = NULL;
    while(p!=NULL)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

//将值小于第一个元素的结点放在第一个结点之前
void changelist(LinkList L)
{
    Node *p, *pre,*p1,*q;//p:遍历所有结点  pre:新链表最后一个结点   p1:第一个结点     q:让p前移
    p1 = L->next;
    pre = p1;
    p = p1->next;

    while(p)
    {
        q = p->next;
        if(p->data>=p1->data)
        {
            pre = p;
            p = q;
        }
        else
        {
            pre->next = p->next;
            p->next = L->next;
            L->next = p;
            p = q;
        }
    }
}

void BinAdd(LinkList L)
{
    Node *p,*q,*r;
    p = L->next;
    q = NULL;
    while(p)
    {
        if(p->data==0)
       {
           q = p;
       }
       p = p->next;
    }
    
    if(q)
    {
      q->data = 1;
      p = q->next;
      while(p)
      {
        p->data = 0;
        p = p->next;
      }
    }
    else
    {
        q = (Node *)malloc(sizeof(Node));
        q->data = 1;
        q->next = L->next;
        L->next = q;
        r = q->next;
        while(r)
        {
            r->data = 0;
            r = r->next;
        }
    }
}

//假定L元素值递增有序，删除值重复地结点
void del_repetition(LinkList L)
{
    Node *p, *q;
    p = L->next;
    q = p->next;
    while(q)
    {
        if(p->data==q->data)
        {
            p->next = q->next;
             q = p->next;
        }
        else
        {
            p = p->next;
        }  
    }
}

void del_x_y(LinkList L,int x,int y)
{
    Node *cur, *pass, *final;
    pass = L->next;
    while(pass->data<x)
    {
        cur = pass;
        pass = pass->next;
    }
   

    while(pass->data<y)
    {
        pass = pass->next;
        final = pass;
    }

    cur->next = final;
}

//得到倒数第k个元素
int get_k(LinkList L,int k)
{
    Node *p;
    p = L->next;
    int len = ListLength(L);
    int count = 0;
    if(len-k<0)
    {
        printf("不合法\n");
    }

    while(count<len-k)
    {
        count++;
        p = p->next;
    }

    printf("%d  ", p->data);
    return 1;
}

int IshAScircle(LinkList L)
{
    Node *p, *q;
    p = L->next;
    q = L->next->next;

    while(p!=q)
    {
        p = p->next;
        q = q->next->next;
    }

    printf("有环");
    return 1;
}

int main ()
{
    LinkList L;
    InitList(&L);
    CreateFromTail(L);

    Node *cur, *rear;
    rear = L->next;
    int k=0;
    while(rear->next)
    {
        k++;
        if(k==3)
        {
            cur = rear;
        }
        rear = rear->next;
    }

    rear->next = cur;

    IshAScircle(L);

    system("pause");
    return 0;
}