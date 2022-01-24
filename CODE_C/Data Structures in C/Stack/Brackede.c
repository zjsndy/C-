/*实现无括号算术表达式的处理，但因为有两个不同类型的栈，
略有遗憾不能使用SeqStack.h头文件，需说明char和int 类型*/

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

#define Stack_Size  50

/*----------------------整型数据类型-------------------------*/
typedef struct
{
   int  elem[Stack_Size];
   int top;
}IntSeqStack;

//初始化
void  InitStack(IntSeqStack *s)
{
    s->top=-1;
}

//判空
int IsEmpty(IntSeqStack *s)
{
    if(s->top==-1)
       return 1;
    return 0;   
}

//进栈
int Push(IntSeqStack *s,int x)
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
int Pop(IntSeqStack *s,int *x)
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
int GetTop(IntSeqStack *s,int *x)
{
    if(s->top==-1)
       return 0;
    else
    {
        *x=s->elem[s->top];
        return *x;
    }   
}

/*------------------整型数据类型--------------------------*/

/*-----------------字符型数据类型-------------------------*/

typedef struct
{
   char  elem[Stack_Size];
   int top;
}CharSeqStack;

//初始化
void  CharInitStack(CharSeqStack *s)
{
    s->top=-1;
}

//判空
int CharIsEmpty(CharSeqStack *s)
{
    if(s->top==-1)
       return 1;
    return 0;   
}

//进栈
int CharPush(CharSeqStack *s,char x)
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
int CharPop(CharSeqStack *s,char *x)
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
char CharGetTop(CharSeqStack *s,char *x)
{
    if(s->top==-1)
       return 0;
    else
    {
        *x=s->elem[s->top];
        return *x;
    }   
}

/*------------------字符型数据类型-------------------------*/

/*------------------无括号算术表达式处理-------------------*/

int In(char ch)
{
  switch (ch)
  {
  case '+':
  case '-':
  case '*':
  case '/':
  case '^':
  case '#':
      return 1;
   default:
      return 0;
  }

}

int GetNumber(char ch)
{
   int m;
   m=ch-48;
   return m;
}

char Compare(char x,char ch)
{
    switch (x)
    {
    case '+':
        if(ch=='+'||ch=='-'||ch=='#')
           return '>';
        else
          return '<' ;  
    case '-':
       if(ch=='+'||ch=='-'||ch=='#')
           return '>';
        else
          return '<' ;  
    case '*':
        if(ch=='^')
           return '<';
        else
           return '>';
     case '/':
        if(ch=='^')
           return '<';
        else
           return '>';      
    case '^' :
         return '>'  ;
    case '#' :
         return '<'  ;      
    }
}

int Execute(int a,char op,int b)
{
   switch(op)
   {
      case '+':
          return a+b;
      case '-':
          return a-b;
      case '*'  :
          return a*b;
      case '/' :
           return a/b;
      case  '^' :
      {
          int c=a*a;
          while (b>2)
          {
              c=c*a;
              b--;
          }
          return c;
      }
   }
}
int ExpEvaluation()
{
    CharSeqStack OPTR;//运算符栈
    IntSeqStack  OVS;//运算数栈
    CharInitStack(&OPTR);
    InitStack(&OVS);
    CharPush(&OPTR,'#');
    printf("输入一个无括号算术表达式(以'#'结束):");
    char ch,x;
    int v;
    ch=getchar();
    while(ch!='#'||CharGetTop(&OPTR,&x)!='#')
    {
        if(!In(ch))
        {
            int n;
            n=GetNumber(ch);
            Push(&OVS,n);
            ch=getchar();
        }
        else
          switch (Compare(ch,CharGetTop(&OPTR,&x)))
          {
          case '>':
          {
               CharPush(&OPTR,ch);
               ch=getchar();
               break;
          }
          case '<':
          {
               int a,b;
               char op;
               Pop(&OVS,&b);
               Pop(&OVS,&a);
               CharPop(&OPTR,&op);
               v=Execute(a,op,b);
               Push(&OVS,v);
               break;
          }
          }
    }
    v=GetTop(&OVS,&v);
    return v;
}

/*------------------无括号算术表达式处理--------------------*/

int main()
{
    int b;
    b= ExpEvaluation();
    printf("%d  ",b);
    return 0;
}