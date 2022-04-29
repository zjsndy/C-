#include "Critical_Path.c"
#include "build.c"

int main()
{
    AdjList G;
     FILE *fp = fopen("DG.txt", "r");
    CreateDG(fp, &G);

    CriticalPath(G);

    fclose(fp);
}