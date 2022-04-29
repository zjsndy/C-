/*************************************************************
*  FileName:   MFSet.c
*  Date:       2022-03-26 16:30:18
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_TWO
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h>
#define MAX_TREE_SIZE  20    //树的最大结点数

typedef int TElemType_p;        //假设集合中元素均为整数

typedef struct PTNode
{
    TElemType_p data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];  //根节点位置默认到0
    int n;                       //树的结点数
} PTree;

typedef PTree MFSet;

//二元关系
typedef struct 
{
    int i;
    int j;
}Node; 

//等价关系
typedef struct 
{
    Node nodes[MAX_TREE_SIZE];      //足够大的集合空间
    int n;
}Relation;

void Initial_mfset(FILE *fp,MFSet *s)
{
    int i;

    fscanf(fp, "%d", &(s->n));//nodes[0]弃用

    for (i = 1; i <= s->n;i++)
    {
        fscanf(fp, "%d", &i);
        s->nodes[i].data = i;
        s->nodes[i].parent = -1;
    }
}

//查找集合s中i所在子集的根
int find_mfset(MFSet s,int i)
{
    int j;

    if(i<1||i>s.n)         //i不属于s中任一子集
        return -1;

    for (j = i; s.nodes[j].parent > 0;j=s.nodes[j].parent)
        ;

    return j;
}

//求si和sj的并集,si和sj无交集
int merfe_mfset(MFSet *s,int i,int j)
{
    if(i<1||j<1||i>s->n||j>s->n)
        return 0;

    if(i!=j)
        s->nodes[i].parent = j;   //固定将集合si并入sj
    return 1;
}

//集合归并函数,算法上面的改进
int mix_mfset(MFSet *s,int i,int j)
{
     if(i<1||j<1||i>s->n||j>s->n)
        return 0;
     

     if(s->nodes[i].parent>s->nodes[j].parent)
     {
         s->nodes[j].parent += s->nodes[i].parent;
         s->nodes[i].parent = j;      //将si并入sj
     }
     else
     {
         s->nodes[i].parent += s->nodes[j].parent;
         s->nodes[j].parent = i;   //将sj并入si
     }

     return 1;
}

//查找集合s中i所在子集的根
int fix_mfset(MFSet *s,int i)
{
    int j, k, t;            //将i至根路径上所有结点压缩为根的孩子结点

    if(i<1||i>s->n)
        return -1;         //i不属于s中任一子集

    for (j = i; s->nodes[j].parent > 0;j=s->nodes[j].parent) //找到i所在子集根节点
        ;

    for (k = i; k != j;k=t)        //顺便压缩路径
    {
        t = s->nodes[k].parent;      //t为当前结点的父节点
        s->nodes[k].parent = j;
    }

    return j;
}

//建立二元等价关系
int BuildRelation_mfset(FILE *fp,Relation *R)
{
    int k;

    fscanf(fp, "%d", &(R->n));
    if(R->n<0)
        return 0;

    for (k = 1; k <= R->n;k++)
        fscanf(fp, "%d%d", &(R->nodes[k - 1].i), &(R->nodes[k - 1].j));

    return 1;
}

//求在等价关系R下集合s的等价类（1）
int EquivalenceClass_mfset_1(MFSet *s,Relation R)
{
    int k, x, y;

    for (k = 0; k < R.n;k++)
    {
        x = find_mfset(*s, R. nodes[k].i);     //分别求取当前元素所属子集
        y = find_mfset(*s, R.nodes[k].j);
        merfe_mfset(s, x, y);       //合并子集
    }

    return 1;
}

//求在等价关系R下集合s的等价类（2）
int EquialenClass_mfset_2(MFSet *s,Relation R)
{
    int k, x, y;

    for (k = 0; k < R.n;k++)
    {
        x = fix_mfset(s, R.nodes[k].i);    //分别求取当前元素所属子集
        y = fix_mfset(s, R.nodes[k].j);
        mix_mfset(s, x, y);            //合并子集
    }

    return 1;
}

//返回集合s中非空子集数目
int SubsetCount_mfset(MFSet s)
{
    int i, count;

    for (i = 1, count = 0; i <= s.n;i++)
    {
        if(s.nodes[i].parent<0)
            count++;
    }

    return count;
}

//展示集合s
void ShowSet_mfset(MFSet s)
{
    int i, j, k, count;
    int a[MAX_TREE_SIZE][MAX_TREE_SIZE]={0}  ;
    int tmp[MAX_TREE_SIZE]={0}  ;

    for (i = 1; i <= s.n;i++)
    {
        j = find_mfset(s, i);         //判断第i个结点属于哪个集合
        if(j>0)
        {
            tmp[j]++;
            a[j][tmp[j]] = s.nodes[i].data;
        }
    }

    k = SubsetCount_mfset(s);         //子集个数

    printf("{");
    count = 0;

    for (i = 1; i <= s.n;i++)
    {
        for (j = 1; j <= s.n;j++)
        {
            if(a[i][j])
            {
                if(j==1)     //某集合第一个元素
                    printf("{%d", a[i][j]);     //某集合第一个元素
                else
                    printf(",%d", a[i][j]);

                if(j==tmp[i])           //某集合最后一个元素
                {
                    count++;
                    printf("}");
                    if(count!=k)
                        printf(", ");       //子集之间要隔开
                }
            }
        }
    }

    printf("}\n");
}

int main ()
{
    FILE *fp;
    MFSet s;

    fp = fopen("TestData_s.txt", "r");
    Initial_mfset(fp, &s);
    fclose(fp);

   // ShowSet_mfset(s);

    Relation R1;
    fp = fopen("TestData_R1.txt", "r");
    BuildRelation_mfset(fp, &R1);
    fclose(fp);
    EquivalenceClass_mfset_1(&s, R1);
    //ShowSet_mfset(s);

    Relation R2;

    fp = fopen("TestData_R2.txt", "r");
    BuildRelation_mfset(fp, &R2);
    fclose(fp);
    EquialenClass_mfset_2(&s, R2);
    ShowSet_mfset(s);

    system("pause");
    return 0;
}