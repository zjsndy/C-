#ifndef __MFSet_H_
#define __MFSet_H_

#include "statement.h"

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

#endif