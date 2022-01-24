/*单向循环链表*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;

void InitCLinkList(LinkList *CL)
{
   (*CL)=(LinkList)malloc(sizeof(Node));
   if(CL==NULL)
      printf("开辟内存失败!\n");
   (*CL)->next=(*CL);
}

//采用头指针
void  CreateCHLinkList(LinkList CL)
{
   Node *rear,*s;
   int a,x;
   rear=CL;
   printf("你想输入几位?");
   scanf("%d",&a);
   for(int i=0;i<a;i++)
   {
      scanf("%d",&x);
      s=(Node*)malloc(sizeof(Node));
      if(s==NULL)
         printf("开辟内存失败！\n");
      s->data=x;
      rear->next=s;
      rear=s;
   }
   rear->next=CL;
}

//有尾指针
LinkList CreateCRLinkList(LinkList CL)
{
   Node *s,*rear;
   int a,x;
   printf("你想输入几位?");
   scanf("%d",&a);
   rear=CL;
   for(int i=1;i<=a;i++)
   {
      scanf("%d",&x);
      s=(Node*)malloc(sizeof(Node));
      if(s==NULL)
         printf("开辟内存失败！\n");
      s->data=x;
      rear->next=s;
      s->next=CL;
      rear=s;
   }
   CL=s;
   return CL;
}
void PrintCLinkList(LinkList CL)
{
   Node *p;
   p=CL->next;
   while (p!=CL)
   {
      printf("%d ",p->data);
      p=p->next;
   }
}

//将采用头指针的循环单链表的首尾连接起来
LinkList merge_1(LinkList LA,LinkList LB)
{
   Node *p,*q;
   p=LA;q=LB;
   while(p->next!=LA)
     p=p->next;
   while(q->next!=LB)
     q=q->next;
   q->next=LA;
   p->next=LB->next; 
   free(LB);
   return LA;
}

//将采用尾指针的循环单链表的首位连接起来
LinkList merge_2(LinkList LA,LinkList LB)
{
    Node  *p;
    p=LA->next;
    LA->next=LB->next->next;
    free(LB->next);
    LB->next=p;
    return LB;
}

void PrintCRLinkList(LinkList LC)
{
   Node *p;
   p=LC->next->next;
   while (p!=LC->next)
   {
      printf("%d  ",p->data);
      p=p->next;
   }
}

int main()
{
    /*LinkList CL;
   LinkList M;
   InitCLinkList(&CL);
   CL=CreateCRLinkList(CL);
   PrintCLinkList(CL);

   InitCLinkList(&M);
   M=CreateCRLinkList(M);
   merge_1(CL,M);
   merge_2(CL,M);
   PrintCRLinkList(M);*/
}
