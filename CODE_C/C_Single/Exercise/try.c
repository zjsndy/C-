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
#include <assert.h>


int main ()
{
  struct s3
  {
    double d;
    char c;
    int i;
  };

  struct s4
  {
    char c1;
    struct s3 s3;
    double d;
  };
  printf("%d\n",(int) sizeof(struct s4));

  system("pause");
  return 0;
}

