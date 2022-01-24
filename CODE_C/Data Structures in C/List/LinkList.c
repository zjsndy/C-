/*带头结点单链表*/

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;

//初始化
void InitList(LinkList *L)
{
   (*L)=(LinkList)malloc(sizeof(Node));
   if(L==NULL)
      printf("开辟内存失败!\n");  
   (*L)->next=NULL;
}

//头插法建表
void CreateFromHead(LinkList L)
{
    Node *s ;int x;int a;
    printf("你想创建多少位?");
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        s=(Node *)malloc(sizeof(Node)); 
        if(s==NULL)
           printf("开辟内存失败！\n");
        scanf("%d",&x);
        s->data=x;
        s->next=L->next;
        L->next=s;
    }
}

//尾插法
void CreateFromTail(LinkList L)
{
    Node *r,*s;int x;int a;
      printf("你想创建多少位?");
    scanf("%d",&a);
    r=L;
    for(int i=0;i<a;i++)
    {
        s=(Node *)malloc(sizeof(Node)); 
        if(s==NULL)
           printf("开辟内存失败！\n");
        scanf("%d",&x);
        s->data=x;
        r->next=s;
        r=s;
    }
    r->next=NULL;
    
}

//按序号查找
Node * Get(LinkList L,int i)
{
   Node *p;int j=0;
   p=L;
   while(p->next!=NULL&&j<i)
   {
      p=p->next;
      j++;
   }   
   if(i==j)
     return p;
   else
     return NULL;  
}

//按值查找
Node * Locate(LinkList L,ElemType key)
{
  Node *p;int j;
  p=L->next;
  while(p!=NULL&&p->data!=key)
      p=p->next;
  if(p==NULL)    
     return NULL;
  else
     return p;   
} 

//求链表的长度
int ListLength(LinkList L)
{
    Node *p;int j=0;
    p=L->next;
    while(p!=NULL)
    {
      j++;
      p=p->next;
    }
    return j;
}

//单链表插入
int InsList(LinkList L,int i,ElemType e)
/*插入到第个位置*/
{
  Node *pre,*s;
  int k=0;
  pre=L;
  while(pre!=NULL&&k<i-1)
  {
     pre=pre->next;
     k++;
  }
  if(pre==NULL)
  {
    printf("插入的位置的不合法!\n");
    return 0;
  }
  else
  {
     s=(Node*)malloc(sizeof(Node));
     s->data=e;
     s->next=pre->next;
     pre->next=s;
     return 0;
  }
}

//单链表删除运算
int DelList(LinkList L,int i)
{
  Node *pre,*r;
  int k=0;
  pre=L;
  while(pre!=NULL&&k<i-1)
  {
     pre=pre->next;
     k++;
  }
  if(pre==NULL)
    {
       printf("删除的位置不合理!\n");
       return 0;
    }
   else
    {
       r=pre->next;
       pre->next=r->next;
       free(r);
       return 0;
    }
}

//排序
void Sort(LinkList L)
{
   Node *pre,*p,*r;
   int j;
   j=ListLength(L);
   pre=L;
   p=L->next;
   for(int i=0;i<j;i++)
   {
     while(p->next!=NULL)
     {
        if(p->data>p->next->data)
        {
           r=p->next->next;
           pre->next=p->next;
           p->next->next=p;
           pre=p->next;
           p->next=r;
        }
        else
        {
           pre=p;
           p=p->next;
        }
     }
     pre=L;
     p=L->next;
   } 
}

//合并两个有序的单链表
LinkList MergeLinkList(LinkList LA,LinkList LB)
{
   Node *pa,*pb,*r;
   LinkList LC;
   InitList(&LC);
   r=LC;
   Sort(LA);Sort(LB);
   pa=LA->next;
   pb=LB->next;
   while(pa!=NULL&&pb!=NULL)
     {
        if(pa->data<=pb->data)
        {
           r->next=pa;
           r=pa;
           pa=pa->next;
        }
        else
        {
             r->next=pb;
             r=pb;
             pb=pb->next;
        }
     }
   if(pa)  
     r->next=pa;
   else
     r->next=pb;
   free(LB);free(LA) ;
   return LC;   
}

//逆置单链表
void ReverseList(LinkList L)
{
   Node *p,*q;
   p=L->next;
   L->next=NULL;
   while(p!=NULL)
   {
          q=p->next;
          p->next=L->next;
          L->next=p;
          p=q;
   }
}

//以第一个元素为标准，进行单链表划分
void changelist(LinkList L)
{
   Node *pl,*pre,*p,*q;
   pl=L->next;
   pre=L;
   p=pre->next;
   while(p!=NULL)
   {
      q=p->next;
      if(p->data<pl->data)
      {
         pre->next=p->next;
         p->next=L->next;
         L->next=p;
         p=q;
      }
      else
      {
         pre=p;
         p=q;

      }

   }
}

