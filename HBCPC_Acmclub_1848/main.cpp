#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,B,temp,bikerent[1002]= {0},student_money[102],cnt;
    cin>>T;
    while(T--)
    {
        memset(bikerent,0,sizeof(bikerent));
        cnt=0;
        cin>>N>>B;
        for(int i=1; i<=N; i++)
            cin>>student_money[i];
        for(int i=1; i<=B; i++)
        {
            cin>>temp;
            bikerent[temp]++;
        }
        sort(student_money+1,student_money+N+1);
        for(int i=1; i<=N; i++)
        {
            if(bikerent[student_money[i]])
            {
                cnt++;
                bikerent[student_money[i]]--;
            }
            else
            {
                for(int j=student_money[i]-1; j>0; j--)
                {
                    if(bikerent[j])
                    {
                        cnt++;
                        bikerent[j]--;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
