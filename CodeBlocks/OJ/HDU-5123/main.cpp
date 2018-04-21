#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,a[102];
    cin>>T;
    while(T--)
    {
        int maxpos=0;
        cin>>N;
        memset(a,0,sizeof(a));
        while(N--)
        {
            int tmp;
            cin>>tmp;
            a[tmp]+=1;
        }
        for(int i=0,maxvalue=0;i<102;i++)
        {
            if(a[i]>maxvalue)
            {
                maxpos=i;
                maxvalue=a[i];
            }
        }
        cout<<maxpos<<endl;
    }
    return 0;
}
