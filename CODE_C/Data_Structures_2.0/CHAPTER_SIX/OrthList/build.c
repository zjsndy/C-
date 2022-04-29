#include "statement.h"

void CreateDG(FILE *fp,OrthList *G)
{
    char tmp;
    char v1, v2;
    fscanf(fp,"%d",&((*G).vexnum));

    fscanf(fp, "%c", &tmp);

    fscanf(fp, "%d", &((*G).arcnum));

    fscanf(fp, "%c", &tmp);

    for (int i = 1; i <= (*G).vexnum;i++)
    {
        fscanf(fp, "%c", &((*G).vertex[i].data));
        (*G).vertex[i].firstin = NULL;
        (*G).vertex[i].firstout = NULL;
    }

    for (int i = 1; i <= (*G).arcnum;i++)
    {
        fscanf(fp, "%c", &tmp);

        fscanf(fp, "%c%c", &v1, &v2);

        int k1 = Locate(*G, v1);
        int k2 = Locate(*G, v2);

        ArcNode *p,*q,*m;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->tailvex = k1;
        p->headvex = k2;
        p->hlink = NULL;
        p->tlink = NULL;

        if((*G).vertex[k1].firstout==NULL)
            (*G).vertex[k1].firstout = p;
        else
        {
            q = (*G).vertex[k1].firstout;
            while(q)
            {
                m = q;
                q = q->tlink;
            }

            m->tlink = p;
        }

        if((*G).vertex[k2].firstin==NULL)
            (*G).vertex[k2].firstin = p;

        else
        {
            q = (*G).vertex[k2].firstin;
            while(q)
            {
                m = q;
                q = q->hlink;
            }

            m->hlink = p;
        }
    }
}