/*汉诺塔*/

#include <stdio.h>
#include <stdlib.h>

void move(int n,char x,char y)
{
    printf("%d:%c→%c\n",n,x,y);
}

void Hanoi(int n,char x,char y,char z)
{
    if(n==1)
       move(1,x,z);
    else
    {
        Hanoi(n-1,x,z,y);//将x上的编号为1至n-1的圆盘移到y，z作为辅助
        move(n,x,z);//将编号为n的圆盘从x移到z
        Hanoi(n-1,y,x,z);//将y上编号为1至n-1的圆盘移到z，x作为辅助塔
    }   
}

int main()
{
    Hanoi(3,'x','y','z');
}