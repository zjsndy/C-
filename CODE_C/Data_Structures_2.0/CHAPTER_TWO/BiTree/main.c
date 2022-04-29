#include "Re_Travel.c"
#include "Statement.h"
#include "Level_Travel.c"
#include "Travel.c"
#include "Basic_Operation.c"
#include <math.h>


void PrinttTree(BiTree T)
{
    int row, col;
    int i, j, m, l, r;
    BiTNode a[100][100];    //用一个足够大的矩阵按原样存储树

    if(T)
    {
        row = PostTreeDepth(T);
        col = pow(2, row) - 1;

        for (i = 1; i <= row - 1;i++)
        {
            for (j = 1; j <= pow(2, i - 1);j++)
            {
                m = (2 * j - 1) * pow(2, row - i);  //当前行节点相对位序
                l = (4 * j - 3) * pow(2, row - i - 1);//下一行相对位序
                r = (4 * j - 1) * pow(2, row - i - 1);

                if(i==1)
                    a[i][m] = *T; //初始化
                if(a[i][m].LChild)
                    a[i + 1][l] = *(a[i][m].LChild);
                if(a[i][m].RChild)
                    a[i + 1][r] = *(a[i][m].RChild);
            }
        }

        for (i = 1; i <= row;i++)
        {
            for (j = 1; j <= col;j++)
            {
                if(a[i][j].data)
                    printf("%c ", a[i][j].data);
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
}

int main()
{
    BiTree T;
    FILE *pf;

    pf = fopen("record.txt", "r");

    if(pf==NULL)
    {
        perror("record.txt:");
    }
     
    CreateBiTree(&T, pf);

    PostOrder(T);

    fclose(pf);

}