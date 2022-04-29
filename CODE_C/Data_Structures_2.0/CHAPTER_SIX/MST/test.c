#include "build.c"

int main()
{
    AdjMatrix G;

    FILE *fp = fopen("TestData_UDN.txt", "r");

    CreateUDN(fp, &G);

    MinSpanTree_KRUSKAL(G);

    fclose(fp);
}