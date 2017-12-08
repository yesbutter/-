#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct date
{
    char bus[27];
    int top;
} BUS;
void first_puts()
{
    printf("1->2\n");
}
void second_puts()
{
    printf("3->2\n");
}
void third_puts()
{
    printf("1->3\n");
}
int main()
{
    int lena;
    BUS a,b,c;
    get(a.bus);
    get(b.bus);
    a.top=lena=strlen(a.bus);
    b.top=0;
    c.top=0;
    strcpy(c.bus,"0");
    while(b.top!=lena)
    {
        if(a.bus[a.top]==b.bus[b.top])
        {
            first_puts();
            b.bus[b.top+1]=a.bus[a.top];
            a.top--;
            b.top++;

        }
        if(b.bus[b.top]==c.bus[c.top])
        {
            second_puts();
            b.top++;
            c.top--;
        }
        if(a.bus[a.top]!=b.bus[b.top]&&b.bus[b.top]!=c.bus[c.top])
        {
            third_puts();
            c.bus[c.top+1]=a.bus[a.top];
            a.top--;
            c.top++;
        }
        if(a.top==0&&b.bus[b.top]!=c.bus[c.top])
        {
            printf("Are you kidding me?");
        }
        if(a.top==0&&b.bus[b.top]!=c.bus[c.top])break;
    }
    getchar();
    return 0;
}
