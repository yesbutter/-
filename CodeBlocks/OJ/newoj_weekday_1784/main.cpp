#include <bits/stdc++.h>

using namespace std;

int main()
{
    int book[1000],cnt;
    char s[1000];
    while(cin.getline(s,1000))
    {
        cnt=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==' ')
            {
                book[cnt++]=i;
            }
        }
        book[cnt]=strlen(s);
        for(int i=cnt-1;i>=0;i--)
        {
            for(int j=book[i]+1;j<book[i+1];j++)
                printf("%c",s[j]);
            printf(" ");
        }
        for(int i=0;i<book[0];i++)
            printf("%c",s[i]);
        cout<<endl;
    }
    return 0;
}
