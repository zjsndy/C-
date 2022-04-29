/*************************************************************
*  FileName:   Queue.c
*  Date:       2022-03-21 21:12:21
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_THREE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>

typedef int QueueElementType;

typedef struct Node
{
    QueueElementType data;//数据域
    struct Node *next;
} LinkQueueNode;

typedef struct 
{
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

int InitQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q->front)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return 1;
    }
    return 0;
}

int EnterQueue(LinkQueue *Q,QueueElementType x)
{
    LinkQueueNode *NewNode;
    NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(NewNode)
    {
        NewNode->data = x;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        Q->rear = NewNode;
        return 1;
    }
    return 0;
}

int DeleteQueue(LinkQueue *Q,QueueElementType *x)
{
    LinkQueueNode *p;

    if(Q->front==Q->rear)
        return 0;

    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->rear==p)          //如果队中只有一个元素p，则p出队后成为空队
        Q->rear = Q->front;
    *x = p->data;
    free(p);
    return 1;
}

int IsEmpty(LinkQueue *Q)
{
  if(Q->front==Q->rear)
      return 1;
  return 0;
}

int GetHead(LinkQueue *Q,QueueElementType *x)
{
    if(!IsEmpty(Q))
    {
       *x = Q->front->next->data;
       return 1;
    }
    else
        return 0;
}

void ClearQueue(LinkQueue *Q)
{
    LinkQueueNode *p,*q;
    p = Q->front->next;
    while(p!=Q->rear)
    {
        q = p->next;
        free(p);
        Q->front->next = q;
        p = q;
    }
    Q->rear = Q->front;
}

int main ()
{
    LinkQueue q;
    InitQueue(&q);
    EnterQueue(&q, 2);
    EnterQueue(&q, 4);
    EnterQueue(&q, 6);
    EnterQueue(&q, 8);
    EnterQueue(&q, 10);
    ClearQueue(&q);

    system("pause");
    return 0;
}