#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
int main()
{
    int book[MAXSIZE]={0},i,j=0,insert,number,killnum,temp,position;
    printf("Please input the number of the people:");
    scanf("%d",&number);
    printf("Please input the number you want to begin:");
    scanf("%d",&insert);
    printf("Please input do you want to kill every kill-number:");
    scanf("%d",&killnum);
    temp=number;
    while(temp!=1)
    {
        for(i=insert;i<number;i++)
        {
            if(!book[i])
            {
                j++;
            }
            if(j%killnum==0)
            {
                book[i]=1;
                temp--;
            }
            if(temp==1)
                position=i;
        }
        insert=0;
    }
    printf("The final number is %d",position+1);
    return 0;
}
