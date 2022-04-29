#ifndef __stack_H_
#define __stack_H_
#include "Statement.h"

#define Stack_Size 5
typedef BiTNode* StackElementType;

typedef struct{
    StackElementType elem[Stack_Size];
    int top;
} SeqStack;

void InitStack(SeqStack *s)
{
    s->top = -1;
}

int push(SeqStack *s, StackElementType x)
{
   if(s->top==Stack_Size-1)
       return 0;
   else
     {
         s->top++;
         s->elem[s->top] = x;
         return 1;
     }    
}

int Pop(SeqStack *s,StackElementType *x)
{
    if(s->top==-1)
        return 0;
    else
    {
        *x = s->elem[s->top];
        s->top--;
        return 1;
    }    
}

int IsEmpty_stack(SeqStack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

int GetTop(SeqStack *s,StackElementType *x)
{
    if(s->top==-1)
        return 0;
    else
    {
        *x = s->elem[s->top];
        return 1;
    }    
}

#endif