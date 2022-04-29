#include "statement.h"

//按层序序列构造树
void CreateTree(FILE *fp,PTree *T)
{
    TElemType ch;
    int i = 0, j = -1;
 

    fscanf(fp, "%c", &ch);
    (*T).nodes[i].data = ch;
    (*T).nodes[i].parent = j;
    (*T).n++;
    i++;
    j++;
    
    fscanf(fp, "%c", &ch);
    while(ch!='\n')
    {
        

        if(ch=='#')      //遇到换行
        {
            fscanf(fp, "%c", &ch);
            fscanf(fp, "%c", &ch);
            fscanf(fp, "%c", &ch);
            j++;
        }    

        (*T).nodes[i].data = ch;
        (*T).nodes[i].parent = j;
        (*T).n++;
        i++;

        fscanf(fp, "%c", &ch);
    } 

   
   
}