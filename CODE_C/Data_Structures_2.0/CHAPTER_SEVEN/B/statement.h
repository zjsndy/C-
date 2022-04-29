#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 3
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define TRUE 1
#define FALSE 0
typedef int KeyType;

typedef struct BTNode{
    struct BTNode *parent;      //指向双亲结点
    int keynum;                 //结点关键字个数
    KeyType key[M + 1];        //关键字向量
    struct BTNode *ptr[M + 1];  //B树结点
} BTNode, *BTree;

typedef struct{
    BTNode *pt;         //指向找到的结点
    int i;              //1.....n，关键字在结点中的序号(插入位置)
    int tag;            //1：查找成功    0:查找失败
} Result;



//创建B树
int CreateBTree(BTree *BT, FILE *fp);

//查找,返回查找信息
Result SearchBTree(BTree BT, KeyType k);

//返回k在结点p中的次序,若不存在,返回0
int Search(BTree p, KeyType k);

//将关键字k插入B树
int InsertKey(BTree *BT, KeyType k);

//插入,在结点*q的key[i]和key[i+1]之间插入关键字k
int InsertBTree(BTree *BT, KeyType k, BTree q, int i);

//将x和ap分别插入到q->key[i+1]和q->ptr[i+1]
void Insert(BTree q, KeyType i, KeyType x, BTree ap);

//以s为界,将q指向的结点分裂成q和ap指向的两部分
void split(BTree q, int s, BTree *ap);

//生成含信息(BT,x,ap)的新的根节点*BT,原BT和ap为子树指针,q初值为NULL
void NewRoot(BTree *BT, BTree q, int x, BTree ap);

//从B树删除关键字K
int DeleteKey(BTree *BT, KeyType K);

//从B树删除结点q中第i个关键字
int DeleteBTree(BTree *BT, BTree q, int i);

//从B树删除结点q中第i个关键字(特殊)
void Delete(BTree *BT, BTree q, int i);

//找出BT中最小的关键字
int SearchMinKey(BTree BT, Result *R);

//寻找双亲结点:q为p的第j个孩子
int FoundParent(BTree q, BTree *p, int *i);

//向左移动关键字和指针
int LeftMove(BTree old_ptr, int m, BTree new_ptr, int n, int len);

//向右移到关键字和指针
int RightMove(BTree old_ptr, int m,BTree new_ptr, int n, int len);

Result SearchBTree(BTree BT,KeyType K)
{
    Result R = {NULL, 0, 0};
    BTree p, q;
    int found, i;

    p = BT;
    q = NULL;
    found = FALSE;
    i = 0;

    while (p&&!found)
    {
        i = Search(p, K);

        if(i>0&&p->key[i]==K)
            found = TRUE;         //找到关键字
        else
        {
            q = p;
            p = p->ptr[i];
        }
    }

    R.i = i;

    if(found)
    {
        R.pt = p;
        R.tag = 1;
    }
    else
    {
        R.pt = q;
        R.tag = 0;
    }

    return R;
}

int Search(BTree p,KeyType k)
{
    int i, j;

    i = 0;

    for (j = 1; j <= p->keynum;j++)
    {
        if(p->key[j]<=k)
            i = j;
        else
            break;
    }

    return i;
}


#endif