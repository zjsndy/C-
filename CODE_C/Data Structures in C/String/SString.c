//简单模式匹配算法
//KMP算法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 40

typedef struct 
{
    char ch[MAXLEN];
    int len;
}SString;

//简单匹配算法
int StrIndex(SString s,int pos,SString t)
//pos为下标
{
    int i,j,start;//i:当前主串比较字符;j:字串当前比较字符;start:每次的新起点;
    if(t.len==0)
      return 0;
    start=pos; i=start; j=0;
    while(i<s.len&&j<t.len)
       if(s.ch[i]==t.ch[j])
          {i++;j++;}
        else
        {
            start++;i=start;j=0;
        }
     if(j>=t.len)   
       return start;
     return 0;  
}

//求next数组
void Getnext(int next[],SString t)
{
  int j=0,k=-1;
  next[0]=-1;
  while(j<t.len-1)
    {
      if(k==-1||t.ch[j]==t.ch[k])
      {
        j++;k++;
        if(t.ch[j]==t.ch[k])
            next[j]=next[k];
        else
            next[j]=k;    
      }
      else
        k=next[k];
    }
}

int KMP(SString s,SString t)
{
  int next[t.len],i=0,j=0;
  Getnext(next,t);
  while(i<s.len&&j<t.len)
  {
    if(j==-1||s.ch[i]==t.ch[j])
    {
      i++;
      j++;
    }
    else
     j=next[j];
  }
  if(j>=t.len)
    return i-t.len;
  else
     return 0;  
}


int main()
{
    SString s={"aaabbbababaabb",14};
    SString t={"abaa",4};
    int m,n;
  /*  m=StrIndex(t,2,s);
    if(StrIndex(t,2,s))
       printf("%d \n",m);
    else 
       printf("错误!\n"); */ 
     n=KMP(s,t);
     if(KMP(s,t))
        printf("%d \n",n);
      else
        printf("错误!\n"); 
}