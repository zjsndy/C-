#include "statement.h"

//清空图(网)
void ClearGraph(AdjMatrix *G)
{
    (*G).vexnum = 0;
    (*G).arcnum = 0;
}

//返回第v个结点的值
VertexData GetVex(AdjMatrix G,int order)
{
    if(order>=1&&order<=G.vexnum)
        return G.vertex[order];
    else
        return '\0';
}

//对顶点v赋值value
void PutVex(AdjMatrix *G,VertexData v,VertexData value)
{
   int pos= LocateVertex(G, v);
   if(pos)
       (*G).vertex[pos] = value;
    else
        return;
}

//插入顶点v到图
void InsertVex(AdjMatrix *G,VertexData v)
{
    int t,k;

    if((*G).vexnum==MAX_VERTEX_NUM)   //顶点数已满
        return;

    if((*G).kind%2)             //网
        t = INFINITY;
    else
        t = 0;                  //图

    k = (*G).vexnum + 1;
    (*G).vertex[k]= v;

    for (int i = 1; i <= k;i++)
    {
        (*G).arcs[i][k].adj = t;
        (*G).arcs[k][i].adj = t;
    }

    (*G).vexnum++;
}

//从图中删除顶点v
void DeleteVex(AdjMatrix *G,VertexData v)
{
    int t;
    int pos = LocateVertex(G, v);

    for (int i = pos; i <= G->vexnum-1;i++)
        G->vertex[i] = G->vertex[i + 1];

    if (!pos)
         return;

    if((*G).kind%2)             //网
        t = INFINITY;
    else
        t = 0;                  //图

    for (int i = 1; i <= G->vexnum;i++)
    {
        if((*G).arcs[pos][i].adj!=t)       //计算新的弧数
            (*G).arcnum--;
        
        if((*G).kind==DG||(*G).kind==DN)  //有向
        {
            if((*G).arcs[i][pos].adj!=t)
                (*G).arcnum--;
        }
    }

    for (int i = 1; i <= (*G).vexnum;i++)
    {
        for (int j = pos + 1; j <= (*G).vexnum;j++)
            (*G).arcs[i][j - 1] = (*G).arcs[i][j];
    }

    for (int i = pos + 1; i <= (*G).vexnum ;i++)
    {
        for(int j=1;j<=(*G).vexnum-1;j++)
            (*G).arcs[i - 1][j] = (*G).arcs[i][j];
    }

    (*G).vexnum--;
}

//插入弧<v,w>到图
void InsertArc(AdjMatrix *G,VertexData v,VertexData w,AdjType adj)
{
    int pos1 = LocateVertex(G, v);
    int pos2 = LocateVertex(G, w);

    if(!pos1||!pos2)
        return;

    (*G).arcs[pos1][pos2].adj = adj;

    if((*G).kind==UDG||(*G).kind==UDN)       //无向
        (*G).arcs[pos2][pos1] = (*G).arcs[pos1][pos2];

    (*G).arcnum++;                     //弧数增一
}

//删除弧<v,w>
void DeleteArc(AdjMatrix *G,VertexData v,VertexData w)
{
    int pos1 = LocateVertex(G, v);
    int pos2 = LocateVertex(G, w);

    if(!pos1||!pos2)
        return;

    if((*G).kind%2)         //图
        (*G).arcs[pos1][pos2].adj = INFINITY;
    else
        (*G).arcs[pos1][pos2].adj = 0;

    if((*G).kind==UDG||(*G).kind==UDN)         //无向
        (*G).arcs[pos2][pos1] = (*G).arcs[pos1][pos2];

    (*G).arcnum--;             //弧数减一
}


