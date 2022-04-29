#include "statement.h"

int CreateBTree(BTree *BT,FILE *fp)
{
    int i,len,tmp;
    char ch;

    *BT = NULL;

    fscanf(fp, "%d", &len);
    fscanf(fp, "%c", &ch);

    for (i = 1; i <= len;i++)
    {
        fscanf(fp, "%d", &tmp);
        if(!InsertKey(BT,tmp))   //插入失败跳出循环
            break;
    }

    if(i>len)
        return 1;
    else
        return 0;
}

int InsertKey(BTree *BT,KeyType K)
{
    Result R;

    R = SearchBTree(*BT, K);

    if(R.tag==0)             //B树不存在此关键字
    {
        InsertBTree(BT, K, R.pt, R.i);
        return 1;
    }
    else
        return 0;
}

int InsertBTree(BTree *BT,KeyType K,BTree  q,int i)
{
    KeyType x;
    BTree ap;
    int finished;
    int s;

    x = K;
    ap = NULL;
    finished = FALSE;

    while(q && !finished)
    {
        Insert(q, i, x, ap); //将x和ap分别插入到q->key[i+1]和q->ptr[i+1]

        if(q->keynum<M)
            finished = TRUE;          //插入完成
        else
        {
            s = ceil((double)M/2);    //B树结点中关键字个数必须>=M/2-1
            split(q, s, &ap);         //分裂结点*q
            x = q->key[s];           //将q->key[s+1....M],q->ptr[s...M]移入新节点*ap
            q = q->parent;

            if(q)                   //在双亲结点*q中查找x的插入位置
                i = Search(q, x);          
        }
    }

    if(!finished)
        NewRoot(BT, q, x, ap);   //BT是空树(参数q初值为NULL)或者根节点已分裂为结点*q和*ap

    return 1;
}

void Insert(BTree q,int i,KeyType x,BTree ap)
{
    int j;

    for (j = q->keynum; j > i;j--)
    {
        q->key[j + 1] = q->key[j];
        q->ptr[j + 1] = q->ptr[j];
    }

    q->key[i + 1] = x;
    q->ptr[i + 1] = ap;
    q->keynum++;
}

void split(BTree q,int s,BTree *ap)       //s初值为M/2
{
    int i;

    (*ap) = (BTree)malloc(sizeof(BTNode));
    (*ap)->ptr[0] = q->ptr[s];

    for (i =  1; i <= M-s;i++)
    {
        (*ap)->key[i] = q->key[i+s];
        (*ap)->ptr[i] = q->ptr[i+s];
    }

    (*ap)->keynum = M - s;
    q->keynum = s - 1;

    (*ap)->parent = q->parent;

    for (i = 0; i <= (*ap)->keynum;i++)
    {
        if((*ap)->ptr[i])
            (*ap)->ptr[i]->parent = *ap;
    }
}

void NewRoot(BTree *BT,BTree q,int x,BTree ap)        //q初始值为空
{
    BTree p;

    p = (BTree)malloc(sizeof(BTNode));
    p->keynum = 1;
    p->parent = NULL;
    p->key[1] = x;
    p->ptr[0] = *BT;
    p->ptr[1] = ap;

    if(p->ptr[0])
        p->ptr[0]->parent = p;
    if(p->ptr[1])
        p->ptr[1]->parent = p;

    *BT = p;
}