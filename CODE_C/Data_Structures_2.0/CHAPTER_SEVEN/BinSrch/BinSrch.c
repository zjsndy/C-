#include "statement.h"

int BinSrch(RecordList L,KeyType k)
{
    int low, high, mid;

    low = 1;
    high = L.length;

    while(low<=high)
    {
        mid = (low + high) / 2;

        if(k==L.r[mid].key)
            return mid;

        else if(k<L.r[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return 0;
}

int main()
{
    RecordList L;
    L.length = 11;

    //舍弃record[0]
    int record[20] = {0,6, 12, 15, 18, 22, 25, 28, 35, 46, 58, 60};
    for (int i = 1; i <= L.length;i++)
        L.r[i].key = record[i];

    int pos = BinSrch(L, 25);
    system("pause");
}