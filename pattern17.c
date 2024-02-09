#include<stdio.h>

int main()
{
    int n;

    printf("\nEnter the number of rows:");
    scanf("%d",&n);

    for ( int i=n; i>=1; i-- )
    {
        for ( int sp=1; sp<=(n-i); sp++)
        {
            printf(" ");
        }
        for ( int j=1; j<=i; j++ )
        {
            printf("* ");
        }
        printf("\n");
    }
}