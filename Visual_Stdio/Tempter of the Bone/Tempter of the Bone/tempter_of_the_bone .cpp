#include<iostream>
#include<string.h>

using namespace std;

char maps[10][10];
int N, M, T;
int visit[10][10];
int flag = 0;
int end_i, end_j;

void dfs(int startx, int starty, int step)
{

	if (maps[startx][starty] == 'D'&&step == T)
	{
		//printf("%d %d %d\n", startx, starty, T);
		flag = 1;
		return;
	}
	if (step == T)
		return;
	int temp = abs(startx - end_i) + abs(starty - end_j);
	temp = T - temp - step;
	if (temp & 1) return;//ÆæÅ¼¼ôÖ¦
	if (startx + 1 >= 0 && startx + 1 < N&&maps[startx + 1][starty]!='X'&&visit[startx + 1][starty]==0) {
		visit[startx + 1][starty] = 1;
		dfs(startx + 1, starty, step+1);
		visit[startx +1][starty] = 0;
	}
	if (startx - 1 >= 0 && startx - 1 < N&&maps[startx - 1][starty] != 'X'&&visit[startx- 1][starty] == 0) {
		visit[startx - 1][starty] = 1;
		dfs(startx - 1, starty, step+1);
		visit[startx - 1][starty] = 0;
	}
	if (starty  +1>= 0 && starty + 1 < M&&maps[startx ][starty+1] != 'X'&&visit[startx ][starty + 1] == 0) {
		visit[startx ][starty+1] = 1;
		dfs(startx , starty+1, step+1);
		visit[startx][starty + 1] = 0;
	}
	if (starty-1>= 0 && starty - 1 < M&&maps[startx ][starty-1] != 'X'&&visit[startx ][starty-1] == 0) {
		visit[startx][starty - 1] = 1;
		dfs(startx , starty-1, step+1);
		visit[startx][starty - 1] = 0;
	}
}
int main()
{
	while (cin >> N >> M >> T)
	{
		getchar();
		int startx = -1, starty = -1, k = 0;
		flag = 0;
		if (N == M && M == T && T == 0)
			break;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				maps[i][j] = getchar();
				if (maps[i][j] == 'S')
				{
					startx = i;
					starty = j;
					visit[i][j] = 1;
				}
				if (maps[i][j] == 'D')
				{
					end_i = i;
					end_j = j;
				}
				if (maps[i][j] == 'X')
					k++;
			}
			getchar();
		}
		int pans = abs(end_j - starty) + abs(end_i - startx);
		if (pans>T || pans % 2 != T%2)
		{
			printf("NO\n");
			continue;
		}
		if (N*M - k - 1 >= T) {
			dfs(startx, starty, 0);
		}
		if (flag==1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
}