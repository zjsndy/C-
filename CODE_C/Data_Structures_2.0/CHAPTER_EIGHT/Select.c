#include "statement.h"

int SelcetMinKey(RecordType a[N],int pos)
{
    int min = a[pos].key;
    int j=pos;
    for (int i = pos+1; i < N;i++)
    {
        if(min>a[i].key)
        {
            min = a[i].key;
            j = i;
        }
    }

    return j;
}

void Select(RecordType a[N])
{
    RecordType tmp;
    int j;

    for (int i = 0; i < N;i++)
    {
        j = SelcetMinKey(a, i);

        if(i!=j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

}
