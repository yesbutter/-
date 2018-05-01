#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> a, b;

bool judge()
{
	while (a[a.top] != b[b.top])
	{

	}
}
int main()
{
	int n;
	string tmpa, tmpb;
	while (cin >> n)
	{
		cin >> tmpa >> tmpb;
		a.top = b.top = -1;
		for (int i = 0; i <n; i++)
		{
			a.push(tmpa[i] - '0');
			b.push(tmpb[i] - '0');
		}
	}
}
