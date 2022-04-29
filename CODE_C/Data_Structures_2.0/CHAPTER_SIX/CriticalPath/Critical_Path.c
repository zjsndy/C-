#include "statement.h"
#include "stack.h"

SeqStack T;

int ve[MAX_VERTEX_NUM + 1];        //各事件(顶点)的最早发生时间
int vl[MAX_VERTEX_NUM + 1];        //各事件(顶点)的最迟发生时间

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

int TopoOrder(AdjList G,SeqStack *T)
{
    SeqStack s;
    ArcNode *p;
    int i, j, k;
    int count, indegree[MAX_VERTEX_NUM + 1];

    FindID(G, indegree);
    InitStack(&s);
    InitStack(T);

    for (i = 1; i <= G.vexnum;i++)
    {
        if(indegree[i]==0)
            push(&s, i);

        ve[i] = 0;
    }

    count = 0;

    while(!IsEmpty_stack(s))
    {
        Pop(&s, &j);
        push(T, j);
        count++;

        p = G.vertex[j].firstarc;
        while(p)
        {
            k = p->adjvex;
            indegree[k]--;

            if(indegree[k]==0)
                push(&s, k);

            //按拓扑顺序计算事件最早发生时间
            if(ve[j]+p->info.in>ve[k])
                ve[k] = ve[j] + p->info.in;

            p = p->nextarc;
        }
    }

    if(count<G.vexnum)
        return 0;
    else
        return 1;
}

int CriticalPath(AdjList G)
{
    int i, j, k;
    ArcNode *p;
    int dut;
    int ee, el;
    char tag;

    if(!TopoOrder(G,&T))
        return 0;

    //将各顶点事件的最迟发生时间初始化为汇点的最早发生时间
    for (i = 1; i <= G.vexnum;i++)
        vl[i] = ve[G.vexnum];
    
    //按逆拓扑顺序求各顶点的vl值
    while(!IsEmpty_stack(T))
    {
        Pop(&T, &j);
        p = G.vertex[j].firstarc;
        while(p)
        {
            k = p->adjvex;
            dut = p->info.in;
            if(vl[k]-dut<vl[j])
                vl[j] = vl[k] - dut;
            p = p->nextarc;
        }
    }
    
    //求ei,ej和关键活动
    for (j = 1; j <= G.vexnum;j++)
    {
        p = G.vertex[j].firstarc;
        while(p)
        {
            k = p->adjvex;
            dut = p->info.in;

            ee = ve[j];
            el = vl[k] - dut;
            tag = (ee == el) ? '*' : ' ';  //用*标记关键活动

            if(tag=='*')
                 printf("%c, %c , %d , %d , %d , %c\n", G.vertex[j].data, G.vertex[k].data, dut, ee, el, tag);
            p = p->nextarc;
        }
    }

    return 1;
}