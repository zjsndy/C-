#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<math.h>
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 50005;
const int mod = 26;
const int INF = 0x3f3f3f3f;
const int Times = 10;
const int N = 5500;
LL ct, cnt;
LL fac[N], num[N];
LL gcd(LL a, LL b)  //求两数最大公因子
{
    return b ? gcd(b, a % b) : a;
}
LL multi(LL a, LL b, LL m)  //快速乘
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
LL pow(LL a, LL b, LL m)  //快速幂
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
bool Miller_Rabin(LL n)  //判断是不是素数
{
    if (n == 2) return true;
    if (n < 2 || !(n & 1)) return false;
    LL m = n - 1;
    int k = 0;
    while ((m & 1) == 0)
    {
        k++;  //这个k就是我们讲的时候的t
        m >>= 1;  //这个m就是k
    }
    for (int i = 0; i < Times; i++) //Times就是我们事先定义的s（要找a的个数）
    {
        LL a = rand() % (n - 1) + 1;  //找一个[1,n-1]内的任意数
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
int main()
{
    LL n;
    while (cin >> n)
    {
        if (Miller_Rabin(n))
            printf("是素数\n");
        else printf("不是素数\n");
    }
    return 0;
}