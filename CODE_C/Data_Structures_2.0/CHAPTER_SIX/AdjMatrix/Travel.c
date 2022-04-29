#include "statement.h"

//返回v的第一个邻接顶点序号
int FirstAdjVex(AdjMatrix G,VertexData v)
{
    int pos = LocateVertex(&G, v);
    int t;

    if(pos)
    {
        if(G.kind%2)        //网
            t = INFINITY;     
        else
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
        if(G.kind%2)
            t = INFINITY;       //网
        else
            t = 0;              //图
    }

    for (int i = pos2 + 1; i <= G.vexnum;i++)
    {
        if(G.arcs[pos1][i].adj!=t)
            return i;
    }

    return 0;
}



//深度优先遍历核心函数
void DFS(AdjMatrix G,int i)
{
    printf("%c ", G.vertex[i]);

    int w;

    visited[i] = True;

    w = FirstAdjVex(G, G.vertex[i]);
    while (w!=0)
    {
       if(!visited[w])
       {
           DFS(G, w);  
       }

       w = NextAdjVex(G, G.vertex[i], G.vertex[w]);
    }
}

//深度优先遍历
void DFSTraverse(AdjMatrix G)
{
    for (int i = 1; i <= G.vexnum;i++)
        visited[i] = False;

    for (int i = 1; i <= G.vexnum;i++)
    {
        if(!visited[i])        //未访问
            DFS(G, i);
    }
}

//深度优先遍历-------非递归
void DFS_2(AdjMatrix G,int v0)
{
    for (int i = 1; i <= G.vexnum;i++)
        visited[i] = False;

    int v,w;
    SeqStack s;
    InitStack(&s);
    push(&s, v0);
    while(!IsEmpty_stack(s))
    {
        Pop(&s, &v);
        if(!visited[v])
        {
            printf("%c ", visited[v]);
        }

        visited[v] = True;

        w = FirstAdjVex(G, G.vertex[v]);
        while(w!=0)
        {
            if(!visited[w])
                push(&s, w);
            w = NextAdjVex(G, G.vertex[v], G.vertex[w]);
        }
    }
}


//广度优先遍历
void BFSTraverse(AdjMatrix G)
{
    int e,w;
    SeqQueue Q;

    for (int i = 1; i <= G.vexnum;i++)
        visited[i] = False;        //初始化未访问

    InitQueue(&Q);

    for (int i = 1; i <= G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i] = True;
            printf("%c  ", G.vertex[i]);
            EnterQueue(&Q, i);
            while (!IsEmpty(&Q))
            {
                DeleteQueue(&Q, &e);
                w = FirstAdjVex(G, G.vertex[i]);
                while(w!=0)
                {
                    if(!visited[w])
                    {
                        printf("%c ", G.vertex[w]);
                        visited[w] = True;
                        EnterQueue(&Q, w);
                    }

                    w = NextAdjVex(G, G.vertex[i], G.vertex[w]);
                }
            }
            
        }
    }
}
