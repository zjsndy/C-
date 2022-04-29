#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

typedef char VertexData;

typedef struct {
    int i;
} InfoType;

typedef struct ArcNode{
    int tailvex;      //弧的起点
    int headvex;      //弧的终点
    struct ArcNode *hlink;    //入度的下一条弧
    struct ArcNode *tlink;    //出度的下一条弧
    InfoType info;
} ArcNode;

typedef struct VertexNode{
    VertexData data;
    ArcNode *firstin;   //入度
    ArcNode *firstout;  //出度
} VertexNode;

typedef struct{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum;  //顶点数
    int arcnum;  //弧数
} OrthList;

int Locate(OrthList G,VertexData v)
{
    for (int i = 1; i <= G.vexnum;i++)
    {
        if(G.vertex[i].data==v)
            return i;
    }
    return 0;
}

#endif