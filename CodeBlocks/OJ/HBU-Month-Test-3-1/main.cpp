#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j;
    int Treenode[1002];
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>Treenode[i];
    cin>>i>>j;
    int flag=0;
    if(i>j&&i%j==0)flag=1;
    if(j>i&&j%i==0)flag=1;
    if(Treenode[i]==0)printf("ERROR: T[%d] is NULL",i);
    else if(Treenode[j]==0)printf("ERROR: T[%d] is NULL",j);
    else if(flag==1)
    {
        if(i>j)
            cout<<j<<" "<<j;
        else if(i<j)
            cout<<i<<" "<<i;
    }
    else{
        if(i>j)
            cout<<j/2<<" "<<Treenode[j/2];
        else if(i<j)
            cout<<i/2<<" "<<Treenode[i/2];
        else
            cout<<i<<" "<<Treenode[i];
    }
    return 0;
}
