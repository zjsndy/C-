#include "statement.h"

//用Dijkstra算法求有向图G的v0顶点到其余顶点v的最短路径p[v]及其带权长度D[v]
//二维数组p中,第i行存储v0到vi经过的结点(结点无序)
//一维数组D中,D[i]存储v0到vi的最短路径长度
void ShortestPath_DIJ(AdjMatrix G,int v0,PathMatrix p[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1],ShortPathTable D[])
{
    int v, w, i, j, min;
    int final[MAX_VERTEX_NUM + 1];          //标记当前结点是否已加入最短路径

/*******************************************************************/
    for (v = 1; v <= G.vexnum;v++)
    {
        final[v] = False;  //final[v]为TRUE当且仅当v属于s，即已经求得从v0到v的最短路径
        D[v] = G.arcs[v0][v].adj;

        for (w = 1; w <= G.vexnum;w++)    //p[v][w]为True,w是从v0到v当前求得最短路径上的顶点
            p[v][w] = False;      //设空路径
        
        if(D[v]<INFINITY)
        {
            p[v][v0] =  True;       //v跟v0连通时,v0是从v0到v上的点
            p[v][v] = True;
        }
    }
/*****************************************************************/

    D[v0] = 0;             //初始化,v0顶点属于s集
    final[v0] = True;

    //开始主循环,每次求得v0到某个v顶点的最短路径,并加v到s集
    for (i = 2; i <= G.vexnum;i++)
    {
        min = INFINITY;          //当前所知离v0顶点的最近距离

        for (w = 1; w <= G.vexnum;w++)
        {
            if(!final[w])          //w顶点在v-s中
            {
                if(D[w]<min)     //w顶点里v0顶点更近
                {
                    v = w;
                    min = D[w];     //选出当前状态下v0到各个顶点距离的最小值
                }
            }
        }

        final[v] = True;     //离v0顶点最近的v加入s集

        for (w = 1; w <= G.vexnum;w++) //更新当前最短路径及距离
        {
           if(!final[w]&&min<INFINITY&&G.arcs[v][w].adj<INFINITY&&(min+G.arcs[v][w].adj<D[w]))
           {
              D[w] = min + G.arcs[v][w].adj;       //修改D[w]和p[w] ,w属于V-S
              for (j = 1; j <= G.vexnum;j++)
                 p[w][j] = p[v][j];

               p[w][w] = True;    //p[w]=p[v]+p[w]
            }
        }
    }
}

//输出用DJS算法求出的有向图路径
void OutputPath_DIJ(AdjMatrix G,int v0,PathMatrix p[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1],ShortPathTable D[])
{
    int i, j, k, tmp;
    int count[MAX_VERTEX_NUM + 1];
    int order[MAX_VERTEX_NUM + 1];

    for (i = 1; i <= G.vexnum;i++)
    {
        order[i] = i;
        count[i] = 0;
        for (j = 1; j <= G.vexnum;j++)
        {
            if(p[i][j])
                count[i]++;
        }
    }

    for (i = 1; i <= G.vexnum;i++)
    {
        for (j = i + 1; j <= G.vexnum;j++)
        {
            if(count[j]<count[i])
            {
                tmp = count[i];
                count[i] = count[j];
                count[j] = tmp;

                for (k = 1; k <= G.vexnum;k++)
                {
                    tmp = p[k][i];
                    p[k][i] = p[k][j];
                    p[k][j] = tmp;
                }

                tmp = order[i];
                order[i] = order[j];
                order[j] = tmp;
            }
        }
    }

    for (i = 1; i <= G.vexnum;i++)
    {
        if(order[i]!=v0)
        {
            printf("%c 到 %c 的最短路径为: ", G.vertex[v0], G.vertex[order[i]]);

            if(!count[i])
                printf("X");
            else
            {
                for (j = 1; j <= G.vexnum;j++)
                {
                    if(p[order[i]][j])
                        printf("%c ", G.vertex[order[j]]);
                }
            }

            printf(", 权值为: ");
            if(D[order[i]]<INFINITY)
                printf("%2d\n", D[order[i]]);
            else
                printf("#\n");
        }
    }
}

//另一种写法
void DIJ(AdjMatrix G,int v0,PathMatrix path[],ShortPathTable dist[])
{
    int set[MAX_VERTEX_NUM + 1];          //set[i]:标记数组，标记各顶点是否已加入路径
    int min, i, j, v;
    int tmp[MAX_VERTEX_NUM + 1], k;

    for (i = 1; i <= G.vexnum;i++)           //数组初始化
    {
        dist[i] = G.arcs[v0][i].adj;       //dist[i],v0到i的最短路径长度
        set[i] = 0;                      //set[i]:标记数组，标记各顶点是否已加入路径
        if(G.arcs[v0][i].adj<INFINITY)
            path[i] = v0;            //path[i]:保存从v0到vi路径上vi的前一个顶点
        else
            path[i] = -1;           //代表v0到vi中间不经过任何顶点(可能不通,也可能是自身)
    }

    set[v0] = 1;
    path[v0] = -1;

    for (i = 1; i <= G.vexnum;i++)
    {
        min = INFINITY;

        for (j = 1; j <= G.vexnum;j++)    //选出v0到剩余顶点中最短的一条路径
        {
            if(!set[j]&&dist[j]<min)
            {
                v = j;
                min = dist[j];        //v0到剩余顶点的最短路径<v0,v>
            }
        }

        set[v] = 1;                 //将顶点v加入最短路径

        for (j = 1; j <= G.vexnum;j++)     //判断v的加入是否会造就v0到剩余顶点的更短路径
        {
            if (!set[j] && min < INFINITY&&G.arcs[v][j].adj<INFINITY&&(min+G.arcs[v][j].adj)<dist[j])
            {
                dist[j] = min + G.arcs[v][j].adj;
                path[j] = v;
            }
        }
    }

    //输出路径
    for (i = 1; i <= G.vexnum;i++)
    {
        if(v0!=i)
        {
            printf("%c  到   %c 的路径为:", G.vertex[v0], G.vertex[i]);

            if(path[i]==-1)
                printf("X");
            else
            {
                tmp[0] = 0;           //计算路径上的顶点个数

                if(v0!=i)
                {
                    k = i;
                    do{
                        tmp[0]++;
                        tmp[tmp[0]] = k;
                        k = path[k];
                    } while (path[k] != -1);
                }

                 printf("%c ", G.vertex[v0]);

                if(tmp[0])
                {
                  for (j = tmp[0]; j >= 1;j--)
                    printf("%c ", G.vertex[tmp[j]]);
                }
            }

            printf(", 权长为: ");
            if(dist[i]==INFINITY)
                printf("#\n");
            else
                printf("%2d\n", dist[i]);
        }

    }
}