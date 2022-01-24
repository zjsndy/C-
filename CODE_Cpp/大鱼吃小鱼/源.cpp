#include<iostream>
#include<cstring>
using namespace std;
int A[100005], B[100005];
int C[100005];
int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i];
	}
	int ans = n;
	int flag = -1;
	for (i = 0; i < n; i++)
	{
		if (B[i] == 1)
			C[++flag] = A[i];
		else
		{
			while (flag != -1)
			{
				ans--;
				if (C[flag] < A[i])
					flag--;
				else
					break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}