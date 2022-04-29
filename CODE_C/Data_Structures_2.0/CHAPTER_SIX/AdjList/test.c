#include "build.c"
#include "Operate.c"
#include "travel.c"

int main()
{
    AdjList G;

    FILE *fp = fopen("Create_UDG.txt", "r");
    CreateGraph(fp, &G);
    BFSTraverse(G);

    fclose(fp);
 
}