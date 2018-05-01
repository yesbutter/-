#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int l, w;
	int flag = 0;
};
bool cmp1(node a,node b)
{
	if(a.l!=b.l)
		return a.l > b.l;
	return a.w > b.w;
}

int main()
{
	int T, n;
	vector<node> v;
	node tmp;
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d", &n);
		v.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &tmp.l, &tmp.w);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end(), cmp1);
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].flag == 0)
			{
				ans++;
				for (int j = i + 1,first=v[i].w; j < v.size(); j++)
				{
					if (v[j].flag == 0&&v[j].w<=first)
					{
						v[j].flag = 1;
						first = v[j].w;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}