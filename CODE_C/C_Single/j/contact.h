#ifndef __contact_H_
#define __contact_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};

struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
    struct PeoInfo *data;//存放一个信息
    int size;//记录当前已经有的元素个数
    int capacity;//当前通讯录的最大容量
};

//声明函数
//初始化通讯录的函数
void InitContact(struct Contact *ps);

//增加一个信息到通讯录
void AddContact(struct Contact *ps);

//打印通讯录中的信息
void ShowContact(const struct Contact *ps);

//删除指定的联系人
void DelContact(struct Contact *ps);

//查找指定的联系人
void SearchContact(const struct Contact *ps);

//修改指定联系人
void ModifyContact(struct Contact *ps);

//排序通讯录内容
void SortContact(struct Contact *ps);

//销毁通讯录
void DestoyContact(struct Contact *ps);

#endif
