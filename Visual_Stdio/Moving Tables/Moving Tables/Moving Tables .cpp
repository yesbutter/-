#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int T, n, start, end, tmp,cnts[502];
	scanf("%d", &T);
	while (T--)
	{
		memset(cnts, 0, sizeof(cnts));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &start, &end);
			if (start > end)
			{
				swap(start, end);
			}
			if (start % 2 == 0)
				start -= 1;
			if (end % 2 == 1)
				end += 1;
			for (int i = start; i <= end; i++)
				cnts[i] += 10;
		}
		printf("%d\n", *max_element(cnts, cnts + 500));
	}
	system("pause");
	return 0;
}