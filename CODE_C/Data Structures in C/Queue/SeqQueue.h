//循环队列
#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
typedef char QueueElemtType;

typedef struct 
{
    QueueElemtType element[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

void InitSQueue(SeqQueue *Q)
{
    Q->front=Q->rear=0;
}

int EnterSQueue(SeqQueue *Q,QueueElemtType x)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
       return 0;
    Q->element[Q->rear]=x;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return 1;
}

int DeleteSQueue(SeqQueue *Q,QueueElemtType *x)
{
    if(Q->front==Q->rear)
       return 0;
    *x=Q->element[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return 1;  
}

int  GetSHead(SeqQueue *Q,QueueElemtType x)
{
    x=Q->element[Q->front];
    return x;
}

int IsEmpty(SeqQueue Q)
{
    if(Q.front==Q.rear)
      return 1;
    return 0;  
}

#endif

