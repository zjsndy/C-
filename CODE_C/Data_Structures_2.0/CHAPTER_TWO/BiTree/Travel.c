#include "stack.h"

void PreOrder_1(BiTree T)
{
   SeqStack s;
   InitStack(&s);
   BiTNode *p = T;

   while(p!=NULL||!IsEmpty_stack(s))
   {
      while(p)     //先遍历左孩子
      {
         printf("%c ", p->data);
         push(&s, p);
         p = p->LChild;
      }
   
      if(!IsEmpty_stack(s))       //当左孩子遍历完后，取顶栈，找右孩子
      {
          Pop(&s, &p);
          p = p->RChild;
      }
   }
}

void InOrder_1(BiTree T)
{
    SeqStack s;
    InitStack(&s);
    BiTNode *p = T;
    
    while(p!=NULL||!IsEmpty_stack(s))
    {
         if(p)
         {
            push(&s, p);
            p = p->LChild;
         }
         else
         {
            Pop(&s, &p);
            printf("%c ", p->data);
            p = p->RChild;
         }
    }
}

void PostOrder_1(BiTree T)
{
   BiTNode *p, *q;
   SeqStack s;
   InitStack(&s);
   q = NULL;
   p = T;
   while(p!=NULL||!IsEmpty_stack(s))
   {
      if(p)
      {
         push(&s, p);
         p = p->LChild;
      }

      else
      {
         GetTop(&s, &p);
         if(!p->RChild||p->RChild==q)
         {
            printf("%c ", p->data);
            q = p;
            Pop(&s, &p);
            p = NULL;
         }
         else
            p = p->RChild;
      }
   }
}