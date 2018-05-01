#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 200;
int dp[maxn][maxn];

int cal(int n, int m)
{
	if (dp[n][m] != -1)
		return dp[n][m];
	if (n < 1 || m < 1)
		return 0;
	if (n == 1 || m == 1)
		return 1;
	if (n < m)
		return dp[n][m] = cal(n, n);
	if (n == m)
		return dp[n][m] = cal(n, m - 1) + 1;
	return dp[n][m] = cal(n, m - 1) + cal(n - m, m);
}
int main()
{
	int n;
	memset(dp, -1, sizeof(dp));
	while (cin >> n)
	{
		cout << cal(n, n) << endl;
	}
	system("pause");
	return 0;
}