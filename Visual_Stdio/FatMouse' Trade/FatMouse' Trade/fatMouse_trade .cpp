#include<iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
struct Food
{
	double x, y;
} food[1005];
int cmp(Food i, Food j)
{
	return i.x*j.y>j.x*i.y;

}
int main()
{
	double s;
	int m, n, i;
	while (scanf("%d%d", &m, &n) != EOF && (m >= 0 && n >= 0))
	{
		for (i = 0; i<n; i++)
			scanf("%lf%lf", &food[i].x, &food[i].y);
		sort(food, food + n, cmp);
		s = 0;
		for (i = 0; i<n; i++)                                 //M可能大于所有food[i].y之和
		{
			if (m>food[i].y)
			{
				s += food[i].x;
				m -= food[i].y;
			}
			else
			{
				s += m * food[i].x / food[i].y;
				break;
			}
		}
		printf("%.3lf\n", s);
	}
	return 0;
}