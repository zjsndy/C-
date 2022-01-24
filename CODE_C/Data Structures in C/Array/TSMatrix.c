//三元组压缩存储结构的稀疏矩阵的转置运算

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MAXSIZE 1000

//二维数组
typedef struct 
{
   int row,col;//非零元素的行下标、列下标
   ElementType e;//非零元素的值
}Triple;

//三元组
typedef struct 
{
    Triple data[MAXSIZE+1];//非零元素的三元组表
    int m,n,len; //矩阵的行数、列数和非零元素的个数
}TSMatrix;

//将稀疏矩阵以三元组形式输出
TSMatrix Transport(int a[6][7],TSMatrix M)
{
    M.len=0;M.m=6;M.n=7;
    for(int i=0;i<6;i++)
       for(int j=0;j<7;j++)
       {
          if(a[i][j]!=0)
             {
                 M.data[M.len].col=j;
                 M.data[M.len].row=i;
                 M.data[M.len].e=a[i][j];
                 M.len++;
             }
       }
    return M;   
}

//二维数组实现矩阵转置
void TransMatrix(int a[6][7],int b[7][6])
{   
    int i,j;
    for(i=0;i<6;i++)
       for(j=0;j<7;j++)
           b[j][i]=a[i][j];
}

//稀疏矩阵列序递增转置
void TransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ 
   int i,j,k;
   B->m=A.n;B->n=B->m;B->len=A.len;
   if(B->len>0)
   {
       j=0;
       for(k=0;k<=A.n;k++)
         for(i=0;i<=A.n;i++)
           if(A.data[i].col==k)
           {
               B->data[j].row=A.data[i].col;
               B->data[j].col=A.data[i].row;
               B->data[j].e=A.data[i].e;
               j++;
           }
   }
}

//稀疏矩阵一次定位快速转置算法
void  FastTranposeTSMatrix(TSMatrix A,TSMatrix *B)
{
    int col,t,p,q;
    int num[MAXSIZE],position[MAXSIZE];
    B->len=A.len;B->n=A.m;B->m=A.n;
    if(B->len)
    {
        for(col=0;col<A.n;col++)
            num[col]=0;
        for(t=0;t<A.len;t++)   
            num[A.data[t].col]++;
        position[0]=1;
        for(col=1;col<A.n;col++) 
          position[col]=position[col-1]+num[col-1];
        for(p=0;p<A.len;p++) 
        {
            col=A.data[p].col;
            q=position[col];
            B->data[q].row=A.data[p].col;
            B->data[q].col=A.data[p].row;
            B->data[q].e=A.data[p].e;
            position[col]++;
        } 
    }
}

//打印三元组
void Print(TSMatrix M)
{
    printf("行号\t列号\t元素值\n");
    for(int i=0;i<M.len;i++)
      printf("%2d\t%2d\t%2d\n",M.data[i].row,M.data[i].col,M.data[i].e);
}

//还原稀疏矩阵
void PrintArray(TSMatrix M)
{
    int m=0;
    for(int i=0;i<7;i++)
    {
       for(int j=0;j<6;j++)
       {
           if(i==M.data[m].row&&j==M.data[m].col)
           {
              printf("%2d  ",M.data[m].e);
              m++;
           }
           else
              printf(" 0  ") ;  
       }
       printf("\n");
    }

}

int main()
{
        TSMatrix M,N;
        int a[6][7]={
          0,12,9,0,0,0,0,
          0,0,0,0,0,0,0,
          -3,0,0,0,0,14,0,
          0,0,24,0,0,0,0,
          0,18,0,0,0,0,0,
          15,0,0,-7,0,0,0
        };

        M=Transport(a,M);
        //TransposeTSMatrix(M,&N);
        FastTranposeTSMatrix(M,&N);
       // Print(N);
        PrintArray(N);
        /*
        Print(M);
        int b[7][6];
        TransMatrix(a,b);
        for(int i=0;i<6;i++)
        {
           for(int j=0;j<7;j++)
           {
               printf("%2d  ",b[i][j]);
           }
            printf("\n");
        }*/
}