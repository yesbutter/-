#include<iostream>
#include<map>
#include<string>

using namespace std;
int main()
{
	int a, b, n,tmp[3] = { 1,1 };
	while (true)
	{
		cin >> a >> b >> n;
		tmp[0] = 1, tmp[1] = 1;
		if (a == b && b == n && n == 0)
			break;
		for (int i = 3; i <= n%48; i++)
		{
			tmp[2] = (a*tmp[1]) + (b*tmp[0]) ;
			tmp[2] %= 7;
			tmp[0] = tmp[1];
			tmp[1] = tmp[2];
		}
		cout << tmp[1] << endl;
	}
	system("pause");
	return 0;
}