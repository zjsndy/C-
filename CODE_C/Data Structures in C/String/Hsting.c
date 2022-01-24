//堆串

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *ch;
    int len;
}HString;

void InitString(HString *s)
{
    s->len=0;
    s->ch='\0';
}

//串的赋值操作
void StrAssign(HString *s,char cstr[])
{
    int i=0,len;
    if(s->ch)
      free(s->ch);
    for(i=0;cstr[i]!='\0';i++)  
       i++;
    len=i;
    if(!i)
    {
        s->len=0;
        s->ch='\0';
    }
    else
    {
        s->ch=(char *)malloc(len);
        if(!s->ch)
          exit(-1);
        for(i=0;i<len;i++)  
           s->ch[i]=cstr[i];
         s->len=len;  
    }
}

int StrEmpty(HString s)
{
    if(s.len==0)
       return 1;
    return 0;   
}

void StrPrint(HString s)
{
    int i;
    for(i=0;i<s.len;i++)
       printf("%c",s.ch[i]);
    printf("\n");  
}

int StrInsert(HString *s,int pos,HString *t)
{
    int i;
    char *temp;
    if(pos<0||pos>s->len||s->len==0)
       return 0;
    temp=(char *)malloc(s->len+t->len);
    if(temp==NULL)
       return 0;
    for(i=0;i<pos;i++)  
       temp[i]=s->ch[i] ;
    for(i=0;i<t->len;i++)   
       temp[i+pos]=t->ch[i];
    for(i=pos;i<s->len;i++)   
       temp[i+t->len]=s->ch[i];
    s->len+=t->len;
    free(s->ch)  ;
     s->ch=temp;
     return 1; 
}

int StrDelete(HString *s,int pos,int len)
{
    int i;
    char *p;
    if(pos<0||len<0||pos+len-1>s->len)
      {
          printf("删除位置不正确，参数len不合法\n");
          return 0;
      }
    p=(char *)malloc(s->len-len);
    if(!p)
      exit(-1);
    for(i=0;i<pos-1;i++)  
       p[i]=s->ch[i];
    for(i=pos-1;i<s->len-len;i++)   
       p[i]=s->ch[i+len];
    s->len=s->len-len;
    free(s->ch)   ;
    s->ch=p;
    return 1;
}


int main()
{
    HString s1,s2;
    char ch[50];
    InitString(&s1);
    printf("请输入字符串: ");
    gets(ch);
    StrAssign(&s1,ch);
    printf("经赋值操作后的串:");
    StrPrint(s1);
    /*InitString(&s2);
    printf("请输入字符串: ");
    gets(ch);
    StrAssign(&s2,ch);
    printf("经赋值操作后的串:");
    StrPrint(s2);
    StrInsert(&s1,2,&s2);
    StrPrint(s1);*/
    StrDelete(&s1,2,3);
    StrPrint(s1);
}