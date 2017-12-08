#include <bits/stdc++.h>

using namespace std;
void Inverted(char *a,int *numa)
{
    for(int i=strlen(a)-1,j=0; i>=0; i--,j++)
        numa[j]=a[i]-'0';
}
int main()
{
    int temp,numa[25]= {0},numb[25]= {0},numc[25]= {0},flag=0,i;
    char a[25],b[25],c[25];
    cin>>a>>b>>c;
    Inverted(a,numa);
    Inverted(b,numb);
    Inverted(c,numc);
    for(int i=0; i<25; i++)
        if(numa[i]==0)
            numa[i]=10;
    for(int i=0; i<25; i++)
    {
        temp=numb[i]+numc[i]+flag;
        numb[i]=temp%numa[i];
        flag=temp/numa[i];
    }
    for(i=24;i>=0; i--)
    {
        if(numb[i]!=0)break;
        if(numb[i]==0)numb[i]=-1;
    }
    if(i==-1)printf("0");
    for(; i>=0; i--)
        printf("%d",numb[i]);
    return 0;
}
