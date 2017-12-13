#include <bits/stdc++.h>

using namespace std;

bool Prime(long n)
{
    for(long i=2; i*i<=n; i++)
        if(n%i==0)return false;
    return true;
}


int main()
{
    long n;
    while(~scanf("%ld",&n))
    {
        long i;
        for(i=1; i*i<=n; i++)
        {
            if(Prime(n/i)&&n%i==0)
            {
                cout<<i<<endl;
                break;
            }
        }
        if(n==1)
            cout<<0<<endl;
    }
    return 0;
}
