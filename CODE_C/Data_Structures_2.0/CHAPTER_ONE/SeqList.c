/*************************************************************
*  FileName:   SeqList.c
*  Date:       2022-02-23 15:59:14
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_ONE
*  Description:顺序表
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType elem[MAXSIZE];
    int last;
} SeqList;

void IniList(SeqList *L)
{
   // L->elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    L->last = -1;
}

int ListLength(SeqList *L)
{
    return L->last + 1;
}

ElemType GetData(SeqList *L,int pos)
{
    int len = ListLength(L);

    if(pos<1||pos>len)
    {
        return -1;
    }

    else
    {
        return L->elem[pos - 1];
    }
}

void InsList(SeqList *L,int pos,ElemType e)
{
    int len = ListLength(L);

    if(pos<1||pos>len+1)
    {
        printf("位置不合法\n");
    }

    else
    {
        L->last++;

        for (int i = L->last; i > pos - 1;i--)
        {
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[pos - 1] = e;
    }

}

void DelList(SeqList *L,int pos,ElemType *e)
{
    int len = ListLength(L);

    if(pos<1||pos>len)
    {
         printf("位置不合法\n");
    }

    else
    {
        *e = L->elem[pos - 1];

        for (int i = pos - 1; i < L->last; i++)
        {
            L->elem[i] = L->elem[i + 1];
        }

        L->last--;

    }

}

int  Locate(SeqList *L,ElemType e)
{
    for (int i = 0; i < L->last + 1;i++)
    {
        if(L->elem[i]==e)
        {
            return i + 1;
        }
    }

    return -1;
}

void PrintList(SeqList *L)
{
    for (int i = 0; i < L->last + 1;i++)
    {
        printf("%d  ", L->elem[i]);
    }
}

void Reverse(SeqList *L)
{
    for (int i = 0;i<(L->last+1)/2;i++)
    {
        int tmp = 0;
        tmp = L->elem[i];
        L->elem[i] = L->elem[L->last - i];
        L->elem[L->last - i] = tmp;
    }
}

void Bubble_Sort_List(SeqList *L)
{
    for (int i = 0; i < L->last;i++)
    {
        for (int j = 0; j < L->last - i;j++)
        {
            if(L->elem[j]>L->elem[j+1])
            {
                int tmp = 0;
                tmp = L->elem[j];
                L->elem[j] = L->elem[j + 1];
                L->elem[j + 1] = tmp;
            }
        }
    }
}

void MergeList(SeqList *LA,SeqList *LB,SeqList *LC)
{
    int i = 0, j = 0,m=0;

    while(i<=LA->last&&j<=LB->last)
    {
      if(LA->elem[i]>LB->elem[j])
     {
        LC->elem[m] = LB->elem[j];
        j++;
        m++;
     }

      else
     {
        LC->elem[m] = LA->elem[i];
        i++;
        m++;
     }

    }

     while(i<=LA->last)
     {
         LC->elem[m] = LA->elem[i];
         m++;
         i++;
     }

     while(j<=LB->last)
     {
         LC->elem[m] = LB->elem[j];
         m++;
         j++;
     }

     LC->last = m - 1;
}

//从顺序表L中删除所有值为x的值
void delx(SeqList *L,ElemType e)
{
    int i = 0, j = 0;
    while(i<=L->last)
    {
        if(L->elem[i]!=e)
        {
            L->elem[j] = L->elem[i];
            j++;
        }  
        i++;
    }
    L->last = j - 1;
}

//删除介于x和y之间所有的元素
void delx_y(SeqList *L,int x,int y)
{
    int i = 0, j = 0;
    while(i<=L->last)
    {
        if(L->elem[i]<x||L->elem[i]>y)
        {
            L->elem[j] = L->elem[i];
            j++;
        }

        i++;
    }

    L->last = j - 1;
}

//奇数排在前面，偶数排在后面
void Sort_by_odd_even(SeqList *L)
{
    int i, j, k;
    i = 0;
    j = 0;
    k = L->last;
    int tmp;
    while(i<=L->last)
    {
        if(k<i)
        {
            break;
        }

        if(L->elem[i]%2==0)
        {
            tmp = L->elem[k];
            L->elem[k] = L->elem[i];
            L->elem[i] = tmp;
            k--;
        }
        else
        {
            L->elem[j] = L->elem[i];
            j++;
            i++;
        }
    }
}

//假定L非递减，删除值相等的yuansu
void delrepeation(SeqList* L)
{
    int i = 0, j = 1,k=0;
    while(i<=L->last)
    {
        if(L->elem[i]!=L->elem[j])
        {
            L->elem[k] = L->elem[i];
            k++;
            i = j;
        }
        j++;
    }
    L->last = k;
}

int main ()
{
   /* SeqList LA, LB, LC;
    IniList(&LA);
    IniList(&LB);
    IniList(&LC);
    int arry_a[3] = {2, 2, 3};
    int arry_b[4] = {1, 3, 3, 4};
    
    for (int i = 0; i < 3;i++)
    {
        LA.elem[i] = arry_a[i];
        LA.last++;
    }

    for (int i = 0; i < 4;i++)
    {
        LB.elem[i] = arry_b[i];
        LB.last++;
    }

    MergeList(&LA, &LB, &LC);*/

   SeqList L, *M;
   M = &L;
   IniList(M);
   int arry_a[10] = {1,3,3,3,3,2,2,2,5,5};
   for (int i = 0; i < 10;i++)
    {
        M->elem[i] = arry_a[i];
        M->last++;
    }

    delrepeation(M);
    system("pause");
    return 0;
}