/*************************************************************
*  FileName:   qsort.c
*  Date:       2022-01-25 22:10:31
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\C_Single\Exercise
*  Description:qsort库函数使用
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 

 struct stu
    {
        char name[20];
        int age;
    };

int cmp_int(const void* e1,const void* e2)
{
    //比较两个整形值
    return *(int *)e1 - *(int *)e2;
}

int cmp_float(const void* e1,const void* e2)
{
  /* if(*(float*)e1==*(float*)e2)
        return 0;
    else if(*(float*)e1 > *(float*)e2)
        return 1;
    else
        return -1;*/
   return ((int)(*(float *)e1 - *(float *)e2));
}

int cmp_stu_by_age(const void*e1,const void*e2)
{
   return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_stu_by_name(const void*e1,const void*e2)
{
    //比较名字就是比较字符串
    //字符串比较不能直接用><=来比较，应该用strcmp函数
    return strcmp(((struct stu *)e1)->name, ((struct stu *)e2)->name);
}

void test1()
{
    int arr[10] = {9, 8, 6, 5, 1, 2, 7, 3, 4, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    for (int i = 0; i < sz;i++)
    {
        printf("%d ", arr[i]);
    }
}

void test2()
{
    float f[] = {9.0, 8.0, 7.0, 6.0, 5.0, 4.0};
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
    for (int i = 0; i < sz;i++)
    {
        printf("%f ", f[i]);
    }
}

void test3()
{
    struct stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
    for (int i = 0; i < sz;i++)
    {
        printf("%s,%d\n", s[i].name, s[i].age);
    }
}

void test4()
{
    struct stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
    for (int i = 0; i < sz;i++)
    {
        printf("%s,%d\n", s[i].name, s[i].age);
    }
}

int main ()
{
    //test1();
    //test2();
    //test3();
    test4();
    system("pause");
    return 0;
}