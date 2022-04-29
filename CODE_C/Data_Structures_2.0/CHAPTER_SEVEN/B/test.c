#include "Create.c"
#include "delete.c"

int main()
{
    BTree T;
    FILE *fp = fopen("data.txt", "r");
    CreateBTree(&T, fp);
    DeleteKey(&T, 24);
    fclose(fp);
}