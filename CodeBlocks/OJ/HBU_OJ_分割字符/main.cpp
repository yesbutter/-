#include <bits/stdc++.h>

using namespace std;

int data[1001];
int restore(char tmp[])
{
    memset(data,0,sizeof(data));
    int i,j=0,counts=0,num=0;
    for(i=0;i<strlen(tmp);i++)
    {
        if(tmp[i]=='5')continue;
        for(j=i;tmp[j]!='5'&&j<strlen(tmp);j++)
        {
            num=num*10+tmp[j]-48;
        }
        data[counts++]=num;
        num=0;
        i=j;
    }
    return counts;
}

int main()
{
    char tmp[1002];
    while(cin.getline(tmp,1002))
    {
        int cnt;
        cnt=restore(tmp);
        sort(data,data+cnt);
        for(int i=0;i<cnt;i++)
        {
            if(i!=0)cout<<" ";
            cout<<data[i];
        }
        cout<<endl;
    }
    return 0;
}
