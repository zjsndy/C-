#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

typedef char VertexData;

typedef struct EdgeNode{
    int mark;   //标记是否被搜素过
    int ivex;
    int jvex;
    struct EdgeNode *ilink;
    struct EdgeNode *jlink;
} EdgeNode;

typedef struct{
    VertexData data;
    EdgeNode *firstedge;
} VertexNode;

typedef struct{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum;
    int arcnum;
} AdjMultiList;

int Locate(AdjMultiList G,VertexData v)
{
    for (int i = 1; i <= G.vexnum;i++)
    {
        if(G.vertex[i].data==v)
            return i;
    }
    return 0;
}

#endif