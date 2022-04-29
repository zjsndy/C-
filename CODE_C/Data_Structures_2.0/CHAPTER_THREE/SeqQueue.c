/*************************************************************
*  FileName:   SeqQueue.c
*  Date:       2022-03-21 22:36:03
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_THREE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 

#define MAXSIZE 50
typedef int QueueElemtType;

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

void YangHuiTriangle(int N)
{
    SeqQueue Q;
    InitQueue(&Q);
    EnterQueue(&Q, 1);     //第一行元素入队
    QueueElemtType temp,x;

    for (int n = 2; n <= N;n++)   //产生第n行元素并入对,同时打印第n-1行的元素
    {
      
        EnterQueue(&Q, 1);      //n行第一个元素入队

        for (int i = 0; i < N - n+1;i++)
        {
            printf(" ");
        }


        for (int i = 0; i < n - 2; i++)
        {
                DeleteQueue(&Q, &temp);
                printf("%d ", temp); //打印第n-1行元素
                GetHead(&Q, &x);
                temp = x + temp; //利用队中第n-1行的元素产生第n行元素
                EnterQueue(&Q, temp);
        }

        DeleteQueue(&Q, &x);
        printf("%d\n", x);      //打印第n-1行最后一个元素
        EnterQueue(&Q, 1);       //打印最后一行元素
    }

    while(!IsEmpty(&Q))
    {
        DeleteQueue(&Q, &x);
        printf("%d ", x);
    }
}

int main ()
{
    YangHuiTriangle(3);

    system("pause");
    return 0;
}