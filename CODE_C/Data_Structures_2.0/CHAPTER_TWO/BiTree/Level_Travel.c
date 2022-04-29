#include "Statement.h"
#include "SeqQueue.h"

void PrintFloor(BiTree T)
{
    SeqQueue s;
    InitQueue(&s);

    BiTNode *p = T;
    
    if(p)
    {
        EnterQueue(&s, p);
    }

    while(!IsEmpty(&s))
    {
        printf("%c ", p->data);
        if(p->LChild)
            EnterQueue(&s, p->LChild);
        if(p->RChild)
            EnterQueue(&s, p->RChild);
        DeleteQueue(&s, &p);
        GetHead(&s, &p);
    }
}
