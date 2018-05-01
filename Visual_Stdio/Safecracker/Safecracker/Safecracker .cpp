#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
using namespace std;

int choose[5],n,flag=0;
int book[2046];
int ans[5];
bool judge(int a[5], int b[5])
{
	for (int i = 0; i < 5; i++)
	{
		if (a[i] < b[i])
			return false;
		if (a[i] > b[i])
			return true;
	}

}
void dfs(string tmp,int choose[5],int cnt)
{
	if (cnt == 5 && choose[0] - (int)pow(choose[1], 2) + (int)pow(choose[2], 3) - (int)pow(choose[3], 4) + (int)pow(choose[4], 5) == n)
	{
		flag = 1;
		if (judge(choose, ans)) 
		{
			for (int i = 0; i < 5; i++)
			{
				ans[i] = choose[i];
			}
		}
		return;
	}
	if (cnt == 5)
		return;
	for (int i = 0; i < tmp.size(); i++)
	{
		//if (flag == 1)
			//return;
		if (book[i] == 0)
		{
			book[i] = 1;
			choose[cnt] = tmp[i] - 'A' + 1;
			dfs(tmp, choose, cnt + 1);
			book[i] = 0;
		}
	}
}
int main()
{
	string tmp;
	while (true)
	{
		cin >> n;
		getchar();
		getline(cin, tmp);
		if (n == 0 && tmp == "END")
			break;
		memset(book, 0, sizeof(book));
		memset(ans, -1, sizeof(ans));
		flag = 0;
		dfs(tmp, choose, 0);
		if (flag == 1)
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%c", ans[i] + 'A' - 1);
				//cout << ans[i] + 'A' - 1;
			}
			cout << endl;
		}
		else
		{
			cout << "no solution" << endl;
		}
	}
	system("pause");
	return 0;
}