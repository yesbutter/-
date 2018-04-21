#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct linear_congruential
{
    double a[30];
    int top;
}line;
double cal(char op,double a,double b)
{
    double sum;
    switch(op)
    {
    case '+':
        sum=a+b;
        break;
    case '-':
        sum=a-b;
        break;
    case '*':
        sum=a*b;
        break;
    case '/':
        if(b)
            sum=a/b;
        else sum=9999;
        break;
    default:
        sum=9999;
        break;
    }
    return sum;
}
//10的n次幂函数
int powc(int weishu)
{
	int sum=1,i=1;
	for(i=1;i<=weishu;i++)
		sum*=10;
	return sum;
}
int main()
{
    char c[60];
    int len,flag=1,i,weishu=0;
    double temp;
    line.top=0;
    gets(c);
    len=strlen(c);
    for(i=len-1;i>=0;i--)
    {
        if(c[i]>='0'&&c[i]<='9')
        {
            //要确保数字读取完整
            line.top++;
            line.a[line.top]=c[i]-48;
            weishu=1;
            while(c[i-1]>='0'&&c[i-1]<='9')
            {
            	line.a[line.top]=powc(weishu)*(c[i-1]-48)+line.a[line.top];
            	i--;
            	weishu++;
			}
			//判断正负
        	if(c[i-1]=='-')
        	{
        		line.a[line.top]=-line.a[line.top];
        		i--;
			}
		}
        else
        {
            if(c[i]!=' ')
            {
                //运算数字不够
                if(line.top<2)
                {
                    flag=0;
                }
                else
                {
                    temp=cal(c[i],line.a[line.top],line.a[line.top-1]);
                    if(temp!=9999)
                    {
                        line.a[line.top-1]=temp;
                        line.top--;
                    }
                    //运算结果错误
                    else
                    {
                        flag=0;
                    }
                }
            }
        }
        if(flag==0)break;
    }
    if(flag)printf("%.1f",line.a[line.top]);
    else printf("ERROR");
    return 0;
}
