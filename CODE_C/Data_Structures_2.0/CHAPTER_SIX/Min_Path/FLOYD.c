#include "statement.h"

//用Floyd算法求有向图G中各对顶点v和w之间的最短路径p[v][v]及其带权长度D[v][w]
void Floyd(AdjMatrix G,PathMatrix path[][MAX_VERTEX_NUM+1],ShortPathTable dist[][MAX_VERTEX_NUM+1])
{
    int i, j, k;

    for (i = 1; i <= G.vexnum;i++)
    {
        for (j = 1; j <= G.vexnum;j++)
        {
            dist[i][j] = G.arcs[i][j].adj;
            path[i][j] = -1;
        }
    }

    for (k = 1; k <= G.vexnum;k++) //以k为中间点检测各对顶点间距离
    {
        for (i = 1; i <= G.vexnum;i++)
        {
            for (j = 1; j <= G.vexnum;j++)
            {
                if(i!=j&&dist[i][k]<INFINITY&&dist[k][j]<INFINITY&&dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    //输出各对顶点之间的路径
    for (i = 1; i <= G.vexnum;i++)
    {
        for (j = 1; j <= G.vexnum;j++)
        {
            if(i!=j)
            {
                printf("%c 到 %c 的最短路径为: ", G.vertex[i], G.vertex[j]);

                if(dist[i][j]!=INFINITY)
                {
                    printf("%c ", G.vertex[i]);
                    k = i;
                    while(path[k][j]!=-1)
                    {
                        printf("%c ", G.vertex[path[k][j]]);
                        k = path[k][j];
                    }
                    printf("%c ", G.vertex[j]);
                }
                else
                    printf("X");

                printf(",权值为: ");
                if(dist[i][j]==INFINITY)
                    printf("#\n");
                else
                    printf("%d\n", dist[i][j]);
            }
        }
    }
}