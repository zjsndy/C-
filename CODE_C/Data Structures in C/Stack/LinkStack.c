#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;

typedef struct node
{
  StackElementType data;
  struct node *next;
}LinkStackNode,*LinkStack;

void Init(LinkStack *s)
{
    (*s)=(LinkStack)malloc(sizeof(LinkStackNode));
    if(s==NULL)
       printf("开辟内存失败!\n");
    (*s)->next=NULL;   
}

int Push(LinkStack top,StackElementType x)
{
    LinkStackNode *temp;
    temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
    if(temp==NULL)
      return 0;
    temp->data=x;
    temp->next=top->next;
    top->next=temp;
    return 1;  
}

int Pop(LinkStack top,StackElementType *x)
{
    LinkStackNode *temp;
    temp=top->next;
    if(temp==NULL)
      return 0;
    top->next=temp->next;
    *x=temp->data;
    free(temp) ;
    return 1;
}

void Print(LinkStack top)
{
    LinkStackNode *r;
    r=top->next;
    while(r!=NULL)
       {
           printf("%d  ",r->data);
           r=r->next;
       }
} 

int main()
{
    LinkStack top;
    Init(&top);
    Push(top,5);
    Push(top,6);
    int x;
    Pop(top,&x);
    Print(top);
}