#include "statement.h"


void Prethread(ThrBiTree p)
{

    if(p==NULL)
        return;

    if(p->LChild==NULL)   
    {
        p->LChild = pre;
        p->LTag = Thread;
    } 

    if(pre&&!pre->RChild)     //为上一个结点右子树建立后继线索
    {
        pre->RTag = Thread;
        pre->RChild = p;
    }

    pre = p;           //pre向前挪一步
    
    if(p->LTag==Link)
       Prethread(p->LChild);      //线索化左子树
    
    if(p->RTag==Link)
       Prethread(p->RChild);      //线索化右子树
}

void Prethread_2(ThrBiTree *Thrt,ThrBiTree T) //头节点后继回指
{
    *Thrt = (ThrBiTree)malloc(sizeof(ThrBiTNode));
    if(!*Thrt)
        return;

    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->RChild = NULL;

    if(!T)          //空树只有线索头节点
        (*Thrt)->LChild = (*Thrt)->RChild= *Thrt;
    
    else
    {
        (*Thrt)->LChild = T;
        pre = *Thrt;        //指向头节点

        Prethread(T);       //开始线索化

        pre->RTag = Thread;     //最后一个结点线索化
        pre->RChild = *Thrt;    //最后一个结点指回头节点
    }
}

void PreTravel(ThrBiTree T,ThrBiTree Thrt)
{
    ThrBiTree p = Thrt;        //p指向二叉树线索结点

    while(p->RChild!=Thrt)
    {
        while(p->LChild&&p->LTag==Link)
        {
            p = p->LChild;
            printf("%c ", p->data);
        }

        if(p->RChild!=Thrt)
        {
            p = p->RChild;
            printf("%c ", p->data);
        }
    }
}