//二进制加1
void BinAdd(LinkList L)
{
   Node *p,*r,*s;
   p=L->next;
   r=L;
   while(p!=NULL)
   {
       if(p->data==0)
         r=p;
       p=p->next;
   }
   if(r!=L)
      r->data=1;
   else
        {
           s=(Node *)malloc(sizeof(Node)) ;
           if(s==NULL) 
              printf("开辟内存失败!\n");
            s->data=1;
            s->next=L->next;
            L->next=s;
            r=s;
        }
    r=r->next;
    while(r!=NULL)
   {
           r->data=0;
           r=r->next;
   }
}

//删除值重复的结点
void delrepeat(LinkList L)
{
   Sort(L);
   Node *pre,*r;
   pre=L->next;r=pre->next;
   while(r!=NULL)
   {
      if(pre->data==r->data)
         {
            pre->next=r->next;
         }
      else
         pre=pre->next ;r=r->next;  
   }
}


//打印
void Print(LinkList L)
{
    Node *p;
    p=L->next;
    while(p!=NULL)
    {
       printf("%d ",p->data);
       p=p->next;
    }   
}

//删除表中小于mink且大于maxk的元素
void del(LinkList L,int mink,int maxk)
{
      Node *pre,*r,*s;
      pre=L->next;
      while(pre->data<mink&&pre->next->data<mink)
          pre=pre->next;
      pre=pre->next;    
      s=L->next;
      s=pre; 
      L->next=s; 
      while(s->data<maxk&&s->next->data<maxk) 
           s=s->next;
       r=s;
       r->next=NULL;
} 

//删除表中大于mink且小于maxk的元素
void delcenter(LinkList L,int mink,int maxk)
{
   Node *pre,*p,*r;
   pre=L;
   p=L->next;
   while(p&&p->data<=mink)
   {
       pre=p;
       p=p->next;
   }    
   while(p&&p->data<maxk)
   {
       r=p;
       p=p->next;
       free(r);
   }   
   pre->next=p;
}

//改变单链表存储结构，n为偶数
void Translate(LinkList L)
{
  Node *s,*r;
  s=L->next;
  while(s->next!=NULL)
  {
     r=s->next;
     s->next=r->next;
     r->next=L->next;
     L->next=r;
     s=s->next;
     if(s==NULL)
        break;
  }

}

//查找链表中倒数第k个位置上的结点
int check(LinkList L,int k)
{
   Node *p,*q;
   p=L->next;
   int j=0;
   q=L->next;
   while(j<k)
    {
       j++;
       q=q->next;
       if(q==NULL)
          return 0;
    }
    while(q!=NULL)
    {
       p=p->next;
       q=q->next;
    }
    printf("值为：%d",p->data);
    return 1;
}

//将两个按元素值递增有序合并成一个按元素值递减有序的
LinkList Merge(LinkList L,LinkList M,LinkList s)
{
   InitList(&s);
   Node *l,*m,*r;
   l=L->next;m=M->next;
   while(l!=NULL&&m!=NULL)
   {
     if(l->data<=m->data)
    {
      r=l;
      l=l->next;
      r->next=s->next;
      s->next=r;
    }
    else
    {
      r=m;
      m=m->next;
      r->next=s->next;
      s->next=r;
    }
   }
   if(l!=NULL)
     while(l!=NULL)
     {
      r=l;
      l=l->next;
      r->next=s->next;
      s->next=r;
     }
   if(m!=NULL)
      while(m!=NULL)
      {
      r=m;
      m=m->next;
      r->next=s->next;
      s->next=r;
     }

}

//删除单链表L的最大值对应的结点
void delmax(LinkList L)
{
   Node *s,*r,*m;
   s=L;
   r=L->next;
   while(s->next!=NULL)
   {
      if(s->next->data>=r->next->data)
          {
              r=s;
          }
      s=s->next;
   }
   m=r->next;
   r->next=m->next;
   free(m);
}

int main()
{
    LinkList L;
    InitList(&L);
   
   // LinkList M;
    //InitList(&M);
   // LinkList s;
    //CreateFromHead(L);
   CreateFromTail(L);
   delmax(L);
   Print(L);
    //CreateFromTail(M);
    //s=Merge(L,M,s);
    //changelist(L);
   // BinAdd(L);
     //delrepeat(L);
   // ReverseList(L);
   //delcenter(L,2,8);
   //Translate(L);
  // check(L,5);
     //Print(s);
    /*InsList(L,2,100);
    DelList(L,2);
    *Node *p;
    p=(Node *)malloc(sizeof(Node));
    p=Get(L,3);
    printf("%d",p->data);

    p=Locate(L,4);
      printf("%d",p->data);

   int x;
    x=ListLength(L);
    printf("x is %d",x);
    LinkList M,k;
    InitList(&M);
    CreateFromTail(M);
   
   k=MergeLinkList(L,M);
   Sort(L);
   Print(k);*/

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