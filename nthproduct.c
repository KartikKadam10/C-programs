#include<stdio.h>
int main()
{
    int x,n,i,p=1;

    printf("Enter the value of x:\n");
    scanf("%d",&x);

    printf("Enter the value of n:\n");
    scanf("%d",&n);

    
    for(i=1;i<=n;i++)
    {
        p=p*x;
    }
    printf("\nProduct:%d",p);
    return 0;

}