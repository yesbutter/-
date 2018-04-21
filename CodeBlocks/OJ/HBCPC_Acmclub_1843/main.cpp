#include <bits/stdc++.h>

using namespace std;

int main()
{
    int C,a[5],demoa[5]={85,55,55,85,305};
    cin>>C;
    while(C--)
    {
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        a[4]=a[0]+a[1]+a[2]+a[3];
        if(a[0]<demoa[0]||a[1]<demoa[1]||a[2]<demoa[2]||a[3]<demoa[3]||a[4]<demoa[4])
        {
            cout<<'C'<<endl;
            continue;
        }
        if(a[4]>=demoa[4]&&a[4]<370)
            cout<<'B'<<endl;
        else cout<<'A'<<endl;
    }
    return 0;
}
