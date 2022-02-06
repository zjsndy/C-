/*************************************************************
*  FileName:   try.c
*  Date:       2022-01-17 12:41:31
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\C_Single\Exercise
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>

struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
} *p;

//假设p的值为0x100000,如下表达式的值分别为?
//已知，结构体Test类型的变量大小是20个字节

int main()
{
	char* a[] = { "work", "at", "alibaba" };
	char** pa = a;

	pa++;
	printf("%s\n,*pa");
	system("pause");
	return 0;
}

