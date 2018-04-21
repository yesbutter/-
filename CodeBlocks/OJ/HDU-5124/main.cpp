#include <bits/stdc++.h>

using namespace std;

int book[1000007];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,maxvalue=0;
        cin>>N;
        memset(book,0,sizeof(book));
        while(N--)
        {          
            int a,b;
            cin>>a>>b;
            for(int i=a;i<1000007&&i<=b;i++)
            {
               	book[i]++;
               	if(book[i]>maxvalue)
               		maxvalue=book[i];
			}
        }
        cout<<maxvalue<<endl;
    }
    return 0;
}
