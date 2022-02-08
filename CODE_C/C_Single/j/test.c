#include "contact.h"
#include "contact.c"

void menu()
{
    printf("*****************************************\n");
    printf("*******1.add        2.del       *********\n");
    printf("*******3.search     4.modify    *********\n");
    printf("*******5.show       6.sort      *********\n");
    printf("*******0.exit                   *********\n");
    printf("*****************************************\n");
}

int main()
{
    int input = 0;
    //创建通讯录
    struct Contact con;//con就是通讯录，里面包含：data指针和size和capacity
    //初始化通讯录
    InitContact(&con);
    do
     {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch(input)
        {
            case ADD:
                AddContact(&con);
                break;
            case DEL:
                DelContact(&con);
                break;
            case SEARCH:
                SearchContact(&con);
                break;
            case MODIFY:
                ModifyContact(&con);
                break;
            case SHOW:
                ShowContact(&con);
                break;
            case SORT:
                SortContact(&con);
                break;
            case EXIT:
                DestoyContact(&con);
                printf("退出通讯录\n");
                break;
            default:
                printf("输入有错,请重新输入\n");
                break;
        }
    } while (input);
  
   system("pause");
   return 0;
}