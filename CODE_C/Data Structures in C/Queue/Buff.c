//键盘输入循环缓冲区算法

#include <stdio.h>
#include <conio.h>
#include "SeqQueue.h"

int main()
{
    char ch1,ch2;
    SeqQueue Q;
    int f;
    InitSQueue(&Q);
    for(; ;)
    {
        for(; ;)
        {
            printf("A");
            if(kbhit())
            {
                ch1=getch();
                if(ch1==','||ch1==';')
                   break;
                f=EnterSQueue(&Q,ch1);
                if(f==0)  
                {
                    printf("循环队列已满\n");
                    break;
                } 
            }
        }
        while (!IsEmpty(Q))
        {
           DeleteSQueue(&Q,&ch2);
           putchar(ch2);
        }
        if(ch1==';')
           break;
        
    }
}