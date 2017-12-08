#include <bits/stdc++.h>

using namespace std;

int main()
{
    char male[25],famale[25];
    while(~scanf("%s%s",male,famale))
    {
        for(int i=0,flag=0,len=strlen(male);i<len;i++)
        {
            if(flag)
            printf("%c",male[i]);
            if(male[i]=='_')
                flag=1;
        }
        cout<<"_small_";
        for(int i=0,flag=0,len=strlen(famale);i<len;i++)
        {
            if(flag)
            printf("%c",famale[i]);
            if(famale[i]=='_')
                flag=1;
        }
        cout<<endl;
    }
}
