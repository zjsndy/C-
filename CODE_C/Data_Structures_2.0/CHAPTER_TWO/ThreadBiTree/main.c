#include "In.c"
#include "Pre.c"
#include "Post.c"

int main()
{
    ThrBiTree T;
    FILE *fp;
    fp = fopen("record.txt", "r");
    CreateBiTree(&T, fp);
    ThrBiTree M;
    Parent(T);
    Postthread_2(&M, T);
   
    PostTravel(M);
    fclose(fp);
}