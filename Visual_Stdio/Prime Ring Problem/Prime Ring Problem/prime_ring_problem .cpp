#include<iostream>

using namespace std;

bool isper(int n)
{
	if (n < 2)return false;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int book[21] = { 0 },a[21];
bool per[10005];
void dfs(int step,int state,int n)
{
	if (step == n&&per[a[n-1]+1])
	{
		for (int i = 0; i < n; i++)
		{
			if (i != 0)cout << " ";
			cout << a[i];
		}
		cout << endl;
		return;
	}
	if (step > n)
		return;
	for (int i = 2; i <= n; i++)
	{
		if (per[state + i]&&book[i]==0)
		{
			book[i] = 1;
			a[step] = i;
			dfs(step + 1, i,n);
			book[i] = 0;
		}
	}
}
int main()
{
	int n,cnt=0;
	memset(per, false, sizeof(per));
	for (int i = 0; i < 10005; i++)
	{
		if (isper(i))
			per[i] = true;
	}
	while (cin >> n)
	{
		a[0] = 1;
		printf("Case %d:\n", ++cnt);
		dfs(1, 1,n);
		cout << endl;
	}
	system("pause");
	return 0;
}