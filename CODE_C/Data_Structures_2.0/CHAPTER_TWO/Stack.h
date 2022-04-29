#ifndef __Stack_H_
#define __Stack_H_

#include <stdio.h>
#include <stdlib.h>
#define Stack_Size 50
#define MAXSIZE 10


//typedef BiTree SElemType_sq;//重定义栈元素类型



typedef BiTNode* StackElementType;

typedef struct{
    StackElementType elem[Stack_Size];
    int top;
} SeqStack;

typedef BiTNode* QueueElemtType;




#endif