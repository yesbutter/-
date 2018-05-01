#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 50;
char maps[maxn][maxn];
int maxvalue;
bool book[maxn][maxn];
bool judge(int i, int j,int size)
{
	if (maps[i][j] != '.')
		return false;
	for (int k = i; k >= 0; k--)
	{
		if (maps[k][j] == 'X')
			break;
		if (book[k][j])
			return false;
	}
	for (int k = i; k < size; k++)
	{
		if (maps[k][j] == 'X')
			break;
		if (book[k][j])
			return false;
	}
	for (int k = j; k >= 0; k--)
	{
		if (maps[i][k] == 'X')
			break;
		if (book[i][k])
			return false;
	}
	for (int k = j; k < size; k++)
	{
		if (maps[i][k] == 'X')
			break;
		if (book[i][k])
			return false;
	}
	return true;
}
void dfs(int startx,int starty,int size, int step)
{
		if (step > maxvalue)
		{
			maxvalue = step;
		}
	for (int i = startx; i < size; i++)
	{
		if (i != startx)
			starty = 0;
		for (int j = starty; j < size; j++)
		{
			if (judge(i,j,size))
			{
				book[i][j] = true;
				dfs(i,j,size, step + 1);
				book[i][j] = false;
			}
		}
	}

}

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				book[i][j] = false;
				maps[i][j] = getchar();
			}
			getchar();
		}
		maxvalue = -1;
		dfs(0,0,n,0);
		cout << maxvalue << endl;
	}
	system("pause");
	return 0;
}