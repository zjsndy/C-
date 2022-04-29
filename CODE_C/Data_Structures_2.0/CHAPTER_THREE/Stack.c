/*************************************************************
*  FileName:   Stack.c
*  Date:       2022-03-20 15:35:38
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_THREE
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define Stack_Size 5
typedef char StackElementType;

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

int IsEmpty(SeqStack s)
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

int Match(char destnation,char resource)
{
     switch (destnation){
         case '{':
            if(resource=='}')
                return 1;
            return 0;
          case '[' :
             if(resource==']')
                 return 1;
             return 0;
          case '(' :
             if(resource==')')
                 return 1;
             return 0;
     }

}
void BracketMatch(char *str)
{
    SeqStack s;
    InitStack(&s);
    for (int i = 0; str[i] != '\0';i++)
    {
        switch(str[i]){
            case '{':
            case '[':
            case '(':
                push(&s, str[i]);
                break;
            case '}'  :
            case ']':
            case ')' :
                 if(IsEmpty(s)) 
                 {
                     printf("右括号多余\n");
                     return;
                 }
                 else
                 {
                     StackElementType e;
                     GetTop(&s, &e);

                     if(Match(e,str[i]))
                         Pop(&s, &e);
                     else
                     {
                         printf("对应的左右括号不同类\n");
                         return;
                     }    
                 }
        }
    }
    if(IsEmpty(s))
        printf("括号匹配\n");
    else
        printf("左括号多余\n");
}

int main()
{
    char *str = "[{}]([])";
    BracketMatch(str);

    system("pause");
    return 0;
}