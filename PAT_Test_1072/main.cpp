#include <bits/stdc++.h>
int main()
{
    char name[10];
    int M,N,book[10000]= {0},temp,i,peo=0,count=0,flag=0,out[10],outcount=0;;
    scanf("%d %d",&N,&M);
    while(M--)
    {
        scanf("%d",&temp);
        book[temp]=1;
    }
    while(N--)
    {
        flag=0,outcount=0;;
        scanf("%s %d",name,&i);
        while(i--)
        {
            scanf("%d",&temp);
            if(book[temp])
            {
                out[outcount++]=temp;
                flag=1;
            }
        }
        count+=outcount;
        i=0;
        if(flag)
        {
            printf("%s: ",name);
            while(i<outcount)
            {
                if(i!=0)printf(" ");
                printf("%04d",out[i++]);
            }
            printf("\n");
            peo++;
        }
    }
    printf("%d %d",peo,count);
    return 0;
}
