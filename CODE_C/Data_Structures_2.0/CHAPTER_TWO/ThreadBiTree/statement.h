#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

typedef char TElemType; //假设二叉树元素均为字符
typedef enum
{
    Link,          // 0     孩子
    Thread        //  1     线索
} PointerTag;

typedef struct ThrBiTNode{
    TElemType data;
    struct ThrBiTNode *LChild;
    struct ThrBiTNode *RChild;
    PointerTag LTag;
    PointerTag RTag;

    struct ThrBiTNode *parent;   //双亲结点指针,仅在非递归后序遍历线索二叉树使用
} ThrBiTNode, *ThrBiTree;


ThrBiTree pre;     //指向当前访问结点的上一个结点
ThrBiTree next;    //指向当前访问结点的后继节点

#endif