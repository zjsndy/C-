/*************************************************************
*  FileName:   test.c
*  Date:       2022-04-11 18:22:51
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_SIX\AdjMatrix
*  Description:
**************************************************************/
#include "statement.h"
#include "build.c"
#include "operate.c"
#include "Travel.c"

//输出图
void OutputMGraph(AdjMatrix G)
{
    if(!G.vexnum&&!G.arcnum)
        printf("空图!\n");
    else
    {
        printf(" ");
        for (int i = 1; i <= G.vexnum;i++)
            printf("%2c ", G.vertex[i]);
        printf("\n");

        for (int i = 1; i <= G.vexnum;i++)
        {
            printf("%c ", G.vertex[i]);
            for (int j = 1; j <= G.vexnum;j++)
            {
                if(G.arcs[i][j].adj==INFINITY)
                    printf("#  ");
                else
                    printf("%-2d ", G.arcs[i][j].adj);
            }

            printf("\n");
        }
    }
}

int main ()
{
    AdjMatrix G;
    FILE *fp;
    int r;
    srand((unsigned)time(NULL));
    r = rand() % 4;

    switch (r)
    {
    case  DG:
        fp = fopen("TestData_DG.txt", "r");
        break;
    case DN:
        fp= fopen("TestData_DN.txt", "r");
    case UDG:
        fp=fopen("TestData_UDG.txt", "r");
    case UDN:
        fp=fopen("TestData_UDN.txt", "r");
    }

    fp = fopen("TestData_DG.txt", "r");

    CreateGraph(fp, &G);
    BFSTraverse(G);

    fclose(fp);

    system("pause");
    return 0;
}