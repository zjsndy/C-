#include "Bubble.c"
#include "Select.c"
#include "Insert.c"
#include "Bin.c"
#include "Shell.c"
#include "quick.c"
#include "Heap.c"
#include "M.c"

void Init(RecordType a[])
{
    int b[N] = {55, 40, 82, 42, 58, 40, 84, 30, 85, 88};
    for (int i = 1; i <= N;i++)
        a[i].key = b[i-1];
}

void Print(RecordType a[])
{
    for (int i = 1; i <= N;i++)
        printf("%d   ", a[i].key);
}


int main ()
{
    RecordType a[N+1] ;
    Init(a);

    MergeSort(a, N);

    Print(a);

    system("pause");
    return 0;
}