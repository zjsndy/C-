#include "Statement.h"

//递归的先、中、后遍历
void PreOrder(BiTree T)
{
    if(T)
   {
    printf("%c  ", T->data);
    PreOrder(T->LChild);
    PreOrder(T->RChild);
    }
}

void InOrder(BiTree T)
{
    if(T)
    {
    InOrder(T->LChild);
    printf("%c ", T->data);
    InOrder(T->RChild);
    }
}

void PostOrder(BiTree T)
{
    if(T)
    {
    PostOrder(T->LChild);
    PostOrder(T->RChild);
    printf("%c ", T->data);
    }
    
}
