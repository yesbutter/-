#include <stdio.h>
int main()
{
    int max=0,maxpos=0,i,n,p,chengji,cj[10010]= {0},book[10010]= {0};
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&p,&chengji);
        cj[p]=chengji+cj[p];
        book[p]=1;
    }
    for(i=1; i<=n; i++)
        if(book[i])
            if(cj[i]>max)
            {
                max=cj[i];
                maxpos=i;
            }
    printf("%d %d",maxpos,max);
    return 0;
}
