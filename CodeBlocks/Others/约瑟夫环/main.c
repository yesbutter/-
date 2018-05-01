#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n,k,t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&k);
        int last[3]={0};
        last[0] = (k-1)%3;
        for(i=4;i<=n;i++)
            last[0]=(last[0]+k)%i;
        last[1] = 1-(0+k)%2;
        for(i=3;i<=n;i++)
            last[1]=(last[1]+k)%i;
        for(i=2;i<=n;i++)
            last[2]=(last[2]+k)%i;
        printf("%d %d %d\n",last[0]+1,last[1]+1,last[2]+1);

    }
    return 0;
}
