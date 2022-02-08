#include "contact.h"

void InitContact(struct Contact *ps)
{
    ps->data = (struct PeoInfo *)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
    if(ps->data==NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
}

void CheckCapacity(struct Contact *ps)
{
     if(ps->size==ps->capacity)
     {
         //增容
         struct PeoInfo *ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
         if(ptr!=NULL)
         {
             ps->data = ptr;
             ps->capacity += 2;
             printf("增容成功\n");
         }
         else
         {
             printf("增容失败\n");
         }
     }
}

void AddContact(struct Contact *ps)
{
    //检测当前通讯录的容量
    //1.如果满了，就增加空间
    //2.如果不满，啥也不干
    CheckCapacity(ps);
    printf("请输入名字:>");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入年龄:>");
    scanf("%d", &ps->data[ps->size].age);
    printf("请输入性别:>");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入电话:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入地址:>");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功\n");
    //增加数据

    /*if(ps->size==MAX)
    {
        printf("通讯录已满,无法增加\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入年龄:>");
        scanf("%d", &ps->data[ps->size].age);
        printf("请输入性别:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功\n");
    }*/
}

void ShowContact(const struct Contact *ps)
{
    if(ps->size==0)
    {
        printf("通讯录为空格\n");
    }
    else
      {
          printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
          for (int i = 0; i < ps->size;i++)
          {
              printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                     ps->data[i].name,
                     ps->data[i].age,
                     ps->data[i].sex,
                     ps->data[i].tele,
                     ps->data[i].addr);
         }
      }  
}

//该函数只能在该函数内调用
static int FindByName(const struct Contact *ps,char name[MAX_NAME])
{
    for (int i = 0; i < ps->size - 1;i++)
    {
        if(0==strcmp(ps->data[i].name,name))
        {
            return i;
        }
    }
    return -1;
}

void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);


    //删除
    if(pos==-1)
     {
         printf("要删除的人不存在\n");
     }
     else
     {
         //删除数据
         for (int j = pos; j < ps->size-1;j++)
         {
             ps->data[j] = ps->data[j + 1];
         }

         ps->size--;
     }
 }


void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if(pos==-1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
          printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
          printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                     ps->data[pos].name,
                     ps->data[pos].age,
                     ps->data[pos].sex,
                     ps->data[pos].tele,
                     ps->data[pos].addr);
    }
}

void ModifyContact(struct Contact *ps)
{
    char Name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", Name);
    int pos = FindByName(ps, Name);
    if(pos==-1)
    {
        printf("要修改人的信息不存在\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &ps->data[pos].age);
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);

        printf("修改完成\n");
    }
}

void SortContact(struct Contact *ps)
{
    for (int i = 0; i < ps->size - 1;i++)
    {
        for (int j = 0; j < ps->size -1-i ;j++)
        {
            if(ps->data[j].age>ps->data[j+1].age)
            {
                struct PeoInfo tmp;
                tmp = ps->data[j];
                ps->data[j] = ps->data[j + 1];
                ps->data[j + 1] = tmp;
            }
        }
    }
}

void DestroyContact(struct Contact *ps)
{
    free(ps->data);
    ps->data = NULL;
}