#include "statement.h"

//构建图、表
int CreateGraph(FILE *fp,AdjMatrix *G)
{
    fscanf(fp, "%d", &((*G).kind));

    switch ((*G).kind)          //随机创建有向图、网或无向网的一种
    {
    case DG:
        return CreateDG(fp, G);
    case DN:
        return CreateDN(fp, G);
    case UDG:
        return CreateUDG(fp, G);
    case UDN:
        return CreateUDN(fp, G);
    default:
        return -1;
    }
}

//有向图
int CreateDG(FILE *fp,AdjMatrix *G)
{
    int i, j, k;
    VertexData v1, v2;
    char tmp;

    fscanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
        fscanf(fp, "%c", &((*G).vertex[i]));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
    {
        for (j = 1; j <= (*G).vexnum;j++)
            (*G).arcs[i][j].adj = 0;
    }

    for (k = 1; k <= (*G).arcnum;k++)
    {
        fscanf(fp, "%c%c", &v1, &v2);
        fscanf(fp, "%c", &tmp);       //跳过换行符

        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        if(!i||!j)
            return -1;

        (*G).arcs[i][j].adj = 1;
    }

    return 0;
}

//构造有向网
int CreateDN(FILE *fp,AdjMatrix *G)
{
    int i, j, k;
    VertexData v1, v2;
    char tmp;
    AdjType w;

    fscanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
        fscanf(fp, "%c", &((*G).vertex[i]));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)     //初始化临界矩阵
    {
        for (j = 1; j <= (*G).vexnum;j++)
            (*G).arcs[i][j].adj = INFINITY;
    }

    for (k = 1; k <= (*G).arcnum;k++)
    {
        fscanf(fp, "%c%c%d", &v1, &v2,&w);
        fscanf(fp, "%c", &tmp);       //跳过换行符

        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        if(!i||!j)
            return -1;

        (*G).arcs[i][j].adj = w;
    }

    return 0;
}

//构造无向图
int CreateUDG(FILE *fp,AdjMatrix *G)
{
    int i, j, k;
    VertexData v1, v2;
    char tmp;

    fscanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
        fscanf(fp, "%c", &((*G).vertex[i]));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
    {
        for (j = 1; j <= (*G).vexnum;j++)
            (*G).arcs[i][j].adj = 0;
    }

    for (k = 1; k <= (*G).arcnum;k++)
    {
        fscanf(fp, "%c%c", &v1, &v2);
        fscanf(fp, "%c", &tmp);       //跳过换行符

        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        if(!i||!j)
            return -1;

        (*G).arcs[i][j].adj = 1;
        (*G).arcs[j][i] = (*G).arcs[i][j];      //填充对称点
    }

    return 0;
}

//构造无向网
int CreateUDN(FILE *fp,AdjMatrix *G)
{
    int i, j, k;
    VertexData v1, v2;
    char tmp;
    AdjType w;

    fscanf(fp, "%d%d", &((*G).vexnum), &((*G).arcnum));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
        fscanf(fp, "%c", &((*G).vertex[i]));
    fscanf(fp, "%c", &tmp);       //跳过换行符

    for (i = 1; i <= (*G).vexnum;i++)
    {
        for (j = 1; j <= (*G).vexnum;j++)
            (*G).arcs[i][j].adj = INFINITY;
    }

    for (k = 1; k <= (*G).arcnum;k++)
    {
        fscanf(fp, "%c%c%d", &v1, &v2,&w);
        fscanf(fp, "%c", &tmp);       //跳过换行符

        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        if(!i||!j)
            return -1;

        (*G).arcs[i][j].adj = w;
        (*G).arcs[j][i].adj = (*G).arcs[i][j].adj;
    }

    return 0;
}
