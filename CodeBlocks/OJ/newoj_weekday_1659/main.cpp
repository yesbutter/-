#include <bits/stdc++.h>

using namespace std;

char str[1024*1024+1];
int a[1024*1024][26];
int main()
{
    int n;
    char s[10];
    int b[26];

    memset(a,0,sizeof(a));

    scanf("%s", str);

    for(int i=0; i<=(strlen(str)-8); i++)
        for(int j=i; j<=i+7; j++)
            a[i][str[j]-'a']+=1;

    scanf("%d",&n);


    int sum=0;
    for(int k=0; k<n; k++)
    {
        int flag;
        memset(b,0,sizeof(b));

        scanf("%s", s);

        for(int i=0; i<strlen(s); i++)
            b[s[i]-'a']+=1;

        for(int i=0; i<=strlen(str)-8; i++)
        {
            flag=1;
            for(int j=0; j<26; j++)
            {
                if(a[i][j]!=b[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
