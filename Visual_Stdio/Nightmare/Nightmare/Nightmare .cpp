#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 10;
int maps[maxn][maxn];
bool visit[maxn][maxn];
int times[maxn][maxn];
int ans = -1 ,n, m;
int nextx[4] = { 1,0,-1,0 };
int nexty[4] = { 0,1,0,-1 };
static long long pp = 0;
void dfs(int posx,int posy,int step,int time)
{
	if (maps[posx][posy] == 3)
	{
		if (step < ans) {
			ans = step;
		}
		return;
	}
	if (time == 1)
		return;
	for (int i = 0; i < 4; i++)
	{
		int dx = posx + nextx[i], dy = posy + nexty[i];
		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;
		if (maps[dx][dy] == 0 || (visit[dx][dy] && times[posx][posy] <= times[dx][dy] - 1))
			continue;
		//if (dx >= 0 && dx < n&&dy >= 0 && dy < m&&(!visit[dx][dy]||times[posx][posy]<=times[dx][dy]-1)&&maps[dx][dy]!=0)
		{
			if (maps[dx][dy] == 4)
				time = 7;
			times[dx][dy] = time - 1;
			visit[dx][dy] = true;
			dfs(dx, dy, step + 1, time - 1);
			visit[dx][dy] = false;
		}
	}
}
int main()
{
	int T,startx,starty;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		ans = inf;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				visit[i][j] = false;
				times[i][j] = 0;
				scanf("%d", &maps[i][j]);
				if (maps[i][j] == 2)
				{
					startx = i;
					starty = j;
					times[i][j] = 6;
				}
			}
		}
		dfs(startx, starty, 0, 6);
		if (ans != inf)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}