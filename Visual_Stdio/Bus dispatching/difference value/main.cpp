#include<bits/stdc++.h>
using namespace std;
char c[50001];
char s[50001];
int n;
struct zz
{
    char s[50];
}q[1050];
int cmp(zz a,zz b)//字典序进行排序
{
    return strcmp(strcat(a.s,b.s),strcat(b.s,a.s))<0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(q,0,sizeof(q));
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",q[i].s);
        }

        sort(q,q+n,cmp);
        for(int i=0,j=n-1;i<n&&j>=0;j--,i++)
        {
             strcat(c,q[i].s);//最小
             strcat(s,q[j].s);//最大

        }

        int l=strlen(c);
        for(int i=l-1;i>=0;i--)
        {
            if(s[i]-c[i]<0)
            {
                --s[i-1];
                s[i]+=10;
            }
           s[i]=s[i]-c[i]+'0';

        }
       int y=0;
       for(;y<l;y++)
       {
           if(s[y]!='0'){puts(s+y);break;}
       }
       if(y==l) printf("0\n");

    }
    return 0;
}
