#include "statement.h"
#include "stack.h"

//入度算法
void FindID(AdjList G,int indegree[MAX_VERTEX_NUM+1])
{
    int i;
    ArcNode *p;

    for (i = 1; i <= G.vexnum;i++)
        indegree[i] = 0;

    for (i = 1; i <= G.vexnum;i++)
    {
        p = G.vertex[i].firstarc;
        while(p)
        {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
}

//拓扑排序算法
int TopoSort(AdjList G)
{
    SeqStack s;
    int indegree[MAX_VERTEX_NUM + 1];
    int i, count, k;
    ArcNode *p;
    FindID(G, indegree);      //求各顶点入度
    InitStack(&s);

    for (i = 1; i <= G.vexnum;i++)
    {
        if(indegree[i]==0)          //将入度为0的顶点入栈
            push(&s, i);
    }
       
    count = 0;

    while(!IsEmpty_stack(s))
    {
        Pop(&s, &i);
        count++;         //输出i号顶点并计数
        printf("%c  ", G.vertex[i].data);

        p = G.vertex[i].firstarc;
        while(p)
        {
            k = p->adjvex;
            indegree[k]--;
            if(indegree[k]==0)         //若入度减为0，则入栈
                push(&s, k);
            p = p->nextarc;
        }
    }

    if(count<G.vexnum)
        return -1;
    else
        return 1;
}