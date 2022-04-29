#include "Construct.c"



//对二叉树线索化
void Inthread(ThrBiTree T)
{
    if(T)
    {
        Inthread(T->LChild);

      
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

        Inthread(T->RChild);
    }
}

//在中序线索树中找结点前驱
ThrBiTNode *InPre(ThrBiTNode *p)
{
    ThrBiTNode *q;
    if(p->LTag==1)
        pre = p->LChild;
    else
    {
        //在p的左子树中查找最右下端结点
     for (q = p->LChild; q->RTag == 0;q=q->RChild)
         ;
      pre = q;

    }
    return pre;
}

//中序遍历二叉树T,并将其全线索化
void Inthread_2(ThrBiTree *Thrt,ThrBiTree T)//头节点后继回指
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

        Inthread(T);  //开始线索化

        pre->RChild = *Thrt; //最后一个结点指回头节点
        pre->RTag = Thread;  //最后一个结点线索化
        (*Thrt)->RChild = pre;   //头节点指向最后一个结点，建立双向联系
    }
}

//在中序线索树中找结点后继
ThrBiTNode* InNext(ThrBiTNode *p)
{
    ThrBiTNode *q;
    if(p->RTag==1)
        next = p->RChild;
    else
    {
        for (q = p->RChild; q->LTag == 0;q=q->LChild)
            ;
        next = q;
    }
    return next;
}

//遍历中序线索树
//1.在中序线索树上求中序遍历的第一个结点
ThrBiTNode *InFirst(ThrBiTree T)
{
    ThrBiTNode *p = T;

    if(!p)
        return NULL;
    while(p->LTag==0)
        p = p->LChild;
    return p;
}

//2.遍历中序二叉线索树
void TInOrder(ThrBiTree T)
{
    ThrBiTNode *p;
    p = InFirst(T);
    while(p)
    {
        printf("%c ", p->data);
        p = InNext(p);
    }
}

