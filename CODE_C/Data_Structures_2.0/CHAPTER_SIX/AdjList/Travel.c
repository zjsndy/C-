#include "statement.h"
#include "Sequeue.h"

//返回v的第一个邻接顶点序号
int FirstAdjVex(AdjList G,VertexData v)
{
    int k = Locate(&G, v);

    if(k&&G.vertex[k].firstarc)
        return G.vertex[k].firstarc->adjvex;

    return 0;
}

//返回v相对于w的下一个邻接顶点序号
int NextAdjVex(AdjList G,VertexData v,VertexData w)
{
    int k1 = Locate(&G, v);
    int k2 = Locate(&G, w);
    
    if(!k1||!k2)
        return 0;

    ArcNode *p;
    p = G.vertex[k1].firstarc;

    while(p&&p->adjvex<k2)
    {
        p = p->nextarc;
    }

    if(!p)
        return 0;
    
    if(p->adjvex==k2&&p->nextarc)
        return p->nextarc->adjvex;
}

//深度优先遍历核心函数
void DFS(AdjList G,int v)
{
    int w;
    visited[v] = True;

    printf("%c ", G.vertex[v].data);

    w = FirstAdjVex(G, v);
    while(w)
    {
        if(!visited[w])
            DFS(G, w);

        w = NextAdjVex(G, v, w);
    }

}

//深度优先遍历
void DFSTraverse(AdjList G)
{
    for (int i = 1; i <= G.vexnum;i++)
        visited[i] = False;

    for (int i = 1; i <= G.vexnum;i++)
    {
        if(!visited[i])
            DFS(G, i);
    }
}

//广度优先遍历
void BFSTraverse(AdjList G)
{
    SeqQueue Q;
    InitQueue(&Q);
    QueueElemtType e;
    int w;

    for (int i = 1; i <= G.vexnum;i++)
        visited[i] = False;

    for (int i = 1; i <= G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i] = True;
            printf("%c  ", G.vertex[i].data);
            EnterQueue(&Q, i);
            while(!IsEmpty(&Q))
            {
                DeleteQueue(&Q, &e);
                w = FirstAdjVex(G, i);
                while(w!=0)
                {
                    if(!visited[w])
                    {
                        printf("%c  ", G.vertex[w].data);
                        visited[w] = True;
                        EnterQueue(&Q, w);
                    }

                    w = NextAdjVex(G, i, w);
                }
            }
            
        }
    }
}