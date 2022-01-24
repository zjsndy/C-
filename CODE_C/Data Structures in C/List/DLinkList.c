/*双向循环链表*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct DNode
{
  ElemType data;
  struct DNode *prior,*next;
}DNode,*DoubleList;

void InitList(DoubleList *L)
{
   *L=(DoubleList)malloc(sizeof(DNode));
   if(L==NULL)
      printf("开辟内存失败!\n");
   (*L)->next=*L;
   (*L)->prior=*L;
   
}

void CreateDLinkList(DoubleList L)
{
   DNode *s,*rear,*pre;
   int a,x;
   printf("创建多少位？");
   scanf("%d",&a);
   rear=L;
   pre=L;
   for(int i=0;i<a;i++)
   {
       s=(DNode*)malloc(sizeof(DNode));
       if(s==NULL)
          printf("开辟内存失败!\n");
       scanf("%d",&x);
       s->data=x;   
       rear->next=s;
       rear=s;
       s->prior=pre;
       pre=pre->next;
       rear->next=L;
       L->prior=rear;
   }
   L=s;
}

int DlinkIns(DoubleList L,int i,ElemType e)
{
    DNode *s,*p;
    int l=0;
    p=L;
    while(p->next!=L)
    {
       p=p->next;
       l++;
    }
    if(i<=0||i>l)
    {
       printf("输入的位置不合法!\n");
       return 0;
    }

    p=L;
    int j=0;
    while(j<i)
      {
          j++;
          p=p->next;
      }
    s=(DNode*)malloc(sizeof(DNode));
    if(s)
        {
           s->data=e;
           s->prior=p->prior;
           p->prior->next=s;
           s->next=p;
           p->prior=s;
           return 1;
        }
    else
       return 0;
}

int DlinkDel(DoubleList L,int i)
{
   DNode *s,*p;
    int l=0;
    p=L;
    while(p->next!=L)
    {
       p=p->next;
       l++;
    }
    if(i<=0||i>l)
    {
       printf("输入的位置不合法!\n");
       return 0;
    }

    p=L;
    int j=0;
    while(j<i)
      {
          j++;
          p=p->next;
      }
      p->prior->next=p->next;
      p->next->prior=p->prior;
      free(p);
      return 0;
}

void PrintList(DoubleList L)
{
    DoubleList p=L->next;
    while(p!=L)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}

int main()
{
    DoubleList L;
    InitList(&L);
    CreateDLinkList(L);
   // DlinkIns(L,2,7);
     DlinkDel(L,2);
    PrintList(L);
}