#include "statement.h"
#include "MFSet.h"
#include "MGraph.h"

int Minimum_1(int n)
{
    int min = INT_MAX;
    int j = 0;

    for (int i = 1; i <= n;i++)
    {
        if(closedge[i].lowcost)                //从权值不为0的边中选择拥有最小权值的边
        {
            if(closedge[i].lowcost<=min)
            {
                min = closedge[i].lowcost;
                j = i;
            }
        }
    }

    return j;
}

//普里姆算法
void MinSpanTree_PRIM_1(AdjMatrix *G,VertexData u)
{
    int i, j, k;

    k = LocateVertex(G, u);

  /*********************辅助数组初始化***********************************/
    for (j = 1; j <= G->vexnum;j++)
    {
        if(j!=k)
        {
            closedge[j].adjvex = k;
            closedge[j].lowcost = G->arcs[k][j].adj;
        }
    }

    closedge[k].lowcost = 0;

  /*********************辅助数组初始化***********************************/

    printf("   %c\n", u);
    for (i = 1; i <= G->vexnum - 1;i++)        //总共需要G.vexnum-1次寻找最小边
    {
        k = Minimum_1((*G).vexnum);
        printf("%-2d,%c\n", closedge[k].lowcost, (*G).vertex[k]);

        closedge[k].lowcost = 0;

        for (j = 1; j <= (*G).vexnum;j++)
        {
            if((*G).arcs[k][j].adj<closedge[j].lowcost)   //当前树到某一顶点的最小权值小于上一棵树到某一顶点的最小权值
            {
                closedge[j].adjvex = LocateVertex(G, (*G).vertex[k]);
                closedge[j].lowcost = (*G).arcs[k][j].adj;
            }
        }
    }
}

void Initial(AdjMatrix G,MFSet *S)
{
    FILE *fp;

    fp = tmpfile();

    fprintf(fp, "%d\n", G.vexnum);
    for (int i = 1; i <= G.vexnum;i++)
        fprintf(fp, "%d\n", i);
    fseek(fp, 0, SEEK_SET);

    Initial_mfset(fp, S);
}

//快速排序
void Sort(EdgeSetType EdgeSet[],int left,int right)
{
    int i, j;
    EdgeSetType tmp;

    i = left;
    j = right;

    if(i<j)
    {
        tmp = EdgeSet[left];

        while(i!=j)
        {
            while(i<j&&EdgeSet[j].w>tmp.w)   //从右往左扫描
                j--;

            if(i<j)
            {
                EdgeSet[i] = EdgeSet[j];
                i++;
            }

            while(i<j&&EdgeSet[i].w<tmp.w)     //从左往右扫描
                i++;
            
            if(i<j)
            {
                EdgeSet[j] = EdgeSet[i];
                j--;
            }
        }

        EdgeSet[i] = tmp;      //至此i==j,完成第一轮快排

        Sort(EdgeSet, left, i - 1);
        Sort(EdgeSet, j + 1, right);
    }
}

void BuildRelation(Relation *R,int a,int b)
{
    R->n = 1;
    R->nodes[0].i = a;
    R->nodes[0].j = b;
}

//克鲁斯卡尔算法,并输出T的各条边
void MinSpanTree_KRUSKAL(AdjMatrix G)
{
    int x, y;
    MFSet s;
    Relation R;
    EdgeSetType r[20];

    if(G.vexnum==1)
    {
        printf("此有向网只有一个顶点,其最小生成树为:%c\n", G.vertex[1]);
        return;
    }

    Initial(G, &s);

    int count = 0;

    for (int i = 1; i <= G.vexnum;i++)
    {
        for (int j = i; j <= G.vexnum;j++)
        {
            if(G.arcs[i][j].adj!=INFINITY)
            {
                count++;
                r[count].a = i;
                r[count].b = j;
                r[count].w = G.arcs[i][j].adj;
            }
        }
    }

    Sort(r, 1, G.arcnum);          //对各条边根据权重从小到大排序

    count = 0;          //统计加入树的边数
    for (int i = 1; i <= G.arcnum;i++)
    {
        x = find_mfset(s, r[i].a);
        y = find_mfset(s, r[i].b);

        if(x!=y)        //通过并查集判断加入的边是否回形成回路
        {
            BuildRelation(&R, r[i].a, r[i].b);
            EquivalenceClass_mfset_1(&s, R);

            printf("%c----%c     %2d\n", G.vertex[r[i].a], G.vertex[r[i].b], r[i].w);

            if(++count==G.vexnum-1)
              break;
        }
    }
}