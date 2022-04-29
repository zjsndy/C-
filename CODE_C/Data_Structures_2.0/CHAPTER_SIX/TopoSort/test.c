#include "TopoSort.c"
#include "build.c"

int main()
{
    AdjList G;
    FILE *fp = fopen("DG.txt", "r");
    CreateDG(fp, &G);

    TopoSort(G);

    fclose(fp);
}