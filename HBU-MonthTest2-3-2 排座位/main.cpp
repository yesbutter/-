#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rel[103][103],emy[103][103];
    int book[103];
    int n,m,k;
    cin>>n>>m>>k;
    memset(emy,0,sizeof(emy));
    memset(rel,0,sizeof(rel));
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        rel[a][b]=rel[b][a]=c;
        if(c==-1)
            emy[a][b]=emy[b][a]=1;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(rel[i][k]==1&&rel[k][j]==1)
                {
                    if(rel[i][j]==-1)rel[i][j]=2;
                    if(rel[i][j]== 0)rel[i][j]=1;
                }
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        memset(book,0,sizeof(book));
        if(rel[a][b]==1)
        {
            cout<<"No problem"<<endl;
        }
        else if(emy[a][b]==1&&rel[a][b]==-1)
        {
            cout<<"No way"<<endl;
        }
        else if(rel[a][b]==0)
        {
            cout<<"OK"<<endl;
        }
        else if(rel[a][b]==2)
            cout<<"OK but..."<<endl;
    }
    return 0;
}
