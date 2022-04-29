#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define EQ(a,b)    ((a)==(b))
#define LT(a,b)    ((a)<(b))
#define RT(a,b)    ((a)>(b))
#define LH  1       //左子树高
#define EH  0       //等高
#define RH -1       //右子树高
#define TRUE 1
#define FALSE 0 

typedef int Boolean;    //布尔值
typedef int BBSTElemType;   //平衡二叉排序树元素类型

typedef struct BBSTNode{
    BBSTElemType data;
    int bf;                   //结点的平衡因子
    struct BBSTNode *LChild;
    struct BBSTNode *RChild;

    union 
    {
        int lsize;              //左子树中结点数加一
    };
    
} BBSTNode,*BBSTree;

#endif