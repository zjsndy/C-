#include <stdio.h>
#include <stdlib.h>

typedef int  StackElementType;
#define M 100

typedef struct 
{
    StackElementType stack[M];
    StackElementType top[2];
}DqStack;

//初始化
void InitStack(DqStack *s)
{
    s->top[0]=-1;
    s->top[1]=M;
}

//双端栈进栈
int Push(DqStack *s,StackElementType x,int i)
{
    if(s->top[0]+1==s->top[1])
       return 0;
    switch(i)   
    {
        case 0:
            s->top[0]++;
            s->stack[s->top[0]]=x;
            break;
        case 1:
            s->top[1]--;
            s->stack[s->top[1]]=x;
            break;
        default:
             return 0;       
    }
    return 1;
}

//双端栈出栈
int Pop(DqStack *s,StackElementType *x,int i)
{
    switch (i)
    {
    case 0:
        if(s->top[0]==-1)
            return 0;
        *x=s->stack[s->top[0]] ;
        s->top[0]--; 
        break;
    case 1:
        if(s->top[1]==M)   
            return 0;
        *x=s->stack[s->top[1]]  ;
        s->top[1]++;
        break;
    default:
        return 0;
    }
    return 1;
}

//打印
void Print(DqStack *s)
{
    printf("首端栈:");
    while(s->top[0]>=0)
    {
       printf("%d  ",s->stack[s->top[0]]);
       s->top[0]--;
    }
    printf("\n尾端栈:") ;
    while(s->top[1]<=M-1)
    {
        printf("%d  ",s->stack[s->top[1]]);
        s->top[1]++;
    } 
        
}

int main()
{
    DqStack s;
    int x;
    InitStack(&s);
    Push(&s,2,0);
    Push(&s,6,0);
    Push(&s,10,0);
    Push(&s,2,1);
    Push(&s,21,1);
    Pop(&s,&x,1);
    Pop(&s,&x,0);
    Print(&s);
}