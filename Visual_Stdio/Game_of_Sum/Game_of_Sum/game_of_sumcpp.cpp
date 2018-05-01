#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"cstdio"

using namespace std;

#define maxn 1002
int num[maxn];
int dp[maxn];

int solve(int n)
{
	int ans = 0,anses=0;
	for (int i = 0; i < n; i++)
	{
		ans = num[i];
		if (num[i + 1] > num[i]&&i+1<n)
		{
			int j = i ;
			while (j < n)
			{
				j++;
				if (num[j] > num[j - 1])
				{
					ans += num[j];
				}
				else
				{
					break;
				}
			}
		}
		if (ans > anses)
		{
			anses = ans;
		}
	}
	return anses;
	/*for (int i = 0; i < n; i++)
	{
		dp[i] = num[i];
	}
	for (int i = 1; i < n; i++)
	{
		ans = dp[i];
		for (int j = 0; j < i; j++)
		{
			if (num[i] >  num[j]&&ans<dp[j]+num[i])
			{
				ans = dp[j]+num[i];
			}
		}
		dp[i] = ans;
	}
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > ans)
		{
			ans = dp[i];
		}
	}*/
}

int main()
{
	int n;
	while (scanf("%d", &n))
	{
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		cout << solve(n) << endl;
	}
	return 0;
}