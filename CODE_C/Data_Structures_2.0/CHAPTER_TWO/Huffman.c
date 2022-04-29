/*************************************************************
*  FileName:   Huffman.c
*  Date:       2022-03-24 09:41:06
*  Author:     JAY.Z
*  Path:       D:\Codefield\CODE_C\Data_Structures_2.0\CHAPTER_TWO
*  Description:
**************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct{
    int weight;     //结点的权值
    int parent;     //双亲的下标
    int LChild;     //左孩子结点的下标
    int RChild;     //右孩子结点的下标
} HTNode, *HuffmanTree; // 0号单元不用

typedef char *HCNode;
typedef HCNode *HuffmanCode;   //动态分配数组存储哈夫曼编码表

//ht数组中存放的哈夫曼树,end表示ht数组中存放结点的最终位置,s1和s2传递的是
//ht数组中权重最小的两个结点在数组中的位置
void Select(HuffmanTree ht,int end,int *s1,int *s2)
{
    int min1, min2;
    //遍历数组初始下标为1
    int i = 1;
    //找到还没构建树的结点
    while(ht[i].parent!=0&&i<=end)
        i++;

    min1 = ht[i].weight;
    *s1 = i;

    i++;
    while(ht[i].parent!=0&&i<=end)
        i++;

    //对找到的两个结点比较大小,min2为大的,min1为小的
    if(ht[i].weight<min1)   
    {
        min2 = min1;
        *s2 = *s1;
        min1 = ht[i].weight;
        *s1 = i;
    } 
    else
    {
        min2 = ht[i].weight;
        *s2 = i;
    }

    //两个结点和后续的所有未构建成树的结点做比较
    for (int j = i + 1; j <= end;j++)
    {
        //如果有父节点,直接跳过，进行下一个
        if(ht[j].parent!=0)
        {
            continue;
        }

        //如果比最小的还小,将min2=min1,min1赋值新的结点的下标
        if(ht[j].weight<min1)
        {
            min2 = min1;
            min1 = ht[j].weight;
            *s2 = *s1;
            *s1 = j;
        }

        //如果介于两者之间,min2赋值为新的结点的位置下标
        else if(ht[j].weight>=min1&&ht[j].weight<min2)
        {
            min2 = ht[j].weight;
            *s2 = j;
        }
    }
}

void CrtHuffmanTree(HuffmanTree *ht,int *w,int n)
{
    if(n<=1)         //如果只有一个编码就相当于0
        return ;
    int  m = 2 * n - 1;  //哈夫曼总结点数,n就是叶子结点
    *ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); //0号位置不用
    HuffmanTree p = *ht;

    (*ht)[0].weight = n;    //利用0号单元的权值存储哈夫曼树叶子个数

    //初始化哈夫曼树中的所有结点
    for (int i = 1; i <= n;i++)
       {
           (p + i)->weight = *(w + i - 1);
           (p + i)->parent = 0;
           (p + i)->LChild = 0;
           (p + i)->RChild = 0;
       }

    //从数组的下标n+1开始初始化哈夫曼树中除叶子结点外的结点    
    for (int i = n + 1; i <= m;i++)
      {
          (p + i)->weight = 0;
          (p + i)->parent = 0;
          (p + i)->LChild = 0;
          (p + i)->RChild = 0;
      }

      //构建哈夫曼树
      for (int i = n + 1; i <= m;i++)
      {
          int s1, s2;
          Select(*ht, i - 1, &s1, &s2);
          (*ht)[s1].parent = (*ht)[s2].parent = i;
          (*ht)[i].LChild = s1;
          (*ht)[i].RChild = s2;
          (*ht)[i].weight = (*ht)[s1].weight + (*ht)[s2].weight;
      }
}

//逆序计算哈夫曼编码值
void CrtHuffmanCode_1(HuffmanTree ht,HuffmanCode *hc)
{
    char *code;
    int n, i;
    int start, c, f;

    n = ht[0].weight;

    *hc = (HuffmanCode)malloc((n + 1) * sizeof(HCNode));

    code = (char *)malloc(n * sizeof(char));//分配求当前编码的工作空间

    code[n - 1] = '\0';//从右向左逐位存放编码，首先存放编码结束符

    for (i = 1; i <= n;i++)
    {
        start = n - 1;//初始化编码起始指针
        c = i;
        f = ht[i].parent;
        while(f!=0)
        {
            --start;
            if(ht[f].LChild==c)
                code[start] = '0';  //左分支为0
            else
                code[start] = '1';   //右分支为1
            c = f;
            f = ht[f].parent; 
         }

         (*hc)[i] = (char *)malloc((n - start) * sizeof(char));
         strcpy((*hc)[i], &code[start]);     //从start开始复制
    }

    free(code);
}

//先序计算哈夫曼编码值
void CrtHuffmanCode_2(HuffmanTree ht,HuffmanCode *hc)
{
    int m, n, i;
    int cdlen;
    int p, mark[10];
    char *code;

    n = ht[0].weight;
    m = 2 * n - 1;

    *hc = (HuffmanCode)malloc((n + 1) * sizeof(HCNode));

    code = (char *)malloc((n) * sizeof(char));

    for (i = 1; i <= n;i++)        
        code[i] = '\0';

    for (i = 1; i <= m;i++)     //初始化访问标记
        mark[i] = 0;            //0、1、2分别表示访问过0次、1次、2次

    p = m;
    cdlen = 0;

    while(p)
    {
        if(mark[p]==0)          //第一次访问此节点
        {
            mark[p] = 1;
            if(ht[p].LChild!=0)   //向左访问
            {
                p = ht[p].LChild;    //p向左走一步
                code[cdlen] = '0';
                cdlen++;
            }
            else
            {
                if(ht[p].RChild==0)    //找到叶子节点
                {
                    (*hc)[p] = (char *)malloc((cdlen + 1) * sizeof(char));
                    strcpy((*hc)[p], code);     //复制编码串
                } 
            }
        }
        else
        {
            if(mark[p]==1)        //第二次访问此节点
            {
                mark[p] = 2;
                if(ht[p].RChild!=0)
                {
                    p = ht[p].RChild;
                    code[cdlen] = '1';
                    cdlen++;
                }
            }
            else            //第三次访问
            {
                p = ht[p].parent;       //返回到父节点
                cdlen--;                //编码长度-1
                if(cdlen>=0)            //不会溢出内存
                   code[cdlen] = '\0';
            }
        }
    }

    free(code);
}

void ShowHUffmanTree(HuffmanTree ht)
{
    printf("|------|------|------|------|------|\n");
    printf("|*order|weight|parent|lchild|rchild|\n");
    int i;
    for (i = 0; i <= 2 * ht[0].weight - 1;i++)
    {
        if(i==0)
            printf("|  %2d  |  %4d|   x  |   x  |  x   |\n", i, ht[i].weight);
        else
            printf("|  %2d  |  %4d|  %2d  |  %2d  |  %2d  |\n", i, ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
    }
    printf("|------|------|------|------|------|\n");
}

void showHuffmanCode(HuffmanTree ht,HuffmanCode hc)
{
    int i;

    printf("|-------|-------|      |              |\n");
    printf("|*order |weight |      |  哈夫曼编码  |\n");
    for (i = 1; i <= ht[0].weight;i++)
        printf("|  %2d   |%4d   |------>  %-12s|\n", i, ht[i].weight, hc[i]);
    printf("|-------|-------|      |              |\n");
}


int main ()
{
    HuffmanTree t;
    HuffmanCode hc;
    int w[5] = {2, 8, 7, 6, 5};
    CrtHuffmanTree(&t, w, 5);
    CrtHuffmanCode_2(t, &hc);
    showHuffmanCode(t, hc);

    system("pause");
    return 0;
}