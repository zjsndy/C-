#include "statement.h"

int CreateDG(FILE *fp,AdjList *G)
{
    char tmp,v1,v2;
    int k1, k2;
    ArcNode *p,*rear;

    fscanf(fp, "%d", &((*G).vexnum));

    fscanf(fp, "%c", &tmp);

    fscanf(fp, "%d", &((*G).arcnum));

    fscanf(fp, "%c", &tmp);

    for (int i = 1; i <= (*G).vexnum;i++)
    {
        fscanf(fp,"%c",&((*G).vertex[i].data));
        (*G).vertex[i].firstarc = NULL;
    }

    for(int i=1;i<=(*G).arcnum;i++)
    {
        fscanf(fp, "%c", &tmp);

        fscanf(fp, "%c%c", &v1, &v2);
        
        k1 = Locate(G, v1);
        k2 = Locate(G, v2);

        p = (*G).vertex[k1].firstarc;
        rear = NULL;

        while(p)
        {
            rear = p;
            p = p->nextarc;
        }

        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = k2;
        if(rear)
        {
          rear->nextarc = p;
          rear = p;
          rear->nextarc = NULL;
        }
        else
        {
            (*G).vertex[k1].firstarc = p;
            p->nextarc=NULL;
        }
    }

    return 1;
}