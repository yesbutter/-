#include <bits/stdc++.h>

using namespace std;

long long grade[1001][1001]= {0},q,posq=-1;

bool judge(int posi,int posj,int row,int col);
int main()
{
    int m,n,posx=-1,posy=-1,flag=0;
    cin>>m>>n>>q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            {
                cin>>grade[i][j];
            }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(judge(i,j,n,m))
            {
                posx=i;
                posy=j;
                flag++;
            }
        }
    if(flag==1)
        printf("(%d, %d): %ld\n",posy+1,posx+1,grade[posx][posy]);
    if(flag>1)
        cout<<"Not Unique"<<endl;
    if(flag==0)
        cout<<"Not Exist"<<endl;
    return 0;
}
bool judge(int posi,int posj,int row,int col)
{
    int flag=0,i;
    for(i=posi-1;i<=posi+1;i++)
    {
        for(int j=posj-1;j<=posj+1;j++)
        {
            if(i>=0&&i<row&&j>=0&&j<col)
            {
                if(i==posi&&j==posj)
                    continue;
                if(abs(grade[i][j]-grade[posi][posj])<q||book[grade[posi][posj]]>1)
                    return false;
            }
        }
    }
    for(int i=posi-1;i<=posi+1;i++)
    {
        for(int j=posj-1;j<=posj+1;j++)
        {
            if(i>=0&&i<row&&j>=0&&j<col)
            {
                if(i==posi&&j==posj)
                    continue;
                if(flag==1&&grade[i][j]<grade[posi][posj])
                    return false;
                if(flag==2&&grade[i][j]>grade[posi][posj])
                    return false;
                if(flag==0&&grade[i][j]>grade[posi][posj])
                    flag=1;
                else if(flag==0&&grade[i][j]<grade[posi][posj])
                    flag=2;
            }
        }
    }
    return true;
}
