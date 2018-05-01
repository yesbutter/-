#include"iostream"
#include"cstdio"
#include<algorithm>
#include<string.h>

#define inf 0x3f3f3f3f

using namespace std;
const int maxn = 200;
int sum[maxn];
int p[maxn];
int dp[maxn][maxn];

int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int t, n, w;
	cin >> t;
	while (t--)
	{
		memset(dp, inf, sizeof(dp));
		cin >> n >> w;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
		}
		sort(p + 1, p + n + 1, cmp);
		dp[0][0] = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + p[i];
			dp[0][i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				for (int k = 1; k <= i; k++)
				{
					dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + i * (sum[i] - sum[k - 1]));
					//cout << i<<" "<<j<<" "<<dp[i][j] << endl;
				}
			}
		}
		printf("%.4f\n", 1.0*dp[n][w] / sum[n]);
		//cout << (double)dp[n][w]/sum[n] << endl;
	}
	system("pause");
	return 0;
}
