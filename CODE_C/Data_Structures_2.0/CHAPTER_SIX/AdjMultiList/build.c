#include "statement.h"

void createUDG(FILE *fp,AdjMultiList *G)
{
    char tmp,v1,v2;
    int k1, k2;
    fscanf(fp, "%d", &((*G).vexnum));

    fscanf(fp, "%c", &tmp);

    fscanf(fp, "%d", &((*G).arcnum));

    fscanf(fp, "%c", &tmp);

    for (int i = 1; i <= (*G).vexnum;i++)
    {
        fscanf(fp, "%c", &((*G).vertex[i].data));
        (*G).vertex[i].firstedge = NULL;
    }
    
    for (int i = 1; i <= (*G).arcnum;i++)
    {
        EdgeNode *p,*q,*m;
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
       
        fscanf(fp, "%c", &tmp);
        fscanf(fp, "%c%c", &v1, &v2);

        k1 = Locate(*G, v1);
        k2 = Locate(*G, v2);

        p->mark = 0;
        p->ivex = k1;
        p->jvex = k2;
        p->ilink = NULL;
        p->jlink = NULL;

       if((*G).vertex[k1].firstedge==NULL)
          (*G).vertex[k1].firstedge = p;
        else
        {
            q = (*G).vertex[k1].firstedge;

            while(q)
            {
                m = q;
                if(q->ivex==k1)
                   q = q->ilink;
                else
                    q = q->jlink;
            }

            if(m->ivex==k1)
                m->ilink = p;
            else
                m->jlink = p;
        }

        
       if((*G).vertex[k2].firstedge==NULL)
          (*G).vertex[k2].firstedge = p;
        else
        {
            q = (*G).vertex[k2].firstedge;
            while(q)
            {
                m = q;
                m = q;
                if(q->ivex==k1)
                   q = q->ilink;
                else
                    q = q->jlink;
            }

            
            if(m->ivex==k1)
                m->ilink = p;
            else
                m->jlink = p;
        }
    }
}