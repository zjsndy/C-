#include "statement.h"


//对二叉树线索化
void  Postthread(ThrBiTree T)
{
    if(T)
    {
        Postthread(T->LChild);
        if(T->RTag==Link)
            Postthread(T->RChild);
        
        if(!T->LChild)
        {
            T->LTag = Thread;
            T->LChild = pre;
        }

        if(pre&&!pre->RChild)
        {
            pre->RChild = T;
            pre->RTag = Thread;
        }

        pre = T;
    }
}

//后序遍历二叉树T，并将其全线索化
void Postthread_2(ThrBiTree *Thrt,ThrBiTree T)//头节点后继回指
{
    *Thrt = (ThrBiTree)malloc(sizeof(ThrBiTNode));
    if(!*Thrt)
        return;

    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->RChild = *Thrt;

    if(!T)
        (*Thrt)->LChild = *Thrt;
    else
    {
        (*Thrt)->LChild = T;
        pre = *Thrt;      //指向头节点

        Postthread(T);    //开始线索化

        (*Thrt)->RChild = T;     //头节点回指
    }
}

//层序遍历二叉树建立各节点的双亲结点指针
void Parent(ThrBiTree T)
{
    ThrBiTree node[20];
    int i, j;

    i = j = 0;

    if(T)
        node[j++] = T;
    node[i]->parent = NULL;

    while(i<j)
    {
        if(node[i]->LChild)
        {
            node[j++] = node[i]->LChild;
            node[i]->LChild->parent = node[i];
        }

        if(node[i]->RChild)
        {
            node[j++] = node[i]->RChild;
            node[i]->RChild->parent = node[i];
        }

        i++;
    }
}

//在后序遍历后序后线索二叉树时,寻找结点p的后继
ThrBiTree PosNext(ThrBiTree Thrt,ThrBiTree p)
{
    if(p==Thrt->LChild)       //根节点是最后一个结点
        return NULL;
    else
    {
        if(p->RTag==Thread)     //右孩子为线索
            return p->RChild;
        else
        {
            if(p==(p->parent->RChild))    //当前结点是右孩子
                return p->parent;
            else
            {
                if(p->parent->RTag!=Link)  //双亲结点没有右孩子
                    p = p->parent;
                else
                {
                    p = p->parent->RChild;
                    while(1)        //寻找右兄弟遍历起点
                    {
                        while(p->LChild&&p->LTag==Link)
                            p = p->LChild;
                        
                        if(p->RChild&&p->RTag!=Thread)
                            p = p->RChild;
                        else
                            break;
                    }
                }

                return p;
            }
        }
    }
    
}

void PostTravel(ThrBiTree Thrt)
{
    ThrBiTree p = Thrt->LChild; //p指向二叉树根节点

    if(p!=Thrt)         //树不为空
    {
        while(1)
        {
            while(p->LChild&&p->LTag==Link)
                p = p->LChild;

            if(p->RChild&&p->RTag!=Thread)
                p = p->RChild;
            else
                break;
        }

        while(p)
        {
            printf("%c  ", p->data);
            p = PosNext(Thrt, p);
        }
    }
}