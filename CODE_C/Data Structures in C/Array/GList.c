//同层结点链存储广义表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{Atom,List}ElemTag;
typedef char AtomType;

typedef struct GLNode
{
    ElemTag tag;
    union 
    {
        AtomType atom;
        struct  GLNode *hp;
    }atom_htp; 
    struct  GLNode *tp;
}GLNode,*GList;

void GetSubs(char str[],char hstr[])
{
    int i=0,j=0,k=0,r=0;
    char s[100];
    while(str[i]&&(str[i]!=','||k))
       {
           if(str[i]=='(')
              k++;
           else if(str[i]==')') 
              k--;
           if(str[i]!=','||str[i]==','&&k)
              {
                  hstr[j]=str[i];
                  i++;
                  j++;
              }     
       }
       hstr[j]='\0';
       if(str[i]==',')
          i++;
       while(str[i])
       {
           s[r]=str[i];
           r++;
           i++;
       }  
       s[r]='\0';
       strcpy(str,s);
}