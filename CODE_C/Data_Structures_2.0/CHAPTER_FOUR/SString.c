/*************************************************************
*  FileName:   SString.c
*  Date:       2022-03-22 21:28:14
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_FOUR
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include  <string.h>

#define MAXLEN 40

typedef struct {
    char ch[MAXLEN];
    int len;
} SString;

int StrIndex(SString s,int pos,SString t)
{
    int i, j, start;
    if(t.len==0)
        return 0;
    start = pos;
    i = start;
    j = 0;

    while (i<s.len&&j<t.len)
    {
        if(s.ch[i]==t.ch[j])
        {
            i++;
            j++;
        }

        else
        {
            start++;
            i = start;
            j = 0;
        }
    }

    if(j>=t.len)
        return start;
     else
         return -1;
}

void Next(char *T,int *next)
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i<strlen(T))
    {
        if(j==0||T[i-1]==T[j-1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    
}

int KMP(char *S,char *T)
{
    int next[10];
    Next(T, next);
    int i = 1, j = 1;

    while(i<=strlen(S)&&(j<=strlen(T)))
    {
        if(j==0||S[i-1]==T[j-1]) //j=0:表示模式串的第一个字符就和指针i指向的字符不相等
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j>strlen(T))
        return i -(int) strlen(T);
    return -1;
}

int main ()
{
    SString s, t;
    char *m = "ababcabcacbab";
    char *n = "abcac";
    strcpy(s.ch, m);
    strcpy(t.ch, n);
    s.len = 13;
    t.len = 5;

   
   


    system("pause");
    return 0;
}