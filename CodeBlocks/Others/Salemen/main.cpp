//����һ��ͼ��Ȼ�����һ�����У��޸�������һЩ���֣�Ҫ��ʹ����������ڵ������㣮Ҫô����ͬ�ĵ㣬Ҫô��ͼ�������ڵ�
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
        for(int i = 1; i < p; ++i)  //����
        {
            scanf("%d",&u);
            for(int j = 1; j <= n; ++j)  //��i����Ϊj�ж���Ѱ��
            {
                dp[i][j] = INF;
                int cost = u == j?0:1;
                for(int k = 1; k <= n; ++k)
                {
                    if(g[k][j] || k == j)//�ж��Ƿ�����
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

