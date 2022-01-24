#include "LinkQueue.h"
#include "SeqQueue.h"

void YangHuiTriangle(int N)
{
    SeqQueue Q;
    InitSQueue(&Q);
    EnterSQueue(&Q,1);
    int x,y;
    for(int n=2;n<=N;n++)//产生第n行元素并入队，同时打印第n-1行的元素
     {
        for(int m=-2*n+3*N;m>=0;m--)
             printf(" ");
         EnterSQueue(&Q,1);//n行的第一个元素入队
         for(int i=1;i<=n-2;i++)//利用队中第n-1行元素产生第n行的中间n-2个元素并入队
          {
              DeleteSQueue(&Q,&x);
              printf("%2d",x);//打印第n-1行元素
              printf("   ");
              y=GetSHead(&Q,y);
              y=y+x;//利用队中第n-1行元素产生第n行
              EnterSQueue(&Q,y);
          }
          DeleteSQueue(&Q,&x);
          printf("%2d",x);//打印n-1行的最后一个元素
          printf("\n");
          EnterSQueue(&Q,1);//n行的最后一个元素入队
     }
     for(int m=N-2;m>=0;m--)
         printf(" ");
     while(!IsEmpty(Q))
     {
         DeleteSQueue(&Q,&x);//打印最后一行
         printf("%2d",x);
         printf("   ");
     }
}

void yang(int N)
{
    LinkQueue L;
    InitLQueue(&L);
    EnterLQueue(&L,1);
    int x,y;
    for(int n=2;n<=N;n++)//产生第n行元素并入队，同时打印第n-1行的元素
     {
        for(int m=-2*n+3*N;m>=0;m--)
             printf(" ");
         EnterLQueue(&L,1);//n行的第一个元素入队
         for(int i=1;i<=n-2;i++)//利用队中第n-1行元素产生第n行的中间n-2个元素并入队
          {
              DeleteLQueue(&L,&x);
              printf("%2d",x);//打印第n-1行元素
              printf("   ");
              y=GetLHead(&L,y);
              y=y+x;//利用队中第n-1行元素产生第n行
              EnterLQueue(&L,y);
          }
          DeleteLQueue(&L,&x);
          printf("%2d",x);//打印n-1行的最后一个元素
          printf("\n");
          EnterLQueue(&L,1);//n行的最后一个元素入队
     }
     for(int m=N-2;m>=0;m--)
         printf(" ");
     while(!IsLEmpty(&L))
     {
         DeleteLQueue(&L,&x);//打印最后一行
         printf("%2d",x);
         printf("   ");
     }


}

int main()
{
   // YangHuiTriangle(7);
    yang(6);
}