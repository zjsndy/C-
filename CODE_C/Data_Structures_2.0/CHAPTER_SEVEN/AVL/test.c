#include "build.c"

int main()
{
    FILE *fp = fopen("record.txt", "r");
    BBSTree T;
    BBSTNode *p,*f;
    CreateAVL(&T, fp);
    p = T;
    f = NULL;
    int taller = FALSE;
    DeleteAVL(&T, 30, f,p, &taller, 0);
    fclose(fp);
}