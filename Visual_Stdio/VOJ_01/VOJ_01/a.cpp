#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int a, b, flag = -1, book[1002] = { 0 };
		stack<int> s;
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (a == 1)
			{
				s.push(b);
				q.push(b);
				book[b] = 1;
			}
			if (a == 2 && flag <2&&flag!=-1)
			{
				if (flag == 0 && q[q.front] == b)
				{
					flag = 4;
				}
				if (q[q.front] != b&&book[b]!=0)
				{
					flag = 4;
				}
			}
			if (a==2&&flag==-1)
			{
				if(s[s.top] == b)
					flag = 0;
				else if (q[q.front] == b)
				{
					flag = 1;
				}
				else if (book[b] != 0)
				{
					flag = 2;
				}
			}

		}
	}
}