#ifndef __GAME_H_
#define __GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//函数声明

//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col);

//打印棋盘函数
void DisplayBoard(char board[ROW][COL],int row,int col);

//玩家下棋
void PlayerMove(char board[ROW][COL],int row,int col);

//电脑下棋
void ComputerMove(char board[ROW][COL],int row,int col);

/*
   1.玩家赢-------*
   2.电脑赢-------#
   3.平局---------Q
   4.游戏继续-----C
 */

//判断游戏是否输赢
char Iswin(char board[ROW][COL],int row,int col);

#endif
