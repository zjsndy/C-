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

void Init(int Arry[],int length)
{
  for (int i = 0; i < length;i++)
    Arry[i] = 0;
}

void print(int Arry[],int length)
{
  for (int i = 0; i < length;i++)
    printf("%d  ", Arry[i]);
}

void reserve(int Arry[],int length)
{
  for (int i = 0; i < length / 2;i++)
    {
      int temp = 0;
      temp = Arry[i];
      Arry[i] = Arry[length - 1 - i];
      Arry[length - 1 - i] = temp;
    }

}

int main ()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 // Init(arr,10);  //初始化数组为0
  print(arr,10);//打印数组每个元素
  printf("\n");
  reserve(arr,10);//函数完成数组元素的逆置
  print(arr,10);
  system("pause");
  return 0;
}