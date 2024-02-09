#include<stdio.h>

int main()
{
    int n;
    
    printf("\nEnter the number of rows:");
    scanf("%d",&n);

    for ( int i=n; i>=1; i-- )
    {
        for ( int sp=0; sp<=(n-i); sp++ )
        {
            printf(" ");
        } 
        for ( int j=i; j>=1; j--)
        {
            printf("*");
        }
        printf("\n");
    } 
}