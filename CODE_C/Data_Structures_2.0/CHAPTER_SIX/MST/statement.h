#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define INFINITY INT_MAX      //表示最大值
typedef char VertexData;
typedef int AdjType;   

struct{
    int adjvex;        //较早加入当前边的端点
    AdjType lowcost;
} closedge[MAX_VERTEX_NUM];

typedef struct{
    int a, b;            //端点
    int w;               //权值
} EdgeSetType;

#endif