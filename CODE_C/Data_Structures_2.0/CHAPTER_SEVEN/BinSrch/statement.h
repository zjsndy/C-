#ifndef __statement_H_
#define __statement_H_

#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 20
typedef int KeyType;

typedef struct  
{
    KeyType key;
}RecordType;


typedef struct{
    RecordType r[LIST_SIZE + 1];
    int length;
} RecordList;

#endif