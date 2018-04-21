#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,a[1000],b[1000],numa=0,numb=0,temp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&temp);
        if(temp%2==0)
        {
            b[numb]=temp;
            numb++;
        }
        else
        {
            a[numa]=temp;
            numa++;
        }
    }
    for(i=0,j=0; i+j<n;)
    {
        if(numa>i)
        {
            if(i!=0)printf(" ");
            printf("%d",a[i]);
            i++;
        }

        if(numa>i)
        {
            if(i!=0)printf(" ");
            printf("%d",a[i]);
            i++;
        }

        if(numb>j)
        {
            if(i!=0||j!=0)printf(" ");
            printf("%d",b[j]);
            j++;
        }

    }
    return 0;
}
