#include <bits/stdc++.h>

using namespace std;

void big_plus(int numa[],int numb[]);//大数的加法，实现是从末尾来存放个位，然后依次递推
void big_mod(int numa[],int numb[]);//大数的求余算法，实际实现是减法，当位数相差比较大时，先减去一个大倍数的b,减少算法上面的时间消耗
void init(int a[],int b[],int c[],char ca[],char cb[],char cc[]);//数据初始化
void restore(int numa[],char a[]);//将字符串，存储到数组中
bool judge(int a[],int b[]);//判断俩个大数的大小，如果相差超过2位，就用a-n*b，n是a和b的相差的长度-1。
int main()
{
    int N;
    cin>>N;//N组测试样例
    while(N--)
    {
        char a[100],b[100],c[100],flag=0;//flag判断是否全部是0
        int numa[100],numb[100],numc[100];//实际测试50大小的数组，并不能满足题目要求，理论上10^20+10^20足够了，emmm还是申请了100大小的
        init(numa,numb,numc,a,b,c);
        cin>>a>>b>>c;
        restore(numa,a);
        restore(numb,b);
        restore(numc,c);
        big_plus(numa,numb);//其实也可以相加之前求余数，不过简化之后的求余函数就没多少必要了
        big_mod(numa,numc);
        for(int i=0;i<100;i++)//求掉前导0
        {
            if(numa[i]!=0)
                flag=1;
            if(flag)cout<<numa[i];
        }
        if(flag==0)cout<<0;
        cout<<endl;
    }
    return 0;
}
void init(int a[],int b[],int c[],char ca[],char cb[],char cc[])
{
    for(int i=0;i<100;i++)
    {
        a[i]=b[i]=c[i]=0;
        ca[i]=cb[i]=cc[i]='#';//#作为数据输入的结束判断
    }
}
void restore(int numa[],char a[])
{
    int i=0;
    for(i=strlen(a)-1;a[i]=='#';i--);
    for(int j=99;i>=0;i--,j--)//将个位放在数组末尾，然后依次向前递推。
        numa[j]=a[i]-48;
}

bool judge(int a[],int b[])
{
    int lena=0,lenb=0,flag[2]={0};
    for(int i=0;i<=99;i++)//先求出俩个大数的长度
    {
        if(a[i]!=0&&flag[0]==0)
        {
            lena=100-i;
            flag[0]=1;
        }
        if(b[i]!=0&&flag[1]==0)
        {
            lenb=100-i;
            flag[1]=1;
        }
    }
    if(lena>lenb)//大数比较大时，开始算法超时也是在这里。比如计算123456789123456789 123456789123456789 2的时候，不知道要跑几个小时。
    {
        int bit=lena-lenb-1,c[100];
        memset(c,0,sizeof(c));
        for(int i=99-lenb;i<=99;i++)
        {
            c[i-bit]=b[i];
        }
        for(int i=99,tmp=0;i>=0;i--)
        {
            tmp=a[i]-c[i];
            if(tmp<0)
            {
                tmp+=10;
                a[i-1]-=1;
            }
            a[i]=tmp;
        }
        return true;
    }
    else if(lena<lenb)
    {
        return false;
    }
    else if(lena==lenb)
    {
        for(int i=100-lena;i<100;i++)
        {
            if(a[i]>b[i])return true;
            else if(a[i]<b[i])return false;
        }
        return true;//全部都相等也是要求余的，比如：1 2 3结果是0
    }
}

void big_plus(int numa[],int numb[])//大数相加，从末尾开始，注意进位就好了
{
    for(int i=99,tmp=0;i>=0;i--)
    {
        tmp=numa[i]+numb[i];
        while(tmp>=10)
        {
            numa[i-1]+=1;
            tmp-=10;
        }
        numa[i]=tmp;
    }
}

void big_mod(int a[],int b[])//大数求余
{
    while(judge(a,b))
    {
        for(int i=99,tmp=0;i>=0;i--)
        {
            tmp=a[i]-b[i];
            if(tmp<0)
            {
                tmp+=10;
                a[i-1]-=1;
            }
            a[i]=tmp;
        }
    }
}
