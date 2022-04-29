#include "statement.h"

//初始化树
void InitTree(PTree *T)
{
    (*T).n = 0;
}

//清空树
void ClearTree(PTree *T)
{
    (*T).n = 0;
}

//判断树是否为空
int IsEmpty(PTree *T)
{
    if((*T).n==0)
        return 1;
    return 0;
}

//返回树的度
int TreeDegree(PTree T)
{
    int i, tmp, count;
    int max;

    max = count = 0;

    if(T.n)
    {
        tmp = T.nodes[0].parent;

        for (i = 0; i < T.n;i++)
        {
            if(T.nodes[i].parent!=tmp)
            {
                tmp = T.nodes[i].parent;
                count = 1;
            }
            else
                count++;

            if(count>max)
                max = count;
        }
    }

    return max;
}

//返回树的深度
int TreeDepth(PTree T)
{
    int k = T.n - 1;
    int count = 0;

    while(k!=-1)
    {
        k = T.nodes[k].parent;
        count++;
    }

    return count++;
}

//返回树的根节点值
TElemType Root(PTree T)
{
    if(T.n)
        return T.nodes[0].data;
    else
        return '\0';
}

//返回树中第i个结点的值(按层序计数)
TElemType Value(PTree T,int i)
{
    if(T.n>=i)
        return T.nodes[i].data;
    else
        return '\0';
}

//返回结点e的值位置(在数组中位置),-1代表无此节点
int Order(PTree T,TElemType e)
{
    for (int i = 0; i < T.n;i++)
    {
        if(T.nodes[i].data==e)
        {
            return i ;
        }
    }

    return -1;
}

//返回结点e的值为value
void Assign(PTree *T,TElemType e,TElemType value)
{
    for (int i = 0; i < (*T).n;i++)
    {
        if((*T).nodes[i].data==e)
        {
            (*T).nodes[i].data = value;
        }
    }
}

//返回结点e的第order个孩子的值(从左到右计数)
TElemType ChildValue(PTree T,TElemType e,int order)
{
    int pos = Order(T, e);
    int count = 0;

    for (int i = 0; i < T.n;i++)
    {
        if(T.nodes[i].parent==pos)
        {
            count++;
            if(count==order)
                return T.nodes[i].data;
        }
    }

    return '\0';
}

//返回元素e的左（右）兄弟,mark标记左右  
//0:左    1:右
TElemType Sibiling(PTree T,TElemType e,int mark)
{
    int pos = Order(T, e);
    if(pos==0)
        return '\0';

    if(mark==0)      //左
    {
        if(T.nodes[pos-1].parent==T.nodes[pos].parent)
            return T.nodes[pos - 1].data;
        else
            return '\0';
    }

    else
    {
        if(pos<(MAX_TREE_SIZE-2)&&T.nodes[pos+1].parent==T.nodes[pos].parent)
            return T.nodes[pos + 1].data;
        else
            return '\0';
    }
}

//返回结点p的孩子结点个数,返回负数代表结点p不存在
int ChildCount(PTree T,TElemType p)
{
    int k1, k2, count;

    if(IsEmpty(&T))     //空树
        return -1;

    k1 = Order(T, p);

    if(k1<0)
        return -2;      //p结点不存在

    k2 = k1 + 1;
    count = 0;
    while(k2<T.n)
    {
        if(T.nodes[k2].parent==k1)
            count++;
        if(T.nodes[k2].parent>k1)  //这个方法妙在不用全部遍历
            break;

        k2++;
    }

    return count;
}

//返回树T中p结点的第i个孩子,num=0定义为最后一个孩子
int ChildSeat(PTree T,TElemType p,int num)
{
    int pos = Order(T, p);
    int count = 0;
    int total = ChildCount(T, p);

    for (int i = pos + 1; i < T.n;i++)
    {
        if(T.nodes[i].parent==pos)
        {
            count++;

            if(num==0)
               return i + total-1;

            else if(count==num)
               return i;
        }
    }

    return -1;
}

//将结点e插入为树中p结点的第i个孩子（层次计数），i=0定义为最后一个孩子
void InsertChild(PTree *T,TElemType p,int i,TElemType e)
{
    int pos = ChildSeat(*T, p, i);

    for (int j = (*T).n; j > pos;j--)
    {
        (*T).nodes[j] = (*T).nodes[j - 1];
    }

    (*T).nodes[pos].data = e;
    (*T).n++;
}

//将树t插入到为树T中p结点的第i棵子树(层序计数),i=0定义为最后一棵子树
void InsetTree(PTree *T,TElemType p,int i,PTree t)
{
    for (int k = 0; k < t.n;k++)
    {
        if(k==0)
            InsertChild(T, p, i, t.nodes[k].data);
        else
            InsertChild(T, t.nodes[t.nodes[k].parent].data, 0, t.nodes[k].data);
    }
}

//删除树T中p结点的第i棵子树
void DeleteTree(PTree *T,TElemType p,int i)
{
    int pos = ChildSeat(*T, p, i);

    for (int j = pos; j < (*T).n-1;j++)
    {
        (*T).nodes[j] = (*T).nodes[j + 1];
    }

    (*T).n--;
}

//层序遍历树
void LevelOrderTraverse(PTree T)
{
    for (int i = 0; i < T.n;i++)
        printf("%c  ", T.nodes[i].data);
}

