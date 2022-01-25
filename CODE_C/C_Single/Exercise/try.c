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


int main ()
{
  int n = 10;
  int *p = &n;
  int **pp = &p;
  test(pp);
  test(&p);
  system("pause");
  return 0;
}

