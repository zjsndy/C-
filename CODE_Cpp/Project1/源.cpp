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
        k++;  //���k�������ǽ���ʱ���t
        m >>= 1;  //���m����k
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
int main()
{
    LL n;
    while (cin >> n)
    {
        if (Miller_Rabin(n))
            printf("������\n");
        else printf("��������\n");
    }
    return 0;
}