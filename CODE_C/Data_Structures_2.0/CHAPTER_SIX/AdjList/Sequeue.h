#ifndef __SeqQueue_H_
#define __SeqQueue_H_

#define MAXSIZE 10

typedef int QueueElemtType;

//循环队列

typedef struct 
{
    QueueElemtType element[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q,QueueElemtType x)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
        return 0;
    Q->element[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int DeleteQueue(SeqQueue *Q,QueueElemtType *x)
{
    if(Q->front==Q->rear)
        return 0;
    *x = Q->element[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

void GetHead(SeqQueue *Q,QueueElemtType *x)
{
    *x = Q->element[Q->front];
}

int IsEmpty(SeqQueue *Q)
{
    if(Q->front==Q->rear)
        return 1;
    return 0;
}

#endif