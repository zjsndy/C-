#include "statement.h"
#include "build.c"

//最短路径
int dist[MAX_VERTEX_NUM];

//前驱节点
int path[MAX_VERTEX_NUM];

//返回v的第一个邻接顶点序号
int FirstAdjVex(AdjMatrix G,VertexData v)
{
    int pos = LocateVertex(&G, v);
    int t;

    if(pos)
    {
        t = 0;          //图

        for (int j = 1; j <= G.vexnum;j++)
        {
            if(G.arcs[pos][j].adj!=t)
                return j;
        }
    }

    return 0;
}

//返回v的相对于w的下一个邻接顶点序号
int NextAdjVex(AdjMatrix G,VertexData v,VertexData w)
{
    int pos1, pos2;
    int t;

    pos1 = LocateVertex(&G, v);
    pos2 = LocateVertex(&G, w);

    if(pos1&&pos2)
    {
        t = 0;              //图
    }

    for (int i = pos2 + 1; i <= G.vexnum;i++)
    {
        if(G.arcs[pos1][i].adj!=t)
            return i;
    }

    return 0;
}

//从顶点v到其它顶点的最短路径
void BFSMinDist(AdjMatrix G,char v) 
{
    for (int i = 0; i < MAX_VERTEX_NUM;i++)
    {
        visited[i] = False;
        dist[i] = -1;
        path[i] = -1;
    }

    SeqQueue Q;
    int w;
    char u;
    InitQueue(&Q);

    int pos = LocateVertex(&G, v);

    dist[pos] = 0;         //顶点v的路径为0
    visited[pos] = True;   //顶点v为已访问
    EnterQueue(&Q, v);   //顶点v入队

    while(!IsEmpty(&Q))
    {
        DeleteQueue(&Q, &u);
        for (w = FirstAdjVex(G, u); w > 0;w=NextAdjVex(G,u,G.vertex[w]))
        {
            if(!visited[w])
            {
                dist[w] = dist[LocateVertex(&G,u)] + 1;
                path[w] = LocateVertex(&G,u);
                visited[w] = True;
                EnterQueue(&Q, G.vertex[w]);
            }
        }
    }
}