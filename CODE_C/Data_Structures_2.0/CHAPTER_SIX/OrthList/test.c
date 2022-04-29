#include "build.c"

int main()
{
    OrthList G;
    FILE *fp = fopen("TestData.txt", "r");
    CreateDG(fp, &G);
    fclose(fp);
}