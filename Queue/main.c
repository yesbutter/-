#include<stdio.h>
#define MAXSIZE 1000
struct stack
{
    int date[MAXSIZE];
    int top;
}i,o;
//Sure s1 is max stack
void max(int *x,int *y)
{
    int temp;
    if(*y>*x)
    {
        temp=*y;
        *y=*x;
        *x=temp;
    }
}
int main()
{
    int n1,n2,temp;
    char c;
    scanf("%d %d",&n1,&n2);
    max(&n1,&n2);
    o.top=i.top=0;
    while(1)
    {
        scanf("%c",&c);
        if(c=='T')break;
        if(c=='A')
        {
            if(i.top==n2&&o.top!=0)
            {
                printf("ERROR:Full\n");
            }
            if(i.top==n2&&o.top==0)
            {
                for(;i.top>0;i.top--)
                {
                    o.top++;
                    o.date[o.top]=i.date[i.top];
                }
            }
            if(i.top!=n2)
            {
                i.top++;
                scanf("%d",&temp);
                i.date[i.top]=temp;
            }
        }
        if(c=='D')
        {
            if(i.top==0&&o.top==0)
            {
                printf("ERROR:Empty\n");
            }
            if(o.top>0)
            {
                printf("%d\n",o.date[o.top]);
                o.top--;
            }
            else if(o.top==0&&i.top>0)
            {
                for(;i.top>0;i.top--)
                {
                    o.top++;
                    o.date[o.top]=i.date[i.top];
                }
                printf("%d\n",o.date[o.top]);
                o.top--;
            }
        }
    }
    return 0;
}
