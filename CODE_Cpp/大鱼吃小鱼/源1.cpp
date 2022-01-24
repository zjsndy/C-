#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

stack<int> q;
int N, x, y, ans, i;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> N;
	ans = N;
	for (i = 0; i < N; i++)
	{
		cin >> x >> y;
		if (y == 1)
			q.push(x);
		else
		{
			while (!q.empty())
			{
				if (x > q.top())
				{
					ans--;
					q.pop();
				}
				else
				{
					ans--;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}