#include <bits/stdc++.h>

using namespace std;

void big_plus(int numa[],int numb[]);//�����ļӷ���ʵ���Ǵ�ĩβ����Ÿ�λ��Ȼ�����ε���
void big_mod(int numa[],int numb[]);//�����������㷨��ʵ��ʵ���Ǽ�������λ�����Ƚϴ�ʱ���ȼ�ȥһ��������b,�����㷨�����ʱ������
void init(int a[],int b[],int c[],char ca[],char cb[],char cc[]);//���ݳ�ʼ��
void restore(int numa[],char a[]);//���ַ������洢��������
bool judge(int a[],int b[]);//�ж����������Ĵ�С���������2λ������a-n*b��n��a��b�����ĳ���-1��
int main()
{
    int N;
    cin>>N;//N���������
    while(N--)
    {
        char a[100],b[100],c[100],flag=0;//flag�ж��Ƿ�ȫ����0
        int numa[100],numb[100],numc[100];//ʵ�ʲ���50��С�����飬������������ĿҪ��������10^20+10^20�㹻�ˣ�emmm����������100��С��
        init(numa,numb,numc,a,b,c);
        cin>>a>>b>>c;
        restore(numa,a);
        restore(numb,b);
        restore(numc,c);
        big_plus(numa,numb);//��ʵҲ�������֮ǰ��������������֮������ຯ����û���ٱ�Ҫ��
        big_mod(numa,numc);
        for(int i=0;i<100;i++)//���ǰ��0
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
        ca[i]=cb[i]=cc[i]='#';//#��Ϊ��������Ľ����ж�
    }
}
void restore(int numa[],char a[])
{
    int i=0;
    for(i=strlen(a)-1;a[i]=='#';i--);
    for(int j=99;i>=0;i--,j--)//����λ��������ĩβ��Ȼ��������ǰ���ơ�
        numa[j]=a[i]-48;
}

bool judge(int a[],int b[])
{
    int lena=0,lenb=0,flag[2]={0};
    for(int i=0;i<=99;i++)//��������������ĳ���
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
    if(lena>lenb)//�����Ƚϴ�ʱ����ʼ�㷨��ʱҲ��������������123456789123456789 123456789123456789 2��ʱ�򣬲�֪��Ҫ�ܼ���Сʱ��
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
        return true;//ȫ�������Ҳ��Ҫ����ģ����磺1 2 3�����0
    }
}

void big_plus(int numa[],int numb[])//������ӣ���ĩβ��ʼ��ע���λ�ͺ���
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

void big_mod(int a[],int b[])//��������
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
