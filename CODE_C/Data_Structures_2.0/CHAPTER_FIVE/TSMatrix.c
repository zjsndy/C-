/*************************************************************
*  FileName:   TSMatrix.c
*  Date:       2022-03-23 09:26:29
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_FIVE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 

#define MAXSIZE 20
typedef int ElementType;

typedef struct 
{
    int row,  col;
    ElementType e;
} Triple;

typedef struct 
{
    Triple data[MAXSIZE + 1];  //不使用data[0]
    int m, n, len;
}TSMatrix;

TSMatrix Tran_to_Tsmatrix(int Arry[6][7])
{
    TSMatrix t;
    int count = 1;

    for (int i = 0; i < 6;i++)
    {
        for (int j = 0; j < 7;j++)
        {
            if(Arry[i][j]!=0)
            {
                t.data[count].col = j;
                t.data[count].row = i;
                t.data[count].e = Arry[i][j];
                count++;
            }
        }
    }

    t.len = count-1;
    t.m = 6;
    t.n = 7;
    return t;
}

void Restore(TSMatrix t)
{
    int row = t.m;
    int col = t.n;
    int count = 1;

    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col;j++)
        {
            if(t.data[count].row==i&&t.data[count].col==j)
            {
                printf("%2d ", t.data[count].e);
                count++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void TransposeTSMatrix(TSMatrix A,TSMatrix *B)
{
    int i, j, k;
    B->m = A.n;
    B->n = A.m;
    B->len = A.len;

    if(B->len>0)
    {
        j = 1;
        for (k = 0; k < A.n;k++)      //每次寻找列值为k的三元组进行转置
        {
            for (i = 1; i <= A.len; i++)
            {
                if (A.data[i].col == k)
                {
                    B->data[j].col = A.data[i].row;
                    B->data[j].row = A.data[i].col;
                    B->data[j].e = A.data[i].e;
                    j++;
                }
            }
        }
    }
}

void FastTransposeTSMatrix(TSMatrix A,TSMatrix *B)
{
    int col, t, p, q;
    int num[MAXSIZE], positon[MAXSIZE];
    B->len = A.len;
    B->n = A.m;
    B->m = A.n;
    if (B->len)
    {
        for (col = 1; col <= A.n;col++)
            num[col] = 0;
        for (t = 1; t <= A.len;t++)
            num[A.data[t].col+1]++;
        positon[1] = 1;
        for (col = 2; col <=A.n;col++)
            positon[col] = positon[col - 1] + num[col - 1];
        for (p = 1; p <= A.len;p++)
        {
            col = A.data[p].col+1;
            q = positon[col];
            B->data[q].row = A.data[p].col;
            B->data[q].col = A.data[p].row;
            B->data[q].e = A.data[p].e;
            positon[col]++;
        }
    }
    
}

int main ()
{
    TSMatrix m,n;
    int Array[6][7] = {
      {0,12,9,0,0,0,0},
      {0,0,0,0,0,0,0},
      {-3,0,0,0,0,14,0},
      {0,0,24,0,0,0,0},
      {0,18,0,0,0,0,0},
      {15,0,0,-7,0,0,0}
    };

    m = Tran_to_Tsmatrix(Array);
    FastTransposeTSMatrix(m, &n);
    Restore(n);

    system("pause");
    return 0;
}