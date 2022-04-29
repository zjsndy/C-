/*************************************************************
*  FileName:   Polylist.c
*  Date:       2022-03-12 10:06:22
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_ONE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 

typedef struct Polynode
{
    int coef;//系数
    int exp;//指数
    struct Polynode *next;
}Polynode,*Polylist;
 
void Init(Polylist *L)
{
    *L = (Polylist)malloc(sizeof(Polynode));
    (*L)->next = NULL;
}

void Create(Polylist L)
{
    Polynode *rear, *s;
    rear = L;
    int coef;//系数
    int exp;//指数
    int total;
    printf("你想创建几个结点:");
    scanf("%d", &total);
    for (int i = 0; i < total;i++)
    {
        scanf("%d%d", &coef,&exp);
        s = (Polynode *)malloc(sizeof(Polynode));
        s->coef = coef;
        s->exp = exp;
        rear->next = s;
        rear = s;
    }
    rear->next = NULL;
}

void PolyAdd(Polylist polya,Polylist polyb)
{
    Polynode *p, *q, *tail, *temp;
    int sum;
    p = polya->next;
    q = polyb->next;
    tail = polya;
    while(p!=NULL&&q!=NULL)
    {
        if(p->exp<q->exp)
        {
            tail->next = p;
            tail = p;
            p = p->next;
        }

        else if(p->exp==q->exp)
        {
            sum = p->coef + q->coef;
            if(sum!=0)
            {
                p->coef = sum;
                tail->next = p;
                tail = p;
                p = p->next;
                temp = q;
                q = q->next;
                free(temp);
            }
            else
            {
                temp = p;
                p = p->next;
                free(temp);
                temp = q;
                q = q->next;
                free(temp);
            }
        }
        else
        {
            tail->next = q;
            tail = q;
            q = q->next;
        }
    }

    if(p)
    {
        tail->next = p;
    }
    if(q)
    {
        tail->next = q;
    }
}

int main ()
{
    Polylist L,M;
    Init(&L);
    Create(L);
    Init(&M);
    Create(M);
    PolyAdd(L, M);

    system("pause");
    return 0;
}