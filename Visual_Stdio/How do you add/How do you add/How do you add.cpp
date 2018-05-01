#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<limits.h>
#define N 100010
#define mod 1000000
#define LL long long
using namespace std;
LL dp[110][110];
void DP()
{
	int i, j, k;
	for (i = 0; i <= 100; i++)
		dp[0][i] = 1;
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 100; j++)
		{
			for (k = 0; k <= i; k++)
				dp[i][j] = (dp[i][j] + dp[k][j - 1]) % mod;
		}
	}
}
int main()
{
	int n, k;
	DP();
	while (scanf("%d%d", &n, &k) != EOF, n || k)
	{
		printf("%lld\n", dp[n][k]);
	}
}