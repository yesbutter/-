#include <bits/stdc++.h>

using namespace std;

int main()
{
    char temp;
    int sum=0,zero=0,one=0;
    while(~scanf("%c",&temp))
    {
        if(temp>='A'&&temp<='Z')
            sum=sum+temp-'A'+1;
        if(temp>='a'&&temp<='z')
            sum=sum+temp-'a'+1;
    }
    while(sum)
    {
        if(sum%2)one++;
        else zero++;
        sum=sum/2;
    }
    cout<<zero<<" "<<one<<endl;
    return 0;
}
