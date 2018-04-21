#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int> >l;
    int a[10002],i,n,money=0,count=1;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    while(count!=n)
    {
        sort(a+1,a+n+1);
        if(n==3&&n-1==count)money+=a[1];
        else money+=a[2]+a[1];
        count++;
        a[1]=a[1]+a[2];
        a[2]=51;
    }
    if(n==1)cout<<a[1];
    else cout<<money;
}
