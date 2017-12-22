#include <bits/stdc++.h>

#define MAXSIZE 50
int StrIndex_KMP(char s[],char t[],int pos,int next[]);
void GetNext(char t[],int next[]);
int main()
{
    char s[MAXSIZE]={0},t[MAXSIZE]={0};
    int i,pos,j;
    int next[9]={0};
    printf("����������s:");
    gets(s);
    printf("������Ҫ��ѯ���Ӵ�:");
    gets(t);
    printf("������Ӵ�s�ĵڼ����ַ���ʼ����:");
    scanf("%d",&pos);
    GetNext(t,next);
    j=StrIndex_KMP(s,t,pos,next);
    if(j==0)
    {
        printf("����ʧ�ܣ�");
    }
    else
        printf("���ҳɹ���%d",j);
    return 0;
}
void GetNext(char t[],int next[])
{
    int j=-1,i=0;
    next[0] = -1;
    while(i<strlen(t)-1)
    {
        if(j==-1||t[i]==t[j])
        {
            next[++i]=++j;
        }
        else j=next[j];
    }
}
int StrIndex_KMP(char s[],char t[],int pos,int next[])
{
    int i=pos,j=-1,lens=strlen(s),lent=strlen(t);
    while((i<lens)&&(j<lent))       //��û������������
    {
        if(j==-1||s[i]==t[j])
        {
            i++;j++;
        }
        else j=next[j];
    }
    if(j==lent)  return (i-strlen(t))+1;
    else return 0;
}
