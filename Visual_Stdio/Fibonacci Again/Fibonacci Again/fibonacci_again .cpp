#include<iostream>
#include<string.h>
using namespace std;

int f[1000005] = { 1,2 };
bool judge[1000005];
int main()
{
	int n;
	memset(judge, false, sizeof(judge));
	for (int i = 2; i < 1000005; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] % 3 == 0)
			judge[i] = true;
		f[i] %= 3;
	}
	while (cin >> n)
	{
		if (judge[n])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	system("pause");
	return 0;

}