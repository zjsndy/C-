/*链队列*/
#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int QueueElementType;

typedef struct Node
{
    QueueElementType data;
    struct Node *next;
}LinkQueueNode;

typedef struct 
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;

int InitLQueue(LinkQueue *Q)
{
    Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q->front!=NULL)
      {
          Q->rear=Q->front;
          Q->front->next=NULL;
           return 1;
      }
    else
       return 0;  
}

int EnterLQueue(LinkQueue *Q,QueueElementType x)
{
    LinkQueueNode *NewNode;
    NewNode=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(NewNode==NULL)
      return 0;
    else
    {
        NewNode->data=x;
        NewNode->next=NULL;
        Q->rear->next=NewNode;
        Q->rear=NewNode;
        return 1;
    }  
}

int DeleteLQueue(LinkQueue *Q,int *x)
{
    LinkQueueNode *p;
    if(Q->front==Q->rear)
       return 0;
    p=Q->front->next;
    Q->front->next=p->next;
    if(Q->rear==p)
       Q->rear=Q->front;
    *x=p->data;
    free(p) ;
    return 1; 
}

void printLQueue(LinkQueue *Q)
{
    LinkQueueNode *p;
    p=Q->front;
    while(p!=Q->rear)
    {
       p=p->next;
       printf("%d  ",p->data);
    }  
}

int GetLHead(LinkQueue *Q,int y)
{
    y=Q->front->next->data;
    return y;
}
int IsLEmpty(LinkQueue *Q)
{
    if(Q->front==Q->rear)
       return 1;
    return 0;  
}

#endif
