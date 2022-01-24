//十字链表
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;

typedef struct OLNode
{
    int row,col;   //非零元素的行和列下标
    ElementType value;
    struct OLNode *right,*down;  //非零元素所在行表、列表的后继链域
}OLNode,*OLink;

typedef struct 
{
    OLink * row_head , *col_head;   //行、列链表的头指针向量
    int m,n,len;           //稀疏矩阵的行数、列数、非零元素的个数
}CrossList;
 
void CreateCrossList(CrossList *M)
{
    int m,n,t;
    int i,j,e;OLNode *p,*q;
    printf("输入M的行数、列数、非零元素的个数");
    scanf("%d%d%d",&m,&n,&t);
    M->m=m;M->n=n;M->len=t;

    if(! (M->row_head=(OLink *)malloc((m+1)*sizeof(OLink))))
        exit(0);
    if (!(M->col_head=(OLink *)malloc((n+1)*sizeof(OLink)))) 
        exit(0);

    for(i=1;i<=m;i++)
        M->row_head[i]=NULL;
    for (j=1;j<=n;j++)
    {
        M->col_head[j]=NULL;
    }

    for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e))
    {
       if(!(p=(OLNode *)malloc(sizeof(OLNode))))
          exit(0);
       else
           p->row=i;p->col=j;p->value=e;//生成结点

       if(M->row_head[i]==NULL||M->row_head[i]->col>j)
       {
            p->right=M->row_head[i];
            M->row_head[i]=p;
       }
       else
         {
             //寻找行表中的插入位置
                q=M->row_head[i];
                while(q->right!=NULL&&q->right->col<j)
                   q=q->right;
                p->right=q->right;q->right=p; //完成插入
         } 

        if(M->col_head[j]==NULL||M->col_head[j]->row>i)
        {
              p->down=M->col_head[j];
               M->col_head[j]=p;
        }
        else
          {
              //寻找列表中的插入位置
              q=M->col_head[j];
              while(q->down!=NULL&&q->down->row<i) 
                   q=q->down;
              p->down=q->down;q->down=p;//完成插入     
          }   
    }
}

void display(CrossList *M)
{
      for(int i=1;i<=M->n;i++)
        if(NULL!=M->col_head[i])
        {
            OLink p=M->col_head[i];
            while(NULL!=p)
            {
                printf("%d\t%d\t%d\n",p->row,p->col,p->value);
                p=p->down;
            }
        }
}

void transport(CrossList *M)
{
    for(int i=1;i<=M->m;i++)
    {
         OLink p=M->row_head[i];
        for(int j=1;j<=M->n;j++)
        {
             if(p!=NULL&&p->row==i&&p->col==j)
             {
                printf("%d  ",p->value);
                p=p->right;
             }
             else
                printf("0  ");  
            
        }
        printf("\n");
    }
}

int main()
{
    CrossList M;
   // M.col_head=NULL;
   // M.row_head=NULL;
    CreateCrossList(&M);
    printf("输出矩阵M:\n");
   // display(&M);
   transport(&M);
}