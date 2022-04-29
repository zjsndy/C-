#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct 
{
    int in;
} OtherInfo;

//弧结点
typedef struct ArcNode
{
    int adjvex;        //顶点序号
    struct ArcNode *nextarc;      //指向下一条弧的指针
    OtherInfo info;      //该弧相关信息
}ArcNode;

typedef char VertexData;

//顶点信息
typedef struct VertexNode{
    VertexData data;
    ArcNode *firstarc;
}VertexNode;

#define MAX_VERTEX_NUM 10

//邻接表的存储表示
typedef struct{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum;      //顶点数
    int arcnum;       //弧数
} AdjList;

int visited[MAX_VERTEX_NUM];

int Locate(AdjList *G,VertexData u)
{
    for (int i = 1; i <= G->vexnum;i++)
    {
        if(G->vertex[i].data==u)
            return i;
    }

    return 0;
}

#endif