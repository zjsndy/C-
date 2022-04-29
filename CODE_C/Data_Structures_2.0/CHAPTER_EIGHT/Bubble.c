/*************************************************************
*  FileName:   Bubble.c
*  Date:       2022-04-27 08:40:40
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_EIGHT
*  Description:冒泡排序
**************************************************************/
#include "statement.h"


void Bubble(RecordType a[N])
{
    int tag = 0;
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N - i - 1;j++)
        {
            if(a[j].key>a[j+1].key)
            {
                RecordType tmp = a[j];
                a[j+1] = a[j];
                a[j] = tmp;
                tag = 1;
            }
        }
        if(!tag)
           break;
    }
}

