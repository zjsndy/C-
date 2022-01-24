/*顺序表基本操作的实现*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXSIZE 100
#define True 1
#define False 0
typedef int ElemType;

typedef struct{
    ElemType elem[MAXSIZE];
    int last;               //线性表中最后一个元素在数组elem[]中的位置
}SeqList;

//初始化
void InitList(SeqList L)
{
    L.last=0;
}

//求表的长度
int ListLength(SeqList L)
{
    return L.last+1;
}

//插入运算
int InsList(SeqList *L,int i,ElemType e)
/*  i:插入的位置;e:插入的元素*/
{
   int k;
   if((i<1)||(i>L->last+2))
   {
      printf("插入的位置不合法\n");
      return False;
   }

   if(L->last>=MAXSIZE-1)
   {
       printf("表满\n");
       return False;
   }

   for(k=L->last;k>=i-1;k--)
      L->elem[k+1]=L->elem[k];
   L->elem[i-1]=e;
   L->last++;
   return True;

}

//删除运算
int DelList(SeqList *L,int i,ElemType *e)
/* i:删除的位置; 指针参数e*/
{
    int k;
    if((i<1)||(i>L->last+1))
    {
         printf("删除的位置错误！\n");
         return False;
    }

    *e=L->elem[i-1];
    for(k=i-1;k<=L->last-1;k++)
      L->elem[k]=L->elem[k+1];
    L->last--;
    return  True;  
}

//定位运算
int Locate(SeqList *L,ElemType e)
/* e:所要查询的元素 */
{
    int i=0;
    while((i<=L->last)&&(L->elem[i]!=e))
        i++;
    if(i<=L->last)  
      return i+1;
    else
      return -1;
}

//求值运算
ElemType GetData(SeqList *L,int i)
{
    return L->elem[i-1];
}

//打印
void Print(SeqList *L)
{
    for(int i=0;i<=L->last;i++)
       printf("%d  ",L->elem[i]);
}

//排序
void Sort(SeqList *L)
/*简单的冒泡排序*/
{
    for(int i=0;i<L->last;i++)
       for(int k=0;k<L->last-i;k++)
          {
              if(L->elem[k]>L->elem[k+1])
                 {
                     int buff=0;
                     buff=L->elem[k];
                     L->elem[k]=L->elem[k+1];
                     L->elem[k+1]=buff;
                 }
          }
}

//合并
void mergeList(SeqList *LA,SeqList *LB,SeqList *LC)
{
    int i,j,k;
    i=0;j=0;k=0;

    while(i<=LA->last&&j<=LB->last)
        if(LA->elem[i]<=LB->elem[j])
           {
               LC->elem[k]=LA->elem[i];
               i++;k++;
           }
        else
          {
            LC->elem[k]=LB->elem[j];
            j++;k++;
          }

    while(i<=LA->last)
       {
           LC->elem[k]=LA->elem[i];
           k++;i++;
       }

    while(j<=LB->last)   
       {
           LC->elem[k]=LC->elem[j];
           j++;k++;
       }
    
    LC->last=LA->last+LB->last+1;
}

//删除所有值为x的元素
void delx(SeqList *L,ElemType e)
{ 
   int i=0,j=0;
   while(i<=L->last)
   {
       if(L->elem[i]!=e)
       {
           L->elem[j]=L->elem[i];
           i++;j++;
       }
       else
         i++;
   }
   L->last=j-1;
}

//删除介于(x,y)之间的数
SeqList delxy(SeqList L,int x,int y)
{
   int i=0,j=0;
   while(i<=L.last)
   {
     if(L.elem[i]>x&&L.elem[i]<y)
       i++;
     else
     {
         L.elem[j]=L.elem[i];
         j++;i++;                                                                     
     }
   }
    L.last=j-1;
    return L;
}


//将L中奇数元素排在前面，偶数元素排在后面
void divide(SeqList *L)
{
    int i=0,j=0;
    for(i=0;i<=L->last;i++)
       {
           if(L->elem[i]%2!=0)
             {
                 if(i!=j)
                 {
                 int temp;
                 temp=L->elem[i];
                 L->elem[i]=L->elem[j];
                 L->elem[j]=temp;
                 }
                 j++;
             }
       }

}

//删除所有值相等的多余元素(算法比较巧妙)
void Delete(SeqList *L)
{
    int i=0,j=1;
    while(j<=L->last)
    {
       if(L->elem[i]==L->elem[j])
        {
          j++;
        }
       else 
        {
            L->elem[i+1]=L->elem[j];
            i++;j++;
        }
    }
    L->last=i;   
}

//逆置算法
void reserve(SeqList *L)
{
    int temp;
     for(int i=0;i<(L->last+1)/2;i++)
     {
         temp=L->elem[i];
         L->elem[i]=L->elem[L->last-i];
         L->elem[L->last-i]=temp;
     }
}

int main()
{
    SeqList L;
    InitList(L);
    int buff[5]={1,2,2,3,4};
    for(int i=0;i<=4;i++)
      L.elem[i]=buff[i];
    L.last=4; 

    int *e;
    e=(int *)malloc(sizeof(int));//为指针开辟空间
    //delx(&L,5);
   // L=delxy(L,2,8);
    //divide(&L);
   // Delete(&L);
   reserve(&L);
    Print(&L);
   /* DelList(&L,101,e); 

    InsList(&L,8,98);

    int location;
    location=Locate(&L,100);
    printf("%d\n",location);

    int length;
    length=ListLength(L);
    printf("%d\n",length);

    int Num;
    Num=GetData(&L,5);
    printf("%d\n",Num);

    Sort(&L);

    SeqList M;
    int BUFF[5]={7,59,6,36,14};
    for(int i=0;i<5;i++)
       M.elem[i]=BUFF[i];
    M.last=4;
    Sort(&M);

    SeqList K;
    mergeList(&L,&M,&K);

    Print(&K);*/

    
}