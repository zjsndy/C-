/*************************************************************
*  FileName:   try.c
*  Date:       2022-01-17 12:41:31
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\C_Single\Exercise
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include <string.h>

int Prime(int m)
{
    int i = 2;
    for (i = 2; i <= sqrt(m); i++)
    {
        if (m % i == 0)
            return 1;
    }
    return 0;
}

int main()
{
    /*int i,cout=0;
    for(i=1000;i<=2000;i++)
    {
      if(((i%4==0)&&(i%100!=0))||(i%400==0))
      {
        printf("%d\t",i);
        cout++;
      }
    }
    printf("\ncout=%d",cout);
   system("pause");
   return 0;*/
   /* for(int i=2;i<=200;i++)
    {
        int m=Prime(i);
        if(m)
          printf("%d  ",i);
    }*/
    /* int arr1[1000];
     for(int i=0;i<1000;i++)
         arr1[i]=0;      //假定都是素数
     for(int i=2;i<1000;i++)
       {
           if(arr1[i-1]==0)
              for(int k=2;k*i<=1000;k++)
                 arr1[k*i-1]=1;
       }
      for(int i=1;i<1000;i++)
      {
          if(arr1[i]==0)
            printf("%d  ",i+1);
      }*/
      /*for(int i=1;i<10;i++)
      {
        for(int j=1;j<=i;j++)
        {
                printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n")     ;
      }*/
      /*srand((unsigned int)time(NULL));
      int ret=rand();
      printf("%d ",ret);*/
    char input[10] = { 0 };
    system("shutdown-s-t 60");
again:
    printf("电脑将在1分钟内关机，如果输入:我是猪，就取消关机\n");
    scanf_s("%s", input);
    if (0 == strcmp(input, "我是猪"))
        system("shutdown-a");
    else
        goto again;
    system("pause");
    return 0;
}