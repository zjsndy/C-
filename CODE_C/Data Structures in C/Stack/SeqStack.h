#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef char StackElemtType;
#define Stack_Size 50

typedef struct
{
   StackElemtType  elem[Stack_Size];
   int top;
}SeqStack;

//初始化
void InitStack(SeqStack *s)
{
    s->top=-1;
}

//判空
int IsEmpty(SeqStack *s)
{
    if(s->top==-1)
       return 1;
    return 0;   
}

//进栈
int Push(SeqStack *s,StackElemtType x)
{
    if(s->top==Stack_Size-1)
      {
          printf("此栈已满\n");
          return 0;
      }
      s->top++;
      s->elem[s->top]=x;
      return 1;
}

//出栈
int Pop(SeqStack *s,StackElemtType *x)
{
    if(s->top==-1)
        return 0;
    else
        {
            *x=s->elem[s->top];
            s->top--;
            return 1;
        }    
}

//读取栈顶元素
int GetTop(SeqStack *s,StackElemtType *x)
{
    if(s->top==-1)
       return 0;
    else
    {
        *x=s->elem[s->top];
        return 1;
    }   
}
void Print(SeqStack *s)
{
  while (s->top>=0)
  {
      printf("%c  ",s->elem[s->top]);
      s->top--;
  }
  
}

#endif