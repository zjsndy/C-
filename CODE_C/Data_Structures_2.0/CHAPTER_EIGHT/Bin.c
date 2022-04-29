#include "statement.h"

void Bin(RecordType a[])
{
    RecordType X;
    int i, low, high, mid;
    for ( i = 2; i <= N;i++)
    {
        X = a[i];
        low = 1;
        high = i - 1;
        while(low<=high)
        {
            mid = (low + high) / 2;
            if(X.key<a[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }

        for (int j = i - 1; j >= low;j--)
            a[j + 1] = a[j];

        a[low] = X;
    }
}
