#include<stdio.h>
int main()
{
    int n=1,i,j,row=4,col=4;
    
    for(i=1;i<=row;i++)
    { 
        for(j=1;j<=i;j++) 
        {
            printf("%d\t",n);
            n++;
        }
            

    }


}