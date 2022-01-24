#include "SeqStack.h"

/*---------------------------------------------------括号匹配---------------------------------------------------*/
int Match(char a,char b)
{
    switch (a)
    {
    case '(':
        if(b==')')
          return 1;
        else
           return 0;  
        break;
    case '{'  :
        if(b=='}')  
           return 1;
        else
           return 0;
    case '['  :
        if(b==']')     
           return 1;
        else
          return 0;       
    default:
        break;
    }
}

void BracketMatch(char *str)
{
    SeqStack s;int i;char ch;
    InitStack(&s);
    for(i=0;str[i]!='\0';i++)
       {
           switch(str[i])
           {
               case '(':
               case '[':
               case '{':
                  Push(&s,str[i]);
                  break;
               case ')':
               case ']':
               case '}':
                   if(IsEmpty(&s))
                      {
                          printf("\n右括号多余！");
                          return ;
                      }
                   else
                   {
                           GetTop(&s,&ch);
                           if(Match(ch,str[i]))
                               Pop(&s,&ch);
                           else
                             {
                                 printf("\n左右括号不匹配!");
                                 return ;
                             }    
                   }   
           }

       }
       if(IsEmpty(&s))
           printf("\n括号匹配！");
        else
            printf("\n左括号多余!") ;  
}
/*---------------------------------------------------括号匹配---------------------------------------------------*/

int main()
{
   char *str="()[]";
   BracketMatch(str);
}

