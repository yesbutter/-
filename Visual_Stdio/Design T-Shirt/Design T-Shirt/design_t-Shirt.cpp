#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 505;

struct node {
	double cnt;
	int t;
};
node cnt[maxn];
int cmp(node a, node b)
{
	return a.cnt > b.cnt;
	
}
int cmp2(node a, node b)
{
	return a.t >b.t;
}
int main()
{
	int n, m, k;
	double tmp;
	while (cin >> n >> m >> k)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == 0)
					cnt[j].cnt = 0;
				scanf("%lf", &tmp);
				cnt[j].cnt += tmp;
				cnt[j].t = j+1;
			}
		}
		sort(cnt, cnt + m,cmp);
		sort(cnt, cnt + k, cmp2);
		for (int i = 0; i < k&&i < m; i++)
		{
			if (i != 0)
				cout << " ";
			cout << cnt[i].t;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}