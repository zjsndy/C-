#include "build.c"

int main()
{
    AdjMultiList G;
    FILE *fp;
    fp = fopen("TestData.txt", "r");

    createUDG(fp, &G);

    fclose(fp);
}