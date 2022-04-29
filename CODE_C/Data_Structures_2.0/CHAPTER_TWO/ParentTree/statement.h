#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 20   //树的最大节点数

typedef char TElemType;

typedef struct PTNode{
    TElemType data;
    int parent;
} PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE]; //根节点的位置默认到0，方便操作
    int n;                       //树的结点数
} PTree;

#endif