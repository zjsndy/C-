#include "Isprime.h"
using namespace std; 

LL gcd(LL a, LL b)  //�������������
{
    return b ? gcd(b, a % b) : a;
}

LL multi(LL a, LL b, LL m)  //���ٳ�
{
    LL ans = 0;
    a %= m;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}

LL pow(LL a, LL b, LL m)  //������
{
    LL ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
        {
            ans = multi(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi(a, a, m);
    }
    return ans;
}

bool Miller_Rabin(LL n)  //�ж��ǲ�������
{
    if (n == 2) return true;
    if (n < 2 || !(n & 1)) return false;
    LL m = n - 1;
    int k = 0;
    while ((m & 1) == 0)
    {
        k++;  //k�൱�ڹ�ʽ��t
        m >>= 1;  //m�൱��k
    }
    for (int i = 0; i < Times; i++) //Times�����������ȶ����s��Ҫ��a�ĸ�����
    {
        LL a = rand() % (n - 1) + 1;  //��һ��[1,n-1]�ڵ�������
        LL x = pow(a, m, n);
        LL y = 0;
        for (int j = 0; j < k; j++)
        {
            y = multi(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if (y != 1) return false;
    }
    return true;
}
