#ifndef __MGraph_H_
#define __MGraph_H_

#include "statement.h"

typedef struct{
    int tag;
} OtherInfo; //弧相关信息 ,可以忽略

typedef struct ArcNode{
    AdjType adj;           //对于无权图，用1或0表示是否相邻；带权图，则为权值类型
    OtherInfo info;
} ArcNode;

typedef struct{
    VertexData vertex[MAX_VERTEX_NUM];    //顶点向量
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //邻接矩阵
    int vexnum, arcnum;        //图的顶点数和弧数
} AdjMatrix;

int visited[MAX_VERTEX_NUM + 1];        //标志数组

//求顶点位置
int LocateVertex(AdjMatrix *G,VertexData v)
{
    for (int i = 1; i <= G->vexnum;i++)
    {
        if(G->vertex[i]==v)
            return i;
    }
    return 0;
}

int CreateUDN(FILE *fp,AdjMatrix *G)
{
    int i, j, k;
    VertexData v1, v2;
    char tmp;
    AdjType w;

    fscanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
        fscanf(fp, "%c", &((*G).vertex[i]));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
    {
        for (j = 1; j <= (*G).vexnum;j++)
            (*G).arcs[i][j].adj = INFINITY;
    }

    for (k = 1; k <= (*G).arcnum;k++)
    {
        fscanf(fp, "%c%c%d", &v1, &v2,&w);
        fscanf(fp, "%c", &tmp);       //跳过换行符

        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        if(!i||!j)
            return -1;

        (*G).arcs[i][j].adj = w;
        (*G).arcs[j][i].adj = (*G).arcs[i][j].adj;
    }

    return 0;
}

#endif