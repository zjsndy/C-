#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef char ElemType;

typedef struct Node 
{
    ElemType data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode,*BiTree;

void CreatBiTree(BiTree *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
       *T=NULL;
    else
        {
            *T=(BiTree)malloc(sizeof(BiTNode));
            if(*T==NULL)
              {
                  printf("开辟内存失败!\n");
                  exit(0);
              }
              (*T)->data=ch;
              CreatBiTree(&(*T)->LChild);
              CreatBiTree(&(*T)->RChild);
        }   
}

void Visit(ElemType data)
{
    printf("%c  ",&data);
}

void PreOrder(BiTree root)
{
    if(root!=NULL)
    {
        Visit(root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void Inorder(BiTree root)
{
    if(root!=NULL)
    {
        Inorder(root->LChild);
        Visit(root->data);
        Inorder(root->RChild);
    }
}

void PostOrder(BiTree root)
{
    if(root!=NULL)
    {
        PostOrder(root->LChild);
        PostOrder(root->RChild);
        Visit(root->data);
    }
}

int main()
{
    BiTree T;
    T=NULL;
    CreatBiTree(&T);
    PostOrder(T);
}