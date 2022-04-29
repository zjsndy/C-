#include "Statement.h"

int depth=0;
int leafcount = 0;

//清空树
void ClearBiTree(BiTree *T)
{
    if(*T)
    {
        if((*T)->LChild)
            ClearBiTree(&((*T)->LChild));//清空左树
        if((*T)->RChild)  
             ClearBiTree(&(*T)->RChild);//清空右树

        free(*T);    //释放根节点

        *T = NULL;      //置空树指针
    }
}

//后序遍历求二叉树高度
int PostTreeDepth(BiTree T)
{
    int hl, hr, max;

    if(T)
    {
        hl = PostTreeDepth(T->LChild);    //求左子树的深度
        hr = PostTreeDepth(T->RChild);    //求右子树的深度
        max = hl > hr ? hl : hr;       //得到左、右树深度较大者
        return max + 1;     //返回树的深度
    }
    else
        return 0;
}

//先序遍历求二叉树高度
//h初值为1
//depth为全局变量,初值为0
void PreTreeDepth(BiTree T,int h)
{
    if (T)
    {
        if(h>depth)
            depth = h;
        PreTreeDepth(T->LChild, h + 1);  //遍历左
        PreTreeDepth(T->RChild, h + 1);  //遍历右
   }
}


//求树结点个数
void node(BiTree T,int *m)
{
    if(T)
    {
        node(T->LChild, m);
        (*m)++;
        node(T->RChild, m);
    }
}

void PreOrderleaf(BiTree T,int *m)
{
    if(T)
    {
        if(T->LChild==NULL&&T->RChild==NULL)
            (*m)++;
        PreOrderleaf(T->LChild, m);
        PreOrderleaf(T->RChild, m);
    }
}

void PostOrderleaf(BiTree T)
{
    if(T)
    {
        PostOrderleaf(T->LChild);
        PostOrderleaf(T->RChild);
        if(T->LChild==NULL&&T->RChild==NULL)
            leafcount++;
    }
}


//采用分治算法,如果是空树，返回0；如果只有一个结点，返回1；否则为左右子树的叶子结点数之和
int PostOrderleaf_1(BiTree T)
{
    int count;
    if(!T)
        count = 0;
    else if(!T->RChild&&!T->LChild)
        count = 1;
    else
        count = PostOrderleaf_1(T->LChild) + PostOrderleaf_1(T->RChild);
    return count;
}

//获取指向e的指针
BiTree LocationTree_1(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;
    
    if(!T)
        return NULL;
    if(T->data==e)
        return T;

    node[i] = *T;

    while(i>=0)
    {
        while(node[i].LChild)
        {
            if(node[i].LChild->data==e)
                return node[i].LChild;
            node[i + 1] = *(node[i].LChild);
            node[i].LChild = NULL;
            i++;
        }

        if(node[i].RChild)
        {
            if(node[i].RChild->data==e)
                return node[i].RChild;
            node[i + 1] = *(node[i].RChild);
            node[i].RChild = NULL;
            i++;
        }

        if(node[i].LChild==NULL&&node[i].RChild==NULL)
            i--;
    }
    return NULL;
}

BiTree LocationTree_2(BiTree T,TElemType e)
{
    BiTree p = NULL;

    if(T)
    {
        if(T->data==e)
        {
            p = T;
        }
        else
        {
            if(p=LocationTree_2(T->LChild, e))
                return p;
            if(p=LocationTree_2(T->RChild, e))
                return p;
        }
    }

    return p;
}

//将树TO插入到树T中成为结点e的子树，LR为插入标记，1为右边，0为左边，TO只有左子树
int InSertBiTree(BiTree T,TElemType e,BiTree TO,int LR)
{
    BiTree p = LocationTree_1(T, e);

    if(p)
    {
        TO->RChild = LR ? p->RChild : p->LChild;
        LR ? (p->RChild = p) : (p->LChild = TO);

        return 1;
    }
    return 0;
}

int DeleteBiTree(BiTree T,TElemType e,int LR)
{
    BiTree p = LocationTree_2(T, e);

    if(p)
    {
        LR ? ClearBiTree(&(p->RChild)) : ClearBiTree(&(p->LChild));
        return 1;
    }

    return 0;
}
