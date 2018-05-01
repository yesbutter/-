#include<iostream>
#include<vector>
#include<map>

using namespace std;

//int v[100000][1000];

/*使用map和矢量进行对下标管理，
 *坑1：map插入需要make_pair一下要不然会爆出未知异常
 *坑2：时刻注意对下标的处理。emm都是泪
 */
int main()
{
	int n, t,cnt=0,tmp;
	map<int, int> m;
	vector<vector<int>> v2;
	while (cin >> n >> t)
	{
		cnt = 1, m.clear(),v2.clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> tmp;
			if (m.count(tmp) == 0)
			{
				vector<int> v;
				m.insert(make_pair(tmp,cnt));
				v.push_back(i);
				v2.push_back(v);
				cnt++;
			}
			else
			{
				int position = m[tmp];
				v2[position-1].push_back(i);
			}
		}

		for (int i = 1,a,b; i <= t; i++)
		{
			cin >> a >> b;
			if (m[b] != 0)
			{
				int position = m[b];
				if (v2[position-1].size() >= a)
				{
					cout << v2[position-1][a-1] << endl;
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	system("pause");
	return 0;
}
