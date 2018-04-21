//给出一张图，然后给出一个序列，修改序列中一些数字，要求使这个序列相邻的两个点．要么是相同的点，要么在图中是相邻点
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 110;
bool g[maxn][maxn];
int dp[5000][maxn];
int main()
{
    int t,n,m,p,u,v;
    scanf("%d",&t);
    while(t--)
    {
        memset(g,false,sizeof(g));
        scanf("%d %d",&n,&m);
        for(int i = 0; i < m; ++i)
        {
            scanf("%d %d",&u,&v);
            g[u][v] = g[v][u] = true;
        }
        for(int i = 1; i <= n; ++i) dp[0][i] = 1;
        scanf("%d %d",&p,&u);
        dp[0][u] = 0;
        for(int i = 1; i < p; ++i)  //输入
        {
            scanf("%d",&u);
            for(int j = 1; j <= n; ++j)  //第i个数为j判断搜寻答案
            {
                dp[i][j] = INF;
                int cost = u == j?0:1;
                for(int k = 1; k <= n; ++k)
                {
                    if(g[k][j] || k == j)//判断是否满足
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+cost);
                }
            }

        }
        int ans = INF;
        for(int i = 1; i <= n; ++i)
            ans = min(ans,dp[p-1][i]);
        cout<<ans<<endl;
    }
    return 0;
}

