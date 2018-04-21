#include <iostream>
#define MOD 1000000007
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long N,temp,ans=0;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            ans=(ans+(((temp*(N-i))%MOD*(i+1))%MOD))%MOD;
        }
        cout<<ans<<endl;
    }
}
