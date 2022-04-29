#include "statement.h"

//清空图
void Clear(AdjList *G)
{
    ArcNode *p, *q;

    for (int i = 1; i <= (*G).vexnum;i++)
    {
        p = (*G).vertex[i].firstarc;
        while(p)
        {
            q = p;
            p = p->nextarc;
            free(q);
        }
    }

    (*G).vexnum = 0;
    (*G).arcnum = 0;
}

//返回第v个结点的值
VertexData GetVex(AdjList G,int order)
{
 if(order>=1&&order<=G.vexnum)
    return G.vertex[order].data;
 else
     return 0;
}

//对顶点v赋值value
int PutVex(AdjList *G,VertexData v,VertexData value)
{
    int pos = Locate(G, v);
    
    if(pos)
    {
        (*G).vertex[pos].data = value;
        return 1;
    }
    else
        return 0;
}

//插入顶点v到图
int InsertVex(AdjList *G,VertexData v)
{
   if((*G).vexnum==MAX_VERTEX_NUM)
       return 0;

   (*G).vexnum++;

   (*G).vertex[(*G).vexnum].data = v;
   (*G).vertex[(*G).vexnum].firstarc = NULL;

   return 1;
}

//删除弧<v,w>
int DeleteArc(AdjList *G,VertexData v,VertexData w)
{
    ArcNode *p, *q;

    int k1 = Locate(G, v);
    int k2 = Locate(G, w);
    
    if(!k1||!k2)
        return -1;

    p = (*G).vertex[k1].firstarc;
    if(p&&p->adjvex==k2)
    {
        (*G).vertex[k1].firstarc = p->nextarc;
        free(p);
    }
    else
    {
        while(p&&p->adjvex!=k2)
        {
            q = p;
            p = p->nextarc;
        }

        if(!p)          //待删除的边不存在
            return -1;
        else
        {
            q->nextarc = p->nextarc;
            free(p);
        }
    }

    if((*G).kind==UDG)
    {

      p = (*G).vertex[k2].firstarc;
      if(p&&p->adjvex==k1)
      {
        (*G).vertex[k2].firstarc = p->nextarc;
        free(p);
      }
      else
      {
        while(p&&p->adjvex!=k1)
        {
            q = p;
            p = p->nextarc;
        }

        if(!p)          //待删除的边不存在
            return -1;
        else
        {
            q->nextarc = p->nextarc;
            free(p);
        }
     }
    }

    (*G).arcnum--;
    return 1;
}

//从图中删除顶点v
int DeleteVex(AdjList *G,VertexData v)
{
    ArcNode *p, *q;
    int pos = Locate(G, v);

    p = (*G).vertex[pos].firstarc;        //释放v的邻接表
    while(p)
    {
        q = p;
        p = p->nextarc;
        DeleteArc(G, v, G->vertex[q->adjvex].data);
    }

    for (int i = pos; i < (*G).vexnum;i++)
        (*G).vertex[i] = (*G).vertex[i + 1];

    (*G).vexnum--;

    if((*G).kind==DG)
    {
        for (int i = 1; i <= (*G).vexnum;i++)
        {
            p = (*G).vertex[i].firstarc;

            while(p&&p->adjvex<pos)
            {
                q = p;
                p = p->nextarc;
            }

            if(p)
            {
                if(p->adjvex==pos)
                {
                    if(p==(*G).vertex[i].firstarc)   //删除首节点
                        (*G).vertex[i].firstarc = p->nextarc;
                    else
                        q->nextarc = p->nextarc;

                    free(p);
                    (*G).arcnum--;
                }
            }
        }
    }
    return 1;
}

//插入弧<v,w>到图
int InsertArc(AdjList *G,VertexData v,VertexData w)
{
    ArcNode *p,*q;
    int k1 = Locate(G, v);
    int k2 = Locate(G, w);

    if(!k1||!k2)
        return 0;

    p = (*G).vertex[k1].firstarc;
    if(!p)
    {
        (*G).vertex[k1].firstarc->adjvex = k2;
        (*G).vertex[k1].firstarc->nextarc = NULL;
    }

    while(p&&p->adjvex<k2)
    {
        q = p;
        p = p->nextarc;
    }

    if(!p)
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = k2;
        p->nextarc = NULL;
        q->nextarc = p;
    }

    if(p->adjvex>k2)
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = k2;
        p->nextarc = q->nextarc;
        q->nextarc = p;
    }
    
    if((*G).kind==UDG)
    {
      p = (*G).vertex[k2].firstarc;
      if(!p)
      {
        (*G).vertex[k2].firstarc->adjvex = k1;
        (*G).vertex[k2].firstarc->nextarc = NULL;
      }

      while(p&&p->adjvex<k1)
      {
        q = p;
        p = p->nextarc;
      }

      if(!p)
      {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = k1;
        p->nextarc = NULL;
        q->nextarc = p;
      }

      if(p->adjvex>k1)
      {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = k1;
        p->nextarc = q->nextarc;
        q->nextarc = p;
      }

    }

    (*G).arcnum++;
    return 1;
}


