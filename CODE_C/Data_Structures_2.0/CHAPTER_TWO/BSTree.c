/*************************************************************
*  FileName:   BSTree.c
*  Date:       2022-04-08 16:34:25
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_TWO
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>

typedef int KeyType;
#define ENDKEY -1 

typedef struct node{
    KeyType key;      //关键字的值
    struct node *lchid, *rchild;      //左右指针
} BSTNode, *BSTree;

//二叉排序树插入的递归算法
void InsertBST(BSTree *bst,KeyType key)
{
    BSTree s;
    if(*bst==NULL)      //递归条件结束
    {
        s = (BSTree)malloc(sizeof(BSTNode));         //申请新的结点s
        s->key = key;
        s->lchid = NULL;
        s->rchild = NULL;
        *bst = s;
    }
    else if(key<(*bst)->key)
        InsertBST(&((*bst)->lchid), key);         //将s插入到左子树
    else if(key>(*bst)->key)
        InsertBST(&((*bst)->rchild), key);        //将s插入到右子树
}

//创建二叉排序树
void CreateBST(BSTree *bst)
{
    KeyType key;
    *bst = NULL;
    scanf("%d", &key);
    while(key!=ENDKEY)     //ENDKEY为-1
    {
        InsertBST(bst, key);
        scanf("%d", &key);
    }
}

//二叉排序树的查找(递归算法)
BSTree SearchBST(BSTree bst,KeyType key)
{
    if(!bst)
        return NULL;
    else if(bst->key==key)
        return bst;
    else if(bst->key<key)
        return SearchBST(bst->rchild, key);
    else
        return SearchBST(bst->lchid, key);
}


//二叉排序树的查找(非递归算法)
BSTree SearchBST_2(BSTree bst,KeyType key)
{
    BSTNode *p;
    p = bst;

    while (p)
    {
        if(p->key==key)
            return p;
        if(p->key>key)
            p = p->lchid;
        else
            p = p->rchild;
    }

    return NULL;
}

//二叉树排序树删除结点
BSTNode *DelBST(BSTree t,KeyType k)
{
    BSTNode *p, *f, *s, *q;
    p = t;
    f = NULL;
    while(p)
    {
        if(p->key==k)
            break;       //找到则跳出循环
        f = p;
        if(p->key>k)
            p = p->lchid;
        else
            p = p->rchild;
    }

    if(p==NULL)     //找不到,返回原来的二叉排序树
        return t;
    if(p->lchid==NULL)      //p无左子树
    {
        if(f==NULL)          //p为根
            t = p->rchild;
        else if(f->lchid==p)      //p为f的左孩子
            f->lchid = p->rchild;
        else             //p为f的右孩子
            f->rchild = p->rchild;
        free(p);            //释放被删除的结点p
    }
    else       //p有左子树
    {
        q = p;
        s = p->lchid;
        while(s->rchild)      //在p的左子树中查找最右下结点
        {
            q = s;
            s = s->rchild;
        }
        if(q==p)
            q->lchid = s->lchid;         //将s的左子树链到q上
        else
            q->rchild = s->lchid;
        p->key = s->key;
        free(s);
    }
    return t;
}

int main()
{
    BSTree s;
    BSTNode *p;
    CreateBST(&s);
    DelBST(s, 24);

    system("pause");
    return 0;
}