#ifndef __statement_H_
#define __statement_H_

#include <stdio.h> 
#include <stdlib.h> 
#include "Sequeue.h"

#define MAX_VERTEX_NUM  20 //最多顶点个数
#define INFINITY INT_MAX      //表示最大值

#define True 1
#define False 0

typedef int PathMatrix;
typedef int ShortPathTable;

typedef char VertexData;       //假设顶点数据为字符型
typedef int AdjType;          //图、表顶点关系类型
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

#endif