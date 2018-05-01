#include<iostream>
#include<map>
#include<string>
#include<string.h>

using namespace std;
int main()
{
	map<string, int> m;
	int cnt[1005] = { 0 }, t, maxs = -1, maxpos = -1;
	string tmp, maxname;
	while (true)
	{
		int num = 1;
		maxs = -1, maxpos = -1;
		cin >> t;
		if (t == 0)
			break;
		m.clear();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < t; i++)
		{
			cin >> tmp;
			if (m.count(tmp) == 0)
			{
				cnt[num] = 1;
				if (maxs < cnt[num])
				{
					maxs = cnt[num];
					maxpos = num;
					maxname = tmp;
				}
				m.insert(make_pair(tmp, num++));
			}
			else
			{
				int position = m[tmp];
				cnt[position] += 1;
				if (maxs < cnt[position])
				{
					maxs = cnt[position];
					maxpos = position;
					maxname = tmp;
				}
			}
		}
		cout << maxname << endl;
	}
	system("pause");
	return 0;
}