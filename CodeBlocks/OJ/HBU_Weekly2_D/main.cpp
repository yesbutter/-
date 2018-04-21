#include <iostream>
#include <cstring>
int dp[1010];
using namespace std;

int LIS(int arr[],int n)
{
    memset(dp,0,sizeof(dp));
    int maxvalue=0,ans=0,maxpos=0;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        ans=dp[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&dp[j]>ans)
                ans=dp[j];
        }
        dp[i]=ans+1;
    }
    ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>=maxvalue)
        {
            maxvalue=dp[i];
            maxpos=i;
        }
    }
    dp[maxpos]=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>ans)
        {
            ans=dp[i];
        }
    }
    return ans;
}
int main()
{
    int T,N,arr_ey[1010];
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr_ey[i];
        cout<<LIS(arr_ey,N)<<endl;
    }
}
