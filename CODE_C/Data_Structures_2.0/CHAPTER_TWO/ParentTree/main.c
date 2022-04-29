#include "construct.c"
#include "Basic_Opt.c"

int main()
{
    FILE *fp;
    PTree T;

    fp = fopen("record.txt", "r");
    InitTree(&T);
    CreateTree(fp, &T);
    DeleteTree(&T, 'B', 2);

    fclose(fp);
}