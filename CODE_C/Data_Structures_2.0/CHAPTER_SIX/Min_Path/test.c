#include "BF.c"
#include "DJS.c"
#include "FLOYD.c"

int main()
{
    AdjMatrix G;
    int p[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
    int D[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1];
    int path[MAX_VERTEX_NUM + 1];
    int dist[MAX_VERTEX_NUM + 1];

    FILE *fp = fopen("DN.txt", "r");
    CreateDN(fp, &G);
    Floyd(G, p, D);

    fclose(fp);

}