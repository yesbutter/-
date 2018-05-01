#include<iostream>

using namespace std;

int main()
{
	int n, u, d, time = 0;
	while (cin >> n >> u >> d)
	{
		if (n == u && u == d && d == 0)
			break;
		if (d < u&&n < 100 && n>0)
		{
			time = 0;
			n = n - u;
			time = n / (u - d);
			time *= 2;
			if (n % (u - d) != 0)
				time += 2;
			time++;
			cout << time << endl;
		}
	}
	system("pause");
	return 0;
}