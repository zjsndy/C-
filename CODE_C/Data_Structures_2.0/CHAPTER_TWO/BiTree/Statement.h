#ifndef __Statement_H_
#define __Statement_H_

#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef struct Node
{
    TElemType data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, *BiTree;

void  CreateBiTree(BiTree *T,FILE *pf)
{
    char ch;

    fscanf(pf, "%c", &ch);
    if(ch=='#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild),pf);
        CreateBiTree(&((*T)->RChild),pf);
    }
}

typedef BiTNode *QueueElemtType;

#endif