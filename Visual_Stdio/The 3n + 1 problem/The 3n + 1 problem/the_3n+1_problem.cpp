#include<iostream>
#include<time.h>
using namespace std;

int cnt[1000002];
void fun(long long n)
{
	long long cnts = 1,tmp=n;
	while (n != 1 )
	{
		if (n % 2 == 1)n = 3 * n + 1;
		else n = n / 2;
		cnts++;
		//cout << n<<": "<<cnts << endl;
	}
	n = tmp; 
	while (n != 1)
	{
		if (n < 1000002)
		{
			cnt[n] = cnts;
		}
		if (n % 2 == 1)n = 3 * n + 1;
		else n = n / 2;
		cnts--;
	}
}
int main()
{
	int i, j, max;
	/*double startTime = clock();
	for (int i = 1000002; i >0; i--)
	{
		if (cnt[i] == 0) 
		{ 
			fun(i);
			double endTime = clock();
			cout << i<<"Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		}
	}
	double endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;*/
	while (cin >> i >> j)
	{
		max = -1;
		int x=i, y=j;
		if (i > j)
		{
			swap(i, j);
		}
		for (int k = i; k <= j; k++)
		{
			if (cnt[k] == 0)
				fun(k);
			if (max < cnt[k])
			{
				max = cnt[k];
			}
		}
		cout << x << " " << y << " " << max << endl;
	}
	system("pause");
	return 0;
}