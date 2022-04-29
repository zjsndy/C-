#include <stdio.h>
#include <stdlib.h>

//哈希表容量递增表,一个合适的素数序列
int hashsize[] = {7, 13, 17, 101, 211, 307, 401, 503, 601, 701, 809, 907, 997};

#define DUPLICATE -1          //表中已存在关键字
#define NULLKEY -2            //标记此处无关键字
#define FULL -3               //表已满(冲突次数达上限就认为表满)
#define EQ(a,b)        ((a)==(b))

typedef struct{
    int key;
} ElemType_Search;

typedef struct{
    ElemType_Search *elem;
    int len;
} Table;

typedef struct{
    int *elem;             //数据元素存储地址,动态分配数组
    int count;            //当前哈希表包含的关键字个数
    int sizeindex;         //hashsize[sizeindex]为当前容量
} HashTable;

void InitHash(HashTable *H);
int CreateHash(HashTable *H, Table T);
int SearchHash(HashTable H, int K, int *p);
int InsertHash(HashTable *H, int K);
int RecreateHashTable(HashTable *H);
int fHash(HashTable H, int K);
void collision(HashTable H, int *p);
void PrintHash(HashTable H);

//初始化一个空的哈希表
void InitHash(HashTable *H)
{
    (*H).count = 0;
    (*H).sizeindex = -1;
    (*H).elem = NULL;
}

int Create(FILE *fp,Table *T,int n)
{
    int i, a;

    T->elem = (ElemType_Search *)malloc((n + 1) * sizeof(ElemType_Search));
    (*T).len = 0;

    for (i = 1; i <= n;i++)
    {
        fscanf(fp, "%d", &a);
        (*T).elem[i].key = a;
        (*T).len++;
    }

    return 1;
}

//创建哈希表
int CreateHash(HashTable *H,Table T)
{
    int i, tag;

    InitHash(H);

    RecreateHashTable(H);

    i = 1;
    while(i<=T.len)             //将关键字依次插入到哈希表中
    {
        tag = InsertHash(H, T.elem[i].key);
        if(tag==1)         //表中已有关键字或关键字顺利插入
            i++;
        else
            i = 1;              //重建哈希表后重新填充
    }

    return 1;
}

//哈希表关键字搜索,p指向查找成功后的元素位置,*c记录发生冲突的次数
int SearchHash(HashTable H,int K,int *p)
{
    int c, sup;

    c = 0;           //记录冲突次数
    sup = hashsize[H.sizeindex] / 2;        //冲突上限
    *p = fHash(H, K);              //p指向K应该插入的位置

    while(1)                    //该位置有记录且与K不等
    {
        if(H.elem[*p]==NULLKEY)
            return NULLKEY;
        else if(EQ(H.elem[*p],K))
            return DUPLICATE;           //表中已有此关键字
        else if(++c==sup)              //已达冲突上限
            return FULL;
        else
            collision(H, p);            //重新定位p的地址
    }
}

//哈希表关键字插入
int InsertHash(HashTable *H,int K)
{
    int flag, p;

    flag = SearchHash(*H, K, &p);

    if(flag==FULL)        //表已满
    {
        RecreateHashTable(H);         //重建哈希表
        return 0;
    }
    else
    {
        if(flag==NULLKEY)
        {
            H->elem[p] = K;              //插入K
            (*H).count++;
        }

        return 1;
    }
}

//重建哈希表
int RecreateHashTable(HashTable *H)
{
    int i, newv;

    (*H).count = 0 ;
    (*H).sizeindex++;
    newv = hashsize[(*H).sizeindex];

    if((*H).elem!=NULL)
        free((*H).elem);

    //扩充了哈希表容量
    (*H).elem = (int *)malloc(newv * sizeof(int));
    if((*H).elem==NULL)
        return 0;

    for (i = 0; i < newv;i++)
        (*H).elem[i] = NULLKEY;

    return 1;
}

//哈希函数
int fHash(HashTable H,int K)  
{
    //简单取余
    return K % hashsize[H.sizeindex];
}

//开放定地址法寻找下一探查位置
void collision(HashTable H,int *p)
{
    //简单位移
    (*p) = (*p + 1) % hashsize[H.sizeindex];
}

//输出哈希表中关键字
void PrintHash(HashTable H)
{
    int i, v;

    v = hashsize[H.sizeindex];

    printf("哈希表容量为:%d , 现有元素:%d 个,表中元素为:\n", v, H.count);

    for (i = 0; i < v;i++)
    {
        if(H.elem[i]!=NULLKEY)
            printf("%d ", H.elem[i]);
    }
}

int main()
{
    FILE *fp = fopen("data.txt", "r");
    HashTable H;
    Table T;
    Create(fp, &T, 20);
    CreateHash(&H, T);
    PrintHash(H);

    fclose(fp);
}