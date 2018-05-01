#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int main()
{
	int a[maxn], b[maxn],n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
}