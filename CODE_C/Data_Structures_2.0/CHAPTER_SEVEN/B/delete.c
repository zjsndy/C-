#include "statement.h"

int DeleteKey(BTree *BT,KeyType K)
{
    Result R;

    R = SearchBTree(*BT, K);

    if(R.tag==1)              //B树存在此关键字
    {
        DeleteBTree(BT, R.pt, R.i);
        return 1;
    }
    else
        return 0;
}

int DeleteBTree(BTree *BT,BTree q,int i)
{
    Result R = {q, i, 1};

    if(i<1||i>q->keynum)            //第i个关键字需存在
        return 0;

    if(q->ptr[i])
        SearchMinKey(q->ptr[i], &R);

    q->key[i] = R.pt->key[R.i];          //用右子树中最小结点替换当前结点

    Delete(BT, R.pt, R.i);                 //开始删除R.pt中第R.i个终端结点

    return 1;
}

void Delete(BTree *BT,BTree q,int i)
{
    int s, tag, order;
    BTree p, lc, rc;

    s = ceil((double)M / 2);
    p = NULL;                //指向p的父节点
    order = -1;              //q为p的第j个关键字

    tag = 0;                //初始化为0

    if(!FoundParent(q,&p,&order))      //只有一个根节点
        tag = 1;
    else
    {
        if(q->keynum>=s)   //q->keynum>=ceil[M/2]
            tag = 2;           //直接删除结点
        else                 //q->keynum=ceil[M/2]-1
        {
            if(tag==0&&order<p->keynum&&p->ptr[order+1]->keynum>=s)
                tag = 3;                  //右兄弟关键字个数>=ceil[M/2]

            if(tag==0&&order>0&&p->ptr[order-1]->keynum>=s)
                tag = 4;                  //左兄弟关键字个数>=ceil[M/2]

            if(tag==0&&order<p->keynum&&p->ptr[order+1]->keynum==s-1)
                tag = 5;                    //右兄弟关键字个数==ceil[M/2]-1

            if(tag==0&&order>0&&p->ptr[order-1]->keynum==s-1)
                tag = 6;                    //左兄弟关键字个数==ceil[M/2]-1
        }
    }

    switch(tag)
    {
        case 1:
           if(q->keynum==1&&i==1)
           {
               *BT = q->ptr[0];
               free(q);
           }
           else
           {
               LeftMove(q, i + 1, q, i, q->keynum - i);
               q->keynum--;
           }
           break;
        case 2:
            LeftMove(q, i + 1, q, i, q->keynum - i);
            q->keynum--;
            break;
        case 3:
            rc = p->ptr[order + 1];
            LeftMove(q, i + 1, q, i, q->keynum - i);
            q->key[q->keynum] = p->key[order + 1];
            q->ptr[q->keynum] = rc->ptr[0];
            p->key[order + 1] = rc->key[1];
            rc->ptr[0] = rc->ptr[1];
            LeftMove(rc, 2, rc, 1, rc->keynum - 1);
            rc->keynum--;
            break;
        case 4:
            lc = p->ptr[order - 1];
            q->ptr[i] = q->ptr[i - 1];      //*
            RightMove(q, i - 1, q, i, i - 1);   //*
            q->key[1] = p->key[order];
            q->ptr[0] = lc->ptr[lc->keynum];         //* 
            p->key[order] = lc->key[lc->keynum];
            lc->keynum--;
            break;
        case 5:
            rc = p->ptr[order + 1];
            LeftMove(q, i + 1, q, i, q->keynum - i);
            q->key[q->keynum] = p->key[order + 1];
            q->ptr[q->keynum] = rc->ptr[0];
            LeftMove(rc, 1, q, q->keynum + 1, rc->keynum);
            q->keynum += rc->keynum;
            free(p->ptr[order + 1]);
            LeftMove(p, order + 2, p, order + 1, p->keynum - order - 1);
            p->keynum--;
            if(p->keynum<s-1)
            {
                p->keynum++;         //构造一个虚拟关键字
                q = p;
                Delete(BT, q, q->keynum);
            }
            break;
        case 6:
            lc = p->ptr[order - 1];
            lc->key[lc->keynum + 1] = p->key[order];
            lc->ptr[lc->keynum + 1] = q->ptr[0];
            LeftMove(q, 1, lc, lc->keynum + 2, i - 1);
            LeftMove(q, i + 1, rc, lc->keynum + i + 1, q->keynum - i);
            lc->keynum += q->keynum;
            free(p->ptr[order]);
            LeftMove(p, order + 1, p, order, p->keynum - order);
            p->keynum--;
            if(p->keynum<s-1)
            {
                p->keynum++;           //构造一个虚拟关键字
                q = p;
                Delete(BT, q, q->keynum);
            }
            break;
    }
}

int SearchMinKey(BTree BT,Result *R)
{
    BTree q = BT;

    while (q&&q->ptr[0])         //向最下层最左端结点移动
    {
        q = q->ptr[0];
    }

    if(q)
    {
        (*R).pt = q;
        (*R).i = 1;
        (*R).tag = 1;
        return 1;
    }
    else
        return 0;
}

int FoundParent(BTree q,BTree *p,int *order)      //B树不为空
{
    *p = q->parent;

    if(*p==NULL)             //q指向根节点
    {
        *order = -1;
        return 0;
    }
    else
    {
        for (*order = 0; (*p)->ptr[*order] != q;(*order)++)
            ;
        return 1;
    }
}

int LeftMove(BTree old_ptr,int m,BTree new_ptr,int n,int len)
{
    int k;

    if(!old_ptr||!new_ptr||m<1||m>old_ptr->keynum)
        return 0;

    for (k = 0; k < len;k++,m++,n++)
    {
        new_ptr->key[n] = old_ptr->key[m];
        new_ptr->ptr[n] = old_ptr->ptr[m];
    }

    return 1;
}

int RightMove(BTree old_ptr,int m,BTree new_ptr,int n,int len)
{
    int k;

    if(!old_ptr||!new_ptr||m<1||m>old_ptr->keynum)
        return 0;

    for (k = 0; k < len;k++,m--,n--)
    {
        new_ptr->key[n] = old_ptr->key[m];
        new_ptr->ptr[n] = old_ptr->ptr[m];
    }

    return 1;
}