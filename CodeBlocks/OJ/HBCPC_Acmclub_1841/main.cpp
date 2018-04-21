#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,tmp;
    char s[33];
    cin>>N;
    while(N--)
    {
        tmp=0;
        cin>>s;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                tmp=10*tmp+s[i]-'0';
        }
        cout<<tmp*513<<endl;
    }
}
