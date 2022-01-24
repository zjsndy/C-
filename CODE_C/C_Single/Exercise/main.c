#include "game.h"
#include "game.c"

void menu()
{
    printf("*******************************************\n");
    printf("**********      1. play          **********\n");
    printf("**********      0. exit          **********\n");
    printf("*******************************************\n");
}

void game()
{
    char board[ROW][COL];  //存储数据，二维数组
    InitBoard(board,ROW,COL);//初始化棋盘，初始化为空格
    DisplayBoard(board,ROW,COL);//打印一下棋盘，本质是打印数组的内容
    char ret=0;//接受游戏状态
    while(1)
    {
        PlayerMove(board,ROW,COL);//玩家
        DisplayBoard(board,ROW,COL);
        ret=Iswin(board,ROW,COL);//判断玩家是否赢得游戏
        if(ret!='C')
            break;
        ComputerMove(board,ROW,COL);//电脑
        DisplayBoard(board,ROW,COL) ; 
        ret=Iswin(board,ROW,COL);
        if(ret!='C')
            break;
    }
    if(ret=='*')
        printf("玩家赢了\n");
    else if(ret=='#')
        printf("电脑赢了\n"); 
    else  
        printf("平局\n");
    DisplayBoard(board,ROW,COL);       
}

int main()
{
    int input=0;
    srand((unsigned int)time(NULL));

    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，重新选择\n");
                break;    
        }
    } while (input);

    return 0;
    
}