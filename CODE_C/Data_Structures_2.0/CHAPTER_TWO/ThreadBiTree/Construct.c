#include "statement.h"



//先构造一棵二叉树
void  CreateBiTree(ThrBiTree *T,FILE *pf)
{
    char ch;

    fscanf(pf, "%c", &ch);
    if(ch=='#')
    {
        *T = NULL;
    }
    else
    {
        *T = (ThrBiTree)malloc(sizeof(ThrBiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild),pf);
        if((*T)->LChild)
            (*T)->LTag = Link;
        else
            (*T)->LTag = Thread;
        CreateBiTree(&((*T)->RChild),pf);
        if((*T)->RChild)
            (*T)->RTag = Link;
        else
            (*T)->RTag = Thread;
    }
}

